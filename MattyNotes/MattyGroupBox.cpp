#include "stdafx.h"
#include "MattyGroupBox.h"
#include "MattyNote.h"
#include "DbManager.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

MattyGroupBox::MattyGroupBox()
{
	buildFrame();
	QObject::connect(deleteNoteButton, SIGNAL(clicked()), this, SLOT(deleteNote()));
}

void MattyGroupBox::fillFrame(MattyNote & ThisNote)
{
	ThisGroupBoxNote = ThisNote;
	this->setTitle(ThisNote.getTitle());
	NoteTypeLabel->setText(ThisNote.getType());
	NoteTextLabel->setText(ThisNote.getText());
	NoteCrTimeAndDateLabel->setText(QString::fromLocal8Bit("Заметка создана: ")
		+ ThisNote.getCrTime() + " " + ThisNote.getCrDate());
	NoteEventTimeAndDateLabel->setText(ThisNote.getEventDate() + ", " + ThisNote.getEvDayofWeek() +  " " + ThisNote.getEventTime());

	this->setObjectName("MattyGroupBox");
	this->setStyleSheet("MattyGroupBox { background-color: #fada5c; "
		"background-repeat: no-repeat;"
		"background-position: bottom right;"
		"background-size: 10px;"
		"border: 1px solid transparent;"
		"border-radius: 10px;"
		"font-weight: bold;"
		"font-size: 14px;"
		"font-style: italic;"
		"color: #4d3f3d;"
		"padding-right: 50px;"
		"padding-top: 25px;"
		"padding-bottom: 25px;"
		"padding-left: 25px;}");
	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	this->setGraphicsEffect(effect);

	NoteTextLabel->setObjectName(QStringLiteral("NoteTextLabel") /*+ "#" + QString::number(ThisNote.getNoteId())*/);
	//NoteTextLabel->setStyleSheet("NoteTextLabel { padding-right: 150px;}");

	/*verticalLayout->setObjectName(QStringLiteral("verticalLayout") + "#" + QString::number(ThisNote.getNoteId()));
	horizontalLayout_1->setObjectName(QStringLiteral("HorizontalLayout_1") + "#" + QString::number(ThisNote.getNoteId()));
	horizontalLayout_2->setObjectName(QStringLiteral("HorizontalLayout_2") + "#" + QString::number(ThisNote.getNoteId()));
	gridLayout->setObjectName(QStringLiteral("gridLayout") + "#" + QString::number(ThisNote.getNoteId()));
	NoteTypeLabel->setObjectName(QStringLiteral("NoteTypeLabel") + "#" + QString::number(ThisNote.getNoteId()));
	NoteCrTimeAndDateLabel->setObjectName(QStringLiteral("NoteCrTimeAndDateLabel") + "#" + QString::number(ThisNote.getNoteId()));
	editNoteButton->setObjectName(QStringLiteral("editNoteButton") + "#" + QString::number(ThisNote.getNoteId()));
	//deleteNoteButton->setObjectName(QStringLiteral("deleteNoteButton") + "#" + QString::number(ThisNote.getNoteId()));
	NoteEventTimeAndDateLabel->setObjectName(QStringLiteral("NoteEventTimeAndDateLabel") + "#" + QString::number(ThisNote.getNoteId()));
	*/
}


