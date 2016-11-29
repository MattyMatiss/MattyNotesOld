#include "stdafx.h"
#include "NoteHolder.h"
#include "MattyGroupBox.h"
#include "MattyNote.h"
#include "DbManager.h"
#include "Constants.h"

int NoteHolder::TotalNoteCount = 0;
QVector<class MattyNote> NoteHolder::ListOfAllNotes = QVector<class MattyNote>();
QVector<QString> NoteHolder::ListOfGroupBoxeNames = QVector<QString>();

NoteHolder::NoteHolder()
{
}


NoteHolder::~NoteHolder()
{
}

void NoteHolder::sortNotesByCrDate()
{
}

void NoteHolder::publishNotes(int orderDirection, QVBoxLayout * ParentLayout)
{
	erasePublishedNotes(ParentLayout);

	getAllNotes();
	
	QVector<class MattyNote>::iterator NoteNumber;
	int i;
	for (NoteNumber = ListOfAllNotes.begin(), i=0; NoteNumber < ListOfAllNotes.end();NoteNumber++, i++)
	{
		QHBoxLayout *HorizontalLayout;
		HorizontalLayout = new QHBoxLayout();
		HorizontalLayout->setParent(ParentLayout);
		HorizontalLayout->setMargin(12);
		HorizontalLayout->setSpacing(6);
		HorizontalLayout->setStretch(0, 0);
		//HorizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
		ParentLayout->addLayout(HorizontalLayout);

		MattyGroupBox* MyGroupBox = new MattyGroupBox(); // удалить delete или поставить родителя (только виджет)
		QString GroupBoxName = QString::number(NoteNumber->getNoteId());
		MyGroupBox->fillFrame(*NoteNumber);

		HorizontalLayout->addWidget(MyGroupBox);
		MyGroupBox->setObjectName(GroupBoxName);
		HorizontalLayout->setObjectName("HorizontalLayoutExperiment" + QString::number(i + 1));
	}
}

void NoteHolder::setFilters()
{
}

void NoteHolder::getAllNotes()
{
	TotalNoteCount = 0;

	QVector<QStringList> ListOfRows = DbManager::showNotes();

	if (!ListOfAllNotes.isEmpty())
		ListOfAllNotes.clear();

	for (int i = 0; i < ListOfRows.length();i++)
	{
		MattyNote TempNote(ListOfRows[i]);
		ListOfAllNotes.append(TempNote);
		TotalNoteCount++;
	}
}

void NoteHolder::getSelectedNotes() // пока не отичается от getAllNotes()
{
	TotalNoteCount = 0;

	QMap<QString, QString> Filter; // это потом заменить на метод, обрабатывающий запросы пользователя на сортировку

	QVector<QStringList> ListOfRows = DbManager::showNotes(Filter);

	if (!ListOfAllNotes.isEmpty())
		ListOfAllNotes.clear();

	for (int i = 0; i < ListOfRows.length();i++)
	{
		MattyNote TempNote(ListOfRows[i]);
		ListOfAllNotes.append(TempNote);
		TotalNoteCount++;
	}
}

void NoteHolder::erasePublishedNotes(QVBoxLayout * ParentLayout)
{
	QLayoutItem *child;
	while ((child = ParentLayout->takeAt(0)) != 0)
	{
		delete child;
	}
}
