#ifndef MATTYTIME_H
#define MATTYTIME_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER


void initCurrTime();


struct TimeAndDate
{
	int hour;
	int minute;
	int second;
	int day;
	int month;
	int year;
	int dayOfWeek;
	TimeAndDate()
		: hour(0),
		minute(0),
		second(0),
		day(0),
		month(0),
		year(0),
		dayOfWeek(0)
	{

	}
	//TimeAndDate(QString TimeQStr, QString DateQStr)
	//{
	//
	//}
};

class MattyTime  
{
public:
	static TimeAndDate* CurrTime; 
	TimeAndDate* UserTimeAndDate;
	MattyTime();
	static void updateCurrTime(); 
	static TimeAndDate* getCurrTime();
	void setUserDateAndTime(int second);
	void setUserDateAndTime(int hour, int minute);
	void setUserDateAndTime(int day, int month, int year);
	void setUserDateAndTime(int hour, int minute, int day, int month, int year);
	void setUserDateAndTime(TimeAndDate* TimeDate);
	TimeAndDate* GetUserDateAndTime();
	static QString PrintCurrTime();
	static QString PrintCurrTimeFull();
	static QString PrintCurrDate();
	static QString PrintCurrTimeAndDate();
	static QString PrintCurrTimeFullAndDate();
	QString PrintUserTime();
	QString PrintUserTimeFull();
	QString PrintUserDate();
	QString PrintUserTimeAndDate();
	QString PrintUserTimeFullAndDate();
	void setUserTimeAndDateNow();
	void setUserTimeAndDateNull();
	void setUserDayOfWeek();
	~MattyTime();
};

void initCurrTime();

#endif