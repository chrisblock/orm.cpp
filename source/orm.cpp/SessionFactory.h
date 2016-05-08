#pragma once

#include <memory>

#include "SessionFactoryConfiguration.h"

namespace odbc
{
	class environment;
};

namespace orm
{
	class session;
}

namespace orm
{
	class SessionFactory
	{
	public:
		SessionFactory();
		SessionFactory(const std::shared_ptr<odbc::environment> &connection, const SessionFactoryConfiguration &configuration);
		SessionFactory(const SessionFactory &other);
		SessionFactory(SessionFactory &&other);
		virtual ~SessionFactory();

		SessionFactory &operator =(SessionFactory other);

		friend void swap(SessionFactory &left, SessionFactory &right);

		orm::session Open() const;

	private:
		std::shared_ptr<odbc::environment> _environment;
		SessionFactoryConfiguration _configuration;
	};
};
