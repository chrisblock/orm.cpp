#include "stdafx.h"

#include "parameter.h"

#include "binary_data.h"

void odbc::swap(odbc::parameter &left, odbc::parameter &right)
{
	using std::swap;

	swap(left._name, right._name);
	swap(left._value, right._value);
}

odbc::parameter::parameter() :
	  _name()
{
}

odbc::parameter::parameter(_In_ const odbc::parameter &other) :
	  _name(other._name)
	, _value(other._value)
{
}

odbc::parameter::parameter(_In_ odbc::parameter &&other) :
	  odbc::parameter()
{
	swap(*this, other);
}

odbc::parameter::~parameter()
{
}

odbc::parameter &odbc::parameter::operator =(_In_ odbc::parameter other)
{
	swap(*this, other);

	return *this;
}

std::string odbc::parameter::get_name() const
{
	return _name;
}

void odbc::parameter::set_name(_In_ const std::string &name)
{
	_name = name;
}

std::int16_t odbc::parameter::get_type() const
{
	return _value.get_type();
}

void *odbc::parameter::get_value() const
{
	const odbc::column_data &data = _value.get_data();

	void *result = nullptr;

	if ((_value.get_type() == SQL_C_CHAR) || (_value.get_type() == SQL_C_BINARY))
	{
		result = data.UnsignedAnsiString;
	}
	else if (_value.get_type() == SQL_C_WCHAR)
	{
		result = data.UnicodeString;
	}
	else
	{
		result = (SQLPOINTER) &data;
	}

	return result;
}

std::int32_t odbc::parameter::get_length() const
{
	return _value.get_width();
}

std::int32_t *odbc::parameter::get_nullable_indicator()
{
	return &_value.get_indicator();
}

bool odbc::parameter::is_null() const
{
	return _value.is_null();
}



void odbc::parameter::set(_In_ const char value)
{
	const char v[2] = { value, '\0' };

	set(v);
}

void odbc::parameter::set(_In_ const wchar_t value)
{
	const wchar_t v[2] = { value, L'\0' };

	set(v);
}



void odbc::parameter::set(_In_opt_z_ const char *value)
{
	std::string v(value);

	_value = v;
}

void odbc::parameter::set(_In_opt_z_ const wchar_t *value)
{
	std::wstring v(value);

	_value = v;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::string> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::string &value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::wstring> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::wstring &value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::int8_t> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::int8_t value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::uint8_t> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::uint8_t value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::int16_t> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::int16_t value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::uint16_t> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::uint16_t value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::int32_t> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::int32_t value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::uint32_t> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::uint32_t value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::int64_t> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::int64_t value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<std::uint64_t> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const std::uint64_t value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<float> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const float value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<double> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const double value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<bool> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const bool value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<odbc::binary_data> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const odbc::binary_data &value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<odbc::date> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const odbc::date &value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<odbc::time> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const odbc::time &value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<odbc::date_time> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const odbc::date_time &value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<odbc::numeric> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const odbc::numeric &value)
{
	_value = value;
}



void odbc::parameter::set(_In_ const std::shared_ptr<GUID> &value)
{
	_value = value;
}

void odbc::parameter::set(_In_ const GUID &value)
{
	_value = value;
}
