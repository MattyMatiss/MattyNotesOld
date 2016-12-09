#include "stdafx.h"
#include "mattymessagebox.h"

MattyMessageBox::MattyMessageBox(Type Type, QWidget *parent)
	: QMessageBox(parent)
{
	this->setObjectName(QStringLiteral("MattyMessageBox"));
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setStyleSheet(NULL);

	switch (Type)
	{
	case Type::Information:

		this->setStandardButtons(QMessageBox::Ok);
		this->button(QMessageBox::Ok)->setObjectName(QStringLiteral("okButton"));

		MattyIcon.load(":/MattyNotes/InformationCircled.png");

		break;

	case Type::Warning:

		this->setStandardButtons(QMessageBox::Ok);
		this->button(QMessageBox::Ok)->setObjectName(QStringLiteral("okButton"));

		MattyIcon.load(":/MattyNotes/WarningTriangled.png");

		break;

	case Type::Question:

		this->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		this->button(QMessageBox::Yes)->setObjectName(QStringLiteral("yesButton"));
		this->button(QMessageBox::No)->setObjectName(QStringLiteral("noButton"));

		MattyIcon.load(":/MattyNotes/QuestionSquared.png");

		break;
	}

	this->setIconPixmap(MattyIcon);
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
