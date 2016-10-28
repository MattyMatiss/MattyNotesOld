#include "stdafx.h"
#include "MattyTime.h"
#include "Constants.h"

TimeAndDate* MattyTime::CurrTime = new TimeAndDate();

QString makeSingleDouble(int incomeInt)
{
	QString outcomeStr = QString::number(incomeInt);
	if (incomeInt < 10)
		outcomeStr.insert(0, Constants::ZeroToFill);
	return outcomeStr;
}

inline QString concatUs(vector<QString> parts)
{
	using namespace std;
	QString CurrTimeTemp = Constants::EmptyQString;
	vector<QString>::iterator itStr;
	for (itStr = parts.begin(); itStr != parts.end(); itStr++)
	{
		CurrTimeTemp.append(*itStr);
	}
	return CurrTimeTemp;
}

MattyTime::MattyTime()
{
	UserTimeAndDate = new TimeAndDate();
}

void MattyTime::updateCurrTime()
{
	SYSTEMTIME* tempTime = new SYSTEMTIME();
	GetLocalTime(tempTime);
	CurrTime->hour = tempTime->wHour;
	CurrTime->minute = tempTime->wMinute;
	CurrTime->second = tempTime->wSecond;
	CurrTime->day = tempTime->wDay;
	CurrTime->month = tempTime->wMonth;
	CurrTime->year = tempTime->wYear;
	CurrTime->dayOfWeek = tempTime->wDayOfWeek;
	delete tempTime;
}

TimeAndDate* MattyTime::getCurrTime()
{
	updateCurrTime();
	return CurrTime;
}

void MattyTime::setUserDateAndTime(int second)
{
	UserTimeAndDate->second = second;
}

void MattyTime::setUserDateAndTime(int hour, int minute)
{
	UserTimeAndDate->hour = hour;
	UserTimeAndDate->minute = minute;
	UserTimeAndDate->second = 0; 
}

void MattyTime::setUserDateAndTime(int day, int month, int year)
{
	UserTimeAndDate->day = day;
	UserTimeAndDate->month = month;
	UserTimeAndDate->year = year;
}

void MattyTime::setUserDateAndTime(int hour, int minute, int day, int month, int year)
{
	UserTimeAndDate->hour = hour;
	UserTimeAndDate->minute = minute;
	UserTimeAndDate->day = day;
	UserTimeAndDate->month = month;
	UserTimeAndDate->year = year;
}

void MattyTime::setUserDateAndTime(TimeAndDate* TimeDate)
{
	UserTimeAndDate->hour = TimeDate->hour;
	UserTimeAndDate->minute = TimeDate->minute;
	UserTimeAndDate->day = TimeDate->day;
	UserTimeAndDate->month = TimeDate->month;
	UserTimeAndDate->year = TimeDate->year;
}

TimeAndDate* MattyTime::GetUserDateAndTime()
{
	return UserTimeAndDate;
}
QString MattyTime::PrintCurrTime()
{
	updateCurrTime();
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp.append(makeSingleDouble(CurrTime->hour));
	CurrTimeTemp.append(Constants::TimeSeparator);
	CurrTimeTemp.append(makeSingleDouble(CurrTime->minute));     
	//cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintCurrTimeFull()
{
	updateCurrTime();
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + Constants::TimeSeparator
		+ makeSingleDouble(CurrTime->minute) + Constants::TimeSeparator + makeSingleDouble(CurrTime->second);
	//std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintCurrDate()
{
	updateCurrTime();
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(CurrTime->day) + Constants::DateSeparator
		+ makeSingleDouble(CurrTime->month) + Constants::DateSeparator + makeSingleDouble(CurrTime->year);
	//std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintCurrTimeAndDate()
{
	updateCurrTime();
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + Constants::TimeSeparator
		+ makeSingleDouble(CurrTime->minute) + " " + makeSingleDouble(CurrTime->day) + Constants::DateSeparator
		+ makeSingleDouble(CurrTime->month) + Constants::DateSeparator + makeSingleDouble(CurrTime->year);
	//std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintCurrTimeFullAndDate()
{
	updateCurrTime();
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + Constants::TimeSeparator
		+ makeSingleDouble(CurrTime->minute) + Constants::TimeSeparator + makeSingleDouble(CurrTime->second) + 
		Constants::Space
		+ makeSingleDouble(CurrTime->day) + Constants::DateSeparator + makeSingleDouble(CurrTime->month) 
		+ Constants::DateSeparator +
		makeSingleDouble(CurrTime->year);
	//std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserTime()
{
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + Constants::TimeSeparator
		+ makeSingleDouble(UserTimeAndDate->minute);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserTimeFull()
{
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + Constants::TimeSeparator
		+ makeSingleDouble(UserTimeAndDate->minute) + Constants::TimeSeparator + makeSingleDouble(UserTimeAndDate->second);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserDate()
{
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->day) + Constants::DateSeparator
		+ makeSingleDouble(UserTimeAndDate->month) + Constants::DateSeparator + makeSingleDouble(UserTimeAndDate->year);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserTimeAndDate()
{
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + Constants::TimeSeparator
		+ makeSingleDouble(UserTimeAndDate->minute) + Constants::Space
		+ makeSingleDouble(UserTimeAndDate->day) + Constants::DateSeparator
		+ makeSingleDouble(UserTimeAndDate->month) + Constants::DateSeparator + makeSingleDouble(UserTimeAndDate->year);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserTimeFullAndDate()
{
	QString CurrTimeTemp = Constants::EmptyQString;
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + Constants::TimeSeparator
		+ makeSingleDouble(UserTimeAndDate->minute) + Constants::TimeSeparator
		+ makeSingleDouble(UserTimeAndDate->second) + Constants::Space +
		makeSingleDouble(UserTimeAndDate->day) + Constants::DateSeparator
		+ makeSingleDouble(UserTimeAndDate->month) + Constants::DateSeparator +
		makeSingleDouble(UserTimeAndDate->year);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
void MattyTime::setUserTimeAndDateNow()
{
	updateCurrTime();
	UserTimeAndDate = CurrTime;
}
void MattyTime::setUserTimeAndDateNull()
{
	UserTimeAndDate->hour = -1;
	UserTimeAndDate->minute = -1;
	UserTimeAndDate->second = -1;
	UserTimeAndDate->day = -1;
	UserTimeAndDate->month = -1;
	UserTimeAndDate->year = -1;
	UserTimeAndDate->dayOfWeek = -1;
}
void MattyTime::setUserDayOfWeek()
{
	int day = UserTimeAndDate->day;
	int month = UserTimeAndDate->month;
	int year = UserTimeAndDate->year;
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	year -= month < 3;
	UserTimeAndDate->dayOfWeek = 1 + ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7);
}
MattyTime::~MattyTime()
{
	//delete CurrTime;
}

void initCurrTime()
{
	MattyTime::CurrTime = new TimeAndDate();
}
