#include "stdafx.h"
#include "NoteHolder.h"
#include "MattyGroupBox.h"
#include "MattyNote.h"
#include "DbManager.h"
#include "Constants.h"

int NoteHolder::NoteCount = 0;
QVector<class MattyNote> NoteHolder::ListOfNotes = QVector<class MattyNote>();
QVector<QString> NoteHolder::ListOfGroupBoxeNames = QVector<QString>();

NoteHolder::NoteHolder()
{
}


NoteHolder::~NoteHolder()
{
}

QVector<class MattyNote> NoteHolder::sortNotesByCrDate()
{
	NoteCount = 0;

	//QVector<QStringList> ListOfRows = DbManager::getAllNotesOrderByCrDate();

	QVector<QStringList> Filter;
	Filter.push_back({ "NoteType", QString::fromLocal8Bit("Работа") });

	QVector<QStringList> ListOfRows = DbManager::showNotes(Filter);

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

void NoteHolder::showNotes(int orderDirection, QVBoxLayout * ParentLayout)
{
	//getNotesOrderByCrDate();
	//qDeleteAll(ParentLayout->findChildren<QHBoxLayout*>("", Qt::FindDirectChildrenOnly));
	QLayoutItem *child;
	while ((child = ParentLayout->takeAt(0)) != 0) 
	{
			delete child;
	}
	QVector<class MattyNote>::iterator NoteNumber;
	int i;
	for (NoteNumber=ListOfNotes.begin(), i=0; NoteNumber < ListOfNotes.end();NoteNumber++, i++)
	{
		QString GroupBoxName = QString::number(NoteNumber->getNoteId());
		QHBoxLayout *HorizontalLayout;
		HorizontalLayout = new QHBoxLayout();  // указать родителя
		HorizontalLayout->setMargin(12);
		HorizontalLayout->setSpacing(6);
		HorizontalLayout->setStretch(0, 0);
		HorizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
		ParentLayout->addLayout(HorizontalLayout);
		HorizontalLayout->setParent(ParentLayout);
		MattyGroupBox* MyGroupBox = new MattyGroupBox(); // удалить delete
		//MyGroupBox->setParent(ParentLayout);
		MyGroupBox->fillFrame(*NoteNumber);
		HorizontalLayout->addWidget(MyGroupBox);
		MyGroupBox->setObjectName(GroupBoxName);
		HorizontalLayout->setObjectName("HorizontalLayoutExperiment" + QString::number(i + 1));
	}
}
