#include "stdafx.h"

#include "Record.h"

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

#include <parameter.h>

#include "Guid.h"

Record::Record() :
	  _isIdAssigned(true)
{
}

Record::Record(const Record &other) :
	  _isIdAssigned(other._isIdAssigned)
	, _schema(other._schema)
	, _table(other._table)
	, _idColumns(other._idColumns)
	, _parametersByName(other._parametersByName)
	, _parameters(other._parameters)
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
		_isIdAssigned = other._isIdAssigned;
		_schema = other._schema;
		_table = other._table;
		_idColumns = other._idColumns;
		_parametersByName = other._parametersByName;
		_parameters = other._parameters;
	}

	return *this;
}

void Record::SetSchema(const std::string &schema)
{
	_schema = schema;
}

std::string Record::GetSchema() const
{
	return _schema;
}

void Record::SetTable(const std::string &table)
{
	_table = table;
}

std::string Record::GetTable() const
{
	return _table;
}

void Record::SetIsIdAssigned(const bool isIdAssigned)
{
	_isIdAssigned = isIdAssigned;
}

bool Record::IsIdAssigned() const
{
	return _isIdAssigned;
}

void Record::SetColumn(const std::string &columnName, std::int8_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::int8_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::uint8_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::uint8_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::int16_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::int16_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::uint16_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::uint16_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::int32_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::int32_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::uint32_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::uint32_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::int64_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::int64_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::uint64_t &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::uint64_t> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, float &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<float> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, double &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<double> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, bool &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<bool> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::string &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::string> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::wstring &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::wstring> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, Guid &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set_name(columnName);
	parameter->set(value);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<Guid> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	std::shared_ptr<GUID> g;

	if (value != nullptr)
	{
		g = std::make_shared<GUID>(*value);
	}

	parameter->set_name(columnName);
	parameter->set(g);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::tm &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	odbc::date_time dt = {};

	dt.year = (std::int16_t) value.tm_year;
	dt.month = (std::int16_t) value.tm_mon;
	dt.day = (std::int16_t) value.tm_mday;
	dt.hour = (std::int16_t) value.tm_hour;
	dt.minute = (std::int16_t) value.tm_min;
	dt.second = (std::int16_t) value.tm_sec;

	parameter->set_name(columnName);
	parameter->set(dt);

	SetColumn(columnName, parameter);
}

void Record::SetColumn(const std::string &columnName, std::shared_ptr<std::tm> &value)
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	std::shared_ptr<odbc::date_time> dt;

	if (value != nullptr)
	{
		odbc::date_time empty = {};

		dt = std::make_shared<odbc::date_time>(empty);

		dt->year = (std::int16_t) value->tm_year;
		dt->month = (std::int16_t) value->tm_mon;
		dt->day = (std::int16_t) value->tm_mday;
		dt->hour = (std::int16_t) value->tm_hour;
		dt->minute = (std::int16_t) value->tm_min;
		dt->second = (std::int16_t) value->tm_sec;
	}

	parameter->set_name(columnName);
	parameter->set(dt);

	SetColumn(columnName, parameter);
}

void Record::AddIdColumn(const std::string &idColumnName)
{
	_idColumns[idColumnName] = true;
}

void Record::RemoveIdColumn(const std::string &idColumnName)
{
	_idColumns.erase(idColumnName);
}

bool Record::IsIdColumn(const std::string &idColumnName) const
{
	std::map<std::string, bool>::const_iterator id = _idColumns.find(idColumnName);

	bool result = (id != _idColumns.cend());

	return result;
}

std::vector<std::shared_ptr<odbc::parameter>> &Record::GetParameters()
{
	return _parameters;
}

const std::vector<std::shared_ptr<odbc::parameter>> &Record::GetParameters() const
{
	return _parameters;
}

std::uint32_t Record::GetNumberOfParameters() const
{
	std::uint32_t result = _parameters.size();

	return result;
}

std::string Record::GetColumn(std::uint32_t index) const
{
	std::string result;

	if (index < _parameters.size())
	{
		const std::shared_ptr<odbc::parameter> &parameter = _parameters.at(index);

		result = parameter->get_name();
	}

	return result;
}

std::shared_ptr<odbc::parameter> Record::GetParameter(std::uint32_t index) const
{
	std::shared_ptr<odbc::parameter> result;
	
	if (index < _parameters.size())
	{
		result = _parameters.at(index);
	}

	return result;
}

void Record::SetColumn(const std::string &columnName, const std::shared_ptr<odbc::parameter> &parameter)
{
	_parameters.push_back(parameter);
	_parametersByName[columnName] = parameter;
}
