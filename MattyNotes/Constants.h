#ifndef CONSTANTS_H
#define CONSTANTS_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

class Constants
{
public:
	static const QString TimeSeparator; // ":"
	static const QString DateSeparator; // "."
	static const QString EmptyQString; // ""
	static const QString Space; // " "
	static const QString ZeroToFill; // "0"
	static const int TimeQStringLength; // 5
	static const int DateQStringLength; // 10
	static const int PositionOfFirstDateSeparator; // 2
	static const int PositionOfSecondDateSeparator; // 5
	Constants();
	~Constants();
};

#endif // CONSTANTS_H