#include "stdafx.h"
#include "mattynotesmainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/MattyNotes/Main_icon.ico"));
	/*QFile styleFile("MattyStyleSheet.qss");
	if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		a.setStyleSheet(styleFile.readAll());
		styleFile.close();
	}*/
	MattyNotesMainWindow w;
	w.show();
	return a.exec();
}
