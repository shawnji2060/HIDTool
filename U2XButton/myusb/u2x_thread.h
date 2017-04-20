#ifndef U2X_THREAD_H
#define U2X_THREAD_H

#include <QThread>
#include <QQueue>
#include <QMutex>
#include "lusb0_usb.h"

#include <windows.h>



class myWidget;
class U2XThread : public QThread
{
    Q_OBJECT
public:
    U2XThread();
    virtual ~U2XThread();
    void Init();
    void Stop();
    bool initiated() { return bInitiated; }
    usb_dev_handle *open_dev();
signals:
    void buttonClicked(int);
    void RecesiveData(char *date);
protected:
    void run();
    void Close();

private slots:
    void SendMessageSlots(char *tmp, int num);

private:
    bool bInitiated;
    /// Variable used to stop the loop in the run() function.
    volatile bool stopped;
    usb_dev_handle *dev;
};

#endif // READER_H
