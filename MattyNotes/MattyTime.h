#pragma once
using namespace std;
std::string makeSingleDouble(int incomeInt);

void initCurrTime();
string makeSingleDouble(int incomeInt);
inline string concatUs(vector<string> parts);

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
};

class MattyTime  
{
public:
	static TimeAndDate* CurrTime; 
	TimeAndDate* UserTimeAndDate;
	MattyTime();
	static void updateCurrTime(); 
	static TimeAndDate* getCurrTime();
	void setUserDateAndTime(int hour, int minute);
	void setUserDateAndTime(int day, int month, int year);
	void setUserDateAndTime(int hour, int minute, int day,
		int month, int year);
	void setUserDateAndTime(TimeAndDate* TimeDate);
	TimeAndDate* GetUserDateAndTime();
	static std::string PrintCurrTime();
	static std::string PrintCurrTimeFull();
	static std::string PrintCurrDate();
	static std::string PrintCurrTimeAndDate();
	static std::string PrintCurrTimeFullAndDate();
	string PrintUserTime();
	string PrintUserTimeFull();
	string PrintUserDate();
	string PrintUserTimeAndDate();
	string PrintUserTimeFullAndDate();
	~MattyTime();
};

void initCurrTime();
