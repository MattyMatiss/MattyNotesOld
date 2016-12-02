#ifndef MATTYSETTINGSDIALOG_H
#define MATTYSETTINGSDIALOG_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QWidget>
#include "ui_mattysettingsdialog.h"

class MattySettingsDialog : public QDialog {
	Q_OBJECT

public:
	MattySettingsDialog(QWidget * parent = 0);
	~MattySettingsDialog();

private:
	Ui::MattySettingsDialog MattySettingsDialogUi;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;
	QPushButton ApplySettingsButton;
	QPushButton CancelSettingsButton;

	QListWidgetItem* General;
	QListWidgetItem* Interface;
	QListWidgetItem* Security;

	QWidget *GeneralPageWidget;
	QWidget *InterfacePageWidget;
	QWidget *SecurityPageWidget;

	private slots:
	void on_ApplySettingsButton_clicked();
	void on_CancelSettingsButton_clicked();
	void changeDisplayedPage();

};

#endif // MATTYSETTINGSDIALOG_H