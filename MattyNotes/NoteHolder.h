#ifndef NOTEHOLDER_H
#define NOTEHOLDER_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER



class NoteHolder
{
public:
	NoteHolder();
	~NoteHolder();
	void sortNotesByCrDate();
	static void publishNotes(int orderDirection, QVBoxLayout* ParentLayout);
	static void setFilters();
private:
	static int TotalNoteCount;
	static QVector<class MattyNote> ListOfAllNotes;
	static QVector<QString> ListOfGroupBoxeNames;

	static void getAllNotes();
	static void getSelectedNotes();
	static void erasePublishedNotes(QVBoxLayout * ParentLayout);
};

#endif // NOTEHOLDER_H