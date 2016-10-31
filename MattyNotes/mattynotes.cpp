#include "stdafx.h"
#include "mattynotes.h"
#include "MattyTime.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "addnotedialog.h"
#include "MattyGroupBox.h"
#include "NoteGroupBoxHolder.h"


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

	NoteGroupBoxHolder::sortNotesByCrDate();
	NoteGroupBoxHolder::showNotes(0, ui.verticalLayout_4);
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
	addNoteDialog* newAddNoteDialog = new addNoteDialog(ui.verticalLayout_4);
	newAddNoteDialog->setWindowModality(Qt::ApplicationModal); 
	newAddNoteDialog->show();
}

