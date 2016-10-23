#pragma once
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
class DbManager
{
public:
	DbManager(const QString& path);
	bool addNote();
	bool deleteNote();
	void showNote();
	QSqlTableModel* getModel(const QString& path);
	~DbManager();
private:
	QSqlDatabase MattyNotesDb;
};

