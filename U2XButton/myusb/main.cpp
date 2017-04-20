#include <QApplication>
#include "mywidget.h"
#include <QTextCodec>
#include "u2xbtneventmonitor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::codecForLocale();

    myWidget w;
    w.show();
    
    return a.exec();
}
