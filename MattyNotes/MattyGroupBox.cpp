#include "stdafx.h"
#include "MattyGroupBox.h"
#include "MattyNote.h"
#include "DbManager.h"
#include "addnotedialog.h"
#include "mattymessagebox.h"
#include "NoteHolder.h"
#include "mattynotesmainwindow.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

MattyGroupBox::MattyGroupBox(class MattyNote & ThisNote, QWidget* parent)
	: QGroupBox(parent)
{
	this->setParent(parent);
	buildFrame();
	fillFrame(ThisNote);
	QObject::connect(deleteNoteButton, SIGNAL(clicked()), this, SLOT(deleteNote()));
	QObject::connect(editNoteButton, SIGNAL(clicked()), this, SLOT(editNote()));
}

void MattyGroupBox::fillFrame(MattyNote & ThisNote)
{
	ThisGroupBoxNote = ThisNote;
	this->setTitle(ThisNote.getTitle());
	NoteTypeLabel->setText(ThisNote.getType());
	NoteTextLabel->setText(ThisNote.getText());
	NoteCrTimeAndDateLabel->setText(QString::fromLocal8Bit("Заметка создана: ")
		+ ThisNote.getCrDate() + " " + ThisNote.getCrTime() );
	NoteEventTimeAndDateLabel->setText(ThisNote.getEventDate() +  " " + ThisNote.getEventTime());

}


void MattyGroupBox::buildFrame()
{
	this->setMinimumSize(QSize(50, 50));
	this->setObjectName(QStringLiteral("MattyGroupBox"));

	//this->title(). //title().setWordWrap(true);

	gridLayout = new QGridLayout(this);

	verticalLayout = new QVBoxLayout(this);
	verticalLayout->setSpacing(6);
	verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

	horizontalLayout_1 = new QHBoxLayout(this);
	horizontalLayout_2 = new QHBoxLayout(this);

	horizontalLayout_1->setSpacing(6);
	horizontalLayout_1->setObjectName(QStringLiteral("HorizontalLayout_1"));

	horizontalLayout_2->setSpacing(6);
	horizontalLayout_2->setObjectName(QStringLiteral("HorizontalLayout_2"));

	verticalLayout->addLayout(horizontalLayout_1);
	verticalLayout->addLayout(horizontalLayout_2);

	gridLayout->setSpacing(6);
	gridLayout->setContentsMargins(11, 11, 11, 11);
	gridLayout->setObjectName(QStringLiteral("gridLayout"));
	gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

	NoteTypeLabel = new QLabel(this);
	NoteTypeLabel->setObjectName(QStringLiteral("NoteTypeLabel"));
	NoteTypeLabel->setText(QString::fromLocal8Bit("Тип"));

	NoteCrTimeAndDateLabel = new QLabel(this);
	NoteCrTimeAndDateLabel->setObjectName(QStringLiteral("NoteCrTimeAndDateLabel"));
	NoteCrTimeAndDateLabel->setText(QString::fromLocal8Bit("Создано: "));

	horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum); // needtodelete

	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);

	editNoteButton = new QPushButton(this);
	editNoteButton->setObjectName(QStringLiteral("editNoteButton"));
	editNoteButton->setSizePolicy(sizePolicy);
	editNoteButton->setMaximumSize(QSize(21, 21));
	editNoteButton->setFlat(true);

	deleteNoteButton = new QPushButton(this);
	deleteNoteButton->setObjectName(QStringLiteral("deleteNoteButton"));
	deleteNoteButton->setSizePolicy(sizePolicy);
	deleteNoteButton->setMaximumSize(QSize(21, 21));
	deleteNoteButton->setFlat(true);

	NoteEventTimeAndDateLabel = new QLabel(this);
	NoteEventTimeAndDateLabel->setObjectName(QStringLiteral("NoteEventTimeAndDateLabel"));
	NoteEventTimeAndDateLabel->setText(QString::fromLocal8Bit("Когда"));

	horizontalLayout_1->addWidget(NoteTypeLabel);
	horizontalLayout_1->addWidget(NoteEventTimeAndDateLabel);
	horizontalLayout_1->addItem(horizontalSpacer_1);
	horizontalLayout_1->addWidget(editNoteButton);
	horizontalLayout_1->addWidget(deleteNoteButton);

	horizontalLayout_2->addWidget(NoteCrTimeAndDateLabel);

	horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum); // needtodelete

	horizontalLayout_2->addItem(horizontalSpacer_2);

	NoteTextLabel = new QLabel(this);
	NoteTextLabel->setObjectName(QStringLiteral("NoteTextLabel"));
	NoteTextLabel->setMinimumSize(QSize(0, 100));

	verticalLayout->addWidget(NoteTextLabel);
	NoteTextLabel->setText(QString::fromLocal8Bit("Текст"));
	NoteTextLabel->setWordWrap(true);

	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding); // needtodelete

	verticalLayout->addItem(verticalSpacer);

	QGraphicsDropShadowEffect* GroupBoxShadow = new QGraphicsDropShadowEffect(this);
	GroupBoxShadow->setBlurRadius(25.0);
	QColor ShadowColor = QColor(77, 63, 61, 200);
	GroupBoxShadow->setColor(ShadowColor);
	GroupBoxShadow->setOffset(15, 15);
	this->setGraphicsEffect(GroupBoxShadow);

}

void MattyGroupBox::editNote()
{
	addNoteDialog* newAddNoteDialog = new addNoteDialog(Edit, ThisGroupBoxNote.getNoteId()); // needtodelete
	newAddNoteDialog->setWindowModality(Qt::ApplicationModal);
	newAddNoteDialog->exec();
}

void MattyGroupBox::deleteNote()
{
	MattyMessageBox WantToDeleteNote(Question);
	WantToDeleteNote.setText(QString::fromLocal8Bit("\n\nВы точно хотите удалить заметку \n\"") + ThisGroupBoxNote.getTitle() + "\"?");
	WantToDeleteNote.setFixedWidth(150);

	int answer = WantToDeleteNote.exec();
	if (answer == QMessageBox::Yes)
	{
		DbManager::deleteNote(ThisGroupBoxNote.getNoteId());
		this->~MattyGroupBox();
	}
}

void MattyGroupBox::mouseDoubleClickEvent(QMouseEvent * e)
{
	if (e->button() == Qt::LeftButton)
	{
		addNoteDialog* newAddNoteDialog = new addNoteDialog(Edit, ThisGroupBoxNote.getNoteId()); // needtodelete
		newAddNoteDialog->setWindowModality(Qt::ApplicationModal);
		newAddNoteDialog->exec();
	}
}
