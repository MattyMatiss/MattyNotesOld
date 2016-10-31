#ifndef NOTEGROUPBOXHOLDER_H
#define NOTEGROUPBOXHOLDER_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER



class NoteGroupBoxHolder
{
public:
	NoteGroupBoxHolder();
	~NoteGroupBoxHolder();
	static QVector<class MattyNote> sortNotesByCrDate();
	static void showNotes(int orderDirection, QVBoxLayout* ParentLayout);
private:
	static int NoteCount;
	static QVector<class MattyNote> ListOfNotes;
};

#endif // NOTEGROUPBOXHOLDER_H