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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addNoteButton;
    QSpacerItem *horizontalSpacer_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *NoteTitleLabel;
    QLabel *NoteTypeLabel;
    QLabel *NoteCrTimeAndDateLabel;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *editNoteButton;
    QPushButton *deleteNoteButton;
    QHBoxLayout *horizontalLayout_10;
    QLabel *NoteEventTimeAndDateLabel;
    QSpacerItem *horizontalSpacer_8;
    QLabel *NoteTextLabel;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MattyNotesClass)
    {
        if (MattyNotesClass->objectName().isEmpty())
            MattyNotesClass->setObjectName(QStringLiteral("MattyNotesClass"));
        MattyNotesClass->resize(705, 534);
        MattyNotesClass->setStyleSheet(QStringLiteral("background-color: rgb(255, 194, 11);"));
        centralWidget = new QWidget(MattyNotesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 336, 428));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(150, 200));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        NoteTitleLabel = new QLabel(groupBox);
        NoteTitleLabel->setObjectName(QStringLiteral("NoteTitleLabel"));

        horizontalLayout_9->addWidget(NoteTitleLabel);

        NoteTypeLabel = new QLabel(groupBox);
        NoteTypeLabel->setObjectName(QStringLiteral("NoteTypeLabel"));

        horizontalLayout_9->addWidget(NoteTypeLabel);

        NoteCrTimeAndDateLabel = new QLabel(groupBox);
        NoteCrTimeAndDateLabel->setObjectName(QStringLiteral("NoteCrTimeAndDateLabel"));

        horizontalLayout_9->addWidget(NoteCrTimeAndDateLabel);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        editNoteButton = new QPushButton(groupBox);
        editNoteButton->setObjectName(QStringLiteral("editNoteButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editNoteButton->sizePolicy().hasHeightForWidth());
        editNoteButton->setSizePolicy(sizePolicy);
        editNoteButton->setMaximumSize(QSize(20, 20));
        editNoteButton->setStyleSheet(QStringLiteral("background-image: url(:/MattyNotes/edit.png);"));
        editNoteButton->setFlat(true);

        horizontalLayout_9->addWidget(editNoteButton);

        deleteNoteButton = new QPushButton(groupBox);
        deleteNoteButton->setObjectName(QStringLiteral("deleteNoteButton"));
        sizePolicy.setHeightForWidth(deleteNoteButton->sizePolicy().hasHeightForWidth());
        deleteNoteButton->setSizePolicy(sizePolicy);
        deleteNoteButton->setMaximumSize(QSize(20, 20));
        deleteNoteButton->setStyleSheet(QStringLiteral("background-image: url(:/MattyNotes/1s-udalenie.png);"));
        deleteNoteButton->setFlat(true);

        horizontalLayout_9->addWidget(deleteNoteButton);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        NoteEventTimeAndDateLabel = new QLabel(groupBox);
        NoteEventTimeAndDateLabel->setObjectName(QStringLiteral("NoteEventTimeAndDateLabel"));

        horizontalLayout_10->addWidget(NoteEventTimeAndDateLabel);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_10);

        NoteTextLabel = new QLabel(groupBox);
        NoteTextLabel->setObjectName(QStringLiteral("NoteTextLabel"));
        NoteTextLabel->setMinimumSize(QSize(0, 100));
        NoteTextLabel->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));

        verticalLayout_5->addWidget(NoteTextLabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(groupBox);


        verticalLayout_4->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

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

        MattyNotesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MattyNotesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 705, 21));
        MattyNotesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MattyNotesClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MattyNotesClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MattyNotesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMinimumSize(QSize(0, 0));
        MattyNotesClass->setStatusBar(statusBar);

        retranslateUi(MattyNotesClass);

        QMetaObject::connectSlotsByName(MattyNotesClass);
    } // setupUi

    void retranslateUi(QMainWindow *MattyNotesClass)
    {
        MattyNotesClass->setWindowTitle(QApplication::translate("MattyNotesClass", "MattyNotes", 0));
        addNoteButton->setText(QApplication::translate("MattyNotesClass", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\274\320\265\321\202\320\272\320\260", 0));
        groupBox->setTitle(QApplication::translate("MattyNotesClass", "GroupBox", 0));
        NoteTitleLabel->setText(QApplication::translate("MattyNotesClass", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272", 0));
        NoteTypeLabel->setText(QApplication::translate("MattyNotesClass", "\320\242\320\270\320\277", 0));
        NoteCrTimeAndDateLabel->setText(QApplication::translate("MattyNotesClass", "\320\241\320\276\320\267\320\264\320\260\320\275\320\276:", 0));
        editNoteButton->setText(QString());
        deleteNoteButton->setText(QString());
        NoteEventTimeAndDateLabel->setText(QApplication::translate("MattyNotesClass", "\320\232\320\276\320\263\320\264\320\260", 0));
        NoteTextLabel->setText(QApplication::translate("MattyNotesClass", "\320\242\320\265\320\272\321\201\321\202", 0));
        pushButtonCalendar->setText(QString());
        refreshDb->setText(QApplication::translate("MattyNotesClass", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MattyNotesClass: public Ui_MattyNotesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATTYNOTES_H
