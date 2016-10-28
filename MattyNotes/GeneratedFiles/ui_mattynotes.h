/********************************************************************************
** Form generated from reading UI file 'mattynotes.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATTYNOTES_H
#define UI_MATTYNOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MattyNotesClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonCalendar;
    QCalendarWidget *calendarWidget;
    QTableView *tableView;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *noteTitleText;
    QTextEdit *noteTypeText;
    QHBoxLayout *horizontalLayout_4;
    QTimeEdit *eventTimeEdit;
    QSpacerItem *horizontalSpacer_5;
    QDateEdit *eventDateEdit;
    QTextEdit *noteTextText;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *addNoteButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MattyNotesClass)
    {
        if (MattyNotesClass->objectName().isEmpty())
            MattyNotesClass->setObjectName(QStringLiteral("MattyNotesClass"));
        MattyNotesClass->resize(694, 570);
        MattyNotesClass->setStyleSheet(QStringLiteral("background-color: rgb(255, 194, 11);"));
        centralWidget = new QWidget(MattyNotesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::StyledPanel);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        pushButtonCalendar = new QPushButton(centralWidget);
        pushButtonCalendar->setObjectName(QStringLiteral("pushButtonCalendar"));

        verticalLayout->addWidget(pushButtonCalendar);

        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(calendarWidget);


        verticalLayout_2->addLayout(verticalLayout);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        noteTitleText = new QTextEdit(centralWidget);
        noteTitleText->setObjectName(QStringLiteral("noteTitleText"));
        noteTitleText->setMaximumSize(QSize(16777215, 31));

        verticalLayout_4->addWidget(noteTitleText);

        noteTypeText = new QTextEdit(centralWidget);
        noteTypeText->setObjectName(QStringLiteral("noteTypeText"));
        noteTypeText->setMaximumSize(QSize(16777215, 31));

        verticalLayout_4->addWidget(noteTypeText);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        eventTimeEdit = new QTimeEdit(centralWidget);
        eventTimeEdit->setObjectName(QStringLiteral("eventTimeEdit"));

        horizontalLayout_4->addWidget(eventTimeEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        eventDateEdit = new QDateEdit(centralWidget);
        eventDateEdit->setObjectName(QStringLiteral("eventDateEdit"));

        horizontalLayout_4->addWidget(eventDateEdit);


        verticalLayout_4->addLayout(horizontalLayout_4);

        noteTextText = new QTextEdit(centralWidget);
        noteTextText->setObjectName(QStringLiteral("noteTextText"));
        noteTextText->setMaximumSize(QSize(16777215, 200));

        verticalLayout_4->addWidget(noteTextText);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        addNoteButton = new QPushButton(centralWidget);
        addNoteButton->setObjectName(QStringLiteral("addNoteButton"));

        horizontalLayout_5->addWidget(addNoteButton);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        gridLayout_2->addLayout(verticalLayout_4, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        MattyNotesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MattyNotesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 694, 21));
        MattyNotesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MattyNotesClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MattyNotesClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MattyNotesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MattyNotesClass->setStatusBar(statusBar);

        retranslateUi(MattyNotesClass);

        QMetaObject::connectSlotsByName(MattyNotesClass);
    } // setupUi

    void retranslateUi(QMainWindow *MattyNotesClass)
    {
        MattyNotesClass->setWindowTitle(QApplication::translate("MattyNotesClass", "MattyNotes", 0));
        label->setText(QApplication::translate("MattyNotesClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">00:00</span></p></body></html>", 0));
        pushButtonCalendar->setText(QString());
        addNoteButton->setText(QApplication::translate("MattyNotesClass", "Add Note", 0));
    } // retranslateUi

};

namespace Ui {
    class MattyNotesClass: public Ui_MattyNotesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATTYNOTES_H
