#pragma once
#include "MattyNote.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
class DbManager
{
public:
	DbManager(const QString& path);
	bool addNote(const MattyNote * Note);
	bool deleteNote();
	void showNote();
	QSqlTableModel* getModel(const QString& path);
	~DbManager();
private:
	QSqlDatabase MattyNotesDb;
};

