/********************************************************************************
** Form generated from reading UI file 'mattysettings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATTYSETTINGS_H
#define UI_MATTYSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MattySettings
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;

    void setupUi(QWidget *MattySettings)
    {
        if (MattySettings->objectName().isEmpty())
            MattySettings->setObjectName(QStringLiteral("MattySettings"));
        MattySettings->resize(627, 439);
        gridLayout = new QGridLayout(MattySettings);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(MattySettings);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        retranslateUi(MattySettings);

        QMetaObject::connectSlotsByName(MattySettings);
    } // setupUi

    void retranslateUi(QWidget *MattySettings)
    {
        MattySettings->setWindowTitle(QApplication::translate("MattySettings", "Form", 0));
        pushButton->setText(QApplication::translate("MattySettings", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MattySettings: public Ui_MattySettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATTYSETTINGS_H
