#ifndef MATTYSTYLESHEETEDITOR_H
#define MATTYSTYLESHEETEDITOR_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

enum DefaultTheme { MattySunShineStyleSheet, MattySnowStyleSheet, MattyDarkStyleSheet
};

class MattyStyleSheetEditor
{
public:
	MattyStyleSheetEditor();

	static bool setTheme(const QString & ThemeName);
	static bool setTheme(DefaultTheme ThemeName);
	static bool refreshTheme();

	~MattyStyleSheetEditor();

private:
	static QString CurrentTheme;

};

#endif // MATTYSTYLESHEETEDITOR_H