#ifndef DBMANAGER_H
#define DBMANAGER_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "MattyNote.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
class DbManager
{
public:
	DbManager(const QString& path);
	~DbManager();
	bool addNote(MattyNote * Note);
	bool deleteNote();
	void showNote();
	QSqlTableModel* getModel(const QString& path);
	QStringList getTypes();
	QString getTypeName(int TypeId);
	int getTypeId(const QString & TypeName);
	int getNoteCount();
	QVector<QStringList> getAllNotesOrderByCrDate();
private:
	QSqlDatabase MattyNotesDb;
};

#endif // DBMANAGER_H