#include "stdafx.h"
#include "mattynotes.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/MattyNotes/Main_icon.ico"));
	MattyNotes w;
	w.show();
	return a.exec();
	a.exec();
}
