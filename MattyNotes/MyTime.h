#pragma once
ref class MyTime
{
public:
	static int currHours;
	static int currMinutes;
	static int currSeconds;
	int hours;
	int minutes;
	int seconds;
	MyTime();
	MyTime(int hours);
	MyTime(int hours, int minutes);
	MyTime(int hours, int minutes, int seconds);
	void setTime(int hours);
	void setTime(int hours, int minutes);
	void setTime(int hours, int minutes, int seconds);
	void updateCurTime();
	void updateUserTime(int hours, int minutes, int seconds);
	int getHours();
	int getMinutes();
	int getSeconds();
	int getCurrHours();
	int getCurrMinutes();
	int getCurrSeconds();
};