#include "stdafx.h"
#include "NoteGroupBoxHolder.h"
#include "MattyGroupBox.h"
#include "MattyNote.h"
#include "DbManager.h"

int NoteGroupBoxHolder::NoteCount = 0;
QVector<class MattyNote> NoteGroupBoxHolder::ListOfNotes = QVector<class MattyNote>();

NoteGroupBoxHolder::NoteGroupBoxHolder()
{
}


NoteGroupBoxHolder::~NoteGroupBoxHolder()
{
}

QVector<class MattyNote> NoteGroupBoxHolder::getNotesOrderByCrDate()
{
	NoteCount = 0;

	DbManager MattyNotesDbManager("MattyNotes.sqlite");

	QVector<QStringList> ListOfRows = MattyNotesDbManager.getAllNotesOrderByCrDate();

	if (!ListOfNotes.isEmpty())
		ListOfNotes.clear();

	for (int i = 0; i < ListOfRows.length();i++)
	{
		MattyNote TempNote(ListOfRows[i]);
		ListOfNotes.append(TempNote);
		NoteCount++;
	}

	return ListOfNotes;
}

void NoteGroupBoxHolder::showOrderByCrDate(int orderDirection, QVBoxLayout * ParentLayout)
{
	getNotesOrderByCrDate();
	QVector<class MattyNote>::iterator NoteNumber;
	int i;
	for (NoteNumber=ListOfNotes.begin(), i=0; NoteNumber < ListOfNotes.end();NoteNumber++, i++)
	{
		QString GroupBoxName = "NoteMattyGroupBox" + QString::number(i + 1);
		QHBoxLayout *HorizontalLayout;
		HorizontalLayout = new QHBoxLayout();
		HorizontalLayout->setSpacing(6);
		HorizontalLayout->setStretch(0, 0);
		HorizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
		ParentLayout->addLayout(HorizontalLayout);
		MattyGroupBox* MyGroupBox = new MattyGroupBox();
		MyGroupBox->fillFrame(*NoteNumber);
		HorizontalLayout->addWidget(MyGroupBox);
		MyGroupBox->setTitle(NoteNumber->getTitle());
		//MyGroupBox->setMaximumSize(QSize(2500, 300));
		MyGroupBox->setObjectName(GroupBoxName);
		HorizontalLayout->setObjectName("HorizontalLayoutExperiment" + QString::number(i + 1));
	}
}