#include "stdafx.h"
#include "MattyGroupBox.h"
#include "MattyNote.h"
#include "DbManager.h"
#include "addnotedialog.h"
#include "mattymessagebox.h"
#include "NoteHolder.h"
#include "mattynotes.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

MattyGroupBox::MattyGroupBox(QWidget* parent)
{
	this->setParent(parent);
	buildFrame();
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
	NoteEventTimeAndDateLabel->setText(ThisNote.getEventDate() + ", " + ThisNote.getEvDayofWeek() +  " " + ThisNote.getEventTime());

}


void MattyGroupBox::buildFrame()
{
	//groupBox->setObjectName(QStringLiteral("groupBox"));
	this->setMinimumSize(QSize(50, 50));
	this->setObjectName(QStringLiteral("MattyGroupBox"));
	this->setStyleSheet(QStringLiteral("#MattyGroupBox { background-color: rgb(255, 255, 222);"
	"border: 1px solid transparent;"
	"border-radius: 10px;}"));

	//this->title(). //title().setWordWrap(true);

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
	editNoteButton->setMaximumSize(QSize(21, 21));
	editNoteButton->setStyleSheet(QStringLiteral("#editNoteButton  {  "
		"background-image: url(:/MattyNotes/EditNote.png);"
		"background-position: center; } "
		"#editNoteButton:hover{ "
		"background-image: url(:/MattyNotes/EditNoteHover.png);"
		"background-position: center; }"));
	editNoteButton->setFlat(true);

	deleteNoteButton = new QPushButton(this);
	deleteNoteButton->setObjectName(QStringLiteral("deleteNoteButton"));
	deleteNoteButton->setSizePolicy(sizePolicy);
	deleteNoteButton->setMaximumSize(QSize(21, 21));
	deleteNoteButton->setStyleSheet(QStringLiteral("#deleteNoteButton  {"
		"background-image: url(:/MattyNotes/DeleteNote.png);"
		"background-position: center; } "
		"#deleteNoteButton:hover{ "
		"background-image: url(:/MattyNotes/DeleteNoteHover.png);"
		"background-position: center; }"));
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

	horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

	horizontalLayout_2->addItem(horizontalSpacer_2);

	NoteTextLabel = new QLabel();
	NoteTextLabel->setObjectName(QStringLiteral("NoteTextLabel"));
	NoteTextLabel->setMinimumSize(QSize(0, 100));
	//NoteTextLabel->setStyleSheet(QStringLiteral("text - indent: 25px;"));

	verticalLayout->addWidget(NoteTextLabel);
	NoteTextLabel->setText(QString::fromLocal8Bit("Текст"));
	NoteTextLabel->setWordWrap(true);

	verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

	verticalLayout->addItem(verticalSpacer);

	this->setObjectName(QStringLiteral("MattyGroupBox"));
	this->setStyleSheet(QStringLiteral("MattyGroupBox { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 250, 97, 1), stop:1 rgba(255, 221, 97, 1)); "
		"background-repeat: no-repeat;"
		"background-position: bottom right;"
		"background-size: 10px;"
		"border: 1px solid transparent;"
		"border-radius: 10px;"
		"font-weight: bold;"
		"font-size: 14px;"
		"font-style: italic;"
		"color: #4d3f3d;"
		"padding-right: 25px;"
		"padding-top: 25px;"
		"padding-bottom: 25px;"
		"padding-left: 25px;"
		"font-family: Comic Sans MS; "
		"text-decoration: underline; }"
		/*"MattyGroupBox::title { padding-left: 35px;  }"*/
		"QLabel { font-family: Comic Sans MS; font-style: italic; }"
		"QLabel#NoteEventTimeAndDateLabel, QLabel#NoteTypeLabel { font-weight: bold;  }"));
	QGraphicsDropShadowEffect* GroupBoxShadow = new QGraphicsDropShadowEffect();
	GroupBoxShadow->setBlurRadius(25.0);
	QColor ShadowColor = QColor(77, 63, 61, 200);
	GroupBoxShadow->setColor(ShadowColor);
	GroupBoxShadow->setOffset(15, 15);
	this->setGraphicsEffect(GroupBoxShadow);

}

void MattyGroupBox::editNote()
{
	addNoteDialog* newAddNoteDialog = new addNoteDialog(Edit, ThisGroupBoxNote.getNoteId());
	newAddNoteDialog->setWindowModality(Qt::ApplicationModal);
	newAddNoteDialog->exec();
}

void MattyGroupBox::deleteNote()
{
	MattyMessageBox WantToDeleteNote(Question);
	WantToDeleteNote.setText(QString::fromLocal8Bit("Вы точно хотите удалить заметку \"") + ThisGroupBoxNote.getTitle() + "\"?");
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
		addNoteDialog* newAddNoteDialog = new addNoteDialog(Edit, ThisGroupBoxNote.getNoteId());
		newAddNoteDialog->setWindowModality(Qt::ApplicationModal);
		newAddNoteDialog->exec();
	}
}
