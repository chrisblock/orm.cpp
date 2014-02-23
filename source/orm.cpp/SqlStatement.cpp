#include "stdafx.h"

#include "SqlStatement.h"

SqlStatement::SqlStatement()
{
}

SqlStatement::SqlStatement(const SqlStatement &other) :
	  _sql(other._sql)
	, _parameters(other._parameters)
{
}

SqlStatement::~SqlStatement()
{
}

SqlStatement &SqlStatement::operator = (const SqlStatement &other)
{
	if (this != &other)
	{
		_sql = other._sql;
		_parameters = other._parameters;
	}

	return *this;
}

void SqlStatement::SetSql(const std::string &sql)
{
	_sql = sql;
}

std::string SqlStatement::GetSql() const
{
	return _sql;
}

uint32_t SqlStatement::GetNumberOfParameters() const
{
	return _parameters.size();
}

void SqlStatement::AddParameter(const std::shared_ptr<odbc::parameter> &parameter)
{
	_parameters.push_back(parameter);
}

std::vector<std::shared_ptr<odbc::parameter>> &SqlStatement::GetParameters()
{
	return _parameters;
}

const std::vector<std::shared_ptr<odbc::parameter>> &SqlStatement::GetParameters() const
{
	return _parameters;
}
