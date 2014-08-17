#include "stdafx.h"

#include "sql_type.h"

const odbc::sql_type odbc::sql_type::sql_bit(SQL_BIT);
const odbc::sql_type odbc::sql_type::sql_char(SQL_CHAR);
const odbc::sql_type odbc::sql_type::sql_varchar(SQL_VARCHAR);
const odbc::sql_type odbc::sql_type::sql_longvarchar(SQL_LONGVARCHAR);
const odbc::sql_type odbc::sql_type::sql_wchar(SQL_WCHAR);
const odbc::sql_type odbc::sql_type::sql_wvarchar(SQL_WVARCHAR);
const odbc::sql_type odbc::sql_type::sql_wlongvarchar(SQL_WLONGVARCHAR);
const odbc::sql_type odbc::sql_type::sql_tinyint(SQL_TINYINT);
const odbc::sql_type odbc::sql_type::sql_smallint(SQL_SMALLINT);
const odbc::sql_type odbc::sql_type::sql_integer(SQL_INTEGER);
const odbc::sql_type odbc::sql_type::sql_bigint(SQL_BIGINT);
const odbc::sql_type odbc::sql_type::sql_real(SQL_REAL);
const odbc::sql_type odbc::sql_type::sql_float(SQL_FLOAT);
const odbc::sql_type odbc::sql_type::sql_double(SQL_DOUBLE);
const odbc::sql_type odbc::sql_type::sql_decimal(SQL_DECIMAL);
const odbc::sql_type odbc::sql_type::sql_binary(SQL_BINARY);
const odbc::sql_type odbc::sql_type::sql_varbinary(SQL_VARBINARY);
const odbc::sql_type odbc::sql_type::sql_longvarbinary(SQL_LONGVARBINARY);
const odbc::sql_type odbc::sql_type::sql_date(SQL_TYPE_DATE);
const odbc::sql_type odbc::sql_type::sql_time(SQL_TYPE_TIME);
const odbc::sql_type odbc::sql_type::sql_datetime(SQL_TYPE_TIMESTAMP);
const odbc::sql_type odbc::sql_type::sql_numeric(SQL_NUMERIC);
const odbc::sql_type odbc::sql_type::sql_guid(SQL_GUID);

void odbc::swap(odbc::sql_type &left, odbc::sql_type &right)
{
	using std::swap;

	swap(left._type, right._type);
}

odbc::sql_type::sql_type(const std::int16_t type) :
	  _type(type)
{
}

odbc::sql_type::sql_type(const odbc::sql_type &other) :
	  _type(other._type)
{
}

odbc::sql_type::sql_type(odbc::sql_type &&other)
{
	swap(*this, other);
}

odbc::sql_type::~sql_type()
{
}

odbc::sql_type &odbc::sql_type::operator =(odbc::sql_type other)
{
	swap(*this, other);

	return *this;
}

bool odbc::sql_type::operator ==(const odbc::sql_type &other) const
{
	bool result = (_type == other._type);

	return result;
}

bool odbc::sql_type::operator !=(const odbc::sql_type &other) const
{
	bool result = (*this == other);

	return (result == false);
}

odbc::sql_type::operator std::int16_t() const
{
	return _type;
}
