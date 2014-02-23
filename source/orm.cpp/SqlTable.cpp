#include "stdafx.h"

#include "SqlTable.h"

SqlTable::SqlTable()
{
}

SqlTable::SqlTable(const SqlTable &other) :
	  _schema(other._schema)
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
		_schema = other._schema;
		_table = other._table;
	}

	return *this;
}

bool SqlTable::operator ==(const SqlTable &other) const
{
	bool result = (this == &other);

	if (this != &other)
	{
		result = (_schema == other._schema)
			&& (_table == other._table);
	}

	return result;
}

bool SqlTable::operator !=(const SqlTable &other) const
{
	bool result = !(*this == other);

	return result;
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
