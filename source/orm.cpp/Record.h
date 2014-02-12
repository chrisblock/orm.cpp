#pragma once

#include <cstdint>
#include <ctime>
#include <memory>
#include <string>

#include "Guid.h"

namespace odbc
{
	class parameter;
};

class Record
{
public:
	Record();
	Record(const Record &other);
	virtual ~Record();

	Record &operator =(const Record &other);

	virtual void SetSchema(const char *schema);

	virtual void SetTable(const char *table);

	virtual void SetColumn(const char *columnName, int8_t &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<int8_t> &value);

	virtual void SetColumn(const char *columnName, uint8_t &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<uint8_t> &value);

	virtual void SetColumn(const char *columnName, int16_t &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<int16_t> &value);

	virtual void SetColumn(const char *columnName, uint16_t &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<uint16_t> &value);

	virtual void SetColumn(const char *columnName, int32_t &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<int32_t> &value);

	virtual void SetColumn(const char *columnName, uint32_t &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<uint32_t> &value);

	virtual void SetColumn(const char *columnName, int64_t &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<int64_t> &value);

	virtual void SetColumn(const char *columnName, uint64_t &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<uint64_t> &value);

	virtual void SetColumn(const char *columnName, float &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<float> &value);

	virtual void SetColumn(const char *columnName, double &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<double> &value);

	virtual void SetColumn(const char *columnName, bool &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<bool> &value);

	virtual void SetColumn(const char *columnName, std::string &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<std::string> &value);

	virtual void SetColumn(const char *columnName, std::wstring &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<std::wstring> &value);

	virtual void SetColumn(const char *columnName, Guid &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<Guid> &value);

	virtual void SetColumn(const char *columnName, struct std::tm &value);
	virtual void SetColumn(const char *columnName, std::shared_ptr<struct std::tm> &value);

	virtual uint32_t GetNumberOfParameters() const;

	virtual std::shared_ptr<odbc::parameter> GetParameter(uint32_t index) const;

private:
	std::string _schema;
	std::string _table;
	std::vector<std::shared_ptr<odbc::parameter>> _parameters;
};
