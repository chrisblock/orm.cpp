#include "stdafx.h"

#include "SqlColumn.h"

SqlColumn::SqlColumn()
{
}

SqlColumn::SqlColumn(const SqlColumn &other) :
	  _table(other._table)
	, _column(other._column)
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
	}

	return *this;
}

bool SqlColumn::operator ==(const SqlColumn &other) const
{
	bool result = (this == &other);

	if (this != &other)
	{
		result = (_table == other._table)
			&& (_column == other._column);
	}

	return result;
}

bool SqlColumn::operator !=(const SqlColumn &other) const
{
	bool result = !(*this == other);

	return result;
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

std::string SqlColumn::GetColumnString() const
{
	std::string result = _table;

	if (_table.empty() == false)
	{
		result.append(".");
	}

	result.append(_column);

	return result;
}
