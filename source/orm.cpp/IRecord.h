#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace odbc
{
	class parameter;
};

class Guid;

class IRecord
{
public:
	IRecord();
	IRecord(const IRecord &other);
	virtual ~IRecord();

	IRecord &operator =(const IRecord &other);

	virtual void SetSchema(const std::string &schema) = 0;
	virtual std::string GetSchema() const = 0;

	virtual void SetTable(const std::string &table) = 0;
	virtual std::string GetTable() const = 0;

	virtual void SetIsIdAssigned(const bool isIdAssigned) = 0;
	virtual bool IsIdAssigned() const = 0;

	virtual void SetColumn(const std::string &columnName, std::int8_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::int8_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::uint8_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::uint8_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::int16_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::int16_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::uint16_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::uint16_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::int32_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::int32_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::uint32_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::uint32_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::int64_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::int64_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::uint64_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::uint64_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, float &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<float> &value) = 0;

	virtual void SetColumn(const std::string &columnName, double &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<double> &value) = 0;

	virtual void SetColumn(const std::string &columnName, bool &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<bool> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::string &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::string> &value) = 0;

	virtual void SetColumn(const std::string &columnName, std::wstring &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::wstring> &value) = 0;

	virtual void SetColumn(const std::string &columnName, Guid &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<Guid> &value) = 0;

	virtual void SetColumn(const std::string &columnName, struct std::tm &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<struct std::tm> &value) = 0;

	virtual void AddIdColumn(const std::string &idColumnName) = 0;
	virtual void RemoveIdColumn(const std::string &idColumnName) = 0;
	virtual bool IsIdColumn(const std::string &idColumnName) const = 0;

	virtual std::vector<std::shared_ptr<odbc::parameter>> &GetParameters() = 0;
	virtual const std::vector<std::shared_ptr<odbc::parameter>> &GetParameters() const = 0;

	virtual std::uint32_t GetNumberOfParameters() const = 0;

	virtual std::string GetColumn(const std::uint32_t index) const = 0;
	virtual std::shared_ptr<odbc::parameter> GetParameter(const std::uint32_t index) const = 0;
};
