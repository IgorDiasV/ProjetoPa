/********************************************************************************
** Form generated from reading UI file 'definirsculptor.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFINIRSCULPTOR_H
#define UI_DEFINIRSCULPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DefinirSculptor
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpinBox *spinX;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *spinY;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QSpinBox *spinZ;

    void setupUi(QDialog *DefinirSculptor)
    {
        if (DefinirSculptor->objectName().isEmpty())
            DefinirSculptor->setObjectName(QString::fromUtf8("DefinirSculptor"));
        DefinirSculptor->resize(400, 300);
        buttonBox = new QDialogButtonBox(DefinirSculptor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(DefinirSculptor);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 70, 131, 121));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        spinX = new QSpinBox(layoutWidget);
        spinX->setObjectName(QString::fromUtf8("spinX"));

        horizontalLayout_5->addWidget(spinX);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinY = new QSpinBox(layoutWidget);
        spinY->setObjectName(QString::fromUtf8("spinY"));

        horizontalLayout_6->addWidget(spinY);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        spinZ = new QSpinBox(layoutWidget);
        spinZ->setObjectName(QString::fromUtf8("spinZ"));

        horizontalLayout_7->addWidget(spinZ);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(verticalLayout_5);


        retranslateUi(DefinirSculptor);
        QObject::connect(buttonBox, SIGNAL(accepted()), DefinirSculptor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DefinirSculptor, SLOT(reject()));

        QMetaObject::connectSlotsByName(DefinirSculptor);
    } // setupUi

    void retranslateUi(QDialog *DefinirSculptor)
    {
        DefinirSculptor->setWindowTitle(QCoreApplication::translate("DefinirSculptor", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("DefinirSculptor", "Tamanho da matriz", nullptr));
        label_6->setText(QCoreApplication::translate("DefinirSculptor", "X", nullptr));
        label_7->setText(QCoreApplication::translate("DefinirSculptor", "Y", nullptr));
        label_8->setText(QCoreApplication::translate("DefinirSculptor", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DefinirSculptor: public Ui_DefinirSculptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFINIRSCULPTOR_H
