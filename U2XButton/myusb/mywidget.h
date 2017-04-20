#ifndef MYWIDGET_H
#define MYWIDGET_H

#include "u2xbtneventmonitor.h"
#include <QWidget>
#include "lusb0_usb.h"
#include "u2x_thread.h"
namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();
     usb_dev_handle *open_dev(void);

private slots:

    void on_pushButton_2_clicked();
    void autoScroll();
    void on_pushButton_4_clicked();
    void NumberUpdate(char *date);
    void DateShowSlot(char *date);
    void on_pushButton_3_toggled(bool checked);

signals:
void SendMessage(char *tmp,int num);

private:
    Ui::myWidget *ui;
    usb_dev_handle *dev;
    struct usb_device_descriptor desc;
    U2XBtnEventMonitor  monitor;
    U2XThread *myThread;
};

#endif // MYWIDGET_H
