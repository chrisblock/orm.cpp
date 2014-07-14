#include "stdafx.h"

#include "column.h"

#include "binary_data.h"

odbc::column_data odbc::column::empty_column_data = {};

void odbc::swap(odbc::column &left, odbc::column &right)
{
	using std::swap;

	swap(left._bound, right._bound);
	swap(left._data, right._data);
	swap(left._indicator, right._indicator);
	swap(left._type, right._type);
	swap(left._width, right._width);
}

odbc::column::column() :
	  _data(empty_column_data)
	, _width(0)
	, _indicator(SQL_NULL_DATA)
	//, _index(0)
	, _type(0)
	, _bound(false)
{
}

odbc::column::column(const odbc::column &other) :
	  _data(other._data)
	, _width(other._width)
	, _indicator(other._indicator)
	//, _index(other._index)
	, _type(other._type)
	, _bound(other._bound)
{
}

odbc::column::column(odbc::column &&other) :
	  odbc::column()
{
	swap(*this, other);
}

odbc::column::~column()
{
	if ((get_type() == SQL_CHAR) || (get_type() == SQL_VARCHAR) || (get_type() == SQL_LONGVARCHAR) || (get_type() == SQL_BINARY) || (get_type() == SQL_VARBINARY) || (get_type() == SQL_LONGVARBINARY))
	{
		::free(_data.UnsignedAnsiString);
	}
	else if ((get_type() == SQL_WCHAR) || (get_type() == SQL_WVARCHAR) || (get_type() == SQL_WLONGVARCHAR))
	{
		::free(_data.UnicodeString);
	}
}

odbc::column &odbc::column::operator =(odbc::column other)
{
	swap(*this, other);

	return *this;
}

odbc::column &odbc::column::operator =(bool value)
{
	_data.UnsignedCharacter = value
		? 0xFF
		: 0x00;
	_type = SQL_C_BIT;
	_indicator = sizeof (std::uint8_t);
	_width = sizeof (std::uint8_t);

	return *this;
}

//odbc::column &odbc::column::operator =(char value)
//{
//	const char v[2] = { value, '\0' };
//
//	std::string s(v);
//
//	*this = s;
//
//	return *this;
//}

//odbc::column &odbc::column::operator =(wchar_t value)
//{
//	const wchar_t v[2] = { value, L'\0' };
//
//	std::wstring s(v);
//
//	*this = s;
//
//	return *this;
//}

