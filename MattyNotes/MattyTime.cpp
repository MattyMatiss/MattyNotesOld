#include "stdafx.h"
#include "MattyTime.h"
#include <msclr\marshal_cppstd.h>

MattyTime::MattyTime()
{
}

void MattyTime::updateCurrTime()
{
	SYSTEMTIME* tempTime = new SYSTEMTIME();
	GetLocalTime(tempTime);
	CurrTime->hour = tempTime->wHour;
	CurrTime->minute = tempTime->wMinute;
	CurrTime->day = tempTime->wDay;
	CurrTime->month = tempTime->wMonth;
	CurrTime->year = tempTime->wYear;
	CurrTime->dayOfWeek = tempTime->wDayOfWeek;
	delete tempTime;
}

TimeAndDate^ MattyTime::getCurrTime()
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

void MattyTime::setUserDateAndTime(TimeAndDate ^ TimeDate)
{
	UserTimeAndDate->hour = TimeDate->hour;
	UserTimeAndDate->minute = TimeDate->minute;
	UserTimeAndDate->day = TimeDate->day;
	UserTimeAndDate->month = TimeDate->month;
	UserTimeAndDate->year = TimeDate->year;
}

TimeAndDate^ MattyTime::GetUserDateAndTime()
{
	return UserTimeAndDate;
}
System::String^ MattyTime::PrintUserTime()
{
	System::String^ UserTime = System::String::Format(UserTimeAndDate->hour + ":"
		+ UserTimeAndDate->minute);
	std::cout << msclr::interop::marshal_as<std::string>(UserTime) << std::endl;
	return UserTime;
}
System::String^ MattyTime::PrintUserDate()
{
	System::String^ UserDate = System::String::Format(UserTimeAndDate->day + "."
		+ UserTimeAndDate->month + "." + UserTimeAndDate->year);
	std::cout << msclr::interop::marshal_as<std::string>(UserDate) << std::endl;
	return UserDate;
}
System::String^ MattyTime::PrintUserTimeAndDate()
{
	System::String^ UserTimeDate = System::String::Format(UserTimeAndDate->hour + ":"
		+ UserTimeAndDate->minute + " " + UserTimeAndDate->day + "."
		+ UserTimeAndDate->month + "." + UserTimeAndDate->year);
	std::cout << msclr::interop::marshal_as<std::string>(UserTimeDate) << std::endl;
	return UserTimeDate;
}
MattyTime::~MattyTime()
{
}
