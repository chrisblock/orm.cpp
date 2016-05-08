#include "stdafx.h"

#include "SqlPredicate.h"

#include <parameter.h>

void swap(SqlPredicate &left, SqlPredicate &right)
{
	using std::swap;

	swap(left._parameters, right._parameters);
	swap(left._predicate, right._predicate);
}

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

SqlPredicate::SqlPredicate(const SqlPredicate &other) :
	  _predicate(other._predicate)
	, _parameters(other._parameters)
{
}

SqlPredicate::SqlPredicate(SqlPredicate &&other)
{
	swap(*this, other);
}

SqlPredicate::~SqlPredicate()
{
	_parameters.clear();
}

SqlPredicate &SqlPredicate::operator =(SqlPredicate other)
{
	swap(*this, other);

	return *this;
}

bool SqlPredicate::IsEmpty() const
{
	return _predicate.empty();
}

void SqlPredicate::SetPredicate(const std::string &predicate)
{
	_predicate = predicate;
}

std::string SqlPredicate::GetPredicate() const
{
	return _predicate;
}

std::uint32_t SqlPredicate::GetNumberOfParameters() const
{
	return _parameters.size();
}

void SqlPredicate::AddParameter(const std::shared_ptr<odbc::parameter> &parameter)
{
	_parameters.push_back(parameter);
}

std::shared_ptr<odbc::parameter> SqlPredicate::GetParameter(const std::uint32_t index) const
{
	return _parameters.at(index);
}

std::vector<std::shared_ptr<odbc::parameter>>::const_iterator SqlPredicate::begin() const
{
	return cbegin();
}

std::vector<std::shared_ptr<odbc::parameter>>::const_iterator SqlPredicate::cbegin() const
{
	return _parameters.cbegin();
}

std::vector<std::shared_ptr<odbc::parameter>>::const_iterator SqlPredicate::end() const
{
	return cend();
}

std::vector<std::shared_ptr<odbc::parameter>>::const_iterator SqlPredicate::cend() const
{
	return _parameters.cend();
}
