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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MattyNotesClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonCalendar;
    QCalendarWidget *calendarWidget;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *refreshDb;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addNoteButton;
    QSpacerItem *horizontalSpacer_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MattyNotesClass)
    {
        if (MattyNotesClass->objectName().isEmpty())
            MattyNotesClass->setObjectName(QStringLiteral("MattyNotesClass"));
        MattyNotesClass->resize(716, 555);
        MattyNotesClass->setStyleSheet(QStringLiteral("background-color: rgb(255, 194, 11);"));
        centralWidget = new QWidget(MattyNotesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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
        pushButtonCalendar->setMinimumSize(QSize(296, 0));

        verticalLayout->addWidget(pushButtonCalendar);

        calendarWidget = new QCalendarWidget(centralWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(calendarWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        refreshDb = new QPushButton(centralWidget);
        refreshDb->setObjectName(QStringLiteral("refreshDb"));

        horizontalLayout_2->addWidget(refreshDb);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        addNoteButton = new QPushButton(centralWidget);
        addNoteButton->setObjectName(QStringLiteral("addNoteButton"));

        horizontalLayout_3->addWidget(addNoteButton);

        horizontalSpacer_5 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_3);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 342, 449));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 271, 141));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 200, 271, 141));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 370, 271, 141));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 2, 1);

        MattyNotesClass->setCentralWidget(centralWidget);
        refreshDb->raise();
        addNoteButton->raise();
        scrollArea->raise();
        menuBar = new QMenuBar(MattyNotesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 716, 21));
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
        refreshDb->setText(QApplication::translate("MattyNotesClass", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        addNoteButton->setText(QApplication::translate("MattyNotesClass", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\274\320\265\321\202\320\272\320\260", 0));
        groupBox->setTitle(QApplication::translate("MattyNotesClass", "GroupBox", 0));
        groupBox_2->setTitle(QApplication::translate("MattyNotesClass", "GroupBox", 0));
        groupBox_3->setTitle(QApplication::translate("MattyNotesClass", "GroupBox", 0));
    } // retranslateUi

};

namespace Ui {
    class MattyNotesClass: public Ui_MattyNotesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATTYNOTES_H
