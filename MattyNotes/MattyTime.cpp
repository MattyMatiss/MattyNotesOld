#include "stdafx.h"
#include "MattyTime.h"
#include <msclr\marshal_cppstd.h>
#include <boost/lambda/lambda.hpp>

System::String^ makeSingleDouble(int incomeInt)
{
	System::String^ outcomeStr;
	if (incomeInt < 10)
		outcomeStr = System::String::Format("0" + incomeInt);
	else
		outcomeStr= System::Convert::ToString(incomeInt);
	return outcomeStr;
}

MattyTime::MattyTime()
{
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
System::String ^ MattyTime::PrintCurrTime()
{
	updateCurrTime();
	System::String^ CurrTimeTemp = System::String::Format(makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute));
	std::cout << "Now is " << msclr::interop::marshal_as<std::string>(CurrTimeTemp) << std::endl;
	return CurrTimeTemp;
}
System::String ^ MattyTime::PrintCurrTimeFull()
{
	updateCurrTime();
	System::String^ CurrTimeTemp = System::String::Format(makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) + ":" + makeSingleDouble(CurrTime->second));
	std::cout << "Now is " << msclr::interop::marshal_as<std::string>(CurrTimeTemp) << std::endl;
	return CurrTimeTemp;
}
System::String ^ MattyTime::PrintCurrDate()
{
	updateCurrTime();
	System::String^ CurrTimeTemp = System::String::Format(makeSingleDouble(CurrTime->day) + "."
		+ makeSingleDouble(CurrTime->month) + "." + makeSingleDouble(CurrTime->year));
	std::cout << "Today is " << msclr::interop::marshal_as<std::string>(CurrTimeTemp) << std::endl;
	return CurrTimeTemp;
}
System::String ^ MattyTime::PrintCurrTimeAndDate()
{
	updateCurrTime();
	System::String^ CurrTimeTemp = System::String::Format(makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) +" " + makeSingleDouble(CurrTime->day) + "."
		+ makeSingleDouble(CurrTime->month) + "." + makeSingleDouble(CurrTime->year));
	std::cout << "Now is " << msclr::interop::marshal_as<std::string>(CurrTimeTemp) << std::endl;
	return CurrTimeTemp;
}
System::String ^ MattyTime::PrintCurrTimeFullAndDate()
{
	updateCurrTime();
	System::String^ CurrTimeTemp = System::String::Format(makeSingleDouble(CurrTime->hour) + ":"
		+ makeSingleDouble(CurrTime->minute) + ":" + makeSingleDouble(CurrTime->second) + " " 
		+ makeSingleDouble(CurrTime->day) + "."	+ makeSingleDouble(CurrTime->month) + "." +
		makeSingleDouble(CurrTime->year));
	std::cout << "Now is " << msclr::interop::marshal_as<std::string>(CurrTimeTemp) << std::endl;
	return CurrTimeTemp;
}
System::String^ MattyTime::PrintUserTime()
{
	System::String^ UserTime = System::String::Format(makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute));
	std::cout << "It is " << msclr::interop::marshal_as<std::string>(UserTime) << std::endl;
	return UserTime;
}
System::String ^ MattyTime::PrintUserTimeFull()
{
	System::String^ UserTime = System::String::Format(makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + ":" + makeSingleDouble(UserTimeAndDate->second));
	std::cout << "It is " << msclr::interop::marshal_as<std::string>(UserTime) << std::endl;
	return UserTime;
}
System::String^ MattyTime::PrintUserDate()
{
	System::String^ UserDate = System::String::Format(makeSingleDouble(UserTimeAndDate->day) + "."
		+ makeSingleDouble(UserTimeAndDate->month) + "." + makeSingleDouble(UserTimeAndDate->year));
	std::cout << "It is " << msclr::interop::marshal_as<std::string>(UserDate) << std::endl;
	return UserDate;
}
System::String^ MattyTime::PrintUserTimeAndDate()
{
	System::String^ UserTimeDate = System::String::Format(makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + " " + makeSingleDouble(UserTimeAndDate->day) + "."
		+ makeSingleDouble(UserTimeAndDate->month) + "." + makeSingleDouble(UserTimeAndDate->year));
	std::cout << "It is " << msclr::interop::marshal_as<std::string>(UserTimeDate) << std::endl;
	return UserTimeDate;
}
System::String ^ MattyTime::PrintUserTimeFullAndDate()
{
	System::String^ UserTimeDate = System::String::Format(makeSingleDouble(UserTimeAndDate->hour) + ":"
		+ makeSingleDouble(UserTimeAndDate->minute) + ":" + makeSingleDouble(UserTimeAndDate->second) + " " +
		makeSingleDouble(UserTimeAndDate->day) + "." + makeSingleDouble(UserTimeAndDate->month) + "." + 
		makeSingleDouble(UserTimeAndDate->year));
	std::cout << "It is " << msclr::interop::marshal_as<std::string>(UserTimeDate) << std::endl;
	return UserTimeDate;
}
MattyTime::~MattyTime()
{
}
