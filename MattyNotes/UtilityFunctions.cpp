#include "stdafx.h"
#include "UtilityFunctions.h"
#include "Constants.h"

UtilityFunctions::UtilityFunctions()
{
}

QString UtilityFunctions::makeSingleDouble(int incomeInt)
{
	QString outcomeStr = QString::number(incomeInt);
	if (incomeInt < 10)
		outcomeStr.insert(0, Constants::ZeroToFill);
	return outcomeStr;
}

QString UtilityFunctions::repareTime(QString TimeToRepair)
{
	QString Time = TimeToRepair;
	if ((!Time.contains(":"))&&Time.length()==Constants::TimeQStringLength-1)
	{
		Time.insert(2, ":");
	}
	if (Time.length() == 5)
		return Time;
	if (Time.length() == 3)
	{
		Time.insert(2, Constants::ZeroToFill);
		Time.insert(0, Constants::ZeroToFill);
		return Time;
	}
	if (Time.length() == 4)
	{
		QStringList DoubleTime = Time.split(":");
		if (DoubleTime[0].length() == 1)
		{
			DoubleTime[0].insert(0, Constants::ZeroToFill);
		}
		else
		{
			DoubleTime[1].insert(0, Constants::ZeroToFill);
		}
		Time = "";
		Time = DoubleTime[0] + Constants::TimeSeparator + DoubleTime[1];
		return Time;
	}
}

QString UtilityFunctions::repareDate(QString Date)
{
	return QString();
}

UtilityFunctions::~UtilityFunctions()
{
}

