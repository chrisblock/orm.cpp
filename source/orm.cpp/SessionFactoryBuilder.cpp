#include "stdafx.h"

#include "SessionFactoryBuilder.h"

#include <connection.h>
#include <environment.h>

#include "SessionFactory.h"
#include "SessionFactoryConfiguration.h"

SessionFactoryBuilder::SessionFactoryBuilder() :
	  _environment(std::make_shared<odbc::environment>())
{
}

SessionFactoryBuilder::SessionFactoryBuilder(const SessionFactoryBuilder &other) :
	  _environment(other._environment)
{
}

SessionFactoryBuilder::~SessionFactoryBuilder()
{
}

SessionFactoryBuilder &SessionFactoryBuilder::operator = (const SessionFactoryBuilder &other)
{
	if (this != &other)
	{
		_environment = other._environment;
	}

	return *this;
}

SessionFactory SessionFactoryBuilder::Build(const std::function<void (SessionFactoryConfiguration &)> &configurator) const
{
	SessionFactoryConfiguration configuration;

	configurator(configuration);

	return Build(configuration);
}

SessionFactory SessionFactoryBuilder::Build(const SessionFactoryConfiguration &configuration) const
{
	SessionFactory result(_environment, configuration);

	return result;
}
