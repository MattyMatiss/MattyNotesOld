#include "stdafx.h"
#include "mattynotesmainwindow.h"
#include "DbManager.h"
#include "MattyNote.h"
#include "addnotedialog.h"
#include "MattyGroupBox.h"
#include "NoteHolder.h"
#include "Constants.h"
#include "MattyClocks.h"
#include "MattySettingsDialog.h"
#include "MattyStyleSheetEditor.h"

MattyNotesMainWindow::MattyNotesMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setContextMenuPolicy(Qt::NoContextMenu);

	connectToDb();

	buildBody();

	buildMainToolBar();

	buildMattyToolBar();

	setActions();

	setConnects();
	
	refreshMainWindow();
}

void MattyNotesMainWindow::addNote()
{
	addNoteDialog newAddNoteDialog(Add);

	if (!newAddNoteDialog.exec())
	{
		NoteHolder::publishNotes(scrollAreaWidgetContents);
	}
}

void MattyNotesMainWindow::closeWindow()
{
	QApplication::quit();
}

void MattyNotesMainWindow::maximizeWindow()
{
	if (this->isMaximized())
		this->showNormal();
	else
		this->showMaximized();
}

void MattyNotesMainWindow::minimizeWindow()
{
	this->showMinimized();
}

void MattyNotesMainWindow::refreshMainWindow()
{
	MattyStyleSheetEditor::refreshTheme();
	NoteHolder::publishNotes(scrollAreaWidgetContents);
}

void MattyNotesMainWindow::openSettings()
{
	MattySettingsDialog newMattySettingsDialog;
	newMattySettingsDialog.setWindowModality(Qt::ApplicationModal);
	newMattySettingsDialog.exec();
}

void MattyNotesMainWindow::resizeMattyToolbarButtons()
{
	if (MattyToolBar->orientation() == Qt::Vertical)
	{
		AddNoteButton->setFixedSize(QSize(70, 51));
		RefreshNoteListButton->setFixedSize(QSize(70, 51));
		SettingsButton->setFixedSize(QSize(51, 51));
	}
	else
	{
		AddNoteButton->setFixedSize(QSize(51, 51));
		RefreshNoteListButton->setFixedSize(QSize(51, 51));
		SettingsButton->setFixedSize(QSize(51, 51));
	}
}

void MattyNotesMainWindow::mousePressEvent(QMouseEvent *event)
{
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
}

void MattyNotesMainWindow::mouseMoveEvent(QMouseEvent *event)
{
	move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}

void MattyNotesMainWindow::connectToDb(QString & PathToDb)
{
	if (PathToDb == "")
		Constants::setPathToDb(Relative);
	else
		Constants::setPathToDb(PathToDb);

	DbManager::connect(Constants::PathToDb);
}

