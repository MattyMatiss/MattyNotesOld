#ifndef MATTYSETTINGS_H
#define MATTYSETTINGS_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QWidget>
#include "ui_mattysettings.h"

class MattySettings : public QWidget {
	Q_OBJECT

public:
	MattySettings(QWidget * parent = 0);
	~MattySettings();

private:
	Ui::MattySettings MattySettingsUi;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;

};

#endif // MATTYSETTINGS_H