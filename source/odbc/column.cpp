#include "stdafx.h"

#include "column.h"

#include "binary_data.h"

odbc::column_data odbc::column::empty_column_data = {};

void odbc::swap(odbc::column &left, odbc::column &right)
{
	using std::swap;

	swap(left._bound, right._bound);
	swap(left._c_type, right._c_type);
	swap(left._data, right._data);
	swap(left._indicator, right._indicator);
	swap(left._type, right._type);
	swap(left._width, right._width);
}

odbc::column::column() :
	  _data(empty_column_data)
	, _width(0)
	, _indicator(odbc::sql_indicator::sql_null_data)
	, _type(odbc::sql_type::sql_integer)
	, _c_type(odbc::sql_c_type::sql_c_slong)
	, _bound(false)
{
}

odbc::column::column(const odbc::column &other) :
	  _data(other._data)
	, _width(other._width)
	, _indicator(other._indicator)
	, _type(other._type)
	, _c_type(other._c_type)
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
	if ((get_type() == odbc::sql_type::sql_char) || (get_type() == odbc::sql_type::sql_varchar) || (get_type() == odbc::sql_type::sql_longvarchar) || (get_type() == odbc::sql_type::sql_binary) || (get_type() == odbc::sql_type::sql_varbinary) || (get_type() == odbc::sql_type::sql_longvarbinary))
	{
		::free(_data.UnsignedAnsiString);
	}
	else if ((get_type() == odbc::sql_type::sql_wchar) || (get_type() == odbc::sql_type::sql_wvarchar) || (get_type() == odbc::sql_type::sql_wlongvarchar))
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
	_type = odbc::sql_type::sql_bit;
	_c_type = odbc::sql_c_type::sql_c_bit;
	_indicator = sizeof (std::uint8_t);
	_width = sizeof (std::uint8_t);

	return *this;
}

