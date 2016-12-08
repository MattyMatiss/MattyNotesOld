#include <stdafx.h>
#include "addnotedialog.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "UtilityFunctions.h"
#include "mattynotesmainwindow.h"
#include "NoteHolder.h"
#include "Constants.h"
#include "QueryConstructor.h"

addNoteDialog::addNoteDialog(Action DialogTypeIncm, int EditingNoteIdIncm)
{
	addNoteDialogUi.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);

	DbManager::connect(Constants::PathToDb); // надо ли?

	addNoteDialogUi.noteTypeComboBox->clear();
	addNoteDialogUi.noteTypeComboBox->addItems(DbManager::getTypes());

	addNoteDialogUi.eventTimeEdit->setTime(QTime::currentTime());
	addNoteDialogUi.eventDateEdit->setDate(QDate::currentDate());
	
	EditingNoteId = EditingNoteIdIncm;

	if (EditingNoteIdIncm != -1)
	{
		EditingNoteId = EditingNoteIdIncm;

		ThisDialogNote = new MattyNote(DbManager::showNote(EditingNoteId));

		addNoteDialogUi.noteTitleText->setText(ThisDialogNote->getTitle());
		addNoteDialogUi.noteTypeComboBox->setCurrentText(ThisDialogNote->getType());
		addNoteDialogUi.noteTextText->setText(ThisDialogNote->getText());
		addNoteDialogUi.eventTimeEdit->setTime(QTime::fromString(ThisDialogNote->getEventTime()));
		addNoteDialogUi.eventDateEdit->setDate(QDate::fromString(ThisDialogNote->getEventDate()));
	}
	else
	{
		ThisDialogNote = new MattyNote();
	}

	DialogType = DialogTypeIncm;

	SaveNote = new QAction(this);
	SaveNote->setShortcut(tr("CTRL+RETURN"));
	this->addAction(SaveNote);
	QObject::connect(SaveNote, SIGNAL(triggered()), this, SLOT(on_createNoteButton_clicked()));
}

addNoteDialog::~addNoteDialog() 
{
	//delete ThisDialogNote;
}

void addNoteDialog::on_cancelAddingNoteButton_clicked()
{
	this->close();
	//this->~addNoteDialog();
}


void addNoteDialog::on_createNoteButton_clicked()
{
	if (addNoteDialogUi.noteTitleText->toPlainText() != "")
	{
		ThisDialogNote->setTitle(addNoteDialogUi.noteTitleText->toPlainText());
		ThisDialogNote->setType(addNoteDialogUi.noteTypeComboBox->currentText());
		ThisDialogNote->setText(addNoteDialogUi.noteTextText->toPlainText());
		ThisDialogNote->setEventTime(UtilityFunctions::repareTime(addNoteDialogUi.eventTimeEdit->text()));
		ThisDialogNote->setEventDate(addNoteDialogUi.eventDateEdit->text());
		
		if (DialogType == Add)
		{
			DbManager::addNote(ThisDialogNote);
		}

		if (DialogType == Edit)
		{
			if (EditingNoteId != -1)
			{
				DbManager::editNote(ThisDialogNote, EditingNoteId);
			}
		}

		//this->~addNoteDialog();
		this->close();
	}
	else
	{

	}
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
