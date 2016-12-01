#include "stdafx.h"
#include "mattynotes.h"
#include "MattyTime.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "addnotedialog.h"
#include "MattyGroupBox.h"
#include "NoteHolder.h"
#include "Constants.h"
#include "MattyClocks.h"

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
	ui.mainToolBar->setMovable(false);

	this->setWindowFlags(Qt::FramelessWindowHint);

	QObject::connect(closeWindowButton, SIGNAL(clicked()), this, SLOT(closeWindow()));
	QObject::connect(maximizeWindowButton, SIGNAL(clicked()), this,
		SLOT(maximizeWindow()));
	QObject::connect(minimizeWindowButton, SIGNAL(clicked()), this, SLOT(minimizeWindow()));

	addNoteButtonTemp = new QPushButton(this);
	addNoteButtonTemp->setObjectName(QStringLiteral("addNoteButtonTemp"));
	addNoteButtonTemp->setMinimumSize(QSize(51, 51));
	addNoteButtonTemp->setMaximumSize(QSize(51, 51));
	addNoteButtonTemp->setStyleSheet(QLatin1String("#addNoteButtonTemp { background-color: transparent;\n"
		"background-image: url(:/MattyNotes/AddNote.png);\n"
		"color: transparent;\n"
		"font-weight: bold;\n"
		"font-style: italic;\n"
		"font-family: Comic Sans MS; }\n"
		"#addNoteButtonTemp:hover { background-image: url(:/MattyNotes/AddNoteHoverWithPen.png); \n"
		"color: #6d6f6d; }"));

	refreshNoteList = new QPushButton(this);
	refreshNoteList->setObjectName(QStringLiteral("refreshNoteList"));
	refreshNoteList->setMinimumSize(QSize(51, 51));
	refreshNoteList->setMaximumSize(QSize(51, 51));
	refreshNoteList->setStyleSheet(QLatin1String("#refreshNoteList { background-color: transparent;\n"
		"background-image: url(:/MattyNotes/RefreshNoteList.png);\n"
		"color: transparent;\n"
		"font-weight: bold;\n"
		"font-style: italic;\n"
		"font-family: Comic Sans MS; }\n"
		"#refreshNoteList:hover { background-image: url(:/MattyNotes/RefreshNoteListHover.png); \n"
		"color: #6d6f6d; }"));

	MattyToolBar = new QToolBar(this);
	MattyToolBar->setObjectName(QStringLiteral("MattyToolBar"));
	MattyToolBar->setFloatable(false);
	this->addToolBar(Qt::BottomToolBarArea, MattyToolBar);
	Qt::ToolBarAreas MattyToolBarAreas;
	MattyToolBarAreas.setFlag(Qt::BottomToolBarArea);
	MattyToolBarAreas.setFlag(Qt::LeftToolBarArea);
	MattyToolBarAreas.setFlag(Qt::RightToolBarArea);
	MattyToolBarAreas.setFlag(Qt::TopToolBarArea);
	MattyToolBar->setAllowedAreas(MattyToolBarAreas);
	QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect(MattyToolBar);
	opacity->setOpacity(0.50); // #0 to 1 will cause the fade effect to kick in
	MattyToolBar->setGraphicsEffect(opacity);
	MattyToolBar->setAutoFillBackground(true);
	MattyToolBar->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 127); "));

	/*QLCDNumber *ClocksLcdNumber;
	ClocksLcdNumber = new QLCDNumber(ui.statusBar);
	ClocksLcdNumber->setObjectName(QStringLiteral("ClocksLcdNumber"));
	ClocksLcdNumber->setStyleSheet(QStringLiteral("color: black;"));
	MattyToolBar->addWidget(ClocksLcdNumber);
	ClocksLcdNumber->display(MattyTime::PrintCurrTime());*/

	MattyClocks* MainClocks = new MattyClocks(this);
	MattyToolBar->addWidget(MainClocks);

	QWidget* spacer3 = new QWidget();
	spacer3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	MattyToolBar->addWidget(spacer3);
	MattyToolBar->addWidget(refreshNoteList);
	MattyToolBar->addWidget(addNoteButtonTemp);

	QObject::connect(addNoteButtonTemp, SIGNAL(clicked()), this, SLOT(on_addNoteButtonTemp_clicked()));
	QObject::connect(refreshNoteList, SIGNAL(clicked()), this, SLOT(on_refreshNoteList_clicked()));
	//QObject::connect()
	
	NoteHolder::publishNotes(ui.scrollAreaWidgetContents);
}


MattyNotes::~MattyNotes()
{

}

void MattyNotes::on_addNoteButtonTemp_clicked()
{
	addNoteDialog* newAddNoteDialog = new addNoteDialog(Add, ui.scrollAreaWidgetContents);
	newAddNoteDialog->setWindowModality(Qt::ApplicationModal); 
	newAddNoteDialog->show();
	//newAddNoteDialog->bu
	// ����� �� ������� ������ �������� ������� ���������� � �������� �������
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

void MattyNotes::on_refreshNoteList_clicked()
{
	NoteHolder::publishNotes(ui.scrollAreaWidgetContents);
}

void MattyNotes::mousePressEvent(QMouseEvent *event) 
{
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
}

void MattyNotes::mouseMoveEvent(QMouseEvent *event) 
{
	move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}