odbc::column &odbc::column::operator =(float value)
{
	_data.Float = value;
	_type = odbc::sql_type::sql_float;
	_c_type = odbc::sql_c_type::sql_c_float;
	_indicator = sizeof (float);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(double value)
{
	_data.Double = value;
	_type = odbc::sql_type::sql_double;
	_c_type = odbc::sql_c_type::sql_c_double;
	_indicator = sizeof (double);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::int8_t value)
{
	_data.Character = value;
	_type = odbc::sql_type::sql_tinyint;
	_c_type = odbc::sql_c_type::sql_c_stinyint;
	_indicator = sizeof (std::int8_t);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::uint8_t value)
{
	_data.UnsignedCharacter = value;
	_type = odbc::sql_type::sql_tinyint;
	_c_type = odbc::sql_c_type::sql_c_utinyint;
	_indicator = sizeof (std::uint8_t);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::int16_t value)
{
	_data.Short = value;
	_type = odbc::sql_type::sql_smallint;
	_c_type = odbc::sql_c_type::sql_c_sshort;
	_indicator = sizeof (std::int16_t);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::uint16_t value)
{
	_data.UnsignedShort = value;
	_type = odbc::sql_type::sql_smallint;
	_c_type = odbc::sql_c_type::sql_c_ushort;
	_indicator = sizeof (std::uint16_t);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::int32_t value)
{
	_data.Long = value;
	_type = odbc::sql_type::sql_integer;
	_c_type = odbc::sql_c_type::sql_c_slong;
	_indicator = sizeof (std::int32_t);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::uint32_t value)
{
	_data.UnsignedLong = value;
	_type = odbc::sql_type::sql_integer;
	_c_type = odbc::sql_c_type::sql_c_ulong;
	_indicator = sizeof (::uint32_t);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::int64_t value)
{
	_data.Int64Value = value;
	_type = odbc::sql_type::sql_bigint;
	_c_type = odbc::sql_c_type::sql_c_sbigint;
	_indicator = sizeof (std::int64_t);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::uint64_t value)
{
	_data.UnsignedInt64Value = value;
	_type = odbc::sql_type::sql_bigint;
	_c_type = odbc::sql_c_type::sql_c_ubigint;
	_indicator = sizeof (std::uint64_t);
	_width = sizeof (value);

	return *this;
}

odbc::column &odbc::column::operator =(std::string value)
{
	_data.UnsignedAnsiString = static_cast<unsigned char *>(::calloc(value.length() + 1, sizeof (unsigned char)));

	::memcpy_s(_data.UnsignedAnsiString, value.length() + 1, value.c_str(), value.length() + 1);

	_type = odbc::sql_type::sql_char;
	_c_type = odbc::sql_c_type::sql_c_char;
	_indicator = odbc::sql_indicator::sql_nts;
	_width = (value.length() + 1) * sizeof (std::string::value_type);

	return *this;
}

odbc::column &odbc::column::operator =(std::wstring value)
{
	_data.UnicodeString = static_cast<wchar_t *>(::calloc(value.length() + 1, sizeof(wchar_t)));

	::memcpy_s(_data.UnicodeString, (value.length() + 1) * sizeof (wchar_t), value.c_str(), (value.length() + 1) * sizeof (wchar_t));

	_type = odbc::sql_type::sql_wchar;
	_c_type = odbc::sql_c_type::sql_c_wchar;
	_indicator = odbc::sql_indicator::sql_nts;
	_width = (value.length() + 1) * sizeof (std::wstring::value_type);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::binary_data value)
{
	_data.UnsignedAnsiString = static_cast<std::uint8_t *>(::calloc(value.length(), sizeof(std::uint8_t)));

	::memcpy_s(_data.UnsignedAnsiString, value.length(), value.data(), value.length());

	_type = odbc::sql_type::sql_binary;
	_c_type = odbc::sql_c_type::sql_c_binary;
	_indicator = value.length();
	_width = value.length();

	return *this;
}

odbc::column &odbc::column::operator =(odbc::date_time value)
{
	_data.DateTime = value;

	_type = odbc::sql_type::sql_datetime;
	_c_type = odbc::sql_c_type::sql_c_datetime;
	_indicator = sizeof (odbc::date_time);
	_width = sizeof (odbc::date_time);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::date value)
{
	_data.Date = value;

	_type = odbc::sql_type::sql_date;
	_c_type = odbc::sql_c_type::sql_c_date;
	_indicator = sizeof (odbc::date);
	_width = sizeof (odbc::date);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::time value)
{
	_data.Time = value;

	_type = odbc::sql_type::sql_time;
	_c_type = odbc::sql_c_type::sql_c_time;
	_indicator = sizeof (odbc::time);
	_width = sizeof (odbc::time);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::guid value)
{
	_data.Guid = value;

	_type = odbc::sql_type::sql_guid;
	_c_type = odbc::sql_c_type::sql_c_guid;
	_indicator = sizeof (odbc::guid);
	_width = sizeof (odbc::guid);

	return *this;
}

odbc::column &odbc::column::operator =(odbc::numeric value)
{
	_data.Numeric = value;

	_type = odbc::sql_type::sql_numeric;
	_c_type = odbc::sql_c_type::sql_c_numeric;
	_indicator = sizeof (odbc::numeric);
	_width = sizeof (odbc::numeric);

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<bool> value)
{
	if (value == nullptr)
	{
		set_null(odbc::sql_type::sql_bit, odbc::sql_c_type::sql_c_bit);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column &odbc::column::operator =(std::shared_ptr<float> value)
{
	if (value == nullptr)
	{
		set_null(odbc::sql_type::sql_float, odbc::sql_c_type::sql_c_float);
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
		set_null(odbc::sql_type::sql_double, odbc::sql_c_type::sql_c_double);
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
		set_null(odbc::sql_type::sql_tinyint, odbc::sql_c_type::sql_c_stinyint);
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
		set_null(odbc::sql_type::sql_tinyint, odbc::sql_c_type::sql_c_utinyint);
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
		set_null(odbc::sql_type::sql_smallint, odbc::sql_c_type::sql_c_sshort);
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
		set_null(odbc::sql_type::sql_smallint, odbc::sql_c_type::sql_c_ushort);
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
		set_null(odbc::sql_type::sql_integer, odbc::sql_c_type::sql_c_slong);
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
		set_null(odbc::sql_type::sql_integer, odbc::sql_c_type::sql_c_ulong);
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
		set_null(odbc::sql_type::sql_bigint, odbc::sql_c_type::sql_c_sbigint);
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
		set_null(odbc::sql_type::sql_bigint, odbc::sql_c_type::sql_c_ubigint);
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
		set_null(odbc::sql_type::sql_char, odbc::sql_c_type::sql_c_char);
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
		set_null(odbc::sql_type::sql_wchar, odbc::sql_c_type::sql_c_wchar);
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
		set_null(odbc::sql_type::sql_binary, odbc::sql_c_type::sql_c_binary);
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
		set_null(odbc::sql_type::sql_datetime, odbc::sql_c_type::sql_c_datetime);
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
		set_null(odbc::sql_type::sql_date, odbc::sql_c_type::sql_c_date);
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
		set_null(odbc::sql_type::sql_time, odbc::sql_c_type::sql_c_time);
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
		set_null(odbc::sql_type::sql_guid, odbc::sql_c_type::sql_c_guid);
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
		set_null(odbc::sql_type::sql_numeric, odbc::sql_c_type::sql_c_numeric);
	}
	else
	{
		*this = *value;
	}

	return *this;
}

odbc::column::operator bool() const
{
	std::shared_ptr<bool> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	bool result = *ptr;

	return result;
}

odbc::column::operator float() const
{
	std::shared_ptr<float> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	float result = *ptr;

	return result;
}

odbc::column::operator double() const
{
	std::shared_ptr<double> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	double result = *ptr;

	return result;
}

odbc::column::operator std::int8_t() const
{
	std::shared_ptr<std::int8_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::int8_t result = *ptr;

	return result;
}

odbc::column::operator std::uint8_t() const
{
	std::shared_ptr<std::uint8_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::uint8_t result = *ptr;

	return result;
}

odbc::column::operator std::int16_t() const
{
	std::shared_ptr<std::int16_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::int16_t result = *ptr;

	return result;
}

odbc::column::operator std::uint16_t() const
{
	std::shared_ptr<std::uint16_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::uint16_t result = *ptr;

	return result;
}

odbc::column::operator std::int32_t() const
{
	std::shared_ptr<std::int32_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::int32_t result = *ptr;

	return result;
}

odbc::column::operator std::uint32_t() const
{
	std::shared_ptr<std::uint32_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::uint32_t result = *ptr;

	return result;
}

odbc::column::operator std::int64_t() const
{
	std::shared_ptr<std::int64_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::int64_t result = *ptr;

	return result;
}

odbc::column::operator std::uint64_t() const
{
	std::shared_ptr<std::uint64_t> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::uint64_t result = *ptr;

	return result;
}

odbc::column::operator std::string() const
{
	std::shared_ptr<std::string> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}
	std::string result = *ptr;

	return result;
}

odbc::column::operator std::wstring() const
{
	std::shared_ptr<std::wstring> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	std::wstring result = *ptr;

	return result;
}

odbc::column::operator odbc::binary_data() const
{
	std::shared_ptr<binary_data> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	odbc::binary_data result = *ptr;

	return result;
}

odbc::column::operator odbc::date_time() const
{
	std::shared_ptr<odbc::date_time> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	odbc::date_time result = *ptr;

	return result;
}

odbc::column::operator odbc::date() const
{
	std::shared_ptr<odbc::date> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	odbc::date result = *ptr;

	return result;
}

odbc::column::operator odbc::time() const
{
	std::shared_ptr<odbc::time> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	odbc::time result = *ptr;

	return result;
}

odbc::column::operator odbc::guid() const
{
	std::shared_ptr<GUID> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	GUID result = *ptr;

	return result;
}

odbc::column::operator odbc::numeric() const
{
	std::shared_ptr<odbc::numeric> ptr = *this;

	if (ptr == nullptr)
	{
		std::exception e("Cannot convert a NULL value into a non-nullable type.");

		throw e;
	}

	odbc::numeric result = *ptr;

	return result;
}

odbc::column::operator std::shared_ptr<bool>() const
{
	std::shared_ptr<bool> result;

	if (is_null() == false)
	{
		if (_c_type == odbc::sql_c_type::sql_c_bit)
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
		if (_c_type == odbc::sql_c_type::sql_c_float)
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
		if (_c_type == odbc::sql_c_type::sql_c_double)
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
		if (_c_type == odbc::sql_c_type::sql_c_stinyint)
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
		if (_c_type == odbc::sql_c_type::sql_c_utinyint)
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
		if (_c_type == odbc::sql_c_type::sql_c_sshort)
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
		if (_c_type == odbc::sql_c_type::sql_c_ushort)
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
		if (_c_type == odbc::sql_c_type::sql_c_slong)
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
		if (_c_type == odbc::sql_c_type::sql_c_ulong)
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
		if (_c_type == odbc::sql_c_type::sql_c_sbigint)
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
		if (_c_type == odbc::sql_c_type::sql_c_ubigint)
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
		if (_c_type == odbc::sql_c_type::sql_c_char)
		{
			result = std::make_shared<std::string>(convert_to_string(reinterpret_cast<const char *>(_data.UnsignedAnsiString)));
		}
		else if (_c_type == odbc::sql_c_type::sql_c_wchar)
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
		if (_c_type == odbc::sql_c_type::sql_c_wchar)
		{
			result = std::make_shared<std::wstring>(convert_to_wstring(_data.UnicodeString));
		}
		else if (_c_type == odbc::sql_c_type::sql_c_char)
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
		if (_c_type == odbc::sql_c_type::sql_c_binary)
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
		if (_c_type == odbc::sql_c_type::sql_c_datetime)
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
		if (_c_type == odbc::sql_c_type::sql_c_date)
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
		if (_c_type == odbc::sql_c_type::sql_c_time)
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
		if (_c_type == odbc::sql_c_type::sql_c_guid)
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
		if (_c_type == odbc::sql_c_type::sql_c_numeric)
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
	bool result = (_indicator == odbc::sql_indicator::sql_null_data);

	return result;
}

odbc::sql_indicator &odbc::column::get_indicator()
{
	return _indicator;
}

const odbc::sql_indicator &odbc::column::get_indicator() const
{
	return _indicator;
}

void odbc::column::set_indicator(const odbc::sql_indicator indicator)
{
	_indicator = indicator;
}

const odbc::sql_type &odbc::column::get_type() const
{
	return _type;
}

void odbc::column::set_type(const odbc::sql_type &type)
{
	_type = type;
}

const odbc::sql_c_type &odbc::column::get_c_type() const
{
	return _c_type;
}

void odbc::column::set_c_type(const odbc::sql_c_type &type)
{
	_c_type = type;
}

bool odbc::column::bind(const std::function<bool (const std::int16_t, void *, const std::int32_t, std::int32_t &)> &binder)
{
	void *buffer = &_data;
	std::int32_t length = sizeof (odbc::column_data);

	bool is_char_or_binary_type = ((_c_type == odbc::sql_c_type::sql_c_char) || (_c_type == odbc::sql_c_type::sql_c_wchar) || (_c_type == odbc::sql_c_type::sql_c_binary));
	bool do_not_bind = ((get_width() == 0) && is_char_or_binary_type);

	set_is_bound(do_not_bind == false);

	if (do_not_bind == false)
	{
		if (is_char_or_binary_type)
		{
			_width += 1; // include space for the null terminator

			if (_c_type == odbc::sql_c_type::sql_c_wchar)
			{
				length = get_width() * sizeof (wchar_t);
				buffer = ::calloc(get_width(), sizeof (wchar_t));
				_data.UnicodeString = static_cast<wchar_t *>(buffer);
			}
			else
			{
				length = get_width() * sizeof (unsigned char);
				buffer = ::calloc(get_width(), sizeof (unsigned char));
				_data.UnsignedAnsiString = static_cast<unsigned char *>(buffer);
			}
		}

		binder(_c_type, buffer, length, _indicator);
	}

	return (do_not_bind == false);
}

void odbc::column::reset()
{
	if ((_c_type == odbc::sql_c_type::sql_c_char) || (_c_type == odbc::sql_c_type::sql_c_binary))
	{
		::free(_data.UnsignedAnsiString);
	}
	else if (_c_type == odbc::sql_c_type::sql_c_wchar)
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

void odbc::column::set_null(const odbc::sql_type &type, const odbc::sql_c_type &c_type)
{
	if ((_c_type == odbc::sql_c_type::sql_c_char) || (_c_type == odbc::sql_c_type::sql_c_binary))
	{
		::free(_data.UnsignedAnsiString);
	}
	else if (_c_type == odbc::sql_c_type::sql_c_wchar)
	{
		::free(_data.UnicodeString);
	}

	_data = empty_column_data;

	//::memset(&_data, 0x00000000, sizeof (odbc::column_data));

	_type = type;
	_c_type = c_type;
	_indicator = odbc::sql_indicator::sql_null_data;
	_width = 0;
}
