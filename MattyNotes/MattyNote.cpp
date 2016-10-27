#include "stdafx.h"
#include "MattyNote.h"


MattyNote::MattyNote()
{
}

MattyNote::~MattyNote()
{
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
	NoteEventTime = EventTime;
}

void MattyNote::setEventDate(const QString & EventDate)
{
	NoteEventDate = EventDate;
}

void MattyNote::setCrTime(const QString & CrTime)
{
	NoteCrTime = CrTime;
}

void MattyNote::setCrDate(const QString & CrDate)
{
	NoteCrDate = CrDate;
}
