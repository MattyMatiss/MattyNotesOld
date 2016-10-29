#pragma once
//#include "C:\Qt\Qt5.7.0\5.7\msvc2015_64\include\QtWidgets\qgroupbox.h"
class MattyGroupBox :
	public QGroupBox
{
	//Q_OBJECT
public:
	MattyGroupBox();
	//QLabel* MyLabel;
	QLabel* NoteTitleLabel;
	QLabel* NoteTypeLabel;
	QLabel* NoteCrTimeAndDateLabel;
	QLabel* NoteEventTimeAndDateLabel;
	QLabel* NoteTextLabel;
	QSpacerItem* horizontalSpacer_1;
	QSpacerItem* horizontalSpacer_2;
	QSpacerItem* verticalSpacer;
	QPushButton* editNoteButton;
	QPushButton* deleteNoteButton;
	//QHBoxLayout* HorizontalLayout;
	QHBoxLayout* horizontalLayout_1;
	QHBoxLayout* horizontalLayout_2;
	//QHBoxLayout* horizontalLayout_3;
	QVBoxLayout *verticalLayout;
	QGridLayout *gridLayout;
	~MattyGroupBox();
};

