#include "stdafx.h"
#include "mattymessagebox.h"

MattyMessageBox::MattyMessageBox(Type Type, QWidget *parent)
	: QMessageBox(parent)
{
	this->setObjectName(QStringLiteral("MattyMessageBox"));
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

	this->setStyleSheet(QStringLiteral("#MattyMessageBox { "
		" border-radius: 15px;"
		"background-color: rgb(255, 255, 127);"
		" border: 3px ridge gray; "
		"font-family: Comic Sans MS; "
		//"font-style: italic;"
		"font-size: 14px;"
		"color: #4d3f3d; "
		"}"
		"#yesButton {height: 53px;"
		"width: 53px;"
		"background-color: transparent;"
		"background-image: url(:/MattyNotes/CommonYes40x40.png);"
		"background-position: center;"
		"background-repeat: no-repeat;"
		"color: transparent; "
		"font-weight: bold;"
		"}"
		"#yesButton:hover { background-image: url(:/MattyNotes/CommonYesHover40x40.png); }"
		"#noButton {height: 53px;"
		"width: 53px;"
		"background-color: transparent;"
		"background-image: url(:/MattyNotes/CommonNo40x40.png);"
		"background-position: center;"
		"background-repeat: no-repeat;"
		"color: transparent; "
		"font-weight: bold;"
		"font-style: italic; }"
		"#noButton:hover { background-image: url(:/MattyNotes/CommonNoHover40x40.png); }"));
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
