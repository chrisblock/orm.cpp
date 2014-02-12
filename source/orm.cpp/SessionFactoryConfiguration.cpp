#include "stdafx.h"

#include "SessionFactoryConfiguration.h"

#include "MappingRegistrar.h"

SessionFactoryConfiguration::SessionFactoryConfiguration() :
	  _trusted(false)
{
}

SessionFactoryConfiguration::SessionFactoryConfiguration(const SessionFactoryConfiguration &other) :
	  _driver(other._driver)
	, _server(other._server)
	, _database(other._database)
	, _username(other._username)
	, _password(other._password)
	, _trusted(other._trusted)
	, _registry(other._registry)
{
}

SessionFactoryConfiguration::~SessionFactoryConfiguration()
{
}

SessionFactoryConfiguration &SessionFactoryConfiguration::operator =(const SessionFactoryConfiguration &other)
{
	if (this != &other)
	{
		_driver = other._driver;
		_server = other._server;
		_database = other._database;
		_username = other._username;
		_password = other._password;
		_trusted = other._trusted;
		_registry = other._registry;
	}

	return *this;
}


void SessionFactoryConfiguration::SetDriver(const std::string &driver)
{
	_driver = driver;
}

std::string SessionFactoryConfiguration::GetDriver() const
{
	return _driver;
}


void SessionFactoryConfiguration::SetServer(const std::string &server)
{
	_server = server;
}

std::string SessionFactoryConfiguration::GetServer() const
{
	return _server;
}


void SessionFactoryConfiguration::SetDatabase(const std::string &database)
{
	_database = database;
}

std::string SessionFactoryConfiguration::GetDatabase() const
{
	return _database;
}


void SessionFactoryConfiguration::SetUserName(const std::string &username)
{
	_username = username;
}

std::string SessionFactoryConfiguration::GetUserName() const
{
	return _username;
}


void SessionFactoryConfiguration::SetPassword(const std::string &password)
{
	_password = password;
}

std::string SessionFactoryConfiguration::GetPassword() const
{
	return _password;
}


void SessionFactoryConfiguration::SetTrusted(const bool trusted)
{
	_trusted = trusted;
}

bool SessionFactoryConfiguration::IsTrusted() const
{
	return _trusted;
}


std::string SessionFactoryConfiguration::BuildConnectionString() const
{
	std::string result;

	//Driver={SQL Server Native Client 11.0}; Server=(local); Database=OdbcCppTestDatabase; Trusted_Connection=Yes;

	if (_driver.empty())
	{
		// esplode
	}

	result.append("Driver={");
	result.append(_driver);
	result.append("}; ");

	if (_server.empty())
	{
		// esplode
	}

	result.append("Server=");
	result.append(_server);
	result.append("; ");

	if (_database.empty())
	{
		// esplode
	}

	result.append("Database=");
	result.append(_database);
	result.append("; ");

	if (_trusted)
	{
		result.append("Trusted_Connection=Yes;");
	}
	else
	{
		if (_username.empty() || _password.empty())
		{
			// esplode
		}

		result.append("UserName=");
		result.append(_username);
		result.append("; ");

		result.append("Password=");
		result.append(_password);
		result.append("; ");
	}

	return result;
}

void SessionFactoryConfiguration::ConfigureMappingRegistry(const MappingRegistrar &registrar)
{
	registrar.Register(_registry);
}

MappingRegistry &SessionFactoryConfiguration::GetMappingRegistry()
{
	return _registry;
}

const MappingRegistry &SessionFactoryConfiguration::GetMappingRegistry() const
{
	return _registry;
}
