#ifndef MATTYGROUPBOX_H
#define MATTYGROUPBOX_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "MattyNote.h"

class MattyGroupBox :
	public QGroupBox
{
	Q_OBJECT
public:
	MattyGroupBox(class MattyNote & ThisNote = MattyNote(), QWidget* parent = 0);
private:
	void buildFrame();
	void fillFrame(class MattyNote & ThisNote);
	QLabel* NoteTypeLabel;
	QLabel* NoteCrTimeAndDateLabel;
	QLabel* NoteEventTimeAndDateLabel;
	QLabel* NoteTextLabel;
	QSpacerItem* horizontalSpacer_1;
	QSpacerItem* horizontalSpacer_2;
	QSpacerItem* verticalSpacer;
	QPushButton* editNoteButton;
	QPushButton* deleteNoteButton;
	QHBoxLayout* horizontalLayout_1;
	QHBoxLayout* horizontalLayout_2;
	QVBoxLayout *verticalLayout;
	QGridLayout *gridLayout;
	class MattyNote ThisGroupBoxNote;
	void mouseDoubleClickEvent(QMouseEvent * e);

	private slots:
	void deleteNote();
	void editNote();
	//void on_deleteNoteButton_clicked();
};

#endif // MATTYGROUPBOX_H