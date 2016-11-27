#include "stdafx.h"
#include "QueryConstructor.h"

QueryConstructor::QueryConstructor()
{
	OrderByClause = "";
	TableName = "";
}


QueryConstructor::~QueryConstructor()
{
}

void QueryConstructor::setOrderByClause(enum OrderNotesBy OrderBy)
{
	QStringList OrderByTypes = { "", " ORDER BY TypeName", " ORDER BY TypeName DESC",
		" ORDER BY CrDate, CrTime", " ORDER BY CrDate, CrTime DESC",
		" ORDER BY EventDate, EventTime", " ORDER BY EventDate, EventTime DESC" };

	OrderByClause = OrderByTypes[OrderBy];
}


QString QueryConstructor::getOrderByClause()
{
	return OrderByClause;
}

void QueryConstructor::addWhatToSelectFieldName(QString & FieldName)
{
	WhatToSelectFieldNames.push_back(FieldName);
}

void QueryConstructor::addWhereFieldValue(QString & Field, QString & Value)
{
	WhereFieldValue.insert(Field, Value);
}

void QueryConstructor::addWhatToSetFieldValue(QString Field, QString & Value)
{
	WhatToSetFieldValue.insert(Field, Value);
}

void QueryConstructor::setTableName(QString& Name)
{
	TableName = Name;
}

QString QueryConstructor::getTableName()
{
	return TableName;
}

void QueryConstructor::setWhatToSelectFieldNames(QStringList & FieldNames)
{
	WhatToSelectFieldNames = FieldNames;
}

QStringList QueryConstructor::getWhatToSelectFieldNames()
{
	return WhatToSelectFieldNames;
}

void QueryConstructor::setWhereFieldValue(QMap<QString, QString>& FieldValue)
{
	WhereFieldValue = FieldValue;
}

QMap<QString, QString> QueryConstructor::getWhereFieldValue()
{
	return WhereFieldValue;
}

void QueryConstructor::setWhatToSetFieldValue(QMap<QString, QString>& FieldValue)
{
	WhatToSetFieldValue = FieldValue;
}

QMap<QString, QString> QueryConstructor::getWhatToSetFieldValue()
{
	return WhatToSetFieldValue;
}

QString QueryConstructor::constructInsertQuery()
{
	QString ResultQuery = "";

	if (TableName!="")
	{
		if (!WhatToSetFieldValue.empty())
		{
			ResultQuery.append(" INSERt INTO " + TableName + "(");

			QMapIterator<QString, QString> *pair = new QMapIterator<QString, QString>(WhatToSetFieldValue);
			while (pair->hasNext())
			{
				ResultQuery.append(pair->key());
			}

			if (ResultQuery.endsWith(","))
				ResultQuery.chop(1);

			ResultQuery.append(") VALUES(");

			pair->toFront();

			while (pair->hasNext())
			{
				ResultQuery.append(pair->value());
			}
			delete pair;

			ResultQuery.append(");");
		}
	}

	return ResultQuery;
}

QString QueryConstructor::constructSelectQuery()
{
	QString ResultQuery = "";
	
	if (TableName != "")
	{
		ResultQuery.append(" SELECT ");

		if (WhatToSelectFieldNames.empty())
		{
			ResultQuery.append("*");
		}
		else
		{
			for (int i = 0;i < WhatToSelectFieldNames.length()-1;i++)
			{
				ResultQuery.append(" " + WhatToSelectFieldNames[i] + ",");
			}
			ResultQuery.append(WhatToSelectFieldNames.last());
		}
		ResultQuery.append(" FROM " + TableName + " WHERE " + constructWhereEqualsClause() + " " + OrderByClause);
	}
	return ResultQuery;
}

QString QueryConstructor::constructDeleteQuery()
{
	QString ResultQuery = "";

	if (TableName != "")
	{
		ResultQuery.append(" DELETE FROM " + TableName + " WHERE " + constructWhereEqualsClause());
	}

	return ResultQuery;
}

QString QueryConstructor::constructUpdateQuery()
{
	QString ResultQuery = "";



	return ResultQuery;
}

QString QueryConstructor::constructWhereEqualsClause()
{
	QString WhereClause = "";

	QMapIterator<QString, QString> *pair = new QMapIterator<QString, QString>(WhereFieldValue);
	while (pair->hasNext())
	{
		WhereClause.append(" " + pair->key() + "=" + pair->value() + ",");
	}
	if (WhereClause.endsWith(","))
		WhereClause.chop(1);

	return WhereClause;
}
