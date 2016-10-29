#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

class UtilityFunctions
{
public:
	UtilityFunctions();
	static QString makeSingleDouble(int incomeInt);
	static QString repareTime(QString TimeToRepair);
	static QString repareDate(QString Date);
	//inline QString concatUs(vector<QString> parts);
	~UtilityFunctions();
};

#endif