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

	virtual void SetColumn(const std::string &columnName, int8_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<int8_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, uint8_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<uint8_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, int16_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<int16_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, uint16_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<uint16_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, int32_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<int32_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, uint32_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<uint32_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, int64_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<int64_t> &value) = 0;

	virtual void SetColumn(const std::string &columnName, uint64_t &value) = 0;
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<uint64_t> &value) = 0;

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

	virtual uint32_t GetNumberOfParameters() const = 0;

	virtual std::string GetColumn(const uint32_t index) const = 0;
	virtual std::shared_ptr<odbc::parameter> GetParameter(const uint32_t index) const = 0;
};
