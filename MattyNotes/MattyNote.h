
#ifndef MATTYNOTE_H
#define MATTYNOTE_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "MattyTime.h"

class MattyNote
{
public:
	MattyNote();
	MattyNote(QStringList RowFromDb);
	~MattyNote();
	void setTitle(const QString & Title);
	void setType(const QString & TypeName);
	void setType(int TypeId);
	void setText(const QString & Text);
	void setEventTime(const QString & EventTime); // Warning! Input format must be: 00:00
	void setEventDate(const QString & EventDate); // Warning! Input format must be: 00.00.0000
	QString getTitle();
	QString getType();
	QString getText();
	QString getEventTime(); // Format: 00:00
	QString getEventDate(); // Format: 00.00.0000
	QString getCrTime(); // Format: 00:00
	QString getCrDate(); // Format: 00.00.0000
	int getTypeId();
	TimeAndDate* getEventTimeAndDate(); // Returns a pointer to TimeAndDate structure containing ints
	TimeAndDate* getCrTimeAndDate(); // Returns a pointer to the TimeAndDate structure containing ints
private:
	int NoteTypeId;
	QString NoteTitle;
	QString NoteType;
	QString NoteText;
	QString NoteEventTime; // Format: 00:00
	QString NoteEventDate; // Format: 00.00.0000
	QString NoteCrTime;
	QString NoteCrDate;
	MattyTime EventTimeAndDate;  // Any unspecified part equals -1
	MattyTime CrTimeAndDate;  // Automaticly set in constructor of MattyNote
};

#endif // MATTYNOTE_H