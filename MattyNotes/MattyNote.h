#pragma once
#include "MattyTime.h"

class MattyNote
{
public:
	MattyNote();
	~MattyNote();
	void setTitle(const QString & Title);
	void setType(const QString & Type);
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
	TimeAndDate* getEventTimeAndDate(); // Returns a pointer to TimeAndDate structure containing ints
	TimeAndDate* getCrTimeAndDate(); // Returns a pointer to the TimeAndDate structure containing ints
private:
	QString NoteTitle;
	QString NoteType;
	QString NoteText;
	QString NoteEventTime; // Format: 00:00
	QString NoteEventDate; // Format: 00.00.0000
	MattyTime* EventTimeAndDate;  // Any unspecified part equals -1
	MattyTime* CrTimeAndDate;  // Automaticly set in constructor of MattyNote
};

