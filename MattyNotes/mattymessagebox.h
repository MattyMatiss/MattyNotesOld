#ifndef MATTYMESSAGEBOX_H
#define MATTYMESSAGEBOX_H

#include <QMessageBox>

enum Type { Information = 0, Warning = 1, Question = 2 };

class MattyMessageBox : public QMessageBox
{
	Q_OBJECT

public:
	MattyMessageBox(Type Type, QWidget *parent = 0);
	~MattyMessageBox();

private:

	QPixmap MattyIcon;

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;

};

#endif // MATTYMESSAGEBOX_H
