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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *NoteTitleLabel;
    QLabel *NoteTypeLabel;
    QLabel *NoteCrTimeAndDateLabel;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *editNoteButton;
    QPushButton *deleteNoteButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *NoteEventTimeAndDateLabel;
    QSpacerItem *horizontalSpacer_8;
    QLabel *NoteTextLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MattyNotesClass)
    {
        if (MattyNotesClass->objectName().isEmpty())
            MattyNotesClass->setObjectName(QStringLiteral("MattyNotesClass"));
        MattyNotesClass->resize(702, 534);
        MattyNotesClass->setStyleSheet(QStringLiteral("#MattyNotesClass{background-color: rgb(255, 255, 127);}"));
        centralWidget = new QWidget(MattyNotesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("#centralWidget {\n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 255), stop:0.375 rgba(255, 255, 0, 255), stop:0.423533 rgba(251, 255, 0, 255), stop:0.45 rgba(247, 255, 0, 255), stop:0.477581 rgba(255, 244, 71, 255), stop:0.518717 rgba(255, 218, 71, 255), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 255), stop:0.625 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255));}"));
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
        addNoteButton->setMinimumSize(QSize(51, 51));
        addNoteButton->setMaximumSize(QSize(51, 51));
        addNoteButton->setStyleSheet(QLatin1String("#addNoteButton { background-color: transparent;\n"
"background-image: url(:/MattyNotes/AddNote.png);\n"
"color: transparent;\n"
"font-weight: bold;\n"
"font-style: italic;\n"
"font-family: Comic Sans MS; }\n"
"#addNoteButton:hover { background-image: url(:/MattyNotes/AddNoteHover.png); \n"
"color: #6d6f6d; }"));

        horizontalLayout_3->addWidget(addNoteButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QLatin1String("QScrollArea { background: transparent; border: 0px none transparent; }\n"
"QScrollArea > QWidget > QWidget { background: transparent; border: 0px none transparent; }"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 337, 402));
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
        horizontalLayout_7->setContentsMargins(-1, 25, -1, -1);
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(150, 200));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setStyleSheet(QLatin1String("#groupBox { \n"
"/*background-image: url(:/MattyNotes/NoteBackground450.png);*/\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 250, 97, 1), stop:1 rgba(255, 221, 97, 1));\n"
"background-repeat: no-repeat;\n"
"background-position: bottom right;\n"
"background-size: 10px; \n"
"border: 1px solid transparent;\n"
"border-radius: 10px;\n"
"font-weight: bold;\n"
"font-size: 14px;\n"
"font-style: italic;\n"
"font-family: Comic Sans MS;\n"
"color: #4d3f3d;\n"
"}\n"
"#groupBox::title { padding-left: 35px;  text-decoration: underline; }\n"
"QLabel { font-family: Comic Sans MS; }"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
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
        editNoteButton->setMaximumSize(QSize(21, 21));
        editNoteButton->setStyleSheet(QLatin1String("#editNoteButton  { background-image: url(:/MattyNotes/EditNote.png);  background-position: center; } \n"
"#editNoteButton:hover { background-image: url(:/MattyNotes/EditNoteHover.png);  background-position: center; }"));
        editNoteButton->setFlat(true);

        horizontalLayout_9->addWidget(editNoteButton);

        deleteNoteButton = new QPushButton(groupBox);
        deleteNoteButton->setObjectName(QStringLiteral("deleteNoteButton"));
        sizePolicy.setHeightForWidth(deleteNoteButton->sizePolicy().hasHeightForWidth());
        deleteNoteButton->setSizePolicy(sizePolicy);
        deleteNoteButton->setMaximumSize(QSize(21, 21));
        deleteNoteButton->setStyleSheet(QLatin1String("#deleteNoteButton  { background-image: url(:/MattyNotes/DeleteNote.png);  background-position: center; } \n"
"#deleteNoteButton:hover { background-image: url(:/MattyNotes/DeleteNoteHover.png);  background-position: center; }"));
        deleteNoteButton->setFlat(true);

        horizontalLayout_9->addWidget(deleteNoteButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


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
        NoteTextLabel->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
""));

        verticalLayout_5->addWidget(NoteTextLabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(groupBox);


        verticalLayout_4->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        MattyNotesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MattyNotesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 702, 21));
        MattyNotesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MattyNotesClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MattyNotesClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MattyNotesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMinimumSize(QSize(0, 0));
        statusBar->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 127);\n"
"border-color: rgb(255, 255, 255);"));
        MattyNotesClass->setStatusBar(statusBar);

        retranslateUi(MattyNotesClass);

        QMetaObject::connectSlotsByName(MattyNotesClass);
    } // setupUi

    void retranslateUi(QMainWindow *MattyNotesClass)
    {
        MattyNotesClass->setWindowTitle(QApplication::translate("MattyNotesClass", "MattyNotes", 0));
        addNoteButton->setText(QApplication::translate("MattyNotesClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", 0));
        groupBox->setTitle(QApplication::translate("MattyNotesClass", "GroupBox", 0));
        NoteTitleLabel->setText(QApplication::translate("MattyNotesClass", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272", 0));
        NoteTypeLabel->setText(QApplication::translate("MattyNotesClass", "\320\242\320\270\320\277", 0));
        NoteCrTimeAndDateLabel->setText(QApplication::translate("MattyNotesClass", "\320\241\320\276\320\267\320\264\320\260\320\275\320\276:", 0));
        editNoteButton->setText(QString());
        deleteNoteButton->setText(QString());
        NoteEventTimeAndDateLabel->setText(QApplication::translate("MattyNotesClass", "\320\232\320\276\320\263\320\264\320\260", 0));
        NoteTextLabel->setText(QApplication::translate("MattyNotesClass", "\320\242\320\265\320\272\321\201\321\202", 0));
    } // retranslateUi

};

namespace Ui {
    class MattyNotesClass: public Ui_MattyNotesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATTYNOTES_H
