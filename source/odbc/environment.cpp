#include "stdafx.h"

#include "environment.h"

void odbc::swap(odbc::environment &left, odbc::environment &right)
{
	using std::swap;

	swap(left._environment, right._environment);
}

odbc::environment::environment() :
	  _environment(nullptr)
{
	set_up_connection_pooling();

	RETCODE rc = ::SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &_environment);

	process_return_code(_environment, SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while allocating the environment.");

	rc = ::SQLSetEnvAttr(_environment, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3_80, 0);

	process_return_code(_environment, SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while setting the ODBC version number of the environment.");
}

odbc::environment::environment(odbc::environment &&other) :
	  odbc::environment()
{
	swap(*this, other);
}

odbc::environment::~environment()
{
	if (_environment != nullptr)
	{
		::SQLFreeHandle(SQL_HANDLE_ENV, _environment);

		_environment = nullptr;
	}
}

odbc::environment &odbc::environment::operator =(odbc::environment other)
{
	swap(*this, other);

	return *this;
}

void odbc::environment::set_up_connection_pooling() const
{
	// note about connection pooling:
	//   connection pooling is largely a process-level setting, so it must be called with a NULL handle
	//   the setting can be changed; this, however, does not affect already allocated environments
	//   it is also possible to change the pooling setting for a connection by passing it's handle to the SQLSetEnvAttr function

	//   by default, connection pooling is off (SQL_CP_OFF)
	//   we can manage the number of connection pools to be per-driver (SQL_CP_ONE_PER_DRIVER),
	//   or we can set it to per-environment (SQL_CP_ONE_PER_HENV)
	//   or we can let the driver deal with connection pooling (SQL_CP_DRIVER_AWARE)

	RETCODE rc = ::SQLSetEnvAttr(nullptr, SQL_ATTR_CONNECTION_POOLING, (SQLPOINTER) SQL_CP_ONE_PER_HENV, 0);

	process_return_code(nullptr, SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while setting the connection pooling strategy of the environment.");

	// the alternate connection pool matching types are not supported by the SQL driver; we are stuck with strict matching
	//SQL_CP_STRICT_MATCH
	//SQL_CP_RELAXED_MATCH
	//rc = SQLSetEnvAttr(_environment, SQL_ATTR_CP_MATCH, (SQLPOINTER) SQL_CP_STRICT_MATCH, 0);

	//ProcessReturnCode(_environment, SQL_HANDLE_ENV, rc, __LOC__ _T("Error caught while setting the connection pool matching strategy of the environment."));
}

_Success_(return != SQL_INVALID_HANDLE)
void *odbc::environment::get_environment_handle() const
{
	return _environment;
}

void odbc::environment::get_attribute(_In_ std::int32_t attribute, _Out_ std::int32_t &value) const
{
	std::int32_t length = 0;

	RETCODE rc = ::SQLGetEnvAttr(_environment, attribute, &value, 0, reinterpret_cast<SQLINTEGER *>(&length));

	process_return_code(_environment, SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while reading an environment attribute.");
}

void odbc::environment::set_attribute(_In_ std::int32_t attribute, _In_ std::int32_t value)
{
	RETCODE rc = ::SQLSetEnvAttr(_environment, attribute, &value, 0);

	process_return_code(_environment, SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while setting an environment attribute.");
}

void odbc::environment::get_attribute(_In_ std::int32_t attribute, _Out_ std::string &value) const
{
	std::int32_t length = 0;

	RETCODE rc = ::SQLGetEnvAttr(_environment, attribute, nullptr, 0, reinterpret_cast<SQLINTEGER *>(&length));

	process_return_code(_environment, SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while reading an environment attribute.");

	std::unique_ptr<char[]> str = std::make_unique<char[]>(length + 1);

	rc = ::SQLGetEnvAttr(_environment, attribute, str.get(), length + 1, reinterpret_cast<SQLINTEGER *>(&length));

	process_return_code(_environment, SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while reading an environment attribute.");

	value = str.get();
}

void odbc::environment::set_attribute(_In_ std::int32_t attribute, _In_ const std::string &value)
{
	std::size_t length = value.length();

	RETCODE rc = ::SQLSetEnvAttr(_environment, attribute, (SQLPOINTER) value.data(), length);

	process_return_code(_environment, SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while setting an environment attribute.");
}
