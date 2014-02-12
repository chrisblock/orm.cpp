#pragma once

#include <cstdint>
#include <ctime>
#include <map>
#include <string>

#include <IDataReader.h>

class MockDataReader : public IDataReader
{
public:
	MockDataReader(const std::map<std::string, int32_t> &values, const uint32_t numberOfRecords = 1);
	MockDataReader(const MockDataReader &other) = delete;
	virtual ~MockDataReader();

	MockDataReader &operator =(const MockDataReader &other) = delete;

	virtual bool Read();

	virtual void Get(const std::string &columnName, int8_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<int8_t> &value) const;

	virtual void Get(const std::string &columnName, uint8_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<uint8_t> &value) const;

	virtual void Get(const std::string &columnName, int16_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<int16_t> &value) const;

	virtual void Get(const std::string &columnName, uint16_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<uint16_t> &value) const;

	virtual void Get(const std::string &columnName, int32_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<int32_t> &value) const;

	virtual void Get(const std::string &columnName, uint32_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<uint32_t> &value) const;

	virtual void Get(const std::string &columnName, int64_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<int64_t> &value) const;

	virtual void Get(const std::string &columnName, uint64_t &value) const;
	virtual void Get(const std::string &columnName, std::shared_ptr<uint64_t> &value) const;

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
	uint32_t _currentRecord;
	uint32_t _numberOfRecords;
	std::map<std::string, int32_t> _values;
};
