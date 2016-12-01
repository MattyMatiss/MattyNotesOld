#ifndef ADDNOTEDIALOG_H
#define ADDNOTEDIALOG_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QWidget>
#include "ui_addnotedialog.h"

class addNoteDialog : public QWidget {
	Q_OBJECT

public:
	addNoteDialog(QWidget * parent = 0);
	QPushButton createNoteButton;
	QPushButton cancelAddingNoteButton;
	QVBoxLayout* GroupBoxLayout;
	QPushButton* closeAddingWindowButton;
	~addNoteDialog();

private:
	Ui::addNoteDialog addNoteDialogUi;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;

	QWidget* ParentToGroupBox;

	private slots:
	void on_createNoteButton_clicked();
	void on_cancelAddingNoteButton_clicked();
};

#endif // ADDNOTEDIALOG_H