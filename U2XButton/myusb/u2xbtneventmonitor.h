#ifndef U2X_BUTTON_EVENT_MONITOR_H
#define U2X_BUTTON_EVENT_MONITOR_H

#include <QObject>

#define ALARM_RESET_BUTTON  1

class U2XThread;

class U2XBtnEventMonitor : public QObject
{
    Q_OBJECT

public:
    U2XBtnEventMonitor(QObject *parent = 0);
    ~U2XBtnEventMonitor();

    bool start();
    bool stop();

signals:
    void buttonClicked(int);


private:
    U2XThread *mThread;
};

#endif // U2X_BUTTON_EVENT_MONITOR_H
