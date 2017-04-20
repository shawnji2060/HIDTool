#pragma execution_character_set("utf-8")
#include "widget.h"

namespace Ui {
class Widget;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QRegExp regExp("[a-fA-F0-9]{8}");//数据校验正则表达式:"[数据范围]{数据长度}"
    ui->sendLineEdit->setValidator(new QRegExpValidator(regExp,this));// 填充数据校验
}

Widget::~Widget()
{
    delete ui;
}

//========================================================================================
//===============================功能操作方法==============================================
//========================================================================================

/*开启设备*/
void Widget::on_openButton_clicked()
{
    myhid_open();
}

/*关闭设备*/
void Widget::on_closeButton_clicked()
{
    myhid_close();
}

/*卸载设备*/
void Widget::on_ejectButton_clicked()
{
    myhid_exit();
}

/*发送数据*/
void Widget::on_sendButton_clicked()
{
    QString send_str = ui->sendLineEdit->text();
    myhid_write(send_str);
}

/*读取数据*/
void Widget::on_readButton_clicked()
{
    qDebug("read data.");
    ui->readBrowser->append("Start recieving...");
//    myhid_read();
//    myhid_read_tmp();
//    rThread->start();
}


//========================================================================================
//===============================功能实现方法==============================================
//========================================================================================

/*************************************************
Function: api_loadcheck()
Description: api加载检测
Calls:NULL
Called By:NULL
Input: void
Return: void
*************************************************/
void Widget::api_loadcheck(){
    QLibrary mylib("hidapi.dll");
    if(mylib.load()){
        QMessageBox::information(NULL,"OK","API load success!");
    }
    else{
        QMessageBox::information(NULL,"Error","API load Error!");
    }
}

/*************************************************
Function: myhid_open()
Description: 打开hid设备并显示设备信息
Calls:
    hid_open()
Called By:
    on_openButton_clicked()
Input: void
Return: void

*************************************************/
void Widget::myhid_open(){
    res = hid_init();//初始化hidapi，成功返回0，失败返回-1
    if(res == -1){
        qDebug("Device init error!");
        QMessageBox::information(NULL,"Error","Init Device Error!");
    }
    else{
        qDebug("Device init success!");
        handle = hid_open(VID,PID,NULL);//打开设备，成功返回pointer，失败返回NULL
        if(handle == NULL){
            qDebug("Device open error!");
            QMessageBox::information(NULL,"Error","Open Device Error!");
        }
        else{
            qDebug("Device open success!");//打开成功，显示设备信息
            ui->vidLineEdit->setText("0x"+QString("%1").arg(VID,4,16,QLatin1Char('0')));//int 转 16进制补0
            ui->pidLineEdit->setText("0x"+QString("%1").arg(PID,4,16,QLatin1Char('0')));
            res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
            ui->manuLineEdit->setText(QString::fromWCharArray(wstr));
            res = hid_get_product_string(handle, wstr, MAX_STR);
            ui->prodLineEdit->setText(QString::fromWCharArray(wstr));
            res = hid_get_serial_number_string(handle, wstr, MAX_STR);
            ui->seriLineEdit->setText(QString::fromWCharArray(wstr));
            res = hid_get_indexed_string(handle, 1, wstr, MAX_STR);
            ui->indxLineEdit->setText(QString::fromWCharArray(wstr));
        }
    }
}


/*************************************************
Function: myhid_close()
Description: 关闭hid设备
Calls:
    hid_close()
Called By:
    on_closeButton_clicked()
    myhid_exit()
Input: void
Return: void
*************************************************/
void Widget::myhid_close(){
    hid_close(handle);
    qDebug("Device is closed.");
    ui->vidLineEdit->clear();
    ui->pidLineEdit->clear();
    ui->manuLineEdit->clear();
    ui->prodLineEdit->clear();
    ui->seriLineEdit->clear();
    ui->indxLineEdit->clear();
}

/*************************************************
Function: myhid_exit()
Description: 关闭并卸载hid设备
Calls:
    hid_exit()
    myhid_close()
Called By:
    on_ejectButton_clicked()
Input: void
Return: void
*************************************************/
void Widget::myhid_exit(){
    res = hid_exit();
    if(0 == res){
        myhid_close();
        qDebug("Device is exitted.");
    }
    else{
        qDebug("Device exit error!");
    }
}

