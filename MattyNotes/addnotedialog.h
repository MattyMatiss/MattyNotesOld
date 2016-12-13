#ifndef ADDNOTEDIALOG_H
#define ADDNOTEDIALOG_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QWidget>
#include "ui_addnotedialog.h"
#include "MattyNote.h"

enum Action { Add, Edit };

class addNoteDialog : public QDialog {
	Q_OBJECT

public:
	addNoteDialog(Action DialogTypeIncm, int EditingNoteIdIncm = -1);

	QPushButton createNoteButton;
	QPushButton cancelAddingNoteButton;

	~addNoteDialog();

private:
	Ui::addNoteDialog addNoteDialogUi;

	QAction *SaveNote;

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;

	Action DialogType;
	int EditingNoteId;

	class MattyNote ThisDialogNote;

	private slots:
	void on_createNoteButton_clicked();
	void on_cancelAddingNoteButton_clicked();
	//void closeEvent(QCloseEvent *event);
};

#endif // ADDNOTEDIALOG_H