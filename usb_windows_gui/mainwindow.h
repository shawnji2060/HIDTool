#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdint.h>
#include "libusb.h"

//
// Hardware specific variables
//
static const GUID GUID_DEVINTERFACE_LAUNCHPAD =
{ 0xfd96fadb, 0x9246, 0x4017, { 0x8d, 0x76, 0x3e, 0x30, 0x77, 0x80, 0xf6, 0xeb } };
//{{fd96fadb-9246-4017-8d76-3e307780f6eb}}
//
// Those are used to find our specific device on a bus
// VID = TI Stellaris
static const uint16_t VENDOR_ID  = 0x1cbe;
static const uint16_t PRODUCT_ID = 0x0003;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void signal_DeviceConnected();
    void signal_DeviceDisconnected();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // handle for our USB device
    libusb_device_handle* LaunchpadDevice;
    
protected :
    virtual bool nativeEvent(const QByteArray& , void* ,
                                      long* );
private slots:
    void DeviceConnected();
    void DeviceDisconnected();
    void slider_Change();
    void timer_timeout();
    void on_button_ONOFF_clicked();

private:
    Ui::MainWindow *ui;

    // Timer for "asking" device
    QTimer *timer;

    // USB handling functions
    void USBSendONOFF(bool on);
    void USBSendRGB(uint16_t red, uint16_t green, uint16_t blue);
    bool USBAskDevice();
};

#endif // MAINWINDOW_H
