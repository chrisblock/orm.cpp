#include "stdafx.h"

#include "parameter.h"

#include "binary_data.h"

odbc::parameter::parameter() :
	  _name()
	, _length(0)
{
	::memset(&_value, 0x00000000, sizeof (odbc::column));
}

odbc::parameter::parameter(_In_ const odbc::parameter &other) :
	  _name(other._name)
	, _value(other._value)
	, _length(other._length)
{
}

odbc::parameter::~parameter()
{
	if ((_value.type == SQL_C_CHAR) || (_value.type == SQL_C_BINARY))
	{
		::free(_value.data.UnsignedAnsiString);
	}
	else if (_value.type == SQL_C_WCHAR)
	{
		::free(_value.data.UnicodeString);
	}
}

odbc::parameter &odbc::parameter::operator =(_In_ const odbc::parameter &other)
{
	if (this != &other)
	{
		_name = other._name;
		_value = other._value;
		_length = other._length;
	}

	return *this;
}

std::string odbc::parameter::get_name() const
{
	return _name;
}

void odbc::parameter::set_name(_In_z_ const char *name)
{
	_name = name;
}

int16_t odbc::parameter::get_type() const
{
	return _value.type;
}

void *odbc::parameter::get_value() const
{
	SQLPOINTER result = nullptr;

	if ((_value.type == SQL_C_CHAR) || (_value.type == SQL_C_BINARY))
	{
		result = _value.data.UnsignedAnsiString;
	}
	else if (_value.type == SQL_C_WCHAR)
	{
		result = _value.data.UnicodeString;
	}
	else
	{
		result = (SQLPOINTER) &_value.data;
	}

	return result;
}

int32_t odbc::parameter::get_length() const
{
	return _length;
}

int32_t *odbc::parameter::get_nullable_indicator()
{
	return &_value.indicator;
}

bool odbc::parameter::is_null() const
{
	return (_value.indicator == SQL_NULL_DATA);
}



void odbc::parameter::set(_In_ const char value)
{
	const char v[2] = { value, L'\0' };

	set(v);
}

void odbc::parameter::set(_In_ const wchar_t value)
{
	const wchar_t v[2] = { value, L'\0' };

	set(v);
}



void odbc::parameter::set(_In_opt_z_ const char *value)
{
	set_null(SQL_C_CHAR);

	if (value != nullptr)
	{
		int strLength = ::strlen(value) + 1;

		_length = strLength * sizeof (SQLCHAR);

		_value.data.UnsignedAnsiString = (SQLCHAR *) ::calloc(strLength, sizeof (SQLCHAR));

		::memcpy_s(_value.data.UnsignedAnsiString, _length, value, _length);

		_value.indicator = SQL_NTS;
	}
}

void odbc::parameter::set(_In_opt_z_ const wchar_t *value)
{
	set_null(SQL_C_WCHAR);

	if (value != nullptr)
	{
		int strLength = ::wcslen(value) + 1;

		_length = strLength * sizeof (SQLWCHAR);

		_value.data.UnicodeString = (SQLWCHAR *) ::calloc(strLength, sizeof (SQLWCHAR));

		::memcpy_s(_value.data.UnicodeString, _length, value, _length);

		_value.indicator = SQL_NTS;
	}
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::string> &value)
{
	if (value == nullptr)
	{
		const char *n = nullptr;

		set(n);
	}
	else
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const std::string &value)
{
	set(value.c_str());
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::wstring> &value)
{
	if (value == nullptr)
	{
		const wchar_t *n = nullptr;

		set(n);
	}
	else
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const std::wstring &value)
{
	set(value.c_str());
}



void odbc::parameter::set(_In_ const std::shared_ptr<int8_t> &value)
{
	set_null(SQL_C_STINYINT);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const int8_t value)
{
	set_null(SQL_C_STINYINT);

	_value.data.Character = value;

	_length = sizeof (SQLSCHAR);

	_value.indicator = sizeof (SQLSCHAR);
}



void odbc::parameter::set(_In_ const std::shared_ptr<uint8_t> &value)
{
	set_null(SQL_C_UTINYINT);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const uint8_t value)
{
	set_null(SQL_C_UTINYINT);

	_value.data.UnsignedCharacter = value;

	_length = sizeof (SQLCHAR);

	_value.indicator = sizeof (SQLCHAR);
}



