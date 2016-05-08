#include "stdafx.h"

#include "sql_table.h"

void orm::sql::swap(orm::sql::sql_table &left, orm::sql::sql_table &right)
{
	using std::swap;

	swap(left._schema, right._schema);
	swap(left._table, right._table);
}

orm::sql::sql_table::sql_table()
{
}

orm::sql::sql_table::sql_table(const orm::sql::sql_table &other) :
	  _schema(other._schema)
	, _table(other._table)
{
}

orm::sql::sql_table::sql_table(orm::sql::sql_table &&other) :
	  orm::sql::sql_table()
{
	swap(*this, other);
}

orm::sql::sql_table::~sql_table()
{
}

orm::sql::sql_table &orm::sql::sql_table::operator =(orm::sql::sql_table other)
{
	swap(*this, other);

	return *this;
}

bool orm::sql::sql_table::operator ==(const orm::sql::sql_table &other) const
{
	bool result = (this == &other);

	if (this != &other)
	{
		result = (_schema == other._schema)
			&& (_table == other._table);
	}

	return result;
}

bool orm::sql::sql_table::operator !=(const orm::sql::sql_table &other) const
{
	bool result = !(*this == other);

	return result;
}


void orm::sql::sql_table::SetSchema(const std::string &schema)
{
	_schema = schema;
}

std::string orm::sql::sql_table::GetSchema() const
{
	return _schema;
}


void orm::sql::sql_table::SetTable(const std::string &table)
{
	_table = table;
}

std::string orm::sql::sql_table::GetTable() const
{
	return _table;
}
