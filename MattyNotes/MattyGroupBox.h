#ifndef MATTYGROUPBOX_H
#define MATTYGROUPBOX_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "MattyNote.h"

//#include "C:\Qt\Qt5.7.0\5.7\msvc2015_64\include\QtWidgets\qgroupbox.h"
class MattyGroupBox :
	public QGroupBox
{
	//Q_OBJECT
public:
	MattyGroupBox();
	void fillFrame(class MattyNote & ThisNote);
	~MattyGroupBox();
private:
	void buildFrame();
	void deleteNote();
	//QLabel* NoteTitleLabel;
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
};

#endif // MATTYGROUPBOX_H