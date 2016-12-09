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

	QPushButton ApplySettingsButton;
	QPushButton CancelSettingsButton;

	QListWidgetItem* General;
	QListWidgetItem* Interface;
	QListWidgetItem* Security;

	QWidget *GeneralPageWidget;
	QWidget *InterfacePageWidget;
	QWidget *SecurityPageWidget;

	QGridLayout *InterfacePageGridLayout;
	QLabel *ChooseThemeLabel;
	QVBoxLayout *ThemeRadioButtonVerticalLayout;
	QRadioButton *SunShineRadioButton;
	QRadioButton *SnowRadioButton;
	QRadioButton *DarkRadioButton;
	QLabel *InsertCssLabel;
	QPlainTextEdit *CssCodePlainTextEdit;
	QSpacerItem *HorizontalSpacer;
	QPushButton *ApplyInterfacePageChangesButton;

	void setConnects();
	void buildPages();
	void fillInterfacePage();

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;

	private slots:
	void on_ApplySettingsButton_clicked();
	void on_CancelSettingsButton_clicked();

};

#endif // MATTYSETTINGSDIALOG_H