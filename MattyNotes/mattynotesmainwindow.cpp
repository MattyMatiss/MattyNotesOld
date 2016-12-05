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

MattyNotesMainWindow::MattyNotesMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setContextMenuPolicy(Qt::NoContextMenu);

	ui.splitter->setStretchFactor(0, 1);
	ui.splitter->setStretchFactor(1, 3);

	connectToDb();

	buildMainToolBar();

	buildMattyToolBar();

	setConnects();
	
	refreshMainWindow();
}

void MattyNotesMainWindow::on_addNoteButtonTemp_clicked()
{
	addNoteDialog *newAddNoteDialog = new addNoteDialog(Add);
	newAddNoteDialog->setWindowModality(Qt::ApplicationModal); 
	if (!newAddNoteDialog->exec())
	{
		NoteHolder::publishNotes(ui.scrollAreaWidgetContents);
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
	QFile styleFile("MattyStyleSheet.qss");
	if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qApp->setStyleSheet(styleFile.readAll());
		styleFile.close();
	}
	NoteHolder::publishNotes(ui.scrollAreaWidgetContents);
}

void MattyNotesMainWindow::on_SettingsButton_clicked()
{
	MattySettingsDialog* newMattySettingsDialog = new MattySettingsDialog();
	newMattySettingsDialog->setWindowModality(Qt::ApplicationModal);
	newMattySettingsDialog->exec();
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

void MattyNotesMainWindow::buildMainToolBar()
{
	CloseWindowButton = new QPushButton(ui.mainToolBar);
	CloseWindowButton->setObjectName("CloseWindowButton");
	CloseWindowButton->setMaximumSize(QSize(20, 20));
	CloseWindowButton->setFlat(true);

	MaximizeWindowButton = new QPushButton(ui.mainToolBar);
	MaximizeWindowButton->setObjectName("MaximizeWindowButton");
	MaximizeWindowButton->setMaximumSize(QSize(20, 20));
	MaximizeWindowButton->setFlat(true);

	MinimizeWindowButton = new QPushButton(ui.mainToolBar);
	MinimizeWindowButton->setObjectName("MinimizeWindowButton");
	MinimizeWindowButton->setMaximumSize(QSize(20, 20));
	MinimizeWindowButton->setFlat(true);

	MainToolBarSpacerLeft = new QWidget(ui.mainToolBar);
	MainToolBarSpacerLeft->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	MainToolBarSpacerRight = new QWidget(ui.mainToolBar);
	MainToolBarSpacerRight->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	WindowHeaderLabel = new QLabel();
	WindowHeaderLabel->setObjectName(QStringLiteral("WindowHeaderLabel"));
	WindowHeaderLabel->setText("MattyNotes");

	ui.mainToolBar->setObjectName(QStringLiteral("MainToolBar"));
	ui.mainToolBar->addWidget(MainToolBarSpacerLeft);
	ui.mainToolBar->addWidget(WindowHeaderLabel);
	ui.mainToolBar->addWidget(MainToolBarSpacerRight);
	ui.mainToolBar->addWidget(MinimizeWindowButton);
	ui.mainToolBar->addWidget(MaximizeWindowButton);
	ui.mainToolBar->addWidget(CloseWindowButton);
	ui.mainToolBar->setMovable(false);
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
	QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect(MattyToolBar);
	opacity->setOpacity(0.50); // #0 to 1 will cause the fade effect to kick in
	MattyToolBar->setGraphicsEffect(opacity);
	MattyToolBar->setAutoFillBackground(true);

	AddNoteButton = new QPushButton(this->MattyToolBar);
	AddNoteButton->setObjectName(QStringLiteral("AddNoteButton"));
	AddNoteButton->setMinimumSize(QSize(51, 51));
	AddNoteButton->setMaximumSize(QSize(51, 51));

	RefreshNoteListButton = new QPushButton(this->MattyToolBar);
	RefreshNoteListButton->setObjectName(QStringLiteral("RefreshNoteListButton"));
	RefreshNoteListButton->setMinimumSize(QSize(51, 51));
	RefreshNoteListButton->setMaximumSize(QSize(51, 51));

	SettingsButton = new QPushButton(this->MattyToolBar);
	SettingsButton->setObjectName(QStringLiteral("SettingsButton"));
	SettingsButton->setMinimumSize(QSize(51, 51));
	SettingsButton->setMaximumSize(QSize(51, 51));

	MattyClocks* MainClocks = new MattyClocks(this->MattyToolBar);
	MattyToolBar->addWidget(MainClocks);

	MattyToolBarMainSpacer = new QWidget(this->MattyToolBar);
	MattyToolBarMainSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	MattyToolBar->addWidget(SettingsButton);
	MattyToolBar->addWidget(MattyToolBarMainSpacer);
	MattyToolBar->addWidget(RefreshNoteListButton);
	MattyToolBar->addWidget(AddNoteButton);
}

inline void MattyNotesMainWindow::setConnects()
{
	QObject::connect(CloseWindowButton, SIGNAL(clicked()), this, SLOT(closeWindow()));
	QObject::connect(MaximizeWindowButton, SIGNAL(clicked()), this,
		SLOT(maximizeWindow()));
	QObject::connect(MinimizeWindowButton, SIGNAL(clicked()), this, SLOT(minimizeWindow()));
	QObject::connect(AddNoteButton, SIGNAL(clicked()), this, SLOT(on_addNoteButtonTemp_clicked()));
	QObject::connect(RefreshNoteListButton, SIGNAL(clicked()), this, SLOT(refreshMainWindow()));
	QObject::connect(SettingsButton, SIGNAL(clicked()), this, SLOT(on_SettingsButton_clicked()));
}

bool MattyNotesMainWindow::event(QEvent *e)
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