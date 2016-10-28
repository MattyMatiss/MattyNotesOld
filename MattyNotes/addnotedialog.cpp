#include <stdafx.h>
#include "addnotedialog.h"
#include "DbManager.h"
#include "MattyNote.h"

addNoteDialog::addNoteDialog(QWidget * parent) : QWidget(parent) 
{
	addNoteDialogUi.setupUi(this);
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
	if (addNoteDialog::addNoteDialogUi.noteTitleText->toPlainText() != "")
	{
		MattyNote* NoteToAdd = new MattyNote();
		NoteToAdd->setTitle(addNoteDialogUi.noteTitleText->toPlainText());
		NoteToAdd->setType(addNoteDialogUi.noteTypeComboBox->currentText());
		NoteToAdd->setText(addNoteDialogUi.noteTextText->toPlainText());
		NoteToAdd->setEventTime(addNoteDialogUi.eventTimeEdit->text());
		NoteToAdd->setEventDate(addNoteDialogUi.eventDateEdit->text());
		//DbManager* MattyNotesDbManager = new DbManager("MattyNotes.sqlite");
		//MattyNotesDbManager->addNote(NoteToAdd);
		//delete MattyNotesDbManager;
		delete NoteToAdd;
	}

	this->close();
}

