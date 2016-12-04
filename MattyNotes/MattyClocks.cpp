#include "stdafx.h"
#include "MattyClocks.h"

MattyClocks::MattyClocks(QWidget *parent) : QLCDNumber(parent)
{
	this->setFixedSize(96, 51);
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(1000);
	showTime();
}


MattyClocks::~MattyClocks()
{
}


void MattyClocks::showTime()
{
	QString CurrentTime = QTime::currentTime().toString();
	CurrentTime = CurrentTime.mid(0, 5);
	display(CurrentTime);
}