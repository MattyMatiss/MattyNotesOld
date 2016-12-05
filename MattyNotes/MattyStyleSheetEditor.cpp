#include "stdafx.h"
#include "MattyStyleSheetEditor.h"


MattyStyleSheetEditor::MattyStyleSheetEditor()
{
}

bool MattyStyleSheetEditor::setSunShineTheme()
{
	QFile styleFile("MattySunShineStyleSheet.qss");
	if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qApp->setStyleSheet(styleFile.readAll());
		styleFile.close();
	}
	return true;
}

bool MattyStyleSheetEditor::setSnowTheme()
{
	QFile styleFile("MattySnowStyleSheet.qss");
	if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qApp->setStyleSheet(styleFile.readAll());
		styleFile.close();
	}
	return true;
}

bool MattyStyleSheetEditor::setDarkTheme()
{
	QFile styleFile("MattyDarkStyleSheet.qss");
	if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qApp->setStyleSheet(styleFile.readAll());
		styleFile.close();
	}
	return true;
}


MattyStyleSheetEditor::~MattyStyleSheetEditor()
{
}
