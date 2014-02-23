#include "stdafx.h"

#include "IMappingProvider.h"

IMappingProvider::IMappingProvider() :
	  _schema("dbo")
{
}

IMappingProvider::IMappingProvider(const IMappingProvider &other) :
	  _schema(other._schema)
	, _table(other._table)
{
}

IMappingProvider::~IMappingProvider()
{
}

IMappingProvider &IMappingProvider::operator =(const IMappingProvider &other)
{
	if (this != &other)
	{
		_schema = other._schema;
		_table = other._table;
	}

	return *this;
}

std::string IMappingProvider::GetSchema() const
{
	return _schema;
}

std::string IMappingProvider::GetTable() const
{
	return _table;
}

void IMappingProvider::Schema(const std::string &schema)
{
	_schema = schema;
}

void IMappingProvider::Table(const std::string &table)
{
	_table = table;
}
