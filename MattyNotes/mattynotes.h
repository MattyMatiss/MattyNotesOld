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
	QLabel* WindowHeaderLabel;
	QPushButton* CloseWindowButton;
	QPushButton* MaximizeWindowButton;
	QPushButton* MinimizeWindowButton;
	QToolBar *MattyToolBar;
	QPushButton *AddNoteButton;
	QPushButton *RefreshNoteListButton;
	QPushButton *SettingsButton;
	QWidget* MainToolBarSpacerLeft;
	QWidget* MainToolBarSpacerRight;
	~MattyNotes();


private:
	Ui::MattyNotesClass ui;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;
	void connectToDb(QString& PathToDb = QStringLiteral(""));
	void buildMainToolBar();
	void buildMattyToolBar();
	inline void setConnects();

	private slots:
	void on_addNoteButtonTemp_clicked();
	void closeWindow();
	void maximizeWindow();
	void minimizeWindow();
	void on_refreshNoteList_clicked();
	void on_SettingsButton_clicked();
};



#endif // MATTYNOTES_H
