#include "stdafx.h"
#include "mattynotes.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MattyNotes w;
	w.show();
	return a.exec();
}
