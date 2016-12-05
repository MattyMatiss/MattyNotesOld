#include <stdafx.h>
#include "MattySettingsDialog.h"

MattySettingsDialog::MattySettingsDialog(QWidget * parent) : QDialog(parent)
{
	MattySettingsDialogUi.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);

	MattySettingsDialogUi.stackedWidget->setMinimumWidth(250);
	MattySettingsDialogUi.splitter->setStretchFactor(0, 1);
	MattySettingsDialogUi.splitter->setStretchFactor(1, 5);

	General = new QListWidgetItem(tr("General"), MattySettingsDialogUi.listWidget);
	Interface = new QListWidgetItem(tr("Interface"), MattySettingsDialogUi.listWidget);
	Security = new QListWidgetItem(tr("Security"), MattySettingsDialogUi.listWidget);

	GeneralPageWidget = new QWidget;
	InterfacePageWidget = new QWidget;
	SecurityPageWidget = new QWidget;

	GeneralPageWidget->setMinimumWidth(250);
	InterfacePageWidget->setMinimumWidth(250);
	SecurityPageWidget->setMinimumWidth(250);

	MattySettingsDialogUi.stackedWidget->addWidget(GeneralPageWidget);
	MattySettingsDialogUi.stackedWidget->addWidget(InterfacePageWidget);
	MattySettingsDialogUi.stackedWidget->addWidget(SecurityPageWidget);

	

	connect(MattySettingsDialogUi.listWidget, SIGNAL(currentItemChanged()),
		this, SLOT(changeDisplayedPage()));
}

void MattySettingsDialog::on_ApplySettingsButton_clicked()
{
	// сюда дорисовать действия
	this->close();
	this->~MattySettingsDialog();
}

void MattySettingsDialog::on_CancelSettingsButton_clicked()
{
	this->close();
	this->~MattySettingsDialog();
}

void MattySettingsDialog::changeDisplayedPage()
{
	MattySettingsDialogUi.stackedWidget->setCurrentIndex(MattySettingsDialogUi.listWidget->currentRow());
}

void MattySettingsDialog::mousePressEvent(QMouseEvent *event)
{
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
}

void MattySettingsDialog::mouseMoveEvent(QMouseEvent *event)
{
	move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}

MattySettingsDialog::~MattySettingsDialog()
{

}