#include "stdafx.h"
#include "DbManager.h"

DbManager::DbManager(const QString& path)
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName(path);

	if (!m_db.open())
	{
		qDebug() << "Error: connection with database fail";
	}
	else
	{
		qDebug() << "Database: connection ok";
	}
}

bool DbManager::addNote()
{
	return true;
}
bool DbManager::deleteNote()
{
	return true;
}
void DbManager::showNote()
{

}

DbManager::~DbManager()
{

}