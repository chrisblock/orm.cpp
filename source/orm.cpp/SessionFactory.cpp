#include "stdafx.h"

#include "SessionFactory.h"

#include "Session.h"
#include "SqlExecutor.h"
#include "SqlServerDialect.h"

SessionFactory::SessionFactory(const std::shared_ptr<odbc::environment> &environment, const SessionFactoryConfiguration &configuration) :
	  _environment(environment)
	, _configuration(configuration)
{
}

SessionFactory::SessionFactory(const SessionFactory &other) :
	  _environment(other._environment)
	, _configuration(other._configuration)
{
}

SessionFactory::~SessionFactory()
{
}

SessionFactory &SessionFactory::operator =(const SessionFactory &other)
{
	if (this != &other)
	{
		_environment = other._environment;
		_configuration = other._configuration;
	}

	return *this;
}

Session SessionFactory::Open() const
{
	std::string connectionString = _configuration.BuildConnectionString();
	const MappingRegistry &registry = _configuration.GetMappingRegistry();

	// TODO: allow this to be configurable...somehow
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<ISqlExecutor> executor = std::make_shared<SqlExecutor>();

	Session result(_environment, connectionString, dialect, executor, registry);

	return result;
}
