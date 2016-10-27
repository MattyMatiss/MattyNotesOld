#include "stdafx.h"
#include "DbManager.h"
#include <QSqlQuery>

DbManager::DbManager(const QString& path)
{
	MattyNotesDb = QSqlDatabase::addDatabase("QSQLITE");
	MattyNotesDb.setDatabaseName(path);

	if (!MattyNotesDb.open())
	{
		QMessageBox::critical(NULL, QObject::tr("Error"), MattyNotesDb.lastError().text());
		MattyNotesDb.close();
	}
}

bool DbManager::addNote(const MattyNote * Note)
{
	QSqlQuery query;
	query.prepare("INSERT INTO Notes (NoteTitle, NoteType, NoteText, EventTime, EventDate, CrTime, CrDate) values(:NoteTitle, :NoteType, :NoteText, :EventTime, :EventDate, :CrTime, :CrDate)");
	query.bindValue(":NoteTitle", Note->getTitle);
	query.bindValue(":NoteType", Note->getType);
	query.bindValue(":NoteText", Note->getText);
	query.bindValue(":EventTime", Note->getEventTime);
	query.bindValue(":EventDate", Note->getEventDate);
	query.bindValue(":CrTime", Note->getCrTime);
	query.bindValue(":CrDate", Note->getCrDate);
	return query.exec();
}
bool DbManager::deleteNote()
{
	return true;
}
void DbManager::showNote()
{

}

QSqlTableModel* DbManager::getModel(const QString & TableName)
{
	QSqlTableModel* MattyNotesModel = new QSqlTableModel();
	MattyNotesModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	MattyNotesModel->setTable(TableName);
	MattyNotesModel->select();
	return MattyNotesModel;
}

DbManager::~DbManager()
{
}
