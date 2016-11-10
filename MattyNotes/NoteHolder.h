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
	static QVector<class MattyNote> sortNotesByCrDate();
	static void showNotes(int orderDirection, QVBoxLayout* ParentLayout);
private:
	static int NoteCount;
	static QVector<class MattyNote> ListOfNotes;
};

#endif // NOTEHOLDER_H