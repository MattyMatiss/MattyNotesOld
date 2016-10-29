#ifndef MATTYNOTES_H
#define MATTYNOTES_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QtWidgets/QMainWindow>
#include "ui_mattynotes.h"

class MattyNotes : public QMainWindow
{
	Q_OBJECT

public:
	MattyNotes(QWidget *parent = 0);
	void createNoteGroups(int NoteCount);
	QPushButton pushButton;
	QPushButton addNoteButton;
	QPushButton refreshDb;
	~MattyNotes();

private:
	Ui::MattyNotesClass ui;
	private slots:
	void on_pushButtonCalendar_clicked();
	void on_addNoteButton_clicked();
	void on_refreshDb_clicked();
};



#endif // MATTYNOTES_H
