#include "stdafx.h"

#include "sql_c_type.h"

const odbc::sql_c_type odbc::sql_c_type::sql_c_bit(SQL_C_BIT);
const odbc::sql_c_type odbc::sql_c_type::sql_c_char(SQL_C_CHAR);
const odbc::sql_c_type odbc::sql_c_type::sql_c_wchar(SQL_C_WCHAR);
const odbc::sql_c_type odbc::sql_c_type::sql_c_stinyint(SQL_C_STINYINT);
const odbc::sql_c_type odbc::sql_c_type::sql_c_utinyint(SQL_C_UTINYINT);
const odbc::sql_c_type odbc::sql_c_type::sql_c_sshort(SQL_C_SSHORT);
const odbc::sql_c_type odbc::sql_c_type::sql_c_ushort(SQL_C_USHORT);
const odbc::sql_c_type odbc::sql_c_type::sql_c_slong(SQL_C_SLONG);
const odbc::sql_c_type odbc::sql_c_type::sql_c_ulong(SQL_C_ULONG);
const odbc::sql_c_type odbc::sql_c_type::sql_c_sbigint(SQL_C_SBIGINT);
const odbc::sql_c_type odbc::sql_c_type::sql_c_ubigint(SQL_C_UBIGINT);
const odbc::sql_c_type odbc::sql_c_type::sql_c_float(SQL_C_FLOAT);
const odbc::sql_c_type odbc::sql_c_type::sql_c_double(SQL_C_DOUBLE);
const odbc::sql_c_type odbc::sql_c_type::sql_c_binary(SQL_C_BINARY);
const odbc::sql_c_type odbc::sql_c_type::sql_c_date(SQL_C_DATE);
const odbc::sql_c_type odbc::sql_c_type::sql_c_time(SQL_C_TIME);
const odbc::sql_c_type odbc::sql_c_type::sql_c_datetime(SQL_C_TIMESTAMP);
const odbc::sql_c_type odbc::sql_c_type::sql_c_numeric(SQL_C_NUMERIC);
const odbc::sql_c_type odbc::sql_c_type::sql_c_guid(SQL_C_GUID);

void odbc::swap(odbc::sql_c_type &left, odbc::sql_c_type &right)
{
	using std::swap;

	swap(left._type, right._type);
}

odbc::sql_c_type::sql_c_type(const std::int16_t type) :
	  _type(type)
{
}

odbc::sql_c_type::sql_c_type(const odbc::sql_c_type &other) :
	  _type(other._type)
{
}

odbc::sql_c_type::sql_c_type(odbc::sql_c_type &&other)
{
	swap(*this, other);
}

odbc::sql_c_type::~sql_c_type()
{
}

odbc::sql_c_type &odbc::sql_c_type::operator =(odbc::sql_c_type other)
{
	swap(*this, other);

	return *this;
}

bool odbc::sql_c_type::operator ==(const odbc::sql_c_type &other) const
{
	bool result = (_type == other._type);

	return result;
}

bool odbc::sql_c_type::operator !=(const odbc::sql_c_type &other) const
{
	bool result = (_type == other._type);

	return (result == false);
}

odbc::sql_c_type::operator std::int16_t() const
{
	return _type;
}
