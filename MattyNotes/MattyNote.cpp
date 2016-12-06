#include "stdafx.h"
#include "MattyNote.h"
#include "Constants.h"
#include "DbManager.h"

MattyNote::MattyNote()
{
	CrTimeAndDate = QDateTime::currentDateTime();
	NoteCrTime = CrTimeAndDate.time().toString().mid(0, 5);
	NoteCrDate = CrTimeAndDate.date().toString("d MMM yyyy, ddd");
}

MattyNote::MattyNote(QStringList RowFromDb)
{
	NoteId = RowFromDb[0].toInt();
	NoteTitle = RowFromDb[1];
	NoteType = RowFromDb[2];
	NoteText = RowFromDb[3];
	setEventTime(RowFromDb[4]);
	setEventDate(RowFromDb[5]);
	NoteCrTime = RowFromDb[6];
	NoteCrDate = RowFromDb[7];
	NoteTypeId = RowFromDb[8].toInt();
}

MattyNote::~MattyNote()
{
}

void MattyNote::setTitle(const QString & Title)
{
	NoteTitle = Title;
}

void MattyNote::setType(const QString & TypeName)
{
	NoteTypeId = DbManager::getTypeId(TypeName);
	NoteType = TypeName;
}

void MattyNote::setType(int TypeId)
{
	NoteType = DbManager::getTypeName(TypeId);
	NoteTypeId = TypeId;
}

void MattyNote::setText(const QString & Text)
{
	NoteText = Text;
}

void MattyNote::setEventTime(const QString & EventTime)
{
	NoteEventTime = EventTime;
	EventTimeAndDate.setTime(QTime::fromString(EventTime));
}

void MattyNote::setEventDate(const QString & EventDate)
{
	NoteEventDate = EventDate;
	EventTimeAndDate.setDate(QDate::fromString(EventDate));
}

QString MattyNote::getTitle()
{
	return NoteTitle;
}

QString MattyNote::getType()
{
	return NoteType;
}

int MattyNote::getTypeId()
{
	return NoteTypeId;
}

QString MattyNote::getText()
{
	return NoteText;
}

QString MattyNote::getEventTime()
{
	return NoteEventTime;
}

QString MattyNote::getEventDate()
{
	return NoteEventDate;
}

QString MattyNote::getCrTime()
{
	return NoteCrTime;
}

QString MattyNote::getCrDate()
{
	return NoteCrDate;
}



int MattyNote::getNoteId()
{
	return NoteId;
}

QDateTime  MattyNote::getEventTimeAndDate()
{
	return EventTimeAndDate;
}

QDateTime  MattyNote::getCrTimeAndDate()
{
	return CrTimeAndDate;
}