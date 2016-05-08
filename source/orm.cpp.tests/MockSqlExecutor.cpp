#include "stdafx.h"

#include "MockSqlExecutor.h"

#include "MockDataReader.h"

MockSqlExecutor::MockSqlExecutor() :
	  _numberOfRecords(1)
{
}

MockSqlExecutor::MockSqlExecutor(const MockSqlExecutor &other) :
	  _numberOfRecords(other._numberOfRecords)
	, _statement(other._statement)
	, _columnValues(other._columnValues)
{
}

MockSqlExecutor::~MockSqlExecutor()
{
}

MockSqlExecutor &MockSqlExecutor::operator =(const MockSqlExecutor &other)
{
	if (this != &other)
	{
		_numberOfRecords = other._numberOfRecords;
		_statement = other._statement;
		_columnValues = other._columnValues;
	}

	return *this;
}

std::shared_ptr<IDataReader> MockSqlExecutor::ExecuteReader(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const orm::sql::statement &statement) const
{
	environment;
	connectionString;

	MockSqlExecutor *e = const_cast<MockSqlExecutor *>(this);

	e->_statement = statement;

	std::shared_ptr<IDataReader> reader = std::make_shared<MockDataReader>(_columnValues, _numberOfRecords);

	return reader;
}

std::uint32_t MockSqlExecutor::ExecuteSql(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const orm::sql::statement &statement) const
{
	environment;
	connectionString;

	MockSqlExecutor *e = const_cast<MockSqlExecutor *>(this);

	e->_statement = statement;

	return 0;
}

void MockSqlExecutor::SetColumnValue(const std::string &column, const std::int32_t value)
{
	_columnValues[column] = value;
}

orm::sql::statement MockSqlExecutor::GetLastStatement() const
{
	return _statement;
}