odbc::column &odbc::column::operator =(float value)
{
	_data.Float = value;
	_type = SQL_C_FLOAT;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(double value)
{
	_data.Double = value;
	_type = SQL_C_DOUBLE;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::int8_t value)
{
	_data.Character = value;
	_type = SQL_C_STINYINT;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::uint8_t value)
{
	_data.UnsignedCharacter = value;
	_type = SQL_C_UTINYINT;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::int16_t value)
{
	_data.Short = value;
	_type = SQL_C_SSHORT;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::uint16_t value)
{
	_data.UnsignedShort = value;
	_type = SQL_C_USHORT;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::int32_t value)
{
	_data.Long = value;
	_type = SQL_C_SLONG;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::uint32_t value)
{
	_data.UnsignedLong = value;
	_type = SQL_C_ULONG;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::int64_t value)
{
	_data.Int64Value = value;
	_type = SQL_C_SBIGINT;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::uint64_t value)
{
	_data.UnsignedInt64Value = value;
	_type = SQL_C_UBIGINT;
	_indicator = sizeof (value);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::string value)
{
	_data.UnsignedAnsiString = reinterpret_cast<unsigned char *>(::calloc(value.length() + 1, sizeof (unsigned char)));

	::memcpy_s(_data.UnsignedAnsiString, value.length() + 1, value.c_str(), value.length() + 1);

	_type = SQL_C_CHAR;
	_indicator = SQL_NTS;
	_width = (value.length() + 1) * sizeof (unsigned char);

	return *this;
}

odbc::column &odbc::column::operator =(std::wstring value)
{
	_data.UnicodeString = reinterpret_cast<wchar_t *>(::calloc(value.length() + 1, sizeof (wchar_t)));

	::memcpy_s(_data.UnicodeString, (value.length() + 1) * sizeof (wchar_t), value.c_str(), (value.length() + 1) * sizeof (wchar_t));

	_type = SQL_C_WCHAR;
	_indicator = SQL_NTS;
	_width = (value.length() + 1) * sizeof (wchar_t);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::binary_data value)
{
	_data.UnsignedAnsiString = reinterpret_cast<std::uint8_t *>(::calloc(value.length(), sizeof (std::uint8_t)));

	::memcpy_s(_data.UnsignedAnsiString, value.length(), value.data(), value.length());

	_type = SQL_C_BINARY;
	_indicator = value.length();
	_width = value.length();

	return *this;
}

odbc::column &odbc::column::operator =(odbc::date_time value)
{
	_data.DateTime = value;
	_type = SQL_C_TYPE_TIMESTAMP;
	_indicator = sizeof (TIMESTAMP_STRUCT);
	_width = sizeof (TIMESTAMP_STRUCT);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::date value)
{
	_data.Date = value;
	_type = SQL_C_TYPE_DATE;
	_indicator = sizeof (DATE_STRUCT);
	_width = sizeof (DATE_STRUCT);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::time value)
{
	_data.Time = value;
	_type = SQL_C_TYPE_TIME;
	_indicator = sizeof (TIME_STRUCT);
	_width = sizeof (TIME_STRUCT);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::guid value)
{
	_data.Guid = value;

	_type = SQL_C_GUID;
	_indicator = sizeof (odbc::guid);
	_width = sizeof (odbc::guid);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::numeric value)
{
	_data.Numeric = value;

	_type = SQL_C_NUMERIC;
	_indicator = sizeof (odbc::numeric);
	_width = sizeof (odbc::numeric);

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<bool> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_BIT);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

//odbc::column &odbc::column::operator =(std::shared_ptr<char> value)
//{
//	if (value == nullptr)
//	{
//		set_null(SQL_C_CHAR);
//	}
//	else
//	{
//		*this = *value;
//	}
//
//	return *this;
//}

//odbc::column &odbc::column::operator =(std::shared_ptr<wchar_t> value)
//{
//	if (value == nullptr)
//	{
//		set_null(SQL_C_WCHAR);
//	}
//	else
//	{
//		*this = *value;
//	}
//
//	return *this;
//}

odbc::column &odbc::column::operator =(std::shared_ptr<float> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_FLOAT);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<double> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_DOUBLE);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::int8_t> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_STINYINT);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::uint8_t> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_UTINYINT);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::int16_t> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_SSHORT);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::uint16_t> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_USHORT);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::int32_t> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_SLONG);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::uint32_t> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_ULONG);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::int64_t> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_SBIGINT);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::uint64_t> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_UBIGINT);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::string> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_CHAR);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<std::wstring> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_WCHAR);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<odbc::binary_data> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_BINARY);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<odbc::date_time> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_TIMESTAMP);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<odbc::date> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_DATE);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<odbc::time> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_TIME);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<odbc::guid> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_GUID);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<odbc::numeric> value)
{
	if (value == nullptr)
	{
		set_null(SQL_C_NUMERIC);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column::operator bool() const
{
	bool result = false;
	std::shared_ptr<bool> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator float() const
{
	float result = 0.0f;
	std::shared_ptr<float> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator double() const
{
	double result = 0.0;
	std::shared_ptr<double> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::int8_t() const
{
	std::int8_t result = 0;
	std::shared_ptr<std::int8_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::uint8_t() const
{
	std::uint8_t result = 0;
	std::shared_ptr<std::uint8_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::int16_t() const
{
	std::int16_t result = 0;
	std::shared_ptr<std::int16_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::uint16_t() const
{
	std::uint16_t result = 0;
	std::shared_ptr<std::uint16_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::int32_t() const
{
	std::int32_t result = 0;
	std::shared_ptr<std::int32_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::uint32_t() const
{
	std::uint32_t result = 0;
	std::shared_ptr<std::uint32_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::int64_t() const
{
	std::int64_t result = 0;
	std::shared_ptr<std::int64_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::uint64_t() const
{
	std::uint64_t result = 0;
	std::shared_ptr<std::uint64_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::string() const
{
	std::string result;
	std::shared_ptr<std::string> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::wstring() const
{
	std::wstring result;
	std::shared_ptr<std::wstring> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator odbc::binary_data() const
{
	odbc::binary_data result;
	std::shared_ptr<binary_data> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator odbc::date_time() const
{
	odbc::date_time result = {};
	std::shared_ptr<odbc::date_time> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator odbc::date() const
{
	odbc::date result = {};
	std::shared_ptr<odbc::date> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator odbc::time() const
{
	odbc::time result = {};
	std::shared_ptr<odbc::time> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator odbc::guid() const
{
	GUID result = {};
	std::shared_ptr<GUID> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator odbc::numeric() const
{
	odbc::numeric result = {};
	std::shared_ptr<odbc::numeric> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	else
	{
		result = *ptr;
	}

	return result;
}

odbc::column::operator std::shared_ptr<bool>() const
{
	std::shared_ptr<bool> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_BIT)
		{
			result = std::make_shared<bool>((_data.UnsignedCharacter != '\0'));
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<float>() const
{
	std::shared_ptr<float> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_FLOAT)
		{
			result = std::make_shared<float>(_data.Float);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<double>() const
{
	std::shared_ptr<double> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_DOUBLE)
		{
			result = std::make_shared<double>(_data.Double);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::int8_t>() const
{
	std::shared_ptr<std::int8_t> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_STINYINT)
		{
			result = std::make_shared<std::int8_t>(_data.Character);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::uint8_t>() const
{
	std::shared_ptr<std::uint8_t> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_UTINYINT)
		{
			result = std::make_shared<std::uint8_t>(_data.UnsignedCharacter);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::int16_t>() const
{
	std::shared_ptr<std::int16_t> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_SSHORT)
		{
			result = std::make_shared<std::int16_t>(_data.Short);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::uint16_t>() const
{
	std::shared_ptr<std::uint16_t> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_USHORT)
		{
			result = std::make_shared<std::uint16_t>(_data.UnsignedShort);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::int32_t>() const
{
	std::shared_ptr<std::int32_t> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_SLONG)
		{
			result = std::make_shared<::std::int32_t>(_data.Long);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::uint32_t>() const
{
	std::shared_ptr<std::uint32_t> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_ULONG)
		{
			result = std::make_shared<std::uint32_t>(_data.UnsignedLong);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::int64_t>() const
{
	std::shared_ptr<std::int64_t> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_SBIGINT)
		{
			result = std::make_shared<std::int64_t>(_data.Int64Value);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::uint64_t>() const
{
	std::shared_ptr<std::uint64_t> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_UBIGINT)
		{
			result = std::make_shared<std::uint64_t>(_data.UnsignedInt64Value);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::string>() const
{
	std::shared_ptr<std::string> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_CHAR)
		{
			result = std::make_shared<std::string>(convert_to_string(reinterpret_cast<const char *>(_data.UnsignedAnsiString)));
		}
		else if (get_c_type() == SQL_C_WCHAR)
		{
			result = std::make_shared<std::string>(convert_to_string(_data.UnicodeString));
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<std::wstring>() const
{
	std::shared_ptr<std::wstring> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_WCHAR)
		{
			result = std::make_shared<std::wstring>(convert_to_wstring(_data.UnicodeString));
		}
		else if (get_c_type() == SQL_C_CHAR)
		{
			result = std::make_shared<std::wstring>(convert_to_wstring(reinterpret_cast<const char *>(_data.UnsignedAnsiString)));
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<odbc::binary_data>() const
{
	std::shared_ptr<odbc::binary_data> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_BINARY)
		{
			result = std::make_shared<odbc::binary_data>(_data.UnsignedAnsiString, _indicator);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<odbc::date_time>() const
{
	std::shared_ptr<odbc::date_time> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_TYPE_TIMESTAMP)
		{
			result = std::make_shared<odbc::date_time>(_data.DateTime);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<odbc::date>() const
{
	std::shared_ptr<odbc::date> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_TYPE_DATE)
		{
			result = std::make_shared<odbc::date>(_data.Date);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<odbc::time>() const
{
	std::shared_ptr<odbc::time> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_TYPE_TIME)
		{
			result = std::make_shared<odbc::time>(_data.Time);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<GUID>() const
{
	std::shared_ptr<GUID> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_GUID)
		{
			result = std::make_shared<GUID>(_data.Guid);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column::operator std::shared_ptr<odbc::numeric>() const
{
	std::shared_ptr<odbc::numeric> result;

	if (is_null() == false)
	{
		if (get_c_type() == SQL_C_NUMERIC)
		{
			result = std::make_shared<odbc::numeric>(_data.Numeric);
		}
		else
		{
			std::exception e(__LOC_A__ "Column is not of the type specified.");

			throw e;
		}
	}

	return result;
}

odbc::column_data &odbc::column::get_data()
{
	return _data;
}

const odbc::column_data &odbc::column::get_data() const
{
	return _data;
}

std::int32_t odbc::column::get_width() const
{
	return _width;
}

void odbc::column::set_width(const std::int32_t width)
{
	_width = width;
}

bool odbc::column::is_null() const
{
	bool result = (_indicator == SQL_NULL_DATA);

	return result;
}

std::int32_t &odbc::column::get_indicator()
{
	return _indicator;
}

const std::int32_t &odbc::column::get_indicator() const
{
	return _indicator;
}

void odbc::column::set_indicator(const std::int32_t indicator)
{
	_indicator = indicator;
}

std::int16_t odbc::column::get_type() const
{
	return _type;
}

void odbc::column::set_type(const std::int16_t type)
{
	_type = type;
}

std::int16_t odbc::column::get_c_type() const
{
	return odbc_base::get_c_type(_type);
}

bool odbc::column::bind(const std::function<bool (const std::int16_t, void *, const std::int32_t, std::int32_t &)> &binder)
{
	void *buffer = &_data;
	std::int32_t length = sizeof (odbc::column_data);

	bool is_char_or_binary_type = ((get_c_type() == SQL_C_CHAR) || (get_c_type() == SQL_C_WCHAR) || (get_c_type() == SQL_C_BINARY));
	bool do_not_bind = ((get_width() == 0) && is_char_or_binary_type);

	set_is_bound(do_not_bind == false);

	if (do_not_bind == false)
	{
		if (is_char_or_binary_type)
		{
			_width += 1; // include space for the null terminator

			if (get_c_type() == SQL_C_WCHAR)
			{
				length = get_width() * sizeof (wchar_t);
				buffer = ::calloc(get_width(), sizeof (wchar_t));
				_data.UnicodeString = reinterpret_cast<wchar_t *>(buffer);
			}
			else
			{
				length = get_width() * sizeof (unsigned char);
				buffer = ::calloc(get_width(), sizeof (unsigned char));
				_data.UnsignedAnsiString = reinterpret_cast<unsigned char *>(buffer);
			}
		}

		binder(get_c_type(), buffer, length, _indicator);
	}

	return (do_not_bind == false);
}

void odbc::column::reset()
{
	if ((get_c_type() == SQL_C_CHAR) || (get_c_type() == SQL_C_BINARY))
	{
		::free(_data.UnsignedAnsiString);
	}
	else if (get_c_type() == SQL_C_WCHAR)
	{
		::free(_data.UnicodeString);
	}

	::memset(&_data, 0x00000000, sizeof(odbc::column_data));

	_width = 1;
}

bool odbc::column::is_bound() const
{
	return _bound;
}

void odbc::column::set_is_bound(const bool bound)
{
	_bound = bound;
}

void odbc::column::set_null(const std::int16_t type)
{
	if ((get_c_type() == SQL_C_CHAR) || (get_c_type() == SQL_C_BINARY))
	{
		::free(_data.UnsignedAnsiString);
	}
	else if (get_c_type() == SQL_C_WCHAR)
	{
		::free(_data.UnicodeString);
	}

	::memset(&_data, 0x00000000, sizeof (odbc::column_data));

	_type = type;
	_indicator = SQL_NULL_DATA;
	_width = 0;
}
