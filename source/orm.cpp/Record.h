#pragma once

#include "IRecord.h"

#include <cstdint>
#include <ctime>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace odbc
{
	class parameter;
};

class Guid;

class Record : public IRecord
{
public:
	Record();
	Record(const Record &other);
	virtual ~Record();

	Record &operator =(const Record &other);

	virtual void SetSchema(const std::string &schema);
	virtual std::string GetSchema() const;

	virtual void SetTable(const std::string &table);
	virtual std::string GetTable() const;

	virtual void SetIsIdAssigned(const bool isIdAssigned);
	virtual bool IsIdAssigned() const;

	virtual void SetColumn(const std::string &columnName, int8_t &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<int8_t> &value);

	virtual void SetColumn(const std::string &columnName, uint8_t &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<uint8_t> &value);

	virtual void SetColumn(const std::string &columnName, int16_t &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<int16_t> &value);

	virtual void SetColumn(const std::string &columnName, uint16_t &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<uint16_t> &value);

	virtual void SetColumn(const std::string &columnName, int32_t &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<int32_t> &value);

	virtual void SetColumn(const std::string &columnName, uint32_t &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<uint32_t> &value);

	virtual void SetColumn(const std::string &columnName, int64_t &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<int64_t> &value);

	virtual void SetColumn(const std::string &columnName, uint64_t &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<uint64_t> &value);

	virtual void SetColumn(const std::string &columnName, float &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<float> &value);

	virtual void SetColumn(const std::string &columnName, double &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<double> &value);

	virtual void SetColumn(const std::string &columnName, bool &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<bool> &value);

	virtual void SetColumn(const std::string &columnName, std::string &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::string> &value);

	virtual void SetColumn(const std::string &columnName, std::wstring &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<std::wstring> &value);

	virtual void SetColumn(const std::string &columnName, Guid &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<Guid> &value);

	virtual void SetColumn(const std::string &columnName, struct std::tm &value);
	virtual void SetColumn(const std::string &columnName, std::shared_ptr<struct std::tm> &value);

	virtual void AddIdColumn(const std::string &idColumnName);
	virtual void RemoveIdColumn(const std::string &idColumnName);
	virtual bool IsIdColumn(const std::string &idColumnName) const;

	virtual std::vector<std::shared_ptr<odbc::parameter>> &GetParameters();
	virtual const std::vector<std::shared_ptr<odbc::parameter>> &GetParameters() const;

	virtual uint32_t GetNumberOfParameters() const;

	virtual std::string GetColumn(const uint32_t index) const;
	virtual std::shared_ptr<odbc::parameter> GetParameter(const uint32_t index) const;

private:
	void SetColumn(const std::string &columnName, const std::shared_ptr<odbc::parameter> &parameter);

	bool _isIdAssigned;
	std::string _schema;
	std::string _table;
	std::map<std::string, bool> _idColumns;
	std::map<std::string, std::shared_ptr<odbc::parameter>> _parametersByName;
	std::vector<std::shared_ptr<odbc::parameter>> _parameters;
};