void MattyGroupBox::buildFrame()
{
	//groupBox->setObjectName(QStringLiteral("groupBox"));
	this->setMinimumSize(QSize(150, 200));
	this->setStyleSheet(QStringLiteral("QGroupBox { background-color: rgb(255, 255, 222);"
	"border: 1px solid transparent;"
	"border-radius: 10px;}"));

	gridLayout = new QGridLayout(this);

	verticalLayout = new QVBoxLayout();
	verticalLayout->setSpacing(6);
	verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

	horizontalLayout_1 = new QHBoxLayout();
	horizontalLayout_2 = new QHBoxLayout();

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

	//NoteTitleLabel = new QLabel(this);
	//NoteTitleLabel->setObjectName(QStringLiteral("NoteTitleLabel"));
	//NoteTitleLabel->setText(QString::fromLocal8Bit("Заголовок"));

	NoteTypeLabel = new QLabel(this);
	NoteTypeLabel->setObjectName(QStringLiteral("NoteTypeLabel"));
	NoteTypeLabel->setText(QString::fromLocal8Bit("Тип"));

	NoteCrTimeAndDateLabel = new QLabel(this);
	NoteCrTimeAndDateLabel->setObjectName(QStringLiteral("NoteCrTimeAndDateLabel"));
	NoteCrTimeAndDateLabel->setText(QString::fromLocal8Bit("Создано: "));

	horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);

	editNoteButton = new QPushButton(this);
	editNoteButton->setObjectName(QStringLiteral("editNoteButton"));
	editNoteButton->setSizePolicy(sizePolicy);
	editNoteButton->setMaximumSize(QSize(20, 20));
	editNoteButton->setStyleSheet(QStringLiteral("background-image: url(:/MattyNotes/edit.png);"));
	editNoteButton->setFlat(true);

	deleteNoteButton = new QPushButton(this);
	//deleteNoteButton->setObjectName(QStringLiteral("deleteNoteButton"));
	deleteNoteButton->setSizePolicy(sizePolicy);
	deleteNoteButton->setMaximumSize(QSize(20, 20));
	deleteNoteButton->setStyleSheet(QStringLiteral("background-image: url(:/MattyNotes/1s-udalenie.png);"));
	deleteNoteButton->setFlat(true);

	//horizontalLayout_1->addWidget(NoteTitleLabel);
	horizontalLayout_1->addWidget(NoteTypeLabel);
	horizontalLayout_1->addWidget(NoteCrTimeAndDateLabel);
	horizontalLayout_1->addItem(horizontalSpacer_1);
	horizontalLayout_1->addWidget(editNoteButton);
	horizontalLayout_1->addWidget(deleteNoteButton);

	NoteEventTimeAndDateLabel = new QLabel(this);
	NoteEventTimeAndDateLabel->setObjectName(QStringLiteral("NoteEventTimeAndDateLabel"));
	NoteEventTimeAndDateLabel->setText(QString::fromLocal8Bit("Когда"));

	horizontalLayout_2->addWidget(NoteEventTimeAndDateLabel);

	horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout_2->addItem(horizontalSpacer_2);

	NoteTextLabel = new QLabel();
	NoteTextLabel->setObjectName(QStringLiteral("NoteTextLabel"));
	NoteTextLabel->setMinimumSize(QSize(0, 100));

	verticalLayout->addWidget(NoteTextLabel);
	NoteTextLabel->setText(QString::fromLocal8Bit("Текст"));
	NoteTextLabel->setWordWrap(true);

	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

	verticalLayout->addItem(verticalSpacer);

}

void MattyGroupBox::deleteNote()
{
	QMessageBox::StandardButton wantToDeleteNote;
	wantToDeleteNote = QMessageBox::question(this, QString::fromLocal8Bit("Удаление"), QString::fromLocal8Bit("Вы точно хотите удалить эту заметку?"),
		QMessageBox::Yes | QMessageBox::No);
	if (wantToDeleteNote == QMessageBox::Yes)
	{
		DbManager::deleteNote(ThisGroupBoxNote.getNoteId());
		this->hide();
	}
}


MattyGroupBox::~MattyGroupBox()
{
	//delete NoteTypeLabel;
	//delete NoteCrTimeAndDateLabel;
	//delete NoteEventTimeAndDateLabel;
	//delete NoteTextLabel;
	//delete horizontalSpacer_1;
	//delete horizontalSpacer_2;
	//delete verticalSpacer;
//	delete editNoteButton;
//	delete deleteNoteButton;
//	delete horizontalLayout_1;
//	delete horizontalLayout_2;
//	delete verticalLayout;
//	delete gridLayout;
}

