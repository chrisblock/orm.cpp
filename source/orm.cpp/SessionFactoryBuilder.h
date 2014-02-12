#pragma once

#include <functional>
#include <memory>

namespace odbc
{
	class environment;
};

class SessionFactory;
class SessionFactoryConfiguration;

class SessionFactoryBuilder
{
public:
	SessionFactoryBuilder();
	SessionFactoryBuilder(const SessionFactoryBuilder &other);
	~SessionFactoryBuilder();

	SessionFactoryBuilder &operator =(const SessionFactoryBuilder &other);

	SessionFactory Build(const std::function<void (SessionFactoryConfiguration &)> &configurator) const;
	SessionFactory Build(const SessionFactoryConfiguration &configuration) const;

private:
	std::shared_ptr<odbc::environment> _environment;
};
