#include "stdafx.h"
#include "mattynotes.h"
#include "MattyTime.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "addnotedialog.h"
#include "MattyGroupBox.h"
#include "NoteHolder.h"
#include "Constants.h"

MattyNotes::MattyNotes(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	Constants::setPathToDb(Relative);
	DbManager::connect(Constants::PathToDb);

	closeWindowButton = new QPushButton();
	closeWindowButton->setObjectName("closeWindowButton");
	closeWindowButton->setStyleSheet(QStringLiteral("QPushButton { background-image: url(:/MattyNotes/CloseWindow.png);"
		"background-position: center;}"
" QPushButton:hover { background-image: url(:/MattyNotes/CloseWindowHover.png);background-position: center; }"));
	closeWindowButton->setMaximumSize(QSize(20, 20));
	closeWindowButton->setFlat(true);

	maximizeWindowButton = new QPushButton();
	maximizeWindowButton->setObjectName("maximazeWindowButton");
	maximizeWindowButton->setStyleSheet(QStringLiteral("QPushButton { background-image: url(:/MattyNotes/MaximizeWindow.png);"
		"background-position: top;}"
		" QPushButton:hover { background-image: url(:/MattyNotes/MaximizeWindowHover.png);background-position: top; }"));
	maximizeWindowButton->setMaximumSize(QSize(20, 20));
	maximizeWindowButton->setFlat(true);

	minimizeWindowButton = new QPushButton();
	minimizeWindowButton->setObjectName("minimizeWindowButton");
	minimizeWindowButton->setStyleSheet(QStringLiteral("QPushButton { background-image: url(:/MattyNotes/MinimizeWindow.png);"
		"background-position: center;}"
		" QPushButton:hover { background-image: url(:/MattyNotes/MinimizeWindowHover.png);background-position: center; }"));
	minimizeWindowButton->setMaximumSize(QSize(20, 20));
	minimizeWindowButton->setFlat(true);

	QWidget* spacer1 = new QWidget();
	spacer1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QWidget* spacer2 = new QWidget();
	spacer2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	header = new QLabel();
	header->setText("MattyNotes");
	header->setStyleSheet("QLabel { color: black; font-style: italic; font-size: 16px;}");

	ui.mainToolBar->addWidget(spacer1);
	ui.mainToolBar->addWidget(header);
	ui.mainToolBar->addWidget(spacer2);
	ui.mainToolBar->addWidget(minimizeWindowButton);
	ui.mainToolBar->addWidget(maximizeWindowButton);
	ui.mainToolBar->addWidget(closeWindowButton);

	this->setWindowFlags(Qt::FramelessWindowHint);

	// 
	/*QSizePolicy sp_retain = ui.calendarWidget->sizePolicy();
	sp_retain.setRetainSizeWhenHidden(true);
	ui.calendarWidget->setSizePolicy(sp_retain);
	ui.calendarWidget->hide();*/

	QLCDNumber *ClocksLcdNumber;
	ClocksLcdNumber = new QLCDNumber(ui.statusBar);
	ClocksLcdNumber->setObjectName(QStringLiteral("ClocksLcdNumber"));
	ClocksLcdNumber->setStyleSheet(QStringLiteral("color: black;"));
	ui.statusBar->addWidget(ClocksLcdNumber);
	ClocksLcdNumber->display(MattyTime::PrintCurrTime());

	NoteHolder::sortNotesByCrDate();
	NoteHolder::showNotes(0, ui.verticalLayout_4);

	QObject::connect(closeWindowButton, SIGNAL(clicked()), this, SLOT(closeWindow()));
	QObject::connect(maximizeWindowButton, SIGNAL(clicked()), this,
		SLOT(maximizeWindow()));
	QObject::connect(minimizeWindowButton, SIGNAL(clicked()), this, SLOT(minimizeWindow()));

	//QString moduleName = GetModuleFileName(NULL, szFileName, MAX_PATH);
	//if(moduleName.ToLower.Contains("qtagent"))

}


MattyNotes::~MattyNotes()
{

}

/*void MattyNotes::on_pushButtonCalendar_clicked()
{
	if (!ui.calendarWidget->isVisible())
		ui.calendarWidget->show();
	else
		ui.calendarWidget->hide();
}*/

void MattyNotes::on_addNoteButton_clicked()
{
	addNoteDialog* newAddNoteDialog = new addNoteDialog(ui.verticalLayout_4);
	newAddNoteDialog->setWindowModality(Qt::ApplicationModal); 
	newAddNoteDialog->show();
}

void MattyNotes::closeWindow()
{
	QApplication::quit();
}

void MattyNotes::maximizeWindow()
{
	if (this->isMaximized())
		this->showNormal();
	else
		this->showMaximized();
}

void MattyNotes::minimizeWindow()
{
	this->showMinimized();
}

/*void MattyNotes::on_closeProgramButton_clicked()
{
	this->close();
}*/

void MattyNotes::mousePressEvent(QMouseEvent *event) 
{
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
}

void MattyNotes::mouseMoveEvent(QMouseEvent *event) 
{
	move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}