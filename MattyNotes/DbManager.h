#ifndef DBMANAGER_H
#define DBMANAGER_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "MattyNote.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>

enum MattyOrderNotesBy { NoOrder, Type, TypeDesc, CrDate, CrDateDesc, EvDate, EvDateDesc }; // скопировано в новый класс, удалить

class DbManager
{
public:
	DbManager();
	~DbManager();
	static bool connect(const QString& path);
	static bool addNote(MattyNote * Note);
	static bool deleteNote(int NoteId);
	static QVector<QStringList> showNotes(enum MattyOrderNotesBy OrderBy = NoOrder);
	static QVector<QStringList> showNotes(QVector<QStringList> & Filter, enum MattyOrderNotesBy OrderBy = NoOrder);
	static QSqlTableModel* getModel(const QString& path);
	static QStringList getTypes();
	static QString getTypeName(int TypeId);
	static int getTypeId(const QString & TypeName);
	static int getNoteCount();
	//static QVector<QStringList> getAllNotesOrderByCrDate();
	static void showIsNotOpenError();
private:
	static QSqlDatabase MattyNotesDb;
};

#endif // DBMANAGER_H