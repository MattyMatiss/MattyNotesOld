#include "stdafx.h"
#include "mattynotes.h"
#include "MattyTime.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "addnotedialog.h"


MattyNotes::MattyNotes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// 
	QSizePolicy sp_retain = ui.calendarWidget->sizePolicy();
	sp_retain.setRetainSizeWhenHidden(true);
	ui.calendarWidget->setSizePolicy(sp_retain);

	ui.calendarWidget->hide();

	QLCDNumber *ClocksLcdNumber;
	ClocksLcdNumber = new QLCDNumber(ui.statusBar);
	ClocksLcdNumber->setObjectName(QStringLiteral("ClocksLcdNumber"));
	ui.statusBar->addWidget(ClocksLcdNumber);
	ClocksLcdNumber->display(MattyTime::PrintCurrTime());
	
	DbManager* MattyNotesDbManager = new DbManager("MattyNotes.sqlite");
	ui.tableView->setModel(MattyNotesDbManager->getModel("Notes"));

	createNoteGroups(MattyNotesDbManager->getNoteCount());

	delete MattyNotesDbManager;
}

void MattyNotes::createNoteGroups(int NoteCount)
{
	for (int i = 0; i < NoteCount;i++)
	{
		QHBoxLayout *HorizontalLayout;
		HorizontalLayout = new QHBoxLayout();
		HorizontalLayout->setSpacing(6);
		HorizontalLayout->setStretch(0, 0);
		HorizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
		ui.verticalLayout_4->addLayout(HorizontalLayout);
		QString GroupBoxName = "NoteGroupBox" + QString::number(i+1);
		QGroupBox *groupBox;
		groupBox = new QGroupBox();
		HorizontalLayout->addWidget(groupBox);
		groupBox->setMinimumSize(QSize(150, 150));
		groupBox->setMaximumSize(QSize(2500, 300));
		groupBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		groupBox->setTitle(QApplication::translate("MattyNotesClass", qPrintable(GroupBoxName), 0));
		groupBox->setObjectName(GroupBoxName);
		HorizontalLayout->setObjectName("HorizontalLayout" + QString::number(i + 1));
	}
}

MattyNotes::~MattyNotes()
{

}

void MattyNotes::on_pushButtonCalendar_clicked()
{
	if (!ui.calendarWidget->isVisible())
		ui.calendarWidget->show();
	else
		ui.calendarWidget->hide();
}

void MattyNotes::on_addNoteButton_clicked()
{
	addNoteDialog* newAddNoteDialog = new addNoteDialog();
	newAddNoteDialog->setWindowModality(Qt::ApplicationModal); 
	newAddNoteDialog->show();
}

void MattyNotes::on_refreshDb_clicked()
{
	DbManager* MattyNotesDbManager = new DbManager("MattyNotes.sqlite");
	ui.tableView->setModel(MattyNotesDbManager->getModel("Notes"));
	delete MattyNotesDbManager;
}
