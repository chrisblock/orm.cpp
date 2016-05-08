#include "stdafx.h"

#include "SessionFactoryBuilder.h"

#include <connection.h>
#include <environment.h>

#include "SessionFactory.h"
#include "SessionFactoryConfiguration.h"

void orm::swap(SessionFactoryBuilder &left, SessionFactoryBuilder &right)
{
	using std::swap;

	swap(left._environment, right._environment);
}

orm::SessionFactoryBuilder::SessionFactoryBuilder() :
	  _environment(std::make_shared<odbc::environment>())
{
}

orm::SessionFactoryBuilder::SessionFactoryBuilder(const SessionFactoryBuilder &other) :
	  _environment(other._environment)
{
}

orm::SessionFactoryBuilder::SessionFactoryBuilder(SessionFactoryBuilder &&other) :
	  SessionFactoryBuilder()
{
	swap(*this, other);
}

orm::SessionFactoryBuilder::~SessionFactoryBuilder()
{
}

orm::SessionFactoryBuilder &orm::SessionFactoryBuilder::operator =(SessionFactoryBuilder other)
{
	swap(*this, other);

	return *this;
}

orm::SessionFactory orm::SessionFactoryBuilder::Build(const std::function<void(SessionFactoryConfiguration &)> &configurator) const
{
	SessionFactoryConfiguration configuration;

	configurator(configuration);

	return Build(configuration);
}

orm::SessionFactory orm::SessionFactoryBuilder::Build(const SessionFactoryConfiguration &configuration) const
{
	SessionFactory result(_environment, configuration);

	return result;
}
