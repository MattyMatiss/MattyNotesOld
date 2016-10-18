#include "stdafx.h"
#include "mattynotes.h"
#include "MattyTime.h"

MattyNotes::MattyNotes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.calendarWidget->hide();
	MattyTime::updateCurrTime();
	QString qs = QString::fromUtf8(MattyTime::PrintCurrTime().c_str());
	ui.label->setText(qs);
	QFont f("Arial", 36, QFont::Bold);
	ui.label->setFont(f);
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