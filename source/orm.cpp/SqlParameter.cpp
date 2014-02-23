#include "stdafx.h"

#include "SqlParameter.h"

SqlParameter::SqlParameter()
{
}

SqlParameter::SqlParameter(const SqlParameter &other) :
	  _parameter(other._parameter)
{
}

SqlParameter::~SqlParameter()
{
}

SqlParameter &SqlParameter::operator = (const SqlParameter &other)
{
	if (this != &other)
	{
		_parameter = other._parameter;
	}

	return *this;
}

void SqlParameter::SetSqlParameter(const std::shared_ptr<odbc::parameter> &parameter)
{
	_parameter = parameter;
}

std::shared_ptr<odbc::parameter> SqlParameter::GetSqlParameter() const
{
	return _parameter;
}
