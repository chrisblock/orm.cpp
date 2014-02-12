#include "stdafx.h"

#include "SqlColumn.h"

SqlColumn::SqlColumn()
{
}

SqlColumn::SqlColumn(const SqlColumn &other) :
	  _table(other._table)
	, _column(other._column)
	, _alias(other._alias)
{
}

SqlColumn::~SqlColumn()
{
}

SqlColumn &SqlColumn::operator =(const SqlColumn &other)
{
	if (this != &other)
	{
		_table = other._table;
		_column = other._column;
		_alias = other._alias;
	}

	return *this;
}

void SqlColumn::SetTable(const std::string &table)
{
	_table = table;
}

std::string SqlColumn::GetTable() const
{
	return _table;
}

void SqlColumn::SetColumn(const std::string &column)
{
	_column = column;
}

std::string SqlColumn::GetColumn() const
{
	return _column;
}

void SqlColumn::SetAlias(const std::string &alias)
{
	_alias = alias;
}

std::string SqlColumn::GetAlias() const
{
	return _alias;
}

std::string SqlColumn::GetColumnString() const
{
	std::string result = _alias;

	if (_alias.empty())
	{
		result = _table + "." + _column;
	}

	return result;
}
