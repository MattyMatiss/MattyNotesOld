#include "stdafx.h"
#include "mattynotes.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/MattyNotes/Main_icon.ico"));
	QFile styleFile(":/MattyNotes/stylesheet.qss");
	if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		a.setStyleSheet(styleFile.readAll());
		styleFile.close();
	}
	MattyNotes w;
	w.show();
	return a.exec();
}
