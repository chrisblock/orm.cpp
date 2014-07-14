#pragma once

#include <ISqlExecutor.h>

#include <SqlStatement.h>

class MockSqlExecutor : public ISqlExecutor
{
public:
	MockSqlExecutor();
	MockSqlExecutor(const MockSqlExecutor &other);
	virtual ~MockSqlExecutor();

	MockSqlExecutor &operator =(const MockSqlExecutor &other);

	virtual std::shared_ptr<IDataReader> ExecuteReader(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const SqlStatement &statement) const;
	virtual std::uint32_t ExecuteSql(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const SqlStatement &statement) const;

	void SetColumnValue(const std::string &column, const std::int32_t value);

	SqlStatement GetLastStatement() const;

private:
	std::int32_t _numberOfRecords;
	SqlStatement _statement;
	std::map<std::string, std::int32_t> _columnValues;
};
