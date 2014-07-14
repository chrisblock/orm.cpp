#pragma once

#include <cstdint>
#include <memory>
#include <string>

class Guid;

class IDataReader
{
public:
	virtual ~IDataReader();

	virtual bool Read() = 0;

	virtual void Get(const std::string &columnName, std::int8_t &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::int8_t> &value) const = 0;

	virtual void Get(const std::string &columnName, std::uint8_t &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::uint8_t> &value) const = 0;

	virtual void Get(const std::string &columnName, std::int16_t &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::int16_t> &value) const = 0;

	virtual void Get(const std::string &columnName, std::uint16_t &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::uint16_t> &value) const = 0;

	virtual void Get(const std::string &columnName, std::int32_t &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::int32_t> &value) const = 0;

	virtual void Get(const std::string &columnName, std::uint32_t &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::uint32_t> &value) const = 0;

	virtual void Get(const std::string &columnName, std::int64_t &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::int64_t> &value) const = 0;

	virtual void Get(const std::string &columnName, std::uint64_t &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::uint64_t> &value) const = 0;

	virtual void Get(const std::string &columnName, float &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<float> &value) const = 0;

	virtual void Get(const std::string &columnName, double &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<double> &value) const = 0;

	virtual void Get(const std::string &columnName, bool &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<bool> &value) const = 0;

	virtual void Get(const std::string &columnName, std::string &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::string> &value) const = 0;

	virtual void Get(const std::string &columnName, std::wstring &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::wstring> &value) const = 0;

	virtual void Get(const std::string &columnName, Guid &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<Guid> &value) const = 0;

	virtual void Get(const std::string &columnName, std::tm &value) const = 0;
	virtual void Get(const std::string &columnName, std::shared_ptr<std::tm> &value) const = 0;
};
