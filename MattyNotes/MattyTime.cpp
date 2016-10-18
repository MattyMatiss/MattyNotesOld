#include "stdafx.h"
#include "MattyTime.h"
using namespace std;
TimeAndDate* MattyTime::CurrTime = new TimeAndDate();

string makeSingleDouble(int incomeInt)
{
	string outcomeStr = to_string(incomeInt);
	if (incomeInt < 10)
		outcomeStr.insert(0, "0");
	return outcomeStr;
}

inline string concatUs(vector<string> parts)
{
	using namespace std;
	string CurrTimeTemp = "";
	vector<string>::iterator itStr;
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
string MattyTime::PrintCurrTime()
{
	updateCurrTime();
	string CurrTimeTemp = "";
	CurrTimeTemp.append(makeSingleDouble(CurrTime->hour));
	CurrTimeTemp.append(":"); 
	CurrTimeTemp.append(makeSingleDouble(CurrTime->minute));     
	cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintCurrTimeFull()
{
	updateCurrTime();
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) + ":" + makeSingleDouble(CurrTime->second);
	std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintCurrDate()
{
	updateCurrTime();
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(CurrTime->day) + "."
		+ makeSingleDouble(CurrTime->month) + "." + makeSingleDouble(CurrTime->year);
	std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintCurrTimeAndDate()
{
	updateCurrTime();
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) + " " + makeSingleDouble(CurrTime->day) + "."
		+ makeSingleDouble(CurrTime->month) + "." + makeSingleDouble(CurrTime->year);
	std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintCurrTimeFullAndDate()
{
	updateCurrTime();
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) + ":" + makeSingleDouble(CurrTime->second) + " "
		+ makeSingleDouble(CurrTime->day) + "." + makeSingleDouble(CurrTime->month) + "." +
		makeSingleDouble(CurrTime->year);
	std::cout << "Now is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintUserTime()
{
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute);
	std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintUserTimeFull()
{
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + ":" + makeSingleDouble(UserTimeAndDate->second);
	std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintUserDate()
{
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->day) + "."
		+ makeSingleDouble(UserTimeAndDate->month) + "." + makeSingleDouble(UserTimeAndDate->year);
	std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintUserTimeAndDate()
{
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + " " + makeSingleDouble(UserTimeAndDate->day) + "."
		+ makeSingleDouble(UserTimeAndDate->month) + "." + makeSingleDouble(UserTimeAndDate->year);
	std::cout << "It is " << CurrTimeTemp << endl;
	return CurrTimeTemp;
}
std::string MattyTime::PrintUserTimeFullAndDate()
{
	string CurrTimeTemp = "";
	CurrTimeTemp = makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + ":" + makeSingleDouble(UserTimeAndDate->second) + " " +
		makeSingleDouble(UserTimeAndDate->day) + "." + makeSingleDouble(UserTimeAndDate->month) + "." +
		makeSingleDouble(UserTimeAndDate->year);
	std::cout << "It is " << CurrTimeTemp << endl;
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
