#include "u2x_thread.h"
#include <QtCore>
#include "u2xbtneventmonitor.h"
#include "lusb0_usb.h"
#include "mywidget.h"

#define EP_IN 0x81
#define EP_OUT 0x02

#define BUF_SIZE 8

#define MY_VID  0x10C4
#define MY_PID  0x0000
#define MY_CONFIG 1
#define MY_INTF 0

U2XThread::U2XThread()
{
    stopped    = false;
    bInitiated = false;
}

/** \brief Destructor
 *
 */
U2XThread::~U2XThread()
{
    Close();
    wait();
}

void U2XThread::Init()
{
    void* async_read_context = NULL;
    void* async_write_context = NULL;

    usb_init(); /* initialize the library */
    usb_find_busses(); /* find all busses */
    usb_find_devices(); /* find all connected devices */

    if (!(dev = open_dev()))
      {

        printf("error opening device: \n%s\n", usb_strerror());
      }
   else
     {
        printf("success: device %04X:%04X opened\n", MY_VID, MY_PID);
     }

   if (usb_set_configuration(dev, MY_CONFIG) < 0)
     {
        printf("error setting config #%d: %s\n", MY_CONFIG, usb_strerror());
        usb_close(dev);
     }
   else
     {
        printf("success: set configuration #%d\n", MY_CONFIG);
     }
   if (usb_claim_interface(dev, 0) < 0)
    {
        printf("error claiming interface #%d:\n%s\n", MY_INTF, usb_strerror());
        usb_close(dev);
    }
   else
    {
       printf("success: claim_interface #%d\n", MY_INTF);
    }
}

void U2XThread::run()
{
    int ret;
    char tmp[BUF_SIZE];
    while (!stopped)
    {
        int sleepTime = 1000;

        ret = usb_interrupt_read(dev, EP_IN, tmp, sizeof(tmp), 5000);
        if (ret < 0)
          {
             printf("error reading:\n%s\n", usb_strerror());
          }
        else
          {
             printf("success: interrupt read %d bytes\n", ret);
             emit RecesiveData(tmp);
          }

        msleep(sleepTime);
    }

    // Reset the stopped variable
    stopped = false;
    // Close the COM port
    Close();
}

void U2XThread::Stop()
{
    stopped = true;
}

void U2XThread::Close()
{
    usb_release_interface(dev, 0);
    usb_close(dev);
}

//usb_dev_handle *U2XThread::open_dev(void)
usb_dev_handle *U2XThread::open_dev()
{
    struct usb_bus *bus;
    struct usb_device *dev;

    for (bus = usb_get_busses(); bus; bus = bus->next)
    {
        for (dev = bus->devices; dev; dev = dev->next)
        {
            if (dev->descriptor.idVendor == MY_VID
                    && dev->descriptor.idProduct == MY_PID)
            {
                return usb_open(dev);
            }
        }
    }
    return NULL;
}
void U2XThread::SendMessageSlots(char *tmp,int num)
{
        int ret,i;

        ret = usb_interrupt_write(dev, EP_OUT, tmp, num, 5000);
        if (ret < 0)
        {
            printf("error writing:\n%s\n", usb_strerror());
        }
        else
        {
            printf("success: interrupt write %d bytes \n", ret);
            for(i=0;i<num;i++)
            {
            printf("write number is:%d\n", tmp[i]-48);
            }
        }

}
