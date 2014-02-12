#pragma once

#include <memory>

#include "SessionFactoryConfiguration.h"

namespace odbc
{
	class environment;
};

class Session;

class SessionFactory
{
public:
	SessionFactory(const std::shared_ptr<odbc::environment> &connection, const SessionFactoryConfiguration &configuration);
	SessionFactory(const SessionFactory &other);
	virtual ~SessionFactory();

	SessionFactory &operator =(const SessionFactory &other);

	Session Open() const;

private:
	std::shared_ptr<odbc::environment> _environment;
	SessionFactoryConfiguration _configuration;
};
