#include "stdafx.h"
#include "DbManager.h"
#include <QSqlQuery>
#include <QSqlRecord>

QSqlDatabase DbManager::MattyNotesDb;

DbManager::DbManager()
{
	
}

bool DbManager::connect(const QString & path)
{
	MattyNotesDb = QSqlDatabase::addDatabase("QSQLITE");
	MattyNotesDb.setDatabaseName(path);

	if (!MattyNotesDb.open())
	{
		QMessageBox::critical(NULL, QObject::tr("Error"), MattyNotesDb.lastError().text());
		MattyNotesDb.close();

		return false;
	}

	return true;
}

bool DbManager::addNote(MattyNote * Note)
{
	if (MattyNotesDb.isOpen())
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
	}
	else
	{
		showIsNotOpenError();
	}
}

bool DbManager::deleteNote(int NoteId)
{
	if (MattyNotesDb.isOpen())
	{
		QSqlQuery deleteNoteQuery;
		deleteNoteQuery.prepare("DELETE FROM Notes WHERE NoteId=:NoteId");
		deleteNoteQuery.bindValue(":NoteId", NoteId);
		return deleteNoteQuery.exec();
	}
	else
	{
		showIsNotOpenError();
	}
}

QSqlTableModel* DbManager::getModel(const QString & TableName)
{
	if (MattyNotesDb.isOpen())
	{
		QSqlTableModel* MattyNotesModel = new QSqlTableModel();
		MattyNotesModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
		MattyNotesModel->setTable(TableName);
		MattyNotesModel->select();
		return MattyNotesModel;
	}

	else 
	{
		showIsNotOpenError();
		return new QSqlTableModel();
	}
}

QStringList DbManager::getTypes()
{
	if (MattyNotesDb.isOpen())
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
	else
	{
		showIsNotOpenError();
		return QStringList();
	}
}

QString DbManager::getTypeName(int TypeId)
{
	if (MattyNotesDb.isOpen())
	{
		QString TypeName;
		QSqlQuery getTypeQuery;
		getTypeQuery.prepare("SELECT TypeName FROM NoteTypes WHERE TypeId=:TypeId");
		getTypeQuery.bindValue(":TypeId", TypeId);
		getTypeQuery.exec();
		TypeName = getTypeQuery.value(0).toString();
		return TypeName;
	}
	else
	{
		showIsNotOpenError();
		return QString();
	}
}

int DbManager::getTypeId(const QString & TypeName)
{
	if (MattyNotesDb.isOpen())
	{
		int TypeId = 0;
		QSqlQuery getTypeQuery;
		getTypeQuery.prepare("SELECT TypeId FROM NoteTypes WHERE TypeName=:TypeName");
		getTypeQuery.bindValue(":TypeName", TypeName);
		getTypeQuery.exec();
		TypeId = getTypeQuery.value(0).toInt();
		return TypeId;
	}
	else
	{
		showIsNotOpenError();
		return 0;
	}
}

int DbManager::getNoteCount()
{
	if (MattyNotesDb.isOpen())
	{
		int NoteCount = 0;
		QSqlQuery getNoteCount;
		getNoteCount.exec("SELECT Count(*) FROM Notes");
		if (getNoteCount.next())
			NoteCount = getNoteCount.value(0).toInt();
		return NoteCount;
	}
	else
	{
		showIsNotOpenError();
		return 0;
	}
}

QVector<QStringList> DbManager::showNotes(enum MattyOrderNotesBy OrderBy)
{
	if (MattyNotesDb.isOpen())
	{
		QStringList OrderClause = { "", " ORDER BY TypeName", " ORDER BY TypeName DESC",
			" ORDER BY CrDate, CrTime", " ORDER BY CrDate, CrTime DESC",
			" ORDER BY EventDate, EventTime", " ORDER BY EventDate, EventTime DESC" }; // скопировано
		QVector<QStringList> VectorOfNotes;
		QSqlQuery getNotesQuery;
		getNotesQuery.prepare("SELECT * FROM Notes" + OrderClause[OrderBy]);
		getNotesQuery.exec();
		while (getNotesQuery.next())
		{
			QStringList Fields;
			for (int i = 0;i < 9;i++)
			{
				Fields.push_back(getNotesQuery.value(i).toString());
			}
			VectorOfNotes.push_back(Fields);
		}
		return VectorOfNotes;
	}
	else
	{
		showIsNotOpenError();
		return QVector<QStringList>();
	}
}

QVector<QStringList> DbManager::showNotes(QVector<QStringList> & Filter, enum MattyOrderNotesBy OrderBy)
{
	if (MattyNotesDb.isOpen())
	{
		QString WhereClause = "";

		for (int i = 0; i < Filter.length(); i++)
		{
			if (i == 0)
				WhereClause.append(" WHERE");
			else
				WhereClause.append(",");

			WhereClause.append(" " + Filter[i][0] + "=:" + Filter[i][0]);
		}

		QStringList OrderClause = { "", " ORDER BY TypeName", " ORDER BY TypeName DESC",
			" ORDER BY CrDate, CrTime", " ORDER BY CrDate, CrTime DESC",
			" ORDER BY EventDate, EventTime", " ORDER BY EventDate, EventTime DESC" };

		QVector<QStringList> VectorOfNotes;

		QSqlQuery getNotesQuery;
		getNotesQuery.prepare("SELECT * FROM Notes" + WhereClause + OrderClause[OrderBy]);

		for (int i = 0; i < Filter.length(); i++)
		{
			getNotesQuery.bindValue(":" + Filter[i][0], Filter[i][1]);
		}

		if (!getNotesQuery.exec())
		{
			QMessageBox::critical(NULL, QObject::tr("Error"), MattyNotesDb.lastError().text());
		}

		while (getNotesQuery.next())
		{
			QStringList Fields;
			for (int i = 0;i < 9;i++)
			{
				Fields.push_back(getNotesQuery.value(i).toString());
			}
			VectorOfNotes.push_back(Fields);
		}
		return VectorOfNotes;


	}
	else
	{
		showIsNotOpenError();
		return QVector<QStringList>();
	}
}

/*QVector<QStringList> DbManager::getAllNotesOrderByCrDate()
{
	if (MattyNotesDb.isOpen())
	{
		QVector<QStringList> VectorOfNotes;
		QSqlQuery getAllNotesQuery("SELECT * FROM Notes ORDER BY NoteId");
		getAllNotesQuery.exec();
		while (getAllNotesQuery.next())
		{
			QStringList Fields;
			for (int i = 0;i < 9;i++)
			{
				Fields.push_back(getAllNotesQuery.value(i).toString());
			}
			VectorOfNotes.push_back(Fields);
		}
		return VectorOfNotes;
	}
	else
	{
		showIsNotOpenError();
		return QVector<QStringList>();
	}
}*/

void DbManager::showIsNotOpenError()
{
	QString DbName = MattyNotesDb.databaseName();

	if (DbName == "")
		QMessageBox::critical(NULL, QObject::tr("Error"), "Internal code error. Database name is not set.");
	else
		QMessageBox::critical(NULL, QObject::tr("Error"), "Database " + DbName + " could not be opened. Please, check whether the file is still there");
}

DbManager::~DbManager()
{
}

