/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSlider *slider_B;
    QSlider *slider_G;
    QSlider *slider_R;
    QLabel *label;
    QPushButton *button_ONOFF;
    QLabel *label_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(315, 321);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/appicon/drive_black_usb.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        slider_B = new QSlider(centralWidget);
        slider_B->setObjectName(QStringLiteral("slider_B"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(slider_B->sizePolicy().hasHeightForWidth());
        slider_B->setSizePolicy(sizePolicy2);
        slider_B->setMaximumSize(QSize(50, 16777215));
        slider_B->setMaximum(65535);
        slider_B->setPageStep(2048);
        slider_B->setValue(0);
        slider_B->setSliderPosition(0);
        slider_B->setOrientation(Qt::Vertical);
        slider_B->setInvertedControls(false);
        slider_B->setTickPosition(QSlider::TicksBothSides);
        slider_B->setTickInterval(0);

        gridLayout->addWidget(slider_B, 1, 3, 1, 1);

        slider_G = new QSlider(centralWidget);
        slider_G->setObjectName(QStringLiteral("slider_G"));
        sizePolicy2.setHeightForWidth(slider_G->sizePolicy().hasHeightForWidth());
        slider_G->setSizePolicy(sizePolicy2);
        slider_G->setMaximumSize(QSize(50, 16777215));
        slider_G->setMaximum(65535);
        slider_G->setPageStep(2048);
        slider_G->setValue(0);
        slider_G->setSliderPosition(0);
        slider_G->setOrientation(Qt::Vertical);
        slider_G->setInvertedControls(false);
        slider_G->setTickPosition(QSlider::TicksBothSides);
        slider_G->setTickInterval(0);

        gridLayout->addWidget(slider_G, 1, 2, 1, 1);

        slider_R = new QSlider(centralWidget);
        slider_R->setObjectName(QStringLiteral("slider_R"));
        sizePolicy2.setHeightForWidth(slider_R->sizePolicy().hasHeightForWidth());
        slider_R->setSizePolicy(sizePolicy2);
        slider_R->setMaximumSize(QSize(50, 16777215));
        slider_R->setLayoutDirection(Qt::LeftToRight);
        slider_R->setMaximum(65535);
        slider_R->setPageStep(2048);
        slider_R->setValue(65535);
        slider_R->setSliderPosition(65535);
        slider_R->setOrientation(Qt::Vertical);
        slider_R->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(slider_R, 1, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        button_ONOFF = new QPushButton(centralWidget);
        button_ONOFF->setObjectName(QStringLiteral("button_ONOFF"));
        button_ONOFF->setMaximumSize(QSize(77, 23));
        button_ONOFF->setCheckable(true);
        button_ONOFF->setChecked(false);
        button_ONOFF->setFlat(false);

        gridLayout->addWidget(button_ONOFF, 1, 4, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Launchpad USB RGB LED control", 0));
        label_2->setText(QApplication::translate("MainWindow", "Green", 0));
        label->setText(QApplication::translate("MainWindow", "Red", 0));
        button_ONOFF->setText(QApplication::translate("MainWindow", "LEDs ON", 0));
        label_3->setText(QApplication::translate("MainWindow", "Blue", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
