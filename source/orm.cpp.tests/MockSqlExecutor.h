#pragma once

#include <ISqlExecutor.h>

#include <map>

#include <statement.h>

class MockSqlExecutor : public ISqlExecutor
{
public:
	MockSqlExecutor();
	MockSqlExecutor(const MockSqlExecutor &other);
	virtual ~MockSqlExecutor();

	MockSqlExecutor &operator =(const MockSqlExecutor &other);

	virtual std::shared_ptr<IDataReader> ExecuteReader(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const orm::sql::statement &statement) const;
	virtual std::uint32_t ExecuteSql(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const orm::sql::statement &statement) const;

	void SetColumnValue(const std::string &column, const std::int32_t value);

	orm::sql::statement GetLastStatement() const;

private:
	std::int32_t _numberOfRecords;
	orm::sql::statement _statement;
	std::map<std::string, std::int32_t> _columnValues;
};
