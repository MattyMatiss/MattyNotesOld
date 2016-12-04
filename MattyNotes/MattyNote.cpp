#include "stdafx.h"
#include "MattyNote.h"
#include "Constants.h"
#include "DbManager.h"

MattyNote::MattyNote()
{
	CrTimeAndDate = QDateTime::currentDateTime();
	NoteCrDayOfWeek = printDayOfWeek(CrTimeAndDate.date());
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
	/*if (EventTime.length() == Constants::TimeQStringLength && EventTime[2] == Constants::TimeSeparator)
	{
		NoteEventTime = EventTime;
		QStringList TimeTemp = EventTime.split(Constants::TimeSeparator);
		EventTimeAndDate.UserTimeAndDate.hour = TimeTemp[0].toInt();
		EventTimeAndDate.UserTimeAndDate.minute = TimeTemp[1].toInt();
		EventTimeAndDate.UserTimeAndDate.second = 0;
	}*/

	NoteEventTime = EventTime;
	EventTimeAndDate.setTime(QTime::fromString(EventTime));
}

void MattyNote::setEventDate(const QString & EventDate)
{
	/*if (EventDate.length() == Constants::DateQStringLength &&
		EventDate[Constants::PositionOfFirstDateSeparator] == Constants::DateSeparator
		&& EventDate[Constants::PositionOfSecondDateSeparator] == Constants::DateSeparator)
	{
		NoteEventDate = EventDate;
		QStringList DateTemp = EventDate.split(Constants::DateSeparator);
		EventTimeAndDate.UserTimeAndDate.day = DateTemp[0].toInt();
		EventTimeAndDate.UserTimeAndDate.month = DateTemp[1].toInt();
		EventTimeAndDate.UserTimeAndDate.year = DateTemp[2].toInt();
		EventTimeAndDate.setUserDayOfWeek();
		NoteEvDayOfWeek = EventTimeAndDate.getUserDayOfWeek();
	}*/

	NoteEventDate = EventDate;
	EventTimeAndDate.setDate(QDate::fromString(EventDate));
	NoteEvDayOfWeek = printDayOfWeek(EventTimeAndDate.date());
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

QString MattyNote::getEvDayofWeek()
{
	return NoteEvDayOfWeek;
}

QString MattyNote::getCrTime()
{
	return NoteCrTime;
}

QString MattyNote::getCrDate()
{
	return NoteCrDate;
}

QString MattyNote::getCrDayOfWeek()
{
	return NoteCrDayOfWeek;
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

QString MattyNote::printDayOfWeek(QDate Date)
{
	QString DayOfWeek = "";
	enum DayOfWeekEnum { Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
	switch (Date.dayOfWeek())
	{
	case Monday:
		DayOfWeek = QString::fromLocal8Bit("ом");
		break;
	case Tuesday:
		DayOfWeek = QString::fromLocal8Bit("бр");
		break;
	case Wednesday:
		DayOfWeek = QString::fromLocal8Bit("яп");
		break;
	case Thursday:
		DayOfWeek = QString::fromLocal8Bit("вр");
		break;
	case Friday:
		DayOfWeek = QString::fromLocal8Bit("ор");
		break;
	case Saturday:
		DayOfWeek = QString::fromLocal8Bit("яа");
		break;
	case Sunday:
		DayOfWeek = QString::fromLocal8Bit("бя");
		break;
	}

	return DayOfWeek;
}