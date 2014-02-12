#include "stdafx.h"

#include "MockDataReader.h"

#include <Guid.h>

MockDataReader::MockDataReader(const std::map<std::string, int32_t> &values, const uint32_t numberOfRecords) :
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

void MockDataReader::Get(const std::string &columnName, int8_t &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (int8_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<int8_t> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<int8_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, uint8_t &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (uint8_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<uint8_t> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<uint8_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, int16_t &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (int16_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<int16_t> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<int16_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, uint16_t &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (uint16_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<uint16_t> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<uint16_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, int32_t &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<int32_t> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<int32_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, uint32_t &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (uint32_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<uint32_t> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<uint32_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, int64_t &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (int64_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<int64_t> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<int64_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, uint64_t &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (uint64_t) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<uint64_t> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<uint64_t>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, float &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (float) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<float> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<float>((float) v);
	}
}


void MockDataReader::Get(const std::string &columnName, double &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (double) v;
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<double> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<double>(v);
	}
}


void MockDataReader::Get(const std::string &columnName, bool &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = (v % 2 == 0);
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<bool> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<bool>(v % 2 == 0);
	}
}


void MockDataReader::Get(const std::string &columnName, std::string &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::to_string(v);
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::string> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<std::string>(std::to_string(v));
	}
}


void MockDataReader::Get(const std::string &columnName, std::wstring &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::to_wstring(v);
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::wstring> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		int32_t v = columnValue->second;

		value = std::make_shared<std::wstring>(std::to_wstring(v));
	}
}


void MockDataReader::Get(const std::string &columnName, Guid &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value = Guid::Empty;

	if (columnValue != _values.cend())
	{
		value = Guid::NewGuid();
	}
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<Guid> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		value = std::make_shared<Guid>(Guid::NewGuid());
	}
}


void MockDataReader::Get(const std::string &columnName, std::tm &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	std::tm date = {};

	value = date;
}

void MockDataReader::Get(const std::string &columnName, std::shared_ptr<std::tm> &value) const
{
	std::map<std::string, int32_t>::const_iterator columnValue = _values.find(columnName);

	value.reset();

	if (columnValue != _values.cend())
	{
		std::tm date = {};

		value = std::make_shared<std::tm>(date);
	}
}
