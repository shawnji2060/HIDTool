/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created: Tue May 12 23:16:32 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_myWidget
{
public:
    QLabel *label_2;
    QPushButton *pushButton_2;
    QProgressBar *progressBar;
    QLabel *label_10;
    QLabel *label_5;
    QLabel *label;
    QProgressBar *progressBar_2;
    QLabel *label_4;
    QLabel *label_3;
    QProgressBar *progressBar_3;
    QLabel *label_11;
    QTextEdit *textEdit;
    QLabel *label_13;
    QLabel *label_12;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *myWidget)
    {
        if (myWidget->objectName().isEmpty())
            myWidget->setObjectName(QString::fromUtf8("myWidget"));
        myWidget->resize(468, 356);
        label_2 = new QLabel(myWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 10, 21, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        pushButton_2 = new QPushButton(myWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(400, 40, 61, 61));
        pushButton_2->setFont(font);
        progressBar = new QProgressBar(myWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 220, 41, 101));
        progressBar->setValue(0);
        progressBar->setOrientation(Qt::Vertical);
        label_10 = new QLabel(myWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(270, 300, 61, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_10->setFont(font1);
        label_10->setTextFormat(Qt::AutoText);
        label_10->setScaledContents(false);
        label_5 = new QLabel(myWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 330, 51, 16));
        label_5->setFont(font);
        label = new QLabel(myWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 21, 20));
        label->setFont(font);
        progressBar_2 = new QProgressBar(myWidget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(110, 220, 41, 101));
        progressBar_2->setValue(0);
        progressBar_2->setOrientation(Qt::Vertical);
        label_4 = new QLabel(myWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 330, 51, 16));
        label_4->setFont(font);
        label_3 = new QLabel(myWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 330, 51, 16));
        label_3->setFont(font);
        progressBar_3 = new QProgressBar(myWidget);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(200, 220, 41, 101));
        progressBar_3->setValue(0);
        progressBar_3->setOrientation(Qt::Vertical);
        label_11 = new QLabel(myWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(270, 240, 61, 31));
        label_11->setFont(font1);
        label_11->setTextFormat(Qt::AutoText);
        label_11->setScaledContents(false);
        textEdit = new QTextEdit(myWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 40, 371, 171));
        label_13 = new QLabel(myWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(340, 240, 61, 31));
        label_13->setFont(font1);
        label_12 = new QLabel(myWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(340, 300, 61, 31));
        label_12->setFont(font1);
        lineEdit = new QLineEdit(myWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 10, 81, 20));
        lineEdit_2 = new QLineEdit(myWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(310, 10, 81, 20));
        pushButton_3 = new QPushButton(myWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(400, 280, 61, 61));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        pushButton_3->setFont(font2);
        pushButton_3->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_3->setMouseTracking(false);
        pushButton_3->setAcceptDrops(false);
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setCheckable(true);
        pushButton_3->setAutoRepeat(true);
        pushButton_3->setAutoDefault(false);
        pushButton_3->setDefault(false);
        pushButton_3->setFlat(false);
        pushButton_4 = new QPushButton(myWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(400, 150, 61, 61));
        pushButton_4->setFont(font);

        retranslateUi(myWidget);

        QMetaObject::connectSlotsByName(myWidget);
    } // setupUi

    void retranslateUi(QWidget *myWidget)
    {
        // translate("myWidget", "myWidget", 0, QApplication::UnicodeUTF8) 改成
        //translate("myWidget", "myWidget", Q_NULLPTR, -1)
        myWidget->setWindowTitle(QApplication::translate("myWidget", "myWidget", Q_NULLPTR, -1));
        label_2->setText(QApplication::translate("myWidget", "PID:",  Q_NULLPTR, -1));
        pushButton_2->setText(QApplication::translate("myWidget", "Send",  Q_NULLPTR, -1));
        label_10->setText(QApplication::translate("myWidget", "\345\274\200\345\205\263\344\272\214\357\274\232", Q_NULLPTR, -1));
        label_5->setText(QApplication::translate("myWidget", "\346\250\241\346\213\237\351\207\217\344\270\211",  Q_NULLPTR, -1));
        label->setText(QApplication::translate("myWidget", "VID:",  Q_NULLPTR, -1));
        label_4->setText(QApplication::translate("myWidget", "\346\250\241\346\213\237\351\207\217\344\272\214", Q_NULLPTR, -1));
        label_3->setText(QApplication::translate("myWidget", "\346\250\241\346\213\237\351\207\217\344\270\200", Q_NULLPTR, -1));
        label_11->setText(QApplication::translate("myWidget", "\345\274\200\345\205\263\344\270\200\357\274\232",  Q_NULLPTR, -1));
        label_13->setText(QString());
        label_12->setText(QString());
        pushButton_3->setText(QApplication::translate("myWidget", "connect", Q_NULLPTR, -1));
        pushButton_4->setText(QApplication::translate("myWidget", "Clear",  Q_NULLPTR, -1));
    } // retranslateUi

};

namespace Ui {
    class myWidget: public Ui_myWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
