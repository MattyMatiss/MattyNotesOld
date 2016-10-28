#ifndef MATTYNOTES_H
#define MATTYNOTES_H

#include <QtWidgets/QMainWindow>
#include "ui_mattynotes.h"

class MattyNotes : public QMainWindow
{
	Q_OBJECT

public:
	MattyNotes(QWidget *parent = 0);
	QPushButton pushButton;
	QPushButton addNoteButton;
	//QTextEdit noteTitleText;
//	QTextEdit noteTypeText;
	//QTextEdit noteTextText;
	//QTimeEdit eventTimeEdit;
	//QDateEdit eventDateEdit;
	~MattyNotes();

private:
	Ui::MattyNotesClass ui;
	private slots:
	void on_pushButtonCalendar_clicked();
	void on_addNoteButton_clicked();
};



#endif // MATTYNOTES_H
