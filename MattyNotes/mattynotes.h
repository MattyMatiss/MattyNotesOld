//#ifndef MATTYNOTES_H
//#define MATTYNOTES_H

#include <QtWidgets/QMainWindow>
#include "ui_mattynotes.h"

class MattyNotes : public QMainWindow
{
	Q_OBJECT

public:
	MattyNotes(QWidget *parent = 0);
	QPushButton pushButton;
	~MattyNotes();

private:
	Ui::MattyNotesClass ui;
	private slots:
	void on_pushButtonCalendar_clicked();
};



//#endif // MATTYNOTES_H
