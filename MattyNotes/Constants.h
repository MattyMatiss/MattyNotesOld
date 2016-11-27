#ifndef CONSTANTS_H
#define CONSTANTS_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

enum MattyPathToDbType { HomeAbsolute, WorkAbsolute, Relative };

class Constants
{
public:
	static QString PathToDb;
	static const QString TimeSeparator; // ":"
	static const QString DateSeparator; // "."
	static const QString EmptyQString; // ""
	static const QString Space; // " "
	static const QString ZeroToFill; // "0"
	static const int TimeQStringLength; // 5
	static const int DateQStringLength; // 10
	static const int PositionOfFirstDateSeparator; // 2
	static const int PositionOfSecondDateSeparator; // 5
	static void setPathToDb(MattyPathToDbType PathType);
	static void setPathToDb(QString & Path);
	Constants();
	~Constants();
};

#endif // CONSTANTS_H