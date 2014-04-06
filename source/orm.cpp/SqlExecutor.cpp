#include "stdafx.h"

#include "SqlExecutor.h"

#include <algorithm>
#include <functional>

#include <connection.h>
#include <statement.h>

#include "DataReader.h"
#include "SqlStatement.h"

SqlExecutor::SqlExecutor()
{
}

SqlExecutor::SqlExecutor(const SqlExecutor &other)
{
	other;
}

SqlExecutor::~SqlExecutor()
{
}

SqlExecutor &SqlExecutor::operator =(const SqlExecutor &other)
{
	if (this != &other)
	{
	}

	return *this;
}

std::shared_ptr<IDataReader> SqlExecutor::ExecuteReader(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const SqlStatement &statement) const
{
	std::shared_ptr<odbc::connection> connection = std::make_shared<odbc::connection>(environment, connectionString.c_str());

	connection->open();

	std::shared_ptr<odbc::statement> stmt = std::make_shared<odbc::statement>(connection, statement.GetSql().c_str());

	const std::vector<std::shared_ptr<odbc::parameter>> &parameters = statement.GetParameters();

	std::function<void (const std::shared_ptr<odbc::parameter> &)> fn = [&stmt] (const std::shared_ptr<odbc::parameter> &parameter) { stmt->add_parameter(parameter); };

	std::for_each(parameters.cbegin(), parameters.cend(), fn);

	std::shared_ptr<DataReader> reader = std::make_shared<DataReader>(stmt, statement.GetSql());

	return reader;
}

uint32_t SqlExecutor::ExecuteSql(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const SqlStatement &statement) const
{
	std::shared_ptr<odbc::connection> connection = std::make_shared<odbc::connection>(environment, connectionString.c_str());

	connection->open();

	odbc::statement stmt(connection, statement.GetSql().c_str());

	const std::vector<std::shared_ptr<odbc::parameter>> &parameters = statement.GetParameters();

	std::function<void (const std::shared_ptr<odbc::parameter> &)> fn = [&stmt] (const std::shared_ptr<odbc::parameter> &parameter) { stmt.add_parameter(parameter); };

	std::for_each(parameters.cbegin(), parameters.cend(), fn);

	stmt.execute();

	uint32_t result = stmt.get_rows_affected();

	return result;
}
