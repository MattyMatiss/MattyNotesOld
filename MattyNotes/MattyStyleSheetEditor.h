#ifndef MATTYSTYLESHEETEDITOR_H
#define MATTYSTYLESHEETEDITOR_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER


class MattyStyleSheetEditor
{
public:
	MattyStyleSheetEditor();

	static bool setSunShineTheme();
	static bool setSnowTheme();
	static bool setDarkTheme();

	~MattyStyleSheetEditor();
};

#endif // MATTYSTYLESHEETEDITOR_H