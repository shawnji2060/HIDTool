#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include "hidapi.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QDebug>
#include <QLibrary>
#include <QMessageBox>
#include <QTextEdit>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QIntValidator>
#include <QThread>
#include <fileapi.h>

#define MAX_STR    255
#define HID_IN_EP  0x81
#define HID_OUT_EP 0x01
#define VID 0x0483
#define PID 0x5750

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    int res;
    hid_device_ *handle;
    hid_device_ *input_report_length;
    wchar_t wstr[MAX_STR];

    int LENGTH_BUF_IN  = 64;
    int LENGTH_BUF_OUT = 64;

    unsigned char buf_IN[64];
    unsigned char buf_OUT[64];

    QTimer *timer1;//定义定时器1
    QTimer *timer2;//定义定时器2

    void api_loadcheck();
    void myhid_open(); 
    void myhid_close();
    void myhid_exit();
    void myhid_read();
    void myhid_read_tmp();
    void myhid_write(QString send_str);

    void delay_ms(unsigned int msec);//延时函数 单位：ms

    QByteArray hexStringtoByteArray(QString hex);
    void formatString(QString &org, int n, const QChar &ch);

private slots:
    void on_openButton_clicked();
    void on_sendButton_clicked();
    void on_readButton_clicked();
    void on_closeButton_clicked();
    void on_ejectButton_clicked();

    void on_led3CheckBox_stateChanged(int state);
    void on_led4CheckBox_stateChanged(int state);
    void on_led5CheckBox_stateChanged(int state);
    void on_led6CheckBox_stateChanged(int state);
    void on_ledAllCheckBox_stateChanged(int state);
};

#endif // WIDGET_H
