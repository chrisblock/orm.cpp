#include "stdafx.h"

#include "sql_column.h"

void orm::sql::swap(orm::sql::sql_column &left, orm::sql::sql_column &right)
{
	using std::swap;

	swap(left._column, right._column);
	swap(left._table, right._table);
}

orm::sql::sql_column::sql_column()
{
}

orm::sql::sql_column::sql_column(const orm::sql::sql_column &other) :
	  _table(other._table)
	, _column(other._column)
{
}

orm::sql::sql_column::sql_column(orm::sql::sql_column &&other) :
	  orm::sql::sql_column()
{
	swap(*this, other);
}

orm::sql::sql_column::~sql_column()
{
}

orm::sql::sql_column &orm::sql::sql_column::operator =(orm::sql::sql_column other)
{
	swap(*this, other);

	return *this;
}

bool orm::sql::sql_column::operator ==(const orm::sql::sql_column &other) const
{
	bool result = (this == &other);

	if (this != &other)
	{
		result = (_table == other._table)
			&& (_column == other._column);
	}

	return result;
}

bool orm::sql::sql_column::operator !=(const orm::sql::sql_column &other) const
{
	bool result = !(*this == other);

	return result;
}

void orm::sql::sql_column::SetTable(const std::string &table)
{
	_table = table;
}

std::string orm::sql::sql_column::GetTable() const
{
	return _table;
}

void orm::sql::sql_column::SetColumn(const std::string &column)
{
	_column = column;
}

std::string orm::sql::sql_column::GetColumn() const
{
	return _column;
}

std::string orm::sql::sql_column::GetColumnString() const
{
	std::string result = _table;

	if (_table.empty() == false)
	{
		result.append(".");
	}

	result.append(_column);

	return result;
}
