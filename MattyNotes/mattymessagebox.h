#ifndef MATTYMESSAGEBOX_H
#define MATTYMESSAGEBOX_H

#include <QMessageBox>

class MattyMessageBox : public QMessageBox
{
	Q_OBJECT

public:
	MattyMessageBox(QWidget *parent = 0);
	~MattyMessageBox();

private:
	
};

#endif // MATTYMESSAGEBOX_H
