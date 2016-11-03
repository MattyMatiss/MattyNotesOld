#include "stdafx.h"
#include "Constants.h"

  QString Constants::PathToDb = "C:\\Users\\Ogrigorieva\\Visual Studio 2015\\Projects\\Personal\\MattyNotes\\MattyNotes.sqlite";
 const QString Constants::AbsolutePathToDb = "C:\\Users\\Ogrigorieva\\Visual Studio 2015\\Projects\\Personal\\MattyNotes\\MattyNotes.sqlite";
 const QString Constants::RelativePathToDb = "MattyNotes.sqlite";
const QString Constants::TimeSeparator = ":";
const QString Constants::DateSeparator = ".";
const QString Constants::EmptyQString = "";
const QString Constants::Space = " ";
const QString Constants::ZeroToFill = "0";
const int Constants::TimeQStringLength = 5;
const int Constants::DateQStringLength = 10;
const int Constants::PositionOfFirstDateSeparator = 2;
const int Constants::PositionOfSecondDateSeparator = 5;

Constants::Constants()
{
}


Constants::~Constants()
{
}
