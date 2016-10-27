#include "stdafx.h"
#include "MattyTime.h"
using namespace std;
TimeAndDate* MattyTime::CurrTime = new TimeAndDate();

QString makeSingleDouble(int incomeInt)
{
	QString outcomeStr = QString::number(incomeInt);
	if (incomeInt < 10)
		outcomeStr.insert(0, "0");
	return outcomeStr;
}

inline QString concatUs(vector<QString> parts)
{
	using namespace std;
	QString CurrTimeTemp = "";
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

void MattyTime::setUserDateAndTime(int hour, int minute)
{
	UserTimeAndDate->hour = hour;
	UserTimeAndDate->minute = minute;
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
	QString CurrTimeTemp = "";
	CurrTimeTemp.append(makeSingleDouble(CurrTime->hour));
	CurrTimeTemp.append(":"); 
	CurrTimeTemp.append(makeSingleDouble(CurrTime->minute));     
	//cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintCurrTimeFull()
{
	updateCurrTime();
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) + ":" + makeSingleDouble(CurrTime->second);
	//std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintCurrDate()
{
	updateCurrTime();
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(CurrTime->day) + "."
		+ makeSingleDouble(CurrTime->month) + "." + makeSingleDouble(CurrTime->year);
	//std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintCurrTimeAndDate()
{
	updateCurrTime();
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) + " " + makeSingleDouble(CurrTime->day) + "."
		+ makeSingleDouble(CurrTime->month) + "." + makeSingleDouble(CurrTime->year);
	//std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintCurrTimeFullAndDate()
{
	updateCurrTime();
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) + ":" + makeSingleDouble(CurrTime->second) + " "
		+ makeSingleDouble(CurrTime->day) + "." + makeSingleDouble(CurrTime->month) + "." +
		makeSingleDouble(CurrTime->year);
	//std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserTime()
{
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserTimeFull()
{
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + ":" + makeSingleDouble(UserTimeAndDate->second);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserDate()
{
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->day) + "."
		+ makeSingleDouble(UserTimeAndDate->month) + "." + makeSingleDouble(UserTimeAndDate->year);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserTimeAndDate()
{
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + " " + makeSingleDouble(UserTimeAndDate->day) + "."
		+ makeSingleDouble(UserTimeAndDate->month) + "." + makeSingleDouble(UserTimeAndDate->year);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
QString MattyTime::PrintUserTimeFullAndDate()
{
	QString CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + ":" + makeSingleDouble(UserTimeAndDate->second) + " " +
		makeSingleDouble(UserTimeAndDate->day) + "." + makeSingleDouble(UserTimeAndDate->month) + "." +
		makeSingleDouble(UserTimeAndDate->year);
	//std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
MattyTime::~MattyTime()
{
	delete CurrTime;
}

void initCurrTime()
{
	MattyTime::CurrTime = new TimeAndDate();
}
