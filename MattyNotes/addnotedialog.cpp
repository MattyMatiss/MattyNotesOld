#include <stdafx.h>
#include "addnotedialog.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "UtilityFunctions.h"
#include "mattynotes.h"
#include "NoteHolder.h"
#include "Constants.h"

addNoteDialog::addNoteDialog(QVBoxLayout* GroupBoxLayoutSent, QWidget * parent) : QWidget(parent)
{
	addNoteDialogUi.setupUi(this);
	//this->setStyleSheet("#addNoteDialog{ background-image: url(:/MattyNotes/NoteBackground600.png);"
	//"background-repeat: no-repeat;"
	//"background-size: cover; }"
	/*"QWidget{ background-color: rgb(255, 255, 222) }");*/
	this->setWindowFlags(Qt::FramelessWindowHint);
	closeAddingWindowButton = new QPushButton();
	QObject::connect(closeAddingWindowButton, SIGNAL(clicked()), this, SLOT(close()));
	DbManager::connect(Constants::PathToDb);
	addNoteDialogUi.noteTypeComboBox->clear();
	addNoteDialogUi.noteTypeComboBox->addItems(DbManager::getTypes());
	GroupBoxLayout = new QVBoxLayout();
	GroupBoxLayout = GroupBoxLayoutSent;
	/*createNoteButton.setFixedSize(70, 70);
	createNoteButton.setStyleSheet(QStringLiteral("QPushButton { background-image: url(:/MattyNotes/ApplyAdding.png);"
		"color: transparent; }"
	"QPushButton:hover { background-image: url(:/MattyNotes/ApplyAddingHover.png);"
		"color: #4d3f3d; }"));
	cancelAddingNoteButton.setFixedSize(60, 60);
	cancelAddingNoteButton.setStyleSheet(QStringLiteral("QPushButton { background-image: url(:/MattyNotes/CancelAdding.png);"
		"color: transparent; }"
	"QPushButton:hover { background-image: url(:/MattyNotes/CancelAddingHover.png);"
	"color: #4d3f3d; }"));*/
}

addNoteDialog::~addNoteDialog() 
{
	
}

void addNoteDialog::on_cancelAddingNoteButton_clicked()
{
	this->close();
}


void addNoteDialog::on_createNoteButton_clicked()
{
	if (addNoteDialogUi.noteTitleText->toPlainText() != "")
	{
		MattyNote* NoteToAdd = new MattyNote();
		NoteToAdd->setTitle(addNoteDialogUi.noteTitleText->toPlainText());
		NoteToAdd->setType(addNoteDialogUi.noteTypeComboBox->currentText());
		NoteToAdd->setText(addNoteDialogUi.noteTextText->toPlainText());
		NoteToAdd->setEventTime(UtilityFunctions::repareTime(addNoteDialogUi.eventTimeEdit->text()));
		NoteToAdd->setEventDate(addNoteDialogUi.eventDateEdit->text());
		DbManager::addNote(NoteToAdd);
		delete NoteToAdd;
	}

	NoteHolder::sortNotesByCrDate();
	NoteHolder::showNotes(0, GroupBoxLayout);

	this->close();
}

void addNoteDialog::mousePressEvent(QMouseEvent *event)
{
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
}

void addNoteDialog::mouseMoveEvent(QMouseEvent *event)
{
	move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}
