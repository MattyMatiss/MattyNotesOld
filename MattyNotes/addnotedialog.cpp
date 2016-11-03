#include <stdafx.h>
#include "addnotedialog.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "UtilityFunctions.h"
#include "mattynotes.h"
#include "NoteGroupBoxHolder.h"
#include "Constants.h"

addNoteDialog::addNoteDialog(QVBoxLayout* GroupBoxLayoutSent, QWidget * parent) : QWidget(parent)
{
	addNoteDialogUi.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	closeAddingWindowButton = new QPushButton();
	QObject::connect(closeAddingWindowButton, SIGNAL(clicked()), this, SLOT(close()));
	DbManager* MattyNotesDbManager = new DbManager(Constants::PathToDb);
	addNoteDialogUi.noteTypeComboBox->clear();
	addNoteDialogUi.noteTypeComboBox->addItems(MattyNotesDbManager->getTypes());
	GroupBoxLayout = new QVBoxLayout();
	GroupBoxLayout = GroupBoxLayoutSent;
	delete MattyNotesDbManager;
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
		DbManager* MattyNotesDbManager = new DbManager(Constants::PathToDb);
		MattyNotesDbManager->addNote(NoteToAdd);
		delete MattyNotesDbManager;
		delete NoteToAdd;
	}

	NoteGroupBoxHolder::sortNotesByCrDate();
	NoteGroupBoxHolder::showNotes(0, GroupBoxLayout);

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
