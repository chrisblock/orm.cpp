#include "stdafx.h"

#include "SessionFactory.h"

#include "Session.h"
#include "SqlExecutor.h"
#include "SqlServerDialect.h"

void orm::swap(SessionFactory &left, SessionFactory &right)
{
	using std::swap;

	swap(left._configuration, right._configuration);
	swap(left._environment, right._environment);
}

orm::SessionFactory::SessionFactory()
{
}

orm::SessionFactory::SessionFactory(const std::shared_ptr<odbc::environment> &environment, const SessionFactoryConfiguration &configuration) :
	  _environment(environment)
	, _configuration(configuration)
{
}

orm::SessionFactory::SessionFactory(const SessionFactory &other) :
	  _environment(other._environment)
	, _configuration(other._configuration)
{
}

orm::SessionFactory::SessionFactory(SessionFactory &&other) :
	  SessionFactory()
{
	swap(*this, other);
}

orm::SessionFactory::~SessionFactory()
{
}

orm::SessionFactory &orm::SessionFactory::operator =(SessionFactory other)
{
	swap(*this, other);

	return *this;
}

orm::session orm::SessionFactory::Open() const
{
	std::string connectionString = _configuration.BuildConnectionString();
	const MappingRegistry &registry = _configuration.GetMappingRegistry();

	// TODO: allow this to be configurable...somehow
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<ISqlExecutor> executor = std::make_shared<SqlExecutor>();

	orm::session result(_environment, connectionString, dialect, executor, registry);

	return result;
}
