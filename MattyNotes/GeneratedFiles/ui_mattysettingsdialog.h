/********************************************************************************
** Form generated from reading UI file 'mattysettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATTYSETTINGSDIALOG_H
#define UI_MATTYSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MattySettingsDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *CancelSettingsButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *ApplySettingsButton;

    void setupUi(QWidget *MattySettingsDialog)
    {
        if (MattySettingsDialog->objectName().isEmpty())
            MattySettingsDialog->setObjectName(QStringLiteral("MattySettingsDialog"));
        MattySettingsDialog->resize(676, 548);
        gridLayout = new QGridLayout(MattySettingsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        splitter = new QSplitter(MattySettingsDialog);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setBaseSize(QSize(150, 0));
        splitter->addWidget(listWidget);
        stackedWidget = new QStackedWidget(splitter);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        splitter->addWidget(stackedWidget);

        horizontalLayout_2->addWidget(splitter);

        verticalSpacer = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CancelSettingsButton = new QPushButton(MattySettingsDialog);
        CancelSettingsButton->setObjectName(QStringLiteral("CancelSettingsButton"));

        horizontalLayout->addWidget(CancelSettingsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ApplySettingsButton = new QPushButton(MattySettingsDialog);
        ApplySettingsButton->setObjectName(QStringLiteral("ApplySettingsButton"));

        horizontalLayout->addWidget(ApplySettingsButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(MattySettingsDialog);

        QMetaObject::connectSlotsByName(MattySettingsDialog);
    } // setupUi

    void retranslateUi(QWidget *MattySettingsDialog)
    {
        MattySettingsDialog->setWindowTitle(QApplication::translate("MattySettingsDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        CancelSettingsButton->setText(QApplication::translate("MattySettingsDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        ApplySettingsButton->setText(QApplication::translate("MattySettingsDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MattySettingsDialog: public Ui_MattySettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATTYSETTINGSDIALOG_H
