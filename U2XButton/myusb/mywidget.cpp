#include "mywidget.h"
#include "ui_mywidget.h"
#include "lusb0_usb.h"
#include <stdio.h>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QString>
#include "u2xbtneventmonitor.h"
#include "u2x_thread.h"


#define MY_VID  0x10C4
#define MY_PID  0x0000


myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,4000);
    ui->progressBar->setValue(0);
    ui->progressBar_2->setRange(0,4000);
    ui->progressBar_2->setValue(0);
    ui->progressBar_3->setRange(0,4000);
    ui->progressBar_3->setValue(0);
    ui->lineEdit->setText(QString::number(MY_VID));
    ui->lineEdit_2->setText(QString::number(MY_PID));

    myThread = new U2XThread;
    QObject::connect(myThread,SIGNAL(RecesiveData(char*)),this,SLOT(NumberUpdate(char*)));
    QObject::connect(myThread,SIGNAL(RecesiveData(char*)),this,SLOT(DateShowSlot(char*)));
    QObject::connect(this,SIGNAL(SendMessage(char*,int)),myThread,SLOT(SendMessageSlots(char*,int)));
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::DateShowSlot(char *date)
{
    int i;
    unsigned char a[8];

    ui->textEdit->setFocus();

    for(i=0;i<8;i++)
      {
         a[i] =  date[i];
      }
    ui->textEdit->insertPlainText(tr("模拟量一："));
    ui->textEdit->insertPlainText(QString::number(a[2]*256 + a[3]));
    ui->textEdit->insertPlainText(" mv   ");
    ui->textEdit->insertPlainText(tr("模拟量二： "));
    ui->textEdit->insertPlainText(QString::number(a[4]*256 + a[5]));
    ui->textEdit->insertPlainText(" mv   ");
    ui->textEdit->insertPlainText(tr("模拟量三： "));
    ui->textEdit->insertPlainText(QString::number(a[6]*256 + a[7]));
    ui->textEdit->insertPlainText(" mv \n");
    autoScroll();
}

void myWidget::on_pushButton_2_clicked()
{
    signed int num;
    QString data = ui->textEdit->toPlainText();
    QByteArray ArrayData = data.toLatin1();
    char *tmp = ArrayData.data();
    num = data.length();
    emit SendMessage(tmp,num);
}


void myWidget::autoScroll()
{
    QTextCursor myCursor = ui->textEdit->textCursor();
    myCursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(myCursor);
}


void myWidget::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
  // monitor.start();
}


void myWidget::NumberUpdate(char *date)
{
    unsigned int i;
    unsigned char a[8];

    for(i=0;i<8;i++)
    {
        a[i] = date[i];
    }   
    ui->progressBar->setValue(a[2]*256 + a[3]);
    ui->progressBar_2->setValue(a[4]*256 +a[5]);
    ui->progressBar_3->setValue(a[6]*256 +a[7]);

    if(a[0] == 1)
    {
        ui->label_12->setText(tr("开"));
    }
    else if(a[0] == 0)
        ui->label_12->setText((tr("关")));
    if(a[1] == 1)
    {
        ui->label_13->setText(tr("开"));
    }
    else if(a[1] == 0)
        ui->label_13->setText((tr("关")));

}

void myWidget::on_pushButton_3_toggled(bool checked)
{
     myThread->Init();
     myThread->start();
}
