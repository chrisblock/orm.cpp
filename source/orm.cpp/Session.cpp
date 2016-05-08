#include "stdafx.h"

#include "session.h"

#include <algorithm>
#include <functional>

#include <connection.h>
#include <statement.h>

void orm::swap(orm::session &left, orm::session &right)
{
	using std::swap;

	swap(left._connectionString, right._connectionString);
	swap(left._dialect, right._dialect);
	swap(left._environment, right._environment);
	swap(left._executor, right._executor);
	swap(left._registry, right._registry);
}

orm::session::session()
{
}

orm::session::session(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const std::shared_ptr<ISqlDialect> &dialect, const std::shared_ptr<ISqlExecutor> &executor, const MappingRegistry &registry) :
	  _environment(environment)
	, _connectionString(connectionString)
	, _dialect(dialect)
	, _executor(executor)
	, _registry(registry)
{
}

orm::session::session(const orm::session &other) :
	  _environment(other._environment)
	, _connectionString(other._connectionString)
	, _dialect(other._dialect)
	, _executor(other._executor)
	, _registry(other._registry)
{
}

orm::session::session(orm::session &&other) :
	  orm::session()
{
	swap(*this, other);
}

orm::session::~session()
{
}

orm::session &orm::session::operator =(orm::session other)
{
	swap(*this, other);

	return *this;
}

std::uint32_t orm::session::ExecuteSql(const orm::sql::statement &statement) const
{
	std::uint32_t result = _executor->ExecuteSql(_environment, _connectionString, statement);

	return result;
}
