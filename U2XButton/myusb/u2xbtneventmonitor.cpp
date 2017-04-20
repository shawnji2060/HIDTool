#include "u2xbtneventmonitor.h"
#include "u2x_thread.h"


U2XBtnEventMonitor::U2XBtnEventMonitor(QObject *parent) : QObject(parent)
{
   mThread = NULL;
}

U2XBtnEventMonitor::~U2XBtnEventMonitor()
{
   stop();
}

bool U2XBtnEventMonitor::start()
{

    if(mThread!=NULL) return false;

    mThread = new U2XThread();


    connect(mThread,SIGNAL(buttonClicked(int)),this, SIGNAL(buttonClicked(int)));

  //  mThread->Init();

    mThread->start();

    return true;
}

bool U2XBtnEventMonitor::stop()
{

    if(mThread!=NULL)
    {

     disconnect(mThread,SIGNAL(buttonClicked(int)),this, SIGNAL(buttonClicked(int)));

      mThread->Stop();

      if(mThread->initiated())
      {
         mThread->Stop();
         mThread->wait();


         delete mThread;

         mThread=NULL;
         return true;
      }
      else
      {
          delete mThread;
          mThread=NULL;
          return false;
      }
    }
    else
    {
       return false;
    }

}
