/********************************************************************************
** Form generated from reading UI file 'addnotedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNOTEDIALOG_H
#define UI_ADDNOTEDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addNoteDialog
{
public:
    QGridLayout *gridLayout;
    QTextEdit *noteTitleText;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *noteTypeComboBox;
    QTimeEdit *eventTimeEdit;
    QDateEdit *eventDateEdit;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *noteTextText;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *cancelAddingNoteButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *createNoteButton;

    void setupUi(QWidget *addNoteDialog)
    {
        if (addNoteDialog->objectName().isEmpty())
            addNoteDialog->setObjectName(QStringLiteral("addNoteDialog"));
        addNoteDialog->resize(395, 338);
        addNoteDialog->setStyleSheet(QStringLiteral("#addNoteDialog  { background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69)); }"));
        gridLayout = new QGridLayout(addNoteDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        noteTitleText = new QTextEdit(addNoteDialog);
        noteTitleText->setObjectName(QStringLiteral("noteTitleText"));
        noteTitleText->setMaximumSize(QSize(16777215, 31));
        noteTitleText->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 222);\n"
"border: 1px solid transparent;\n"
"border-radius: 10px"));

        gridLayout->addWidget(noteTitleText, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        noteTypeComboBox = new QComboBox(addNoteDialog);
        noteTypeComboBox->setObjectName(QStringLiteral("noteTypeComboBox"));
        noteTypeComboBox->setMinimumSize(QSize(150, 0));
        noteTypeComboBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 222);\n"
"border: 1px solid transparent;"));

        horizontalLayout->addWidget(noteTypeComboBox);

        eventTimeEdit = new QTimeEdit(addNoteDialog);
        eventTimeEdit->setObjectName(QStringLiteral("eventTimeEdit"));
        eventTimeEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 222);"));

        horizontalLayout->addWidget(eventTimeEdit);

        eventDateEdit = new QDateEdit(addNoteDialog);
        eventDateEdit->setObjectName(QStringLiteral("eventDateEdit"));
        eventDateEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 222);"));
        eventDateEdit->setDate(QDate(2016, 11, 1));

        horizontalLayout->addWidget(eventDateEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        noteTextText = new QTextEdit(addNoteDialog);
        noteTextText->setObjectName(QStringLiteral("noteTextText"));
        noteTextText->setMaximumSize(QSize(16777215, 16777215));
        noteTextText->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 222);\n"
"border: 1px solid transparent;\n"
"border-radius: 10px"));

        gridLayout->addWidget(noteTextText, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cancelAddingNoteButton = new QPushButton(addNoteDialog);
        cancelAddingNoteButton->setObjectName(QStringLiteral("cancelAddingNoteButton"));

        horizontalLayout_5->addWidget(cancelAddingNoteButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        createNoteButton = new QPushButton(addNoteDialog);
        createNoteButton->setObjectName(QStringLiteral("createNoteButton"));

        horizontalLayout_5->addWidget(createNoteButton);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);


        retranslateUi(addNoteDialog);

        QMetaObject::connectSlotsByName(addNoteDialog);
    } // setupUi

    void retranslateUi(QWidget *addNoteDialog)
    {
        addNoteDialog->setWindowTitle(QApplication::translate("addNoteDialog", "addNoteDialog", 0));
        eventTimeEdit->setDisplayFormat(QApplication::translate("addNoteDialog", "HH:mm", 0));
        cancelAddingNoteButton->setText(QApplication::translate("addNoteDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        createNoteButton->setText(QApplication::translate("addNoteDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\267\320\260\320\274\320\265\321\202\320\272\321\203", 0));
    } // retranslateUi

};

namespace Ui {
    class addNoteDialog: public Ui_addNoteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOTEDIALOG_H
