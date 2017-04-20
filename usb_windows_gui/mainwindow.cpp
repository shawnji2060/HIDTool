#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "libusb.h"

#include <QtCore>
#include <QtGui>
#include <QtDebug>
#include <dbt.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "Start";

    ui->setupUi(this);
    this->setWindowFlags( Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    connect(this, &MainWindow::signal_DeviceConnected,      this,  &MainWindow::DeviceConnected );
    connect(this, &MainWindow::signal_DeviceDisconnected,   this,  &MainWindow::DeviceDisconnected );

    connect(this->ui->slider_R, &QSlider::valueChanged,  this,  &MainWindow::slider_Change );
    connect(this->ui->slider_G, &QSlider::valueChanged,  this,  &MainWindow::slider_Change );
    connect(this->ui->slider_B, &QSlider::valueChanged,  this,  &MainWindow::slider_Change );

    // Create timer
    this->timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timer_timeout);

    //
    // Windows specific code - register for windows messages: device add/remove notification

    // Register for device connect notification
    DEV_BROADCAST_DEVICEINTERFACE devInt;
    ZeroMemory( &devInt, sizeof(devInt) );
    devInt.dbcc_size        = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
    devInt.dbcc_devicetype  = DBT_DEVTYP_DEVICEINTERFACE;
    devInt.dbcc_classguid   = GUID_DEVINTERFACE_LAUNCHPAD;
    //
    HDEVNOTIFY m_hDeviceNotify =
            RegisterDeviceNotification((HANDLE)winId(),&devInt, DEVICE_NOTIFY_WINDOW_HANDLE );
    //
    if(m_hDeviceNotify == NULL)
    {
        qDebug() << "Error: Failed to register device notification!";
        qApp->quit();
    }

    // No device at the begining
    LaunchpadDevice = NULL;

    // Initialize libusbX
    if (libusb_init(NULL) < 0)
    {
        qDebug() << "Failed to initialize libusbX";
        qApp->quit();
    }

    //If we are debugging print all information
    //libusb_set_debug(NULL, LIBUSB_LOG_LEVEL_DEBUG);

    // Initialize interface components
    DeviceDisconnected();

    // Check if device is already connected to system
    DeviceConnected();
}

// Clean on quit
MainWindow::~MainWindow()
{
    DeviceDisconnected();
    libusb_exit(NULL);
    delete ui;
}

// Function that receive messages
// This is windows-specific
bool MainWindow::nativeEvent(const QByteArray& eventType, void* message,
                             long* result)
{
    Q_UNUSED( result );
    Q_UNUSED( eventType );

    MSG* msg = reinterpret_cast<MSG*>(message);

    // Does this specific message interest us?
    if(msg->message == WM_DEVICECHANGE)
    {
        switch(msg->wParam)
        {
        case DBT_DEVICEARRIVAL:
            emit signal_DeviceConnected();
            break;

        case DBT_DEVICEREMOVECOMPLETE:
            emit signal_DeviceDisconnected();
            break;
        }
    }

    // Qt handles the rest
    return false;
}

// Our device appeared in the system
void MainWindow::DeviceConnected()
{
    // List storing all detected devices
    libusb_device **devs;

    // Get all devices connected to system
    if (libusb_get_device_list(NULL, &devs) < 0)
    {
        qDebug() << "Failed to get devices list";
        return;
    }

    // Scan for LaunchpadDevice VID & PID
    libusb_device *dev;
    // retdev stores the first device detected
    libusb_device *retdev = NULL;
    int i = 0;
    int count = 0;
    while ( (dev = devs[i++]) != NULL )
    {
        struct libusb_device_descriptor desc;

        if (libusb_get_device_descriptor(dev, &desc) < 0)
        {
            qDebug() << "failed to get device descriptor";
            continue;
        }

        // Is this device the one we are looking for?
        if ( (desc.idVendor == VENDOR_ID) && (desc.idProduct == PRODUCT_ID) )
        {
            count++;
            if ( retdev == NULL )
                retdev = dev;
        }
    }

    if (count <= 0)
    {
        qDebug() << "Warning! No device found";
        return;
    }

    if (count > 1 )
    {
        qDebug() << "Warning! More than one device found. Using first on the list";
    }

    if (libusb_open(retdev, &this->LaunchpadDevice) < 0)
    {
        qDebug() << "Error! Failed to open device";
        return;
    }

    libusb_free_device_list(devs, 1);

    // now connect to interface //

    if (libusb_claim_interface(this->LaunchpadDevice, 0) != LIBUSB_SUCCESS)
    {
        qDebug() << "Error! Failed to claim interface";
        return;
    }

    qDebug() << "DeviceConnected";

    // If all ok enable control
    this->ui->slider_R->setEnabled(true);
    this->ui->slider_G->setEnabled(true);
    this->ui->slider_B->setEnabled(true);
    this->ui->button_ONOFF->setEnabled(true);

    // Send some data for embedded device initial conditions
    slider_Change();
    USBSendONOFF(false);

    // Start the timer to pool updates from device
    this->timer->start(500);

    ui->statusBar->showMessage("Device connected.");
}

// Device was disconnected
void MainWindow::DeviceDisconnected()
{
    qDebug() << "DeviceDisconnected";

    // Disable timer

    this->timer->stop();

    // Disable controls and reset them to initial state

    this->ui->slider_R->setValue(200);
    this->ui->slider_G->setValue(200);
    this->ui->slider_B->setValue(200);
    this->ui->button_ONOFF->setChecked(false);

    this->ui->slider_R->setEnabled(false);
    this->ui->slider_G->setEnabled(false);
    this->ui->slider_B->setEnabled(false);
    this->ui->button_ONOFF->setEnabled(false);

    if(this->LaunchpadDevice != NULL)
    {
        libusb_release_interface(this->LaunchpadDevice, 0);
        libusb_close(this->LaunchpadDevice);
        this->LaunchpadDevice=NULL;
    }

    ui->statusBar->showMessage("Awaiting device connection.");
}

// Update device when we change sliders values
void MainWindow::slider_Change()
{
    USBSendRGB(this->ui->slider_R->value(),this->ui->slider_G->value(),this->ui->slider_B->value());
}

// Toogle LED on button click
void MainWindow::on_button_ONOFF_clicked()
{
    // Enable/Disable LED according to button state
    // Stop timer so updates from device will not
    // mess with user action

    //this->timer->stop();
    USBSendONOFF(ui->button_ONOFF->isChecked());
    //this->timer->start(500);
}

// Periodically check if LED is still on on the device
void MainWindow::timer_timeout()
{
    this->ui->button_ONOFF->setChecked(USBAskDevice());
}

// USB /////

void MainWindow::USBSendONOFF(bool on)
{
    uint8_t packet[1];
    int transferred = 0;

    if(this->LaunchpadDevice == NULL)
    {
        qDebug() << "Warning: Device is not availabe!";
        return;
    }

    // Should we enable or disable LEDs?
    if (on)
        packet[0] = 0x0E;
    else
        packet[0] = 0x0D;

    // Endpoint address can be seen in USBView.exe . 0x01 is 1st OUT endpoint in this case
    // We are sending packet with 100 [ms] timeout. Transmitted bytes count should be same as
    // packet size and function should return no errors
    if ( (libusb_bulk_transfer(this->LaunchpadDevice, 0x01, packet, sizeof(packet) , &transferred, 100) != 0 )
         || (transferred != sizeof(packet)) )
    {
            qDebug() << "Error: Failed to send data";
            DeviceDisconnected();
            return;
    }
}

void MainWindow::USBSendRGB(uint16_t red, uint16_t green, uint16_t blue)
{
    uint8_t packet[7];
    int transferred = 0;

    if(this->LaunchpadDevice == NULL)
    {
        qDebug() << "Warning: Device is not availabe!";
        return;
    }

    // Construct packet
    packet[0] = 0x0C;
    packet[1] = (uint8_t)(red)      &0xFF;
    packet[2] = (uint8_t)(red>>8)   &0xFF;
    packet[3] = (uint8_t)(green)    &0xFF;
    packet[4] = (uint8_t)(green>>8) &0xFF;
    packet[5] = (uint8_t)(blue)     &0xFF;
    packet[6] = (uint8_t)(blue>>8)  &0xFF;

    // Endpoint address can be seen in USBView.exe . 0x01 is 1st OUT endpoint in this case
    // We are sending packet with 100 [ms] timeout. Transmitted bytes count should be same as
    // packet size and function should return no errors
    if ( (libusb_bulk_transfer(this->LaunchpadDevice, 0x01, packet, sizeof(packet) , &transferred, 100) != 0 )
         || (transferred != sizeof(packet)) )
    {
        qDebug() << "Error: Failed to send data";
        DeviceDisconnected();
        return;
    }
}

// We need to periodically ask device for it's state as it cannot prompt when user pressed on/off button
// This function returns LEDs state
bool  MainWindow::USBAskDevice()
{
    uint8_t packet[1];
    int transferred = 0;

    if(this->LaunchpadDevice == NULL)
    {
        qDebug() << "Warning: Device is not availabe!";
        return false;
    }

    // create packet
    packet[0] = 0x0A;

    // Endpoint address can be seen in USBView.exe . 0x01 is 1st OUT endpoint in this case
    // We are sending packet with 100 [ms] timeout. Transmitted bytes count should be same as
    // packet size and function should return no errors
    if ( (libusb_bulk_transfer(this->LaunchpadDevice, 0x01, packet, sizeof(packet) , &transferred, 100) != 0 )
         || (transferred != sizeof(packet)) )
    {
            qDebug() << "Error: Failed to send data";
            DeviceDisconnected();
            return false;
    }

    // Receive response ///

    // Endpoint address can be seen in USBView.exe . 0x81 is 1st IN endpoint in this case
    // We are receiving packet with 100 [ms] timeout. Transmitted bytes count should be same as
    // packet size and function should return no errors
    if ( (libusb_bulk_transfer(this->LaunchpadDevice, 0x81, packet, sizeof(packet) , &transferred, 100) != 0 )
         || (transferred != sizeof(packet)) )
    {
        qDebug() << "Error: Failed to receive data";
        DeviceDisconnected();
        return false;
    }

    return ( packet[0] == 0 );
}
