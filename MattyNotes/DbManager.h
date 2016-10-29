#pragma once
#include "MattyNote.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
class DbManager
{
public:
	DbManager(const QString& path);
	bool addNote(MattyNote * Note);
	bool deleteNote();
	void showNote();
	QSqlTableModel* getModel(const QString& path);
	QStringList getTypes();
	QString getTypeName(int TypeId);
	int getTypeId(const QString & TypeName);
	int getNoteCount();
	~DbManager();
private:
	QSqlDatabase MattyNotesDb;
};

