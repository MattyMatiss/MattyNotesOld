#include "stdafx.h"
#include "MattyGroupBox.h"
//#include "MattyNote.h"


MattyGroupBox::MattyGroupBox()
{
	buildFrame();
}

//void MattyGroupBox::fillFrame(MattyNote & ThisNote)
//{
	//NoteTitleLabel->setText(ThisNote.getTitle());
	//NoteTypeLabel->setText(ThisNote.getType());
	//NoteTextLabel->setText(ThisNote.getText());

	//NoteTitleLabel->setText(QString::fromLocal8Bit("Заголовок"));
	//NoteTypeLabel->setText(QString::fromLocal8Bit("Тип"));
	//NoteCrTimeAndDateLabel->setText(QString::fromLocal8Bit("Создано: ")); // append!
	//NoteEventTimeAndDateLabel->setText(QString::fromLocal8Bit("Когда"));
	//NoteTextLabel->setText(QString::fromLocal8Bit("Текст"));

//}

void MattyGroupBox::buildFrame()
{
	//groupBox->setObjectName(QStringLiteral("groupBox"));
	this->setMinimumSize(QSize(150, 200));
	this->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

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

	NoteTitleLabel = new QLabel(this);
	NoteTitleLabel->setObjectName(QStringLiteral("NoteTitleLabel"));
	NoteTitleLabel->setText(QString::fromLocal8Bit("Заголовок"));

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
	deleteNoteButton->setObjectName(QStringLiteral("deleteNoteButton"));
	deleteNoteButton->setSizePolicy(sizePolicy);
	deleteNoteButton->setMaximumSize(QSize(20, 20));
	deleteNoteButton->setStyleSheet(QStringLiteral("background-image: url(:/MattyNotes/1s-udalenie.png);"));
	deleteNoteButton->setFlat(true);

	horizontalLayout_1->addWidget(NoteTitleLabel);
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

MattyGroupBox::~MattyGroupBox()
{
	delete NoteTitleLabel;
	delete NoteTypeLabel;
	delete NoteCrTimeAndDateLabel;
	delete NoteEventTimeAndDateLabel;
	delete NoteTextLabel;
	delete horizontalSpacer_1;
	delete horizontalSpacer_2;
	delete verticalSpacer;
	delete editNoteButton;
	delete deleteNoteButton;
	delete horizontalLayout_1;
	delete horizontalLayout_2;
	delete verticalLayout;
	delete gridLayout;
}

