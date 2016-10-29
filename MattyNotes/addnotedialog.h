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
	~addNoteDialog();

private:
	Ui::addNoteDialog addNoteDialogUi;
	private slots:
	void on_createNoteButton_clicked();
	void on_cancelAddingNoteButton_clicked();
};

#endif // ADDNOTEDIALOG_H