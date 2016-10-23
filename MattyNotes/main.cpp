#include "stdafx.h"
#include "mattynotes.h"
//#include "DbManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//DbManager MattyDb("MattyNotes.sqlite");
	MattyNotes w;
	
	w.show();
	return a.exec();
	a.exec();
}
