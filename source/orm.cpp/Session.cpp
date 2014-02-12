#include "stdafx.h"

#include "Session.h"

Session::Session(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const MappingRegistry &registry) :
	  _environment(environment)
	, _connectionString(connectionString)
	, _registry(registry)
{
}

Session::Session(const Session &other) :
	  _environment(other._environment)
	, _connectionString(other._connectionString)
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
		_registry = other._registry;
	}

	return *this;
}