/*************************************************
Function: myhid_read()
Description: 读取接收的数据并存入buf_IN
Calls:
    hid_set_nonblocking()
    hid_read_timeout()
Called By:
    on_readButton_clicked()
Input: void
Return: void
*************************************************/
void Widget::myhid_read(){
    int res_read;
    qDebug("hid read start");
    int count_read = 0;  

    while (1) {
        res = hid_set_nonblocking(handle, 0);//设置阻塞模式
        count_read++;
//        res_read = hid_read(handle,buf_IN,LENGTH_BUF_IN);//读数据
        res_read = hid_read_timeout(handle,buf_IN,LENGTH_BUF_IN,5000);//设置超时读取（超时退出）

        if(LENGTH_BUF_IN == res_read){
            if(buf_IN[0] == 0x05 && buf_IN[1] == 0x01){
                ui->readBrowser->append("Connected!");
            }
            qDebug("buf_IN: %02x %02x     count: %d    res_read = %d",buf_IN[0],buf_IN[1],count_read,res_read);

            ui->readBrowser->append(QString("%1").arg(buf_IN[count_read],2,16,QLatin1Char('0')));//int 转 16进制补0
        }
        else if(0 == res_read){
            qDebug("All read    res_read = %d",res_read);
            break;
        }
        else if(-1 == res_read){
            QMessageBox::information(NULL,"Error","Read Data Error!");
            break;
        }
    }
}

/*************************************************
Function: myhid_read_tmp()
Description: myhid_read()的另一种实现
Calls:
    hid_set_nonblocking()
    hid_read_timeout()
Called By:
    on_readButton_clicked()
Input: void
Return: void
*************************************************/
void Widget::myhid_read_tmp(){
    int count_read = 0;

    while(1){
        count_read++;
        res = hid_read(handle,buf_IN,LENGTH_BUF_IN);
//        res = hid_read_timeout(handle,buf_IN,LENGTH_BUF_IN,5000);
        ui->readBrowser->append(QString("%1").arg(buf_IN[0],2,16,QLatin1Char('0'))+' '+QString("%1").arg(buf_IN[1],2,16,QLatin1Char('0')));
        qDebug("buf_IN: %02x %02x     count: %d    length = %d",buf_IN[0],buf_IN[1],count_read, res);
        if(-1 == res)
            ui->readBrowser->append("Read finished.");
            break;
    }
}


/*************************************************
Function: myhid_write()
Description: 将待发送数据写入buf_OUT
Calls:
    hid_write()
    formatString()
    hexStringtoByteArray()
Called By:
    on_sendButton_clicked()
Input:send_str
Return: void
*************************************************/
void Widget::myhid_write(QString send_str){
    qDebug("write function run.");
    QByteArray send_byte = hexStringtoByteArray(send_str);

    if(send_str.length()%2 == 1)
        send_str = send_str.insert(send_str.length()-1,'0');//发送数据位奇数个在前面补‘0’

    char *send_char = send_byte.data();

    for(int i = 0;i < send_byte.length();i++){
        buf_OUT[i] = (unsigned char)(send_char[i]);
    }

    res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
    Widget::formatString(send_str,2,' ');//在send_str中插入空格
    ui->sendTextEdit->append(send_str);
}

/*************************************************
Function:
    on_led3CheckBox_stateChanged()
    on_led4CheckBox_stateChanged()
    on_led5CheckBox_stateChanged()
    on_led6CheckBox_stateChanged()
    on_ledAllCheckBox_stateChanged()
Description: 发送LED控制信号
Calls:
Called By:
Input:state
Return: void
*************************************************/
void Widget::on_led3CheckBox_stateChanged(int state)
{
    if(state==Qt::Checked){
        buf_OUT[0] = 0x01;
        buf_OUT[1] = 0x01;
        qDebug("%d",buf_OUT[0]);
        qDebug("%d",buf_OUT[1]);
        res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
        ui->sendTextEdit->append("01 01");
    }
    else if(state==Qt::Unchecked){
        buf_OUT[0] = 0x01;
        buf_OUT[1] = 0x00;
        qDebug("%d",buf_OUT[0]);
        qDebug("%d",buf_OUT[1]);
        res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
        ui->sendTextEdit->append("01 00");
    }
}

void Widget::on_led4CheckBox_stateChanged(int state)
{
    if(state==Qt::Checked){
        buf_OUT[0] = 0x02;
        buf_OUT[1] = 0x01;
        res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
        ui->sendTextEdit->append("02 01");
    }
    else if(state==Qt::Unchecked){
        buf_OUT[0] = 0x02;
        buf_OUT[1] = 0x00;
        res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
        ui->sendTextEdit->append("02 00");
    }
}

