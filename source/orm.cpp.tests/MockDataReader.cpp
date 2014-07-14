#include "stdafx.h"

#include "MockDataReader.h"

#include <Guid.h>

MockDataReader::MockDataReader(const std::map<std::string, std::int32_t> &values, const std::uint32_t numberOfRecords) :
	  _values(values)
	, _currentRecord(0)
	, _numberOfRecords(numberOfRecords)
{
}

MockDataReader::~MockDataReader()
{
}

bool MockDataReader::Read()
{
	return (_currentRecord++ < _numberOfRecords);
}

void MockDataReader::Get(const std::string &columnName, std::int8_t &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (std::int8_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::int8_t> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::int8_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, std::uint8_t &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (std::uint8_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::uint8_t> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::uint8_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, std::int16_t &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (std::int16_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::int16_t> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::int16_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, std::uint16_t &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (std::uint16_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::uint16_t> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::uint16_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, std::int32_t &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::int32_t> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::int32_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, std::uint32_t &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (std::uint32_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::uint32_t> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::uint32_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, std::int64_t &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (std::int64_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::int64_t> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::int64_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, std::uint64_t &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (std::uint64_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::uint64_t> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::uint64_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, float &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (float) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<float> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<float>((float) v);
	}
}


void MockDataReader::Get(const std::string &columnName, double &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (double) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<double> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<double>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, bool &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = (v % 2 == 0);
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<bool> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<bool>(v % 2 == 0);
	}
}


void MockDataReader::Get(const std::string &columnName, std::string &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::to_string(v);
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::string> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::string>(std::to_string(v));
	}
}


void MockDataReader::Get(const std::string &columnName, std::wstring &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::to_wstring(v);
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::wstring> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::int32_t v = columnValue->second;

		value = std::make_shared<std::wstring>(std::to_wstring(v));
	}
}


void MockDataReader::Get(const std::string &columnName, Guid &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value = Guid::Empty;

	if (columnValue != _values.cend())
	{
		value = Guid::NewGuid();
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<Guid> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		value = std::make_shared<Guid>(Guid::NewGuid());
	}
}


void MockDataReader::Get(const std::string &columnName, std::tm &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	std::tm date = {};

	value = date;
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::tm> &value) const
{
	std::map<std::string, std::int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::tm date = {};

		value = std::make_shared<std::tm>(date);
	}
}
