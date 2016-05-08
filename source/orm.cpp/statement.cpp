#include "stdafx.h"

#include "statement.h"

void orm::sql::swap(orm::sql::statement &left, orm::sql::statement &right)
{
	using std::swap;

	swap(left._parameters, right._parameters);
	swap(left._sql, right._sql);
}

orm::sql::statement::statement()
{
}

orm::sql::statement::statement(const orm::sql::statement &other) :
	  _sql(other._sql)
	, _parameters(other._parameters)
{
}

orm::sql::statement::statement(orm::sql::statement &&other) :
	  orm::sql::statement()
{
	swap(*this, other);
}

orm::sql::statement::~statement()
{
}

orm::sql::statement &orm::sql::statement::operator = (orm::sql::statement other)
{
	swap(*this, other);

	return *this;
}

void orm::sql::statement::SetSql(const std::string &sql)
{
	_sql = sql;
}

std::string orm::sql::statement::GetSql() const
{
	return _sql;
}

std::uint32_t orm::sql::statement::GetNumberOfParameters() const
{
	return _parameters.size();
}

void orm::sql::statement::AddParameter(const std::shared_ptr<odbc::parameter> &parameter)
{
	_parameters.push_back(parameter);
}

std::vector<std::shared_ptr<odbc::parameter>> &orm::sql::statement::GetParameters()
{
	return _parameters;
}

const std::vector<std::shared_ptr<odbc::parameter>> &orm::sql::statement::GetParameters() const
{
	return _parameters;
}
