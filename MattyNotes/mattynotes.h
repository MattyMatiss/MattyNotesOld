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
	QPushButton pushButton;
	QPushButton addNoteButton;
	QPushButton* closeProgramButton;
	//QPushButton refreshDb;
	~MattyNotes();


private:
	Ui::MattyNotesClass ui;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;

	private slots:
	void on_pushButtonCalendar_clicked();
	void on_addNoteButton_clicked();
	//void on_closeProgramButton_clicked();
	//void on_refreshDb_clicked();
};



#endif // MATTYNOTES_H
