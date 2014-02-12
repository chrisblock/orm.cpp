#pragma once

#include "odbc_base.h"

namespace odbc
{
	class environment : public odbc::odbc_base
	{
	public:
		environment();
		environment(const environment &other);
		virtual ~environment();

		_Success_(return != SQL_INVALID_HANDLE)
		void *get_environment_handle() const;

		void set_attribute(_In_ long attribute, _In_ long value);
		void set_attribute(_In_ long attribute, _In_z_ const char *value);

	private:
		void *_environment;

		void set_up_connection_pooling() const;
	};
};
