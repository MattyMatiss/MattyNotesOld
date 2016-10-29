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

bool DbManager::addNote(MattyNote * Note)
{
	QSqlQuery query;
	query.prepare("INSERT INTO Notes (NoteTitle, NoteType, NoteText, EventTime, EventDate, CrTime, CrDate, TypeId)"
		"values(:NoteTitle, :NoteType, :NoteText, :EventTime, :EventDate, :CrTime, :CrDate, :TypeId)");
	query.bindValue(":NoteTitle", Note->getTitle());
	query.bindValue(":NoteType", Note->getType());
	query.bindValue(":NoteText", Note->getText());
	query.bindValue(":EventTime", Note->getEventTime());
	query.bindValue(":EventDate", Note->getEventDate());
	query.bindValue(":CrTime", Note->getCrTime());
	query.bindValue(":CrDate", Note->getCrDate());
	query.bindValue(":TypeId", Note->getTypeId());
	return query.exec();

	//return true;
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

QStringList DbManager::getTypes()
{
	QStringList NoteTypes;
	QSqlQuery getTypeQuery;
	getTypeQuery.exec("SELECT TypeName FROM NoteTypes ORDER BY TypeId");
	while (getTypeQuery.next())
	{
		NoteTypes << getTypeQuery.value(0).toString();
	}
	return NoteTypes;
}

QString DbManager::getTypeName(int TypeId)
{
	QString TypeName;
	QSqlQuery getTypeQuery;
	getTypeQuery.prepare("SELECT TypeName FROM NoteTypes WHERE TypeId=:TypeId");
	getTypeQuery.bindValue(":TypeId", TypeId);
	getTypeQuery.exec();
	TypeName = getTypeQuery.value(0).toString();
	return TypeName;
}

int DbManager::getTypeId(const QString & TypeName)
{
	int TypeId = 0;
	QSqlQuery getTypeQuery;
	getTypeQuery.prepare("SELECT TypeId FROM NoteTypes WHERE TypeName=:TypeName");
	getTypeQuery.bindValue(":TypeName", TypeName);
	getTypeQuery.exec();
	TypeId = getTypeQuery.value(0).toInt();
	return TypeId;
}

int DbManager::getNoteCount()
{
	int NoteCount = 0;
	QSqlQuery getNoteCount;
	getNoteCount.exec("SELECT Count(*) FROM Notes");
	if (getNoteCount.next())
		NoteCount = getNoteCount.value(0).toInt();
	return NoteCount;
}

DbManager::~DbManager()
{
}
