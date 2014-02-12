#include "stdafx.h"

#include "DataReader.h"

#include <column.h>
#include <statement.h>

#include "Guid.h"

DataReader::DataReader(const std::shared_ptr<odbc::statement> &statement, const std::string &commandText) :
	  _statement(statement)
	, _commandText(commandText)
{
}

DataReader::~DataReader()
{
}

bool DataReader::Read()
{
	bool result = _statement->next();

	return result;
}

void DataReader::Get(const std::string &columnName, int8_t &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<int8_t> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, uint8_t &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<uint8_t> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, int16_t &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<int16_t> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, uint16_t &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<uint16_t> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, int32_t &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<int32_t> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, uint32_t &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<uint32_t> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, int64_t &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<int64_t> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, uint64_t &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<uint64_t> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, float &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<float> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, double &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<double> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, bool &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<bool> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::string &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<std::string> &value) const
{
	_statement->get(columnName.c_str(), value);

}

void DataReader::Get(const std::string &columnName, std::wstring &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<std::wstring> &value) const
{
	_statement->get(columnName.c_str(), value);
}

void DataReader::Get(const std::string &columnName, Guid &value) const
{
	GUID v = {};

	_statement->get(columnName.c_str(), v);

	value = v;
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<Guid> &value) const
{
	GUID empty = {};

	std::shared_ptr<GUID> v = std::make_shared<GUID>(empty);

	value.reset();

	_statement->get(columnName.c_str(), v);

	if (v != nullptr)
	{
		value = std::make_shared<Guid>(*v);
	}
}

void DataReader::Get(const std::string &columnName, std::tm &value) const
{
	odbc::DateTime v = {};

	_statement->get(columnName.c_str(), v);

	std::tm t = {};

	// TODO: figure out how to set the *rest* of the properties on the tm struct
	t.tm_year = v.year;
	t.tm_mon = v.month;
	t.tm_mday = v.day;
	t.tm_hour = v.hour;
	t.tm_min = v.minute;
	t.tm_sec = v.second;

	value = t;
}

void DataReader::Get(const std::string &columnName, std::shared_ptr<std::tm> &value) const
{
	odbc::DateTime empty = {};
	std::shared_ptr<odbc::DateTime> v = std::make_shared<odbc::DateTime>(empty);

	value.reset();

	_statement->get(columnName.c_str(), v);

	if (v != nullptr)
	{
		odbc::DateTime r = *v;

		value = std::make_shared<struct std::tm>();

		// TODO: figure out how to set the *rest* of the properties on the tm struct
		value->tm_year = r.year;
		value->tm_mon = r.month;
		value->tm_mday = r.day;
		value->tm_hour = r.hour;
		value->tm_min = r.minute;
		value->tm_sec = r.second;
	}
}
