#pragma once

#include <cstdint>
#include <ctime>
#include <map>
#include <string>

#include <IDataReader.h>

class MockDataReader : public IDataReader
{
public:
	MockDataReader(const std::map<std::string, std::int32_t> &values, const std::uint32_t numberOfRecords = 1);
	MockDataReader(const MockDataReader &other) = delete;
	virtual ~MockDataReader();

	MockDataReader &operator =(const MockDataReader &other) = delete;

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
	std::uint32_t _currentRecord;
	std::uint32_t _numberOfRecords;
	std::map<std::string, std::int32_t> _values;
};
