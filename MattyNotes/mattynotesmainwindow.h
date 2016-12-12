#ifndef MATTYNOTES_H
#define MATTYNOTES_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QtWidgets/QMainWindow>
#include "ui_mattynotesmainwindow.h"

class MattyNotesMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MattyNotesMainWindow(QWidget *parent = 0);

	~MattyNotesMainWindow();

	void connectToDb(QString& PathToDb = QStringLiteral(""));


private:
	Ui::MattyNotesMainWindowClass ui;

	QToolBar *MattyToolBar;
	QWidget *NoteOptionsWidget;

	QLabel* WindowHeaderLabel;

	QPushButton* CloseWindowButton;
	QPushButton* MaximizeWindowButton;
	QPushButton* MinimizeWindowButton;
	QPushButton *AddNoteButton;
	QPushButton *RefreshNoteListButton;
	QPushButton *SettingsButton;

	QWidget* MainToolBarSpacerLeft;
	QWidget* MainToolBarSpacerRight;
	QWidget* MattyToolBarMainSpacer;

	class MattyClocks* MainClocks;

	QGraphicsOpacityEffect* opacity;

	QAction *closeMainWindow;
	QAction *addNewNote;
	QAction *RefreshMainWindow;

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;

	void buildMainToolBar();
	void buildMattyToolBar();
	void buildNoteOptionsToolbar();
	void setConnects();
	void setActions();

	private slots:

	void addNote();
	void closeWindow();
	void maximizeWindow();
	void minimizeWindow();
	void refreshMainWindow();
	void openSettings();
	void resizeMattyToolbarButtons();
	bool WindowActivatedEvent(QEvent *e);
};



#endif // MATTYNOTES_H
