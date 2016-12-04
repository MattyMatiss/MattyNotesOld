#ifndef MATTYMESSAGEBOX_H
#define MATTYMESSAGEBOX_H

#include <QMessageBox>

enum Type { Information, Warning, Question };

class MattyMessageBox : public QMessageBox
{
	Q_OBJECT

public:
	MattyMessageBox(Type Type, QWidget *parent = 0);
	~MattyMessageBox();

private:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	int m_nMouseClick_X_Coordinate;
	int m_nMouseClick_Y_Coordinate;

};

#endif // MATTYMESSAGEBOX_H
