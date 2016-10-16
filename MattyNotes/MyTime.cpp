#include "stdafx.h"
#include "MyTime.h"


MyTime::MyTime()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	currHours = static_cast<int>(tm.wHour);
	currMinutes = static_cast<int>(tm.wMinute);
	currSeconds = static_cast<int>(tm.wSecond);
}
MyTime::MyTime(int hours)
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	currHours = hours;
	currMinutes = static_cast<int>(tm.wMinute);
	currSeconds = static_cast<int>(tm.wSecond);
}
MyTime::MyTime(int hours, int minutes)
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	currHours = hours;
	currMinutes = minutes;
	currSeconds = static_cast<int>(tm.wSecond);
}
MyTime::MyTime(int hours, int minutes, int seconds)
{
	currHours = hours;
	currMinutes = minutes;
	currSeconds = seconds;
}
void MyTime::setTime(int hours)
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	this->hours = hours;
	this->minutes = static_cast<int>(tm.wMinute);
	this->seconds = static_cast<int>(tm.wSecond);
}
void MyTime::setTime(int hours, int minutes)
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = static_cast<int>(tm.wSecond);
}
void MyTime::setTime(int hours, int minutes, int seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}
void MyTime::updateCurTime()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	currHours = static_cast<int>(tm.wHour);
	currMinutes = static_cast<int>(tm.wMinute);
	currSeconds = static_cast<int>(tm.wSecond);
}
void MyTime::updateUserTime(int hours, int minutes, int seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}
int MyTime::getHours()
{
	return this->hours;
}
int MyTime::getMinutes()
{
	return this->minutes;
}
int MyTime::getSeconds()
{
	return this->seconds;
}
int MyTime::getCurrHours()
{
	return this->currHours;
}
int MyTime::getCurrMinutes()
{
	return this->currMinutes;
}
int MyTime::getCurrSeconds()
{
	return this->currSeconds;
}