void MattyNotesMainWindow::buildBody()
{
	gridLayout_4 = new QGridLayout(ui.centralWidget);
	gridLayout_4->setSpacing(6);
	//gridLayout_4->setContentsMargins(11, 11, 11, 11);
	gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));

	splitter = new QSplitter(ui.centralWidget);
	splitter->setObjectName(QStringLiteral("splitter"));
	splitter->setOrientation(Qt::Horizontal);

	LeftSide = new QWidget(splitter);
	LeftGridLayout = new QGridLayout;
	LeftSide->setLayout(LeftGridLayout);
	splitter->addWidget(LeftSide);
	LeftSide->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	LeftSide->setObjectName(QStringLiteral("LeftSide"));

	RightSide = new QWidget(splitter);
	RightGridLayout = new QGridLayout;
	RightSide->setLayout(RightGridLayout);
	splitter->addWidget(RightSide);
	RightSide->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	RightSide->setObjectName(QStringLiteral("RightSide"));

	MotivatorLabel = new QLabel(LeftSide);
	MotivatorLabel->setText(QString::fromLocal8Bit("Мокко-фраппе Ингредиенты на 1 порцию: 1 ст.ложка кофе тонкого помола, "
		"100 мл горячего шоколада, "
		"100 мл молока, "
		"15 мл шоколадного сиропа, " 
		"тертый шоколад, "
		"взбитые сливки."));
	MotivatorLabel->setObjectName(QStringLiteral("MotivatorLabel"));
	MotivatorLabel->setMinimumSize(QSize(250, 0));
	MotivatorLabel->setMaximumSize(QSize(250, 16777215));
	MotivatorLabel->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignTop);
	MotivatorLabel->setWordWrap(true);

	LeftGridLayout->addWidget(MotivatorLabel);

	scrollArea = new QScrollArea(RightSide);
	scrollArea->setObjectName(QStringLiteral("scrollArea"));
	scrollArea->setWidgetResizable(true);
	scrollAreaWidgetContents = new QWidget(scrollArea);
	scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
	scrollAreaWidgetContents->setGeometry(QRect(0, 0, 426, 480));
	gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
	gridLayout_2->setSpacing(6);
	gridLayout_2->setContentsMargins(11, 11, 11, 11);
	gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
	scrollArea->setWidget(scrollAreaWidgetContents);

	NoteOptionsWidget = new QWidget(scrollArea);
	NoteOptionsWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	NoteOptionsWidget->setFixedHeight(100);
	NoteOptionsWidget->setObjectName(QStringLiteral("NoteOptionsWidget"));
	RightGridLayout->addWidget(NoteOptionsWidget);
	RightGridLayout->addWidget(scrollArea);

	opacity = new QGraphicsOpacityEffect(NoteOptionsWidget);
	NoteOptionsWidget->setGraphicsEffect(opacity);
	NoteOptionsWidget->setAutoFillBackground(true);

	gridLayout_4->addWidget(splitter, 0, 0, 1, 1);

	menuBar = new QMenuBar(this);
	menuBar->setObjectName(QStringLiteral("menuBar"));
	menuBar->setGeometry(QRect(0, 0, 768, 21));
	this->setMenuBar(menuBar);
	mainToolBar = new QToolBar(this);
	mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
	this->addToolBar(Qt::TopToolBarArea, mainToolBar);
	statusBar = new QStatusBar(this);
	statusBar->setObjectName(QStringLiteral("statusBar"));
	statusBar->setMinimumSize(QSize(0, 0));
	this->setStatusBar(statusBar);

	splitter->setStretchFactor(0, 1);
	splitter->setStretchFactor(1, 5);

}

void MattyNotesMainWindow::buildMainToolBar()
{
	CloseWindowButton = new QPushButton(mainToolBar);
	CloseWindowButton->setObjectName("CloseWindowButton");
	CloseWindowButton->setMaximumSize(QSize(20, 20));
	CloseWindowButton->setFlat(true);

	MaximizeWindowButton = new QPushButton(mainToolBar);
	MaximizeWindowButton->setObjectName("MaximizeWindowButton");
	MaximizeWindowButton->setMaximumSize(QSize(20, 20));
	MaximizeWindowButton->setFlat(true);

	MinimizeWindowButton = new QPushButton(mainToolBar);
	MinimizeWindowButton->setObjectName("MinimizeWindowButton");
	MinimizeWindowButton->setMaximumSize(QSize(20, 20));
	MinimizeWindowButton->setFlat(true);

	MainToolBarSpacerLeft = new QWidget(mainToolBar);
	MainToolBarSpacerLeft->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	MainToolBarSpacerRight = new QWidget(mainToolBar);
	MainToolBarSpacerRight->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	WindowHeaderLabel = new QLabel(mainToolBar);
	WindowHeaderLabel->setObjectName(QStringLiteral("WindowHeaderLabel"));
	WindowHeaderLabel->setText("MattyNotes");

	mainToolBar->setObjectName(QStringLiteral("MainToolBar"));
	mainToolBar->addWidget(MainToolBarSpacerLeft);
	mainToolBar->addWidget(WindowHeaderLabel);
	mainToolBar->addWidget(MainToolBarSpacerRight);
	mainToolBar->addWidget(MinimizeWindowButton);
	mainToolBar->addWidget(MaximizeWindowButton);
	mainToolBar->addWidget(CloseWindowButton);
	mainToolBar->setMovable(false);
}

