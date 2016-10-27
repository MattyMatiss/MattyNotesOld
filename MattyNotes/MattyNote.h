#pragma once
class MattyNote
{
public:
	MattyNote();
	~MattyNote();
	void setTitle(const QString & Title);
	void setType(const QString & Type);
	void setText(const QString & Text);
	void setEventTime(const QString & EventTime);
	void setEventDate(const QString & EventDate);
	void setCrTime(const QString & CrTime);
	void setCrDate(const QString & CrDate);
private:
	QString NoteTitle;
	QString NoteType;
	QString NoteText;
	QString NoteEventTime;
	QString NoteEventDate;
	QString NoteCrTime;
	QString NoteCrDate;
};

