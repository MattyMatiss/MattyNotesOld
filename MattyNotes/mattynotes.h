#ifndef MATTYNOTES_H
#define MATTYNOTES_H

#include <QtWidgets/QMainWindow>
#include "ui_mattynotes.h"

class MattyNotes : public QMainWindow
{
	Q_OBJECT

public:
	MattyNotes(QWidget *parent = 0);
	~MattyNotes();

private:
	Ui::MattyNotesClass ui;
};

#endif // MATTYNOTES_H
