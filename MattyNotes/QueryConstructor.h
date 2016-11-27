#ifndef QUERYCONSTRUCTOR_H
#define QUERYCONSTRUCTOR_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include <QHash>

enum OrderNotesBy { NoOrder, Type, TypeDesc, CrDate, CrDateDesc, EvDate, EvDateDesc };

class QueryConstructor
{
public:
	QueryConstructor();
	~QueryConstructor();
	

	void setOrderByClause(enum OrderNotesBy OrderBy);
	QString constructInsertQuery();
	QString constructSelectQuery();
	QString constructDeleteQuery();
	QString constructUpdateQuery();

private:

	QString TableName;
	QStringList WhatToSelectFieldNames;
	QMap<QString, QString> WhereFieldValue;
	QMap<QString, QString> WhatFieldValue;
	QString OrderByClause;

	static QString SelectWord;
	static QString InsertWord;
	static QString UpdateWord;
	static QString DeleteWord;
	static QString OrderWord;
	static QString WhereWord;
};

#endif // QUERYCONSTRUCTOR_H