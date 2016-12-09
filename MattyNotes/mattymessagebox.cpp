#include "stdafx.h"
#include "mattymessagebox.h"

MattyMessageBox::MattyMessageBox(Type Type, QWidget *parent)
	: QMessageBox(parent)
{
	this->setObjectName(QStringLiteral(""));
	this->setWindowFlags(Qt::FramelessWindowHint);

	switch (Type)
	{
	case 0:

		this->setStandardButtons(QMessageBox::Ok);
		this->button(QMessageBox::Ok)->setObjectName(QStringLiteral("okButton"));

		break;

	case 1:

		this->setStandardButtons(QMessageBox::Ok);
		this->button(QMessageBox::Ok)->setObjectName(QStringLiteral("okButton"));

		break;

	case 2:

		this->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		this->button(QMessageBox::Yes)->setObjectName(QStringLiteral("yesButton"));
		this->button(QMessageBox::No)->setObjectName(QStringLiteral("noButton"));

		QPixmap QuestionSquared(":/MattyNotes/QuestionSquared.png");
		this->setIconPixmap(QuestionSquared);

		break;
	}

}

void MattyMessageBox::mousePressEvent(QMouseEvent *event)
{
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
}

void MattyMessageBox::mouseMoveEvent(QMouseEvent *event)
{
	move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}

MattyMessageBox::~MattyMessageBox()
{

}
