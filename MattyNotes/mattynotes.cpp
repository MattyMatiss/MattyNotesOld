#include "stdafx.h"
#include "mattynotes.h"
#include "MattyTime.h"
#include "DbManager.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>

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

	//DbManager MattyDb("C:/Users/Matty/Documents/Visual Studio 2015/Projects/Personal/MattyNotes/MattyNotes/MattyNotes.sqlite");
	QSqlDatabase MattyNotesDb = QSqlDatabase::addDatabase("QSQLITE");
	MattyNotesDb.setDatabaseName("C:/Users/Matty/Documents/Visual Studio 2015/Projects/Personal/MattyNotes/MattyNotes/MattyNotes.sqlite");

	if (!MattyNotesDb.open())
	{
		QMessageBox::critical(NULL, QObject::tr("Error"), MattyNotesDb.lastError().text());
	}
	QSqlTableModel* MattyNotesModel = new QSqlTableModel(this);
	MattyNotesModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	MattyNotesModel->setTable("Notes");
	MattyNotesModel->select();
	ui.tableView->setModel(MattyNotesModel);
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