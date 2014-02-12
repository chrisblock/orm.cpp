#include "stdafx.h"

#include "SqlTable.h"

SqlTable::SqlTable() :
	  _areNullsAllowed(false)
{
}

SqlTable::SqlTable(const SqlTable &other) :
	  _areNullsAllowed(other._areNullsAllowed)
	, _schema(other._schema)
	, _table(other._table)
{
}

SqlTable::~SqlTable()
{
}

SqlTable &SqlTable::operator =(const SqlTable &other)
{
	if (this != &other)
	{
		_areNullsAllowed = other._areNullsAllowed;
		_schema = other._schema;
		_table = other._schema;
	}

	return *this;
}


void SqlTable::SetSchema(const std::string &schema)
{
	_schema = schema;
}

std::string SqlTable::GetSchema() const
{
	return _schema;
}


void SqlTable::SetTable(const std::string &table)
{
	_table = table;
}

std::string SqlTable::GetTable() const
{
	return _table;
}


void SqlTable::SetAreNullsAllowed(const bool areNullsAllowed)
{
	_areNullsAllowed = areNullsAllowed;
}

bool SqlTable::AreNullsAllowed() const
{
	return _areNullsAllowed;
}