void odbc::parameter::set(_In_ const std::shared_ptr<int16_t> &value)
{
	set_null(SQL_C_SSHORT);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const int16_t value)
{
	set_null(SQL_C_SSHORT);

	_value.data.Short = value;

	_length = sizeof (SQLSMALLINT);

	_value.indicator = sizeof (SQLSMALLINT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<uint16_t> &value)
{
	set_null(SQL_C_USHORT);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const uint16_t value)
{
	set_null(SQL_C_USHORT);

	_value.data.UnsignedShort = value;

	_length = sizeof (SQLUSMALLINT);

	_value.indicator = sizeof (SQLUSMALLINT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<int32_t> &value)
{
	set_null(SQL_C_SLONG);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const int32_t value)
{
	set_null(SQL_C_SLONG);

	_value.data.Long = value;

	_length = sizeof (SQLINTEGER);

	_value.indicator = sizeof (SQLINTEGER);
}



void odbc::parameter::set(_In_ const std::shared_ptr<uint32_t> &value)
{
	set_null(SQL_C_ULONG);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const uint32_t value)
{
	set_null(SQL_C_ULONG);

	_value.data.UnsignedLong = value;

	_length = sizeof (SQLUINTEGER);

	_value.indicator = sizeof (SQLUINTEGER);
}



void odbc::parameter::set(_In_ const std::shared_ptr<int64_t> &value)
{
	set_null(SQL_C_SBIGINT);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const int64_t value)
{
	set_null(SQL_C_SBIGINT);

	_value.data.Int64Value = value;

	_length = sizeof (SQLBIGINT);

	_value.indicator = sizeof (SQLBIGINT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<uint64_t> &value)
{
	set_null(SQL_C_UBIGINT);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const uint64_t value)
{
	set_null(SQL_C_UBIGINT);

	_value.data.UnsignedInt64Value = value;

	_length = sizeof (SQLUBIGINT);

	_value.indicator = sizeof (SQLUBIGINT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<float> &value)
{
	set_null(SQL_C_FLOAT);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const float value)
{
	set_null(SQL_C_FLOAT);

	_value.data.Float = value;

	_length = sizeof (SQLFLOAT);

	_value.indicator = sizeof (SQLFLOAT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<double> &value)
{
	set_null(SQL_C_DOUBLE);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const double value)
{
	set_null(SQL_C_DOUBLE);

	_value.data.Double = value;

	_length = sizeof (SQLDOUBLE);

	_value.indicator = sizeof (SQLDOUBLE);
}



void odbc::parameter::set(_In_ const std::shared_ptr<bool> &value)
{
	set_null(SQL_C_BIT);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const bool value)
{
	set_null(SQL_C_BIT);

	_value.data.UnsignedCharacter = value ? 0xFF : 0x00;

	_length = sizeof (SQLCHAR);

	_value.indicator = sizeof (SQLCHAR);
}



void odbc::parameter::set(_In_ const std::shared_ptr<odbc::binary_data> &value)
{
	set_null(SQL_C_BINARY);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const odbc::binary_data &value)
{
	set_null(SQL_C_BINARY);

	UNREFERENCED_PARAMETER(value);
}



void odbc::parameter::set(_In_ const std::shared_ptr<odbc::date> &value)
{
	set_null(SQL_C_TYPE_DATE);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const odbc::date &value)
{
	set_null(SQL_C_TYPE_DATE);

	_value.data.Date = value;

	_length = sizeof (DATE_STRUCT);

	_value.indicator = sizeof (DATE_STRUCT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<Time> &value)
{
	set_null(SQL_C_TYPE_TIME);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const Time &value)
{
	set_null(SQL_C_TYPE_TIME);

	_value.data.Time = value;

	_length = sizeof (TIME_STRUCT);

	_value.indicator = sizeof (TIME_STRUCT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<DateTime> &value)
{
	set_null(SQL_C_TYPE_TIMESTAMP);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const DateTime &value)
{
	set_null(SQL_C_TYPE_TIMESTAMP);

	_value.data.DateTime = value;

	_length = sizeof (TIMESTAMP_STRUCT);

	_value.indicator = sizeof (TIMESTAMP_STRUCT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<Numeric> &value)
{
	set_null(SQL_C_NUMERIC);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const Numeric &value)
{
	set_null(SQL_C_NUMERIC);

	_value.data.Numeric = value;

	_length = sizeof (SQL_NUMERIC_STRUCT);

	_value.indicator = sizeof (SQL_NUMERIC_STRUCT);
}



void odbc::parameter::set(_In_ const std::shared_ptr<GUID> &value)
{
	set_null(SQL_C_GUID);

	if (value != nullptr)
	{
		set(*value);
	}
}

void odbc::parameter::set(_In_ const GUID &value)
{
	set_null(SQL_C_GUID);

	_value.data.Guid = value;

	_length = sizeof (SQLGUID);

	_value.indicator = sizeof (SQLGUID);
}



void odbc::parameter::set_null(_In_ int16_t type)
{
	if ((_value.c_type == SQL_C_CHAR) || (_value.c_type == SQL_C_BINARY))
	{
		::free(_value.data.UnsignedAnsiString);
	}
	else if (_value.c_type == SQL_C_WCHAR)
	{
		::free(_value.data.UnicodeString);
	}

	_length = 0;

	::memset(&_value, 0x00000000, sizeof (odbc::column));

	_value.type = type;
	_value.c_type = type;
	_value.indicator = SQL_NULL_DATA;
}
