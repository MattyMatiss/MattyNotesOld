#include <stdafx.h>
#include "mattysettings.h"

MattySettings::MattySettings(QWidget * parent) : QWidget(parent)
{
	MattySettingsUi.setupUi(this);
	//this->setStyleSheet("#addNoteDialog{ background-image: url(:/MattyNotes/NoteBackground600.png);"
	//"background-repeat: no-repeat;"
	//"background-size: cover; }"
	/*"QWidget{ background-color: rgb(255, 255, 222) }");*/
	this->setWindowFlags(Qt::FramelessWindowHint);
}

MattySettings::~MattySettings()
{

}

void MattySettings::mousePressEvent(QMouseEvent *event)
{
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
}

void MattySettings::mouseMoveEvent(QMouseEvent *event)
{
	move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}
