#include "stdafx.h"

#include "SqlPredicate.h"

#include <parameter.h>

SqlPredicate::SqlPredicate()
{
}

SqlPredicate::SqlPredicate(const std::string &predicate) :
	  _predicate(predicate)
{
}

SqlPredicate::SqlPredicate(const std::string &predicate, const std::vector<std::shared_ptr<odbc::parameter>> &parameters) :
	  _predicate(predicate)
	, _parameters(parameters)
{
}

SqlPredicate::~SqlPredicate()
{
	_parameters.clear();
}

SqlPredicate &SqlPredicate::operator =(const SqlPredicate &other)
{
	if (this != &other)
	{
		_predicate = other._predicate;
		_parameters = other._parameters;
	}

	return *this;
}

void SqlPredicate::SetPredicate(const std::string &predicate)
{
	_predicate = predicate;
}

std::string SqlPredicate::GetPredicate() const
{
	return _predicate;
}

uint32_t SqlPredicate::GetNumberOfParameters() const
{
	return _parameters.size();
}

void SqlPredicate::AddParameter(const std::shared_ptr<odbc::parameter> &parameter)
{
	_parameters.push_back(parameter);
}

std::shared_ptr<odbc::parameter> SqlPredicate::GetParameter(uint32_t index) const
{
	return _parameters.at(index);
}

std::vector<std::shared_ptr<odbc::parameter>>::const_iterator SqlPredicate::GetBegin() const
{
	return _parameters.cbegin();
}

std::vector<std::shared_ptr<odbc::parameter>>::const_iterator SqlPredicate::GetEnd() const
{
	return _parameters.cend();
}
