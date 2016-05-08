#pragma once

#include <cstdint>
#include <ctime>
#include <memory>
#include <string>

#include "IDataReader.h"

namespace odbc
{
	class statement;
};

class Guid;

class DataReader : public IDataReader
{
public:
	DataReader();
	DataReader(const std::shared_ptr<odbc::statement> &statement, const std::string &commandText);
	DataReader(const DataReader &other) = delete;
	DataReader(DataReader &&other);
	virtual ~DataReader();

	DataReader &operator =(const DataReader &other) = delete;

	friend void swap(DataReader &left, DataReader &right);

	virtual bool Read();

	virtual void Get(const std::string &columnName, std::int8_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::int8_t> &value) const;

	virtual void Get(const std::string &columnName, std::uint8_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::uint8_t> &value) const;

	virtual void Get(const std::string &columnName, std::int16_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::int16_t> &value) const;

	virtual void Get(const std::string &columnName, std::uint16_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::uint16_t> &value) const;

	virtual void Get(const std::string &columnName, std::int32_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::int32_t> &value) const;

	virtual void Get(const std::string &columnName, std::uint32_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::uint32_t> &value) const;

	virtual void Get(const std::string &columnName, std::int64_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::int64_t> &value) const;

	virtual void Get(const std::string &columnName, std::uint64_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::uint64_t> &value) const;

	virtual void Get(const std::string &columnName, float &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<float> &value) const;

	virtual void Get(const std::string &columnName, double &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<double> &value) const;

	virtual void Get(const std::string &columnName, bool &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<bool> &value) const;

	virtual void Get(const std::string &columnName, std::string &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::string> &value) const;

	virtual void Get(const std::string &columnName, std::wstring &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::wstring> &value) const;

	virtual void Get(const std::string &columnName, Guid &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<Guid> &value) const;

	virtual void Get(const std::string &columnName, std::tm &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::tm> &value) const;

private:
	std::string _commandText;

	std::shared_ptr<odbc::statement> _statement;
};

void swap(DataReader &left, DataReader &right);
