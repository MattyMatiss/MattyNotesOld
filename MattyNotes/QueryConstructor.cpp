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

void QueryConstructor::setOrderByClause(OrderNotesBy OrderBy)
{
	QStringList OrderByTypes = { "", " ORDER BY TypeName", " ORDER BY TypeName DESC",
		" ORDER BY CrDate, CrTime", " ORDER BY CrDate, CrTime DESC",
		" ORDER BY EventDate, EventTime", " ORDER BY EventDate, EventTime DESC" };

	OrderByClause = OrderByTypes[OrderBy];
}

QString QueryConstructor::constructInsertQuery()
{
	QString ResultQuery = "";

	if (TableName!="")
	{
		if (!WhatFieldValue.empty())
		{
			ResultQuery.append(" INSERt INTO " + TableName + "(");

			QMapIterator<QString, QString> *pair = new QMapIterator<QString, QString>(WhatFieldValue);
			while (pair->hasNext())
			{
				ResultQuery.append(pair->key());
			}
			delete pair;

			if (ResultQuery.endsWith(","))
				ResultQuery.chop(1);

			ResultQuery.append(") VALUES(");

			QMapIterator<QString, QString> *pair = new QMapIterator<QString, QString>(WhatFieldValue);
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

		if (WhatToSelectFieldNames.empty())
		{

		}

		else
		{

		}
	}
	return ResultQuery;
}

QString QueryConstructor::constructDeleteQuery()
{
	QString ResultQuery = "";



	return ResultQuery;
}

QString QueryConstructor::constructUpdateQuery()
{
	QString ResultQuery = "";



	return ResultQuery;
}
