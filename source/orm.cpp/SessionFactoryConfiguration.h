#pragma once

#include <string>

#include "MappingRegistry.h"

class MappingRegistrar;

class SessionFactoryConfiguration
{
public:
	SessionFactoryConfiguration();
	SessionFactoryConfiguration(const SessionFactoryConfiguration &other);
	~SessionFactoryConfiguration();

	SessionFactoryConfiguration &operator =(const SessionFactoryConfiguration &other);

	void SetDriver(const std::string &driver);
	std::string GetDriver() const;

	void SetServer(const std::string &server);
	std::string GetServer() const;

	void SetDatabase(const std::string &database);
	std::string GetDatabase() const;

	void SetUserName(const std::string &username);
	std::string GetUserName() const;

	void SetPassword(const std::string &password);
	std::string GetPassword() const;

	void SetTrusted(const bool trusted);
	bool IsTrusted() const;

	std::string BuildConnectionString() const;

	void ConfigureMappingRegistry(const MappingRegistrar &registrar);

	MappingRegistry &GetMappingRegistry();
	const MappingRegistry &GetMappingRegistry() const;

private:
	bool _trusted;
	std::string _driver;
	std::string _server;
	std::string _database;
	std::string _username;
	std::string _password;
	MappingRegistry _registry;
};
