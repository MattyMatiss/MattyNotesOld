#include "stdafx.h"
#include "NoteHolder.h"
#include "MattyGroupBox.h"
#include "MattyNote.h"
#include "DbManager.h"
#include "Constants.h"

int NoteHolder::TotalNoteCount = 0;
QVector<class MattyNote> NoteHolder::ListOfAllNotes = QVector<class MattyNote>();
QVector<QString> NoteHolder::ListOfGroupBoxeNames = QVector<QString>();
QVector<MattyGroupBox*> NoteHolder::ListofGroupBoxes = QVector<MattyGroupBox*>();

NoteHolder::NoteHolder()
{
}


NoteHolder::~NoteHolder()
{
}

void NoteHolder::sortNotesByCrDate()
{
}

void NoteHolder::publishNotes(QWidget* ParentWidget)
{
	erasePublishedNotes(ParentWidget);

	getAllNotes();
	
	QVector<class MattyNote>::iterator NoteNumber;
	int i;
	for (NoteNumber = ListOfAllNotes.begin(), i=0; NoteNumber < ListOfAllNotes.end();NoteNumber++, i++)
	{
		if (!ListofGroupBoxes.empty())
			ListofGroupBoxes.clear();

		QHBoxLayout *HorizontalLayout;
		HorizontalLayout = new QHBoxLayout();
		HorizontalLayout->setMargin(12);
		HorizontalLayout->setSpacing(6);
		HorizontalLayout->setStretch(0, 0);
		HorizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

		//ParentWidget->layou->insertLayout(0, HorizontalLayout);

		/*MattyGroupBox* MyGroupBox = new MattyGroupBox(); // ������� delete ��� ��������� �������� (������ ������)
		QString GroupBoxName = QString::number(NoteNumber->getNoteId());
		MyGroupBox->fillFrame(*NoteNumber);

		ListofGroupBoxes.push_back(MyGroupBox);
		HorizontalLayout->addWidget(MyGroupBox);
		//MyGroupBox->setObjectName(GroupBoxName);
		HorizontalLayout->setObjectName("HorizontalLayoutExperiment" + QString::number(i + 1));
		QObject* MgbParent = MyGroupBox->parent();*/

		MattyGroupBox* MyGroupBox = new MattyGroupBox(ParentWidget);
		MyGroupBox->fillFrame(*NoteNumber);
		// ��� ������ �������� ������� ���� �� ������, ����. ������� �������� ������
		ParentWidget->layout()->addWidget(MyGroupBox);

	}
}

void NoteHolder::setFilters()
{
}

void NoteHolder::getAllNotes()
{
	TotalNoteCount = 0;

	if (!ListOfAllNotes.isEmpty())
		ListOfAllNotes.clear();

	QVector<QStringList> ListOfRows = DbManager::showNotes();

	for (int i = 0; i < ListOfRows.length();i++)
	{
		MattyNote TempNote(ListOfRows[i]);
		ListOfAllNotes.append(TempNote);
		TotalNoteCount++;
	}
}

void NoteHolder::getSelectedNotes() // ���� �� ��������� �� getAllNotes()
{
	TotalNoteCount = 0;

	QMap<QString, QString> Filter; // ��� ����� �������� �� �����, �������������� ������� ������������ �� ����������

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

void NoteHolder::erasePublishedNotes(QWidget* ParentWidget)
{
	MattyGroupBox* MgbTemp;
	while ((MgbTemp = ParentWidget->findChild<MattyGroupBox*>()) != 0)
	{
		delete MgbTemp;
	}

	QGroupBox* GbTemp;
	while ((GbTemp = ParentWidget->findChild<QGroupBox*>()) != 0)
	{
		delete GbTemp;
	}
}