void Widget::on_led5CheckBox_stateChanged(int state)
{
    if(state==Qt::Checked){
        buf_OUT[0] = 0x03;
        buf_OUT[1] = 0x01;
        res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
        ui->sendTextEdit->append("03 01");
    }
    else if(state==Qt::Unchecked){
        buf_OUT[0] = 0x03;
        buf_OUT[1] = 0x00;
        res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
        ui->sendTextEdit->append("03 00");
    }
}

void Widget::on_led6CheckBox_stateChanged(int state)
{
    if(state==Qt::Checked){
        buf_OUT[0] = 0x04;
        buf_OUT[1] = 0x01;
        res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
        ui->sendTextEdit->append("04 01");
    }
    else if(state==Qt::Unchecked){
        buf_OUT[0] = 0x04;
        buf_OUT[1] = 0x00;
        res = hid_write(handle,buf_OUT,LENGTH_BUF_OUT);
        ui->sendTextEdit->append("04 00");
    }
}

/*循环亮灯*/
void Widget::on_ledAllCheckBox_stateChanged(int state)
{
    if(state == Qt::Checked){
        for(int i = 0;i < 5;i++){
            Widget::on_led3CheckBox_stateChanged(Qt::Checked);
            delay_ms(50);
            Widget::on_led4CheckBox_stateChanged(Qt::Checked);
            delay_ms(50);
            Widget::on_led6CheckBox_stateChanged(Qt::Checked);
            delay_ms(50);
            Widget::on_led5CheckBox_stateChanged(Qt::Checked);
            delay_ms(50);
            Widget::on_led3CheckBox_stateChanged(Qt::Unchecked);
            delay_ms(50);
            Widget::on_led4CheckBox_stateChanged(Qt::Unchecked);
            delay_ms(50);
            Widget::on_led6CheckBox_stateChanged(Qt::Unchecked);
            delay_ms(50);
            Widget::on_led5CheckBox_stateChanged(Qt::Unchecked);
            delay_ms(50);
        }
        Widget::on_led3CheckBox_stateChanged(Qt::Checked);
        delay_ms(50);
        Widget::on_led4CheckBox_stateChanged(Qt::Checked);
        delay_ms(50);
        Widget::on_led6CheckBox_stateChanged(Qt::Checked);
        delay_ms(50);
        Widget::on_led5CheckBox_stateChanged(Qt::Checked);
    }
    else if(state == Qt::Unchecked){
        Widget::on_led3CheckBox_stateChanged(Qt::Unchecked);
        Widget::on_led4CheckBox_stateChanged(Qt::Unchecked);
        Widget::on_led5CheckBox_stateChanged(Qt::Unchecked);
        Widget::on_led6CheckBox_stateChanged(Qt::Unchecked);
    }
}


/*************************************************
Function: hexStringtoByteArray()
Description: 十六进制字串转化为十六进制编码
Calls:
    formatString()
Called By:
Input:hex
Return:QByteArray
*************************************************/
QByteArray Widget::hexStringtoByteArray(QString hex)
{
    QByteArray ret;
    hex=hex.trimmed();
    formatString(hex,2,' ');
    QStringList sl=hex.split(" ");
    foreach(QString s,sl)
    {
        if(!s.isEmpty())
            ret.append((char)s.toInt(0,16)&0xFF);
    }
    return ret;
}
/*************************************************
Function:formatString()
Description: 将十六进制字串每字节中间加空格分隔
Calls:
Called By:hexStringtoByteArray()
Input: org->待处理的字串
       n->间隔数默认为2
       ch->分隔标志，在此取空格
Return: void
*************************************************/
void Widget::formatString(QString &org, int n=2, const QChar &ch=QChar(' '))
{
    int size= org.size();
    int space= qRound(size*1.0/n+0.5)-1;
    if(space<=0)
        return;
    for(int i=0,pos=n;i<space;++i,pos+=(n+1))
    {
        org.insert(pos,ch);
    }
}

/*************************************************
Function: delay_ms()
Description: 延时函数（单位：毫秒）
Calls:
Called By:
Input:
    msec->延时毫秒数
Return: void
*************************************************/
void Widget::delay_ms(unsigned int msec){
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents);
        QThread::msleep(msec);//加上后CPU占用为11%，去掉后为26%
}
