#include "stdafx.h"
#include "DbManager.h"


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

QSqlTableModel * DbManager::getModel(const QString & TableName)
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