void MattyNotesMainWindow::buildMattyToolBar()
{
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
	opacity = new QGraphicsOpacityEffect(MattyToolBar);
	opacity->setOpacity(0.50); // #0 to 1 will cause the fade effect to kick in
	MattyToolBar->setGraphicsEffect(opacity);
	MattyToolBar->setAutoFillBackground(true);

	AddNoteButton = new QPushButton(this->MattyToolBar);
	AddNoteButton->setObjectName(QStringLiteral("AddNoteButton"));
	AddNoteButton->setFixedSize(QSize(51, 51));

	RefreshNoteListButton = new QPushButton(this->MattyToolBar);
	RefreshNoteListButton->setObjectName(QStringLiteral("RefreshNoteListButton"));
	RefreshNoteListButton->setFixedSize(QSize(51, 51));

	SettingsButton = new QPushButton(this->MattyToolBar);
	SettingsButton->setObjectName(QStringLiteral("SettingsButton"));
	SettingsButton->setFixedSize(QSize(51, 51));

	MainClocks = new MattyClocks(this->MattyToolBar);
	MattyToolBar->addWidget(MainClocks);

	MattyToolBarMainSpacer = new QWidget(this->MattyToolBar);
	MattyToolBarMainSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	MattyToolBar->addWidget(SettingsButton);
	MattyToolBar->addWidget(MattyToolBarMainSpacer);
	MattyToolBar->addWidget(RefreshNoteListButton);
	MattyToolBar->addWidget(AddNoteButton);
}


void MattyNotesMainWindow::setActions()
{
	closeMainWindow = new QAction(this);
	closeMainWindow->setShortcut(tr("CTRL+Q"));
	this->addAction(closeMainWindow);

	addNewNote = new QAction(this);
	addNewNote->setShortcut(tr("ALT+N"));
	this->addAction(addNewNote);

	RefreshMainWindow = new QAction(this);
	RefreshMainWindow->setShortcut(tr("F5"));
	this->addAction(RefreshMainWindow);
}

inline void MattyNotesMainWindow::setConnects()
{
	QObject::connect(CloseWindowButton, SIGNAL(clicked()), this, SLOT(closeWindow()));
	QObject::connect(MaximizeWindowButton, SIGNAL(clicked()), this,	SLOT(maximizeWindow()));
	QObject::connect(MinimizeWindowButton, SIGNAL(clicked()), this, SLOT(minimizeWindow()));
	QObject::connect(AddNoteButton, SIGNAL(clicked()), this, SLOT(addNote()));
	QObject::connect(RefreshNoteListButton, SIGNAL(clicked()), this, SLOT(refreshMainWindow()));
	QObject::connect(SettingsButton, SIGNAL(clicked()), this, SLOT(openSettings()));
	QObject::connect(closeMainWindow, SIGNAL(triggered()), this, SLOT(close()));
	QObject::connect(addNewNote, SIGNAL(triggered()), this, SLOT(addNote()));
	QObject::connect(RefreshMainWindow, SIGNAL(triggered()), this, SLOT(refreshMainWindow()));
	//QObject::connect(MattyToolBar, SIGNAL(orientationChanged()), this, SLOT(resizeMattyToolbarButtons()));
}

bool MattyNotesMainWindow::WindowActivatedEvent(QEvent *e)
{
	if (e->type() == QEvent::WindowActivate)
	{
		refreshMainWindow();
	}
	return QWidget::event(e);
}

MattyNotesMainWindow::~MattyNotesMainWindow()
{

}