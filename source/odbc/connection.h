#pragma once

#include "odbc_base.h"

#include <memory>

namespace odbc
{
	class environment;
};

namespace odbc
{
	class connection : public odbc::odbc_base
	{
	public:
		connection();
		connection(_In_ const std::shared_ptr<odbc::environment> &environment);
		connection(_In_ const std::shared_ptr<odbc::environment> &environment, _In_ const std::string &connectionString);
		connection(const connection &other) = delete;
		connection(connection &&other);
		virtual ~connection();

		connection &operator =(connection other);

		friend void swap(connection  &left, connection &right);

		void open();
		void open(_In_ const std::string &connectionString);
		void close();

		_Success_(return != SQL_INVALID_HANDLE)
		void *get_connection_handle() const;

		void set_attribute(_In_ long attribute, _In_ long value);
		void set_attribute(_In_ long attribute, _In_ unsigned long value);
		void set_attribute(_In_ long attribute, _In_ const std::string &value);

	private:
		std::shared_ptr<odbc::environment> _environment;
		void *_connection;
		std::string _connectionString;
	};

	void swap(connection &left, connection &right);
};
