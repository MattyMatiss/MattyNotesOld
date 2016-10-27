#include "stdafx.h"
#include "MattyNote.h"

MattyNote::MattyNote()
{
	EventTimeAndDate = new MattyTime();
	EventTimeAndDate->setUserTimeAndDateNull();
	CrTimeAndDate = new MattyTime();
	MattyTime::updateCurrTime();
	CrTimeAndDate->UserTimeAndDate = MattyTime::CurrTime;
}

MattyNote::~MattyNote()
{
	delete EventTimeAndDate;
	delete CrTimeAndDate;
}

void MattyNote::setTitle(const QString & Title)
{
	NoteTitle = Title;
}

void MattyNote::setType(const QString & Type)
{
	NoteType = Type;
}

void MattyNote::setText(const QString & Text)
{
	NoteText = Text;
}

void MattyNote::setEventTime(const QString & EventTime)
{
	if (EventTime.length() == 5 && EventTime[2] == ":")
	{
		NoteEventTime = EventTime;
		QStringList TimeTemp = EventTime.split(":");
		EventTimeAndDate->UserTimeAndDate->hour = TimeTemp[0].toInt();
		EventTimeAndDate->UserTimeAndDate->minute = TimeTemp[1].toInt();
		EventTimeAndDate->UserTimeAndDate->second = 0;
	}
}

void MattyNote::setEventDate(const QString & EventDate)
{
	if (EventDate.length() == 10 && EventDate[2] == "." && EventDate[5] == ".")
	{
		NoteEventDate = EventDate;
		QStringList DateTemp = EventDate.split(".");
		EventTimeAndDate->UserTimeAndDate->day = DateTemp[0].toInt();
		EventTimeAndDate->UserTimeAndDate->month = DateTemp[1].toInt();
		EventTimeAndDate->UserTimeAndDate->year = DateTemp[2].toInt();
		//EventTimeAndDate->UserTimeAndDate ->dayOfWeek  ÏÐÈÄÓÌÀÒÜ!!!
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
	return CrTimeAndDate->PrintUserTime();
}

QString MattyNote::getCrDate()
{
	return CrTimeAndDate->PrintUserDate();
}

TimeAndDate * MattyNote::getEventTimeAndDate()
{
	return EventTimeAndDate->UserTimeAndDate;
}

TimeAndDate * MattyNote::getCrTimeAndDate()
{
	return CrTimeAndDate->UserTimeAndDate;
}
