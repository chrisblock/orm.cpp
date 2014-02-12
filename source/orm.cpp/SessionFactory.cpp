#include "stdafx.h"

#include "SessionFactory.h"

#include "Session.h"

SessionFactory::SessionFactory(const std::shared_ptr<odbc::environment> &environment, const SessionFactoryConfiguration &configuration) :
	  _environment(environment)
	, _configuration(configuration)
{
}

SessionFactory::SessionFactory(const SessionFactory &other) :
	  _environment(other._environment)
	, _configuration(other._configuration)
{
	other;
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

	Session result(_environment, connectionString, registry);

	return result;
}
