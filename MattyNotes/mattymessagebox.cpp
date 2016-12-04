#include "stdafx.h"
#include "mattymessagebox.h"

MattyMessageBox::MattyMessageBox(QWidget *parent)
	: QMessageBox(parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	this->setObjectName(QStringLiteral("MattyMessageBox"));
	this->button(QMessageBox::Yes)->setObjectName(QStringLiteral("yesButton"));
	this->button(QMessageBox::No)->setObjectName(QStringLiteral("noButton"));
	this->setStyleSheet(QStringLiteral("#MattyMessageBox { "
		" border-radius: 15px;"
		"background-color: rgb(255, 255, 127);"
		" border: 3px ridge gray; "
		"font-family: Comic Sans MS; "
		"font-style: italic;"
		"font-size: 14px;"
		"color: #4d3f3d; "
		"}"
		"#yesButton {height: 53px;"
		"width: 53px;"
		"background-color: transparent;"
		"background-image: url(:/MattyNotes/CommonYes.png);"
		"background-position: center;"
		"background-repeat: no-repeat;"
		"color: transparent; "
		"font-weight: bold;"
		"font-style: italic; }"
		"#yesButton:hover { background-image: url(:/MattyNotes/CommonYesHover.png); }"
		"#noButton {height: 53px;"
		"width: 53px;"
		"background-color: transparent;"
		"background-image: url(:/MattyNotes/CommonNo.png);"
		"background-position: center;"
		"background-repeat: no-repeat;"
		"color: transparent; "
		"font-weight: bold;"
		"font-style: italic; }"
		"#noButton:hover { background-image: url(:/MattyNotes/CommonNoHover.png); }"));
}

MattyMessageBox::~MattyMessageBox()
{

}
