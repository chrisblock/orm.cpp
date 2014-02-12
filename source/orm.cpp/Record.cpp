#include "stdafx.h"

#include "Record.h"

#include <parameter.h>

Record::Record()
{
}

Record::Record(const Record &other) :
	  _parameters(other._parameters)
{
}

Record::~Record()
{
	_parameters.clear();
}

Record &Record::operator =(const Record &other)
{
	if (this != &other)
	{
		_parameters = other._parameters;
	}

	return *this;
}

void Record::SetSchema(const char *schema)
{
	_schema = schema;
}

void Record::SetTable(const char *table)
{
	_table = table;
}

void Record::SetColumn(const char *columnName, int8_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<int8_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, uint8_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<uint8_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, int16_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<int16_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, uint16_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<uint16_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, int32_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<int32_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, uint32_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<uint32_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, int64_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<int64_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, uint64_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<uint64_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, float &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<float> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, double &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<double> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, bool &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<bool> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::string &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<std::string> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::wstring &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<std::wstring> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, Guid &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<Guid> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	std::shared_ptr<GUID> g;

	if (value != nullptr)
	{
		g = std::make_shared<GUID>(*value);
	}

	parameter->set_name(columnName);
	parameter->set(g);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::tm &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	odbc::DateTime dt = {};

	dt.year = (int16_t) value.tm_year;
	dt.month = (int16_t) value.tm_mon;
	dt.day = (int16_t) value.tm_mday;
	dt.hour = (int16_t) value.tm_hour;
	dt.minute = (int16_t) value.tm_min;
	dt.second = (int16_t) value.tm_sec;

	parameter->set_name(columnName);
	parameter->set(dt);

	_parameters.push_back(parameter);
}

void Record::SetColumn(const char *columnName, std::shared_ptr<std::tm> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	std::shared_ptr<odbc::DateTime> dt;

	if (value != nullptr)
	{
		odbc::DateTime empty = {};

		dt = std::make_shared<odbc::DateTime>(empty);

		dt->year = (int16_t) value->tm_year;
		dt->month = (int16_t) value->tm_mon;
		dt->day = (int16_t) value->tm_mday;
		dt->hour = (int16_t) value->tm_hour;
		dt->minute = (int16_t) value->tm_min;
		dt->second = (int16_t) value->tm_sec;
	}

	parameter->set_name(columnName);
	parameter->set(dt);

	_parameters.push_back(parameter);
}

uint32_t Record::GetNumberOfParameters() const
{
	uint32_t result = _parameters.size();

	return result;
}

std::shared_ptr<odbc::parameter> Record::GetParameter(uint32_t index) const
{
	std::shared_ptr<odbc::parameter> result;
	
	if (index < _parameters.size())
	{
		result = _parameters.at(index);
	}

	return result;
}
