#include "stdafx.h"
#include "mattynotes.h"
#include "MattyTime.h"
#include "DbManager.h"


MattyNotes::MattyNotes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.calendarWidget->hide();
	MattyTime::updateCurrTime();
	ui.label->setText(MattyTime::PrintCurrTime());
	QFont f("Arial", 36, QFont::Bold);
	ui.label->setFont(f);
	
	DbManager* MattyNotesDbManager = new DbManager("MattyNotes.sqlite");
	ui.tableView->setModel(MattyNotesDbManager->getModel("Notes"));
	delete MattyNotesDbManager;
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