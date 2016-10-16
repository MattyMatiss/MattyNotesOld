#pragma once

ref struct TimeAndDate
{
	int hour;
	int minute;
	int day;
	int month;
	int year;
	int dayOfWeek;
	TimeAndDate()
		: hour(0),
		minute(0),
		day(0),
		month(0),
		year(0),
		dayOfWeek(0)
	{

	}
};

ref class MattyTime
{
public:
	static TimeAndDate^ CurrTime = gcnew TimeAndDate();
	TimeAndDate^ UserTimeAndDate = gcnew TimeAndDate();
	MattyTime();
	static void updateCurrTime();
	static TimeAndDate^ getCurrTime();
	void setUserDateAndTime(int hour, int minute);
	void setUserDateAndTime(int day, int month, int year);
	void setUserDateAndTime(int hour, int minute, int day,
		int month, int year);
	void setUserDateAndTime(TimeAndDate^ TimeDate);
	TimeAndDate^ GetUserDateAndTime();
	System::String^ PrintUserTime();
	System::String^ PrintUserDate();
	System::String^ PrintUserTimeAndDate();
	~MattyTime();
};


