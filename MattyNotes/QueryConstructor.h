#ifndef QUERYCONSTRUCTOR_H
#define QUERYCONSTRUCTOR_H

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER


enum OrderNotesBy { NoOrder, Type, TypeDesc, TypeId, CrDate, CrDateDesc, EvDate, EvDateDesc };

class QueryConstructor
{
public:
	QueryConstructor();
	~QueryConstructor();
	
	void setTableName(QString& tableName);
	QString getTableName();
	void setWhatToSelectFieldNames(QStringList& FieldNames);
	QStringList getWhatToSelectFieldNames();
	void setWhereFieldValue(QMap<QString, QString>& FieldValue);
	QMap<QString, QString> getWhereFieldValue();
	void setWhatToSetFieldValue(QMap<QString, QString>& FieldValue);
	QMap<QString, QString> getWhatToSetFieldValue();
	void setOrderByClause(enum OrderNotesBy OrderBy);
	QString getOrderByClause();
	void addWhatToSelectFieldName(QString& FieldName);
	void addWhereFieldValue(QString& Field, QString& Value);
	void addWhatToSetFieldValue(QString Field, QString& Value);
	QString constructInsertQuery();
	QString constructSelectQuery();
	QString constructDeleteQuery();
	QString constructUpdateQuery();

private:

	QString TableName;
	QStringList WhatToSelectFieldNames;
	QMap<QString, QString> WhereFieldValue;
	QMap<QString, QString> WhatToSetFieldValue;
	QString OrderByClause;
	QString constructWhereEqualsClause();
};

#endif // QUERYCONSTRUCTOR_H