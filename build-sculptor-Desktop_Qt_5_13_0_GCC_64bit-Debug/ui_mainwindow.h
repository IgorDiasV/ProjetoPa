/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <plotter.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *botaoNew;
    QPushButton *botaoCores;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox;
    QSpinBox *spinEsfera;
    QSlider *sliderEsfera;
    QGroupBox *groupBox_3;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
    QLCDNumber *lcdNumber_5;
    QLCDNumber *lcdPlanoZ;
    QSlider *horizontalSlider_7;
    QSlider *horizontalSlider_8;
    QSlider *sliderPlanoZ;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_10;
    Plotter *widget;
    QLCDNumber *lcdX;
    QLCDNumber *lcdY;
    QLabel *label_11;
    QLabel *label_12;
    QLCDNumber *l;
    QGroupBox *groupBox_2;
    QPushButton *Button_putvoxel;
    QPushButton *Button_cutvoxel;
    QPushButton *Button_putbox;
    QPushButton *Button_putsphere;
    QPushButton *Button_putellipsoid;
    QGroupBox *groupBox_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(914, 713);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        botaoNew = new QPushButton(centralWidget);
        botaoNew->setObjectName(QString::fromUtf8("botaoNew"));
        botaoNew->setGeometry(QRect(10, 10, 41, 25));
        botaoCores = new QPushButton(centralWidget);
        botaoCores->setObjectName(QString::fromUtf8("botaoCores"));
        botaoCores->setGeometry(QRect(560, 470, 111, 71));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(630, 110, 47, 13));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(669, 190, 191, 20));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(669, 220, 191, 20));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(centralWidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(669, 250, 191, 20));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(630, 190, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(630, 260, 47, 13));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(630, 230, 47, 13));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(560, 70, 341, 91));
        spinEsfera = new QSpinBox(groupBox);
        spinEsfera->setObjectName(QString::fromUtf8("spinEsfera"));
        spinEsfera->setGeometry(QRect(270, 40, 42, 22));
        spinEsfera->setMinimum(1);
        spinEsfera->setMaximum(100);
        sliderEsfera = new QSlider(groupBox);
        sliderEsfera->setObjectName(QString::fromUtf8("sliderEsfera"));
        sliderEsfera->setGeometry(QRect(100, 40, 160, 19));
        sliderEsfera->setMinimum(1);
        sliderEsfera->setOrientation(Qt::Horizontal);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(560, 300, 341, 161));
        horizontalSlider_4 = new QSlider(groupBox_3);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(79, 40, 171, 20));
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_5 = new QSlider(groupBox_3);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setGeometry(QRect(79, 80, 171, 20));
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        horizontalSlider_6 = new QSlider(groupBox_3);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setGeometry(QRect(80, 120, 171, 19));
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 40, 47, 13));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 90, 47, 13));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 130, 47, 13));
        lcdNumber = new QLCDNumber(groupBox_3);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(260, 30, 64, 23));
        lcdNumber_2 = new QLCDNumber(groupBox_3);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(260, 80, 64, 23));
        lcdNumber_3 = new QLCDNumber(groupBox_3);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(260, 120, 64, 23));
        lcdNumber_4 = new QLCDNumber(centralWidget);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(460, 490, 64, 23));
        lcdNumber_5 = new QLCDNumber(centralWidget);
        lcdNumber_5->setObjectName(QString::fromUtf8("lcdNumber_5"));
        lcdNumber_5->setGeometry(QRect(460, 530, 64, 23));
        lcdPlanoZ = new QLCDNumber(centralWidget);
        lcdPlanoZ->setObjectName(QString::fromUtf8("lcdPlanoZ"));
        lcdPlanoZ->setGeometry(QRect(460, 570, 64, 23));
        lcdPlanoZ->setFrameShape(QFrame::Box);
        lcdPlanoZ->setFrameShadow(QFrame::Plain);
        lcdPlanoZ->setSegmentStyle(QLCDNumber::Flat);
        horizontalSlider_7 = new QSlider(centralWidget);
        horizontalSlider_7->setObjectName(QString::fromUtf8("horizontalSlider_7"));
        horizontalSlider_7->setGeometry(QRect(160, 500, 281, 19));
        horizontalSlider_7->setOrientation(Qt::Horizontal);
        horizontalSlider_8 = new QSlider(centralWidget);
        horizontalSlider_8->setObjectName(QString::fromUtf8("horizontalSlider_8"));
        horizontalSlider_8->setGeometry(QRect(160, 530, 281, 19));
        horizontalSlider_8->setOrientation(Qt::Horizontal);
        sliderPlanoZ = new QSlider(centralWidget);
        sliderPlanoZ->setObjectName(QString::fromUtf8("sliderPlanoZ"));
        sliderPlanoZ->setGeometry(QRect(160, 570, 281, 19));
        sliderPlanoZ->setMaximum(9);
        sliderPlanoZ->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 500, 47, 13));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(120, 530, 47, 13));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 570, 47, 13));
        widget = new Plotter(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 70, 481, 391));
        lcdX = new QLCDNumber(centralWidget);
        lcdX->setObjectName(QString::fromUtf8("lcdX"));
        lcdX->setGeometry(QRect(10, 120, 51, 23));
        lcdX->setFrameShape(QFrame::NoFrame);
        lcdX->setFrameShadow(QFrame::Raised);
        lcdX->setSegmentStyle(QLCDNumber::Flat);
        lcdY = new QLCDNumber(centralWidget);
        lcdY->setObjectName(QString::fromUtf8("lcdY"));
        lcdY->setGeometry(QRect(10, 170, 51, 23));
        lcdY->setSegmentStyle(QLCDNumber::Flat);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 100, 67, 17));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 150, 67, 17));
        l = new QLCDNumber(centralWidget);
        l->setObjectName(QString::fromUtf8("l"));
        l->setGeometry(QRect(0, 40, 64, 23));
        l->setSegmentStyle(QLCDNumber::Flat);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(560, 170, 341, 121));
        Button_putvoxel = new QPushButton(centralWidget);
        Button_putvoxel->setObjectName(QString::fromUtf8("Button_putvoxel"));
        Button_putvoxel->setGeometry(QRect(70, 10, 61, 51));
        Button_cutvoxel = new QPushButton(centralWidget);
        Button_cutvoxel->setObjectName(QString::fromUtf8("Button_cutvoxel"));
        Button_cutvoxel->setGeometry(QRect(140, 10, 61, 51));
        Button_putbox = new QPushButton(centralWidget);
        Button_putbox->setObjectName(QString::fromUtf8("Button_putbox"));
        Button_putbox->setGeometry(QRect(210, 10, 61, 51));
        Button_putsphere = new QPushButton(centralWidget);
        Button_putsphere->setObjectName(QString::fromUtf8("Button_putsphere"));
        Button_putsphere->setGeometry(QRect(280, 10, 61, 51));
        Button_putellipsoid = new QPushButton(centralWidget);
        Button_putellipsoid->setObjectName(QString::fromUtf8("Button_putellipsoid"));
        Button_putellipsoid->setGeometry(QRect(350, 10, 61, 51));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(70, 460, 481, 181));
        MainWindow->setCentralWidget(centralWidget);
        groupBox_4->raise();
        groupBox->raise();
        botaoNew->raise();
        botaoCores->raise();
        label_2->raise();
        horizontalSlider->raise();
        horizontalSlider_2->raise();
        horizontalSlider_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        groupBox_3->raise();
        lcdNumber_4->raise();
        lcdNumber_5->raise();
        lcdPlanoZ->raise();
        horizontalSlider_7->raise();
        horizontalSlider_8->raise();
        sliderPlanoZ->raise();
        label_3->raise();
        label_9->raise();
        label_10->raise();
        widget->raise();
        lcdX->raise();
        lcdY->raise();
        label_11->raise();
        label_12->raise();
        l->raise();
        groupBox_2->raise();
        Button_putvoxel->raise();
        Button_cutvoxel->raise();
        Button_putbox->raise();
        Button_putsphere->raise();
        Button_putellipsoid->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 914, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        botaoNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        botaoCores->setText(QCoreApplication::translate("MainWindow", "cores", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "raio", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rx", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Rz", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ry", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Esfera", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Caixa", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "DimX", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "DimY", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "DimZ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        Button_putvoxel->setText(QCoreApplication::translate("MainWindow", "putvoxel", nullptr));
        Button_cutvoxel->setText(QCoreApplication::translate("MainWindow", "cutvoxel", nullptr));
        Button_putbox->setText(QCoreApplication::translate("MainWindow", "putbox", nullptr));
        Button_putsphere->setText(QCoreApplication::translate("MainWindow", "putsphere", nullptr));
        Button_putellipsoid->setText(QCoreApplication::translate("MainWindow", "putellipsoid", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "PLANO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
