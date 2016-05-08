#pragma once

#include <functional>
#include <memory>

namespace odbc
{
	class environment;
};

namespace orm
{
	class SessionFactory;
};

class SessionFactoryConfiguration;

namespace orm
{
	class SessionFactoryBuilder
	{
	public:
		SessionFactoryBuilder();
		SessionFactoryBuilder(const SessionFactoryBuilder &other);
		SessionFactoryBuilder(SessionFactoryBuilder &&other);
		~SessionFactoryBuilder();

		SessionFactoryBuilder &operator =(SessionFactoryBuilder other);

		friend void swap(SessionFactoryBuilder &left, SessionFactoryBuilder &right);

		SessionFactory Build(const std::function<void(SessionFactoryConfiguration &)> &configurator) const;
		SessionFactory Build(const SessionFactoryConfiguration &configuration) const;

	private:
		std::shared_ptr<odbc::environment> _environment;
	};

	void swap(SessionFactoryBuilder &left, SessionFactoryBuilder &right);
};
