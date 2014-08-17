#include "stdafx.h"

#include "sql_indicator.h"

const odbc::sql_indicator odbc::sql_indicator::sql_null_data(SQL_NULL_DATA);
const odbc::sql_indicator odbc::sql_indicator::sql_nts(SQL_NTS);

void odbc::swap(odbc::sql_indicator &left, odbc::sql_indicator &right)
{
	using std::swap;

	swap(left._indicator, right._indicator);
}

odbc::sql_indicator::sql_indicator(const std::int32_t indicator) :
	  _indicator(indicator)
{
}

odbc::sql_indicator::sql_indicator(const odbc::sql_indicator &other) :
	  _indicator(other._indicator)
{
}

odbc::sql_indicator::sql_indicator(odbc::sql_indicator &&other)
{
	swap(*this, other);
}

odbc::sql_indicator::~sql_indicator()
{
}

odbc::sql_indicator &odbc::sql_indicator::operator = (odbc::sql_indicator other)
{
	swap(*this, other);

	return *this;
}

bool odbc::sql_indicator::operator ==(const odbc::sql_indicator &other) const
{
	bool result = (_indicator == other._indicator);

	return result;
}

bool odbc::sql_indicator::operator !=(const odbc::sql_indicator &other) const
{
	bool result = (_indicator == other._indicator);

	return (result == false);
}

odbc::sql_indicator::operator std::int32_t &()
{
	return _indicator;
}

odbc::sql_indicator::operator const std::int32_t &() const
{
	return _indicator;
}
