#include "stdafx.h"
#include "MattyNote.h"
#include "Constants.h"
#include "DbManager.h"

MattyNote::MattyNote()
{
	//EventTimeAndDate = new MattyTime();
	EventTimeAndDate.setUserTimeAndDateNull();
	//CrTimeAndDate = new MattyTime();
	MattyTime::updateCurrTime();
	CrTimeAndDate.UserTimeAndDate = MattyTime::CurrTime;
	NoteCrTime = CrTimeAndDate.PrintUserTime();
	NoteCrDate = CrTimeAndDate.PrintUserDate();
}

MattyNote::MattyNote(QStringList RowFromDb)
{
	//CrTimeAndDate = new MattyTime();
	CrTimeAndDate.setUserTimeAndDateNull();
	//EventTimeAndDate = new MattyTime();
	//EventTimeAndDate->setUserTimeAndDateNull();
	NoteTitle = RowFromDb[0];
	NoteType = RowFromDb[1];
	NoteText = RowFromDb[2];
	NoteEventTime = RowFromDb[3];
	NoteEventDate = RowFromDb[4];
	NoteCrTime = RowFromDb[5];
	NoteCrDate = RowFromDb[6];
	NoteTypeId = RowFromDb[7].toInt();
}

MattyNote::~MattyNote()
{
	//delete EventTimeAndDate;
	//delete CrTimeAndDate;
}

void MattyNote::setTitle(const QString & Title)
{
	NoteTitle = Title;
}

void MattyNote::setType(const QString & TypeName)
{
	DbManager* MattyNotesDbManager = new DbManager("MattyNotes.sqlite");
	NoteTypeId = MattyNotesDbManager->getTypeId(TypeName);
	NoteType = TypeName;
	delete MattyNotesDbManager;
}

void MattyNote::setType(int TypeId)
{
	DbManager* MattyNotesDbManager = new DbManager("MattyNotes.sqlite");
	NoteType = MattyNotesDbManager->getTypeName(TypeId);
	NoteTypeId = TypeId;
	delete MattyNotesDbManager;
}

void MattyNote::setText(const QString & Text)
{
	NoteText = Text;
}

void MattyNote::setEventTime(const QString & EventTime)
{
	if (EventTime.length() == Constants::TimeQStringLength && EventTime[2] == Constants::TimeSeparator)
	{
		NoteEventTime = EventTime;
		QStringList TimeTemp = EventTime.split(Constants::TimeSeparator);
		EventTimeAndDate.UserTimeAndDate->hour = TimeTemp[0].toInt();
		EventTimeAndDate.UserTimeAndDate->minute = TimeTemp[1].toInt();
		EventTimeAndDate.UserTimeAndDate->second = 0;
	}
}

void MattyNote::setEventDate(const QString & EventDate)
{
	if (EventDate.length() == Constants::DateQStringLength &&
		EventDate[Constants::PositionOfFirstDateSeparator] == Constants::DateSeparator
		&& EventDate[Constants::PositionOfSecondDateSeparator] == Constants::DateSeparator)
	{
		NoteEventDate = EventDate;
		QStringList DateTemp = EventDate.split(Constants::DateSeparator);
		EventTimeAndDate.UserTimeAndDate->day = DateTemp[0].toInt();
		EventTimeAndDate.UserTimeAndDate->month = DateTemp[1].toInt();
		EventTimeAndDate.UserTimeAndDate->year = DateTemp[2].toInt();
		EventTimeAndDate.setUserDayOfWeek();
	}
}

QString MattyNote::getTitle()
{
	return NoteTitle;
}

QString MattyNote::getType()
{
	return NoteType;
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

int MattyNote::getTypeId()
{
	return NoteTypeId;
}

TimeAndDate * MattyNote::getEventTimeAndDate()
{
	return EventTimeAndDate.UserTimeAndDate;
}

TimeAndDate * MattyNote::getCrTimeAndDate()
{
	return CrTimeAndDate.UserTimeAndDate;
}
