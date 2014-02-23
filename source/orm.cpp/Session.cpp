#include "stdafx.h"

#include "Session.h"

#include <algorithm>
#include <functional>

#include <connection.h>
#include <statement.h>

Session::Session(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const std::shared_ptr<ISqlDialect> &dialect, const std::shared_ptr<ISqlExecutor> &executor, const MappingRegistry &registry) :
	  _environment(environment)
	, _connectionString(connectionString)
	, _dialect(dialect)
	, _executor(executor)
	, _registry(registry)
{
}

Session::Session(const Session &other) :
	  _environment(other._environment)
	, _connectionString(other._connectionString)
	, _dialect(other._dialect)
	, _executor(other._executor)
	, _registry(other._registry)
{
}

Session::~Session()
{
}

Session &Session::operator =(const Session &other)
{
	if (this != &other)
	{
		_environment = other._environment;
		_connectionString = other._connectionString;
		_dialect = other._dialect;
		_executor = other._executor;
		_registry = other._registry;
	}

	return *this;
}

uint32_t Session::ExecuteSql(const SqlStatement &statement) const
{
	uint32_t result = _executor->ExecuteSql(_environment, _connectionString, statement);

	return result;
}
