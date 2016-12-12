/********************************************************************************
** Form generated from reading UI file 'mattynotesmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATTYNOTESMAINWINDOW_H
#define UI_MATTYNOTESMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MattyNotesMainWindowClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *MattyNotesMainWindowClass)
    {
        if (MattyNotesMainWindowClass->objectName().isEmpty())
            MattyNotesMainWindowClass->setObjectName(QStringLiteral("MattyNotesMainWindowClass"));
        MattyNotesMainWindowClass->resize(768, 553);
        centralWidget = new QWidget(MattyNotesMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MattyNotesMainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MattyNotesMainWindowClass);

        QMetaObject::connectSlotsByName(MattyNotesMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MattyNotesMainWindowClass)
    {
        MattyNotesMainWindowClass->setWindowTitle(QApplication::translate("MattyNotesMainWindowClass", "MattyNotes", 0));
    } // retranslateUi

};

namespace Ui {
    class MattyNotesMainWindowClass: public Ui_MattyNotesMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATTYNOTESMAINWINDOW_H
