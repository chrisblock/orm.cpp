#pragma once

#include <cstdint>
#include <string>

#include "odbc_base.h"

namespace odbc
{
	class environment : public odbc::odbc_base
	{
	public:
		environment();
		environment(const environment &other) = delete;
		environment(environment &&other);
		virtual ~environment();

		environment &operator =(environment other);

		friend void swap(environment &left, environment &right);

		_Success_(return != SQL_INVALID_HANDLE)
		void *get_environment_handle() const;

		void get_attribute(_In_ std::int32_t attribute, _Out_ std::int32_t &value) const;
		void set_attribute(_In_ std::int32_t attribute, _In_ std::int32_t value);
		void get_attribute(_In_ std::int32_t attribute, _Out_ std::string &value) const;
		void set_attribute(_In_ std::int32_t attribute, _In_ const std::string &value);

	private:
		// TODO: make this a shared_ptr and allow copy construction of odbc::environment??
		void *_environment;

		void set_up_connection_pooling() const;
	};

	void swap(environment &left, environment &right);
};
