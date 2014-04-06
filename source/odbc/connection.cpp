#include "stdafx.h"

#include "connection.h"

#include "environment.h"

//#define COLLECT_PERF_STATS

#ifdef COLLECT_PERF_STATS
#include <odbcss.h>
#endif

std::string GetModuleFileNameA()
{
	char buffer[MAX_PATH] = {};
	::GetModuleFileNameA(nullptr, buffer, MAX_PATH);

	char drive[MAX_PATH] = {};
	char directory[MAX_PATH] = {};
	char fileName[MAX_PATH] = {};
	char extension[MAX_PATH] = {};

	::_splitpath_s(buffer, drive, MAX_PATH, directory, MAX_PATH, fileName, MAX_PATH, extension, MAX_PATH);

	std::string result(fileName);

	return result;
}

std::wstring GetModuleFileNameW()
{
	wchar_t buffer[MAX_PATH] = {};
	::GetModuleFileNameW(nullptr, buffer, MAX_PATH);

	wchar_t drive[MAX_PATH] = {};
	wchar_t directory[MAX_PATH] = {};
	wchar_t fileName[MAX_PATH] = {};
	wchar_t extension[MAX_PATH] = {};

	::_wsplitpath_s(buffer, drive, MAX_PATH, directory, MAX_PATH, fileName, MAX_PATH, extension, MAX_PATH);

	std::wstring result(fileName);

	return result;
}

#ifdef UNICODE
#define GetModuleFileName GetModuleFileNameW
#else
#define GetModuleFileName GetModuleFileNameA
#endif

odbc::connection::connection(_In_ const std::shared_ptr<odbc::environment> &environment) :
	  _environment(environment)
	, _connection(nullptr)
{
	RETCODE rc = ::SQLAllocHandle(SQL_HANDLE_DBC, _environment->get_environment_handle(), &_connection);

	process_return_code(_environment->get_environment_handle(), SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while allocating the connection.");
}

odbc::connection::connection(_In_ const std::shared_ptr<odbc::environment> &environment, _In_ const std::string &connectionString) :
	  _environment(environment)
	, _connection(nullptr)
	, _connectionString(connectionString)
{
	RETCODE rc = ::SQLAllocHandle(SQL_HANDLE_DBC, _environment->get_environment_handle(), &_connection);

	process_return_code(_environment->get_environment_handle(), SQL_HANDLE_ENV, rc, __LOC_A__ "Error caught while allocating the connection.");
}

odbc::connection::~connection()
{
	close();

	if (_connection != nullptr)
	{
#ifdef COLLECT_PERF_STATS
		set_attribute(SQL_COPT_SS_PERF_DATA, (SQLUINTEGER)SQL_PERF_STOP);
		set_attribute(SQL_COPT_SS_PERF_QUERY, (SQLUINTEGER)SQL_PERF_STOP);
#endif

		::SQLFreeHandle(SQL_HANDLE_DBC, _connection);

		_connection = nullptr;
	}
}

void odbc::connection::open()
{
	open(_connectionString.c_str());
}

void odbc::connection::open(_In_z_ const std::string &connectionString)
{
	if (connectionString.empty())
	{
		std::exception e("Empty connection string is invalid.");

		throw e;
	}

	RETCODE rc = ::SQLDriverConnectA(_connection, nullptr, (SQLCHAR *) connectionString.c_str(), SQL_NTS, nullptr, 0, nullptr, SQL_DRIVER_NOPROMPT);

	process_return_code(_connection, SQL_HANDLE_DBC, rc, __LOC_A__ "Error while connecting to the database.");

#ifdef COLLECT_PERF_STATS
	std::string moduleFileName = ::GetModuleFileNameA();
	char processId[20] = { };

	::_snprintf_s(processId, 20, "%d", ::GetCurrentProcessId());

	std::string performanceLogFileName("c:\\ODBC_PERF_");
	performanceLogFileName += moduleFileName;
	performanceLogFileName += "_";
	performanceLogFileName += processId;
	performanceLogFileName += ".log";

	set_attribute(SQL_COPT_SS_PERF_DATA_LOG, performanceLogFileName.c_str());
	set_attribute(SQL_COPT_SS_PERF_DATA, (SQLUINTEGER)SQL_PERF_START);

	std::string longRunningQueryLogFileName("c:\\ODBC_LONG_RUNNING_QUERY_");
	longRunningQueryLogFileName += moduleFileName;
	longRunningQueryLogFileName += "_";
	longRunningQueryLogFileName += processId;
	longRunningQueryLogFileName += ".log";

	set_attribute(SQL_COPT_SS_PERF_QUERY_LOG, longRunningQueryLogFileName.c_str());
	set_attribute(SQL_COPT_SS_PERF_QUERY_INTERVAL, (SQLUINTEGER)0U);
	set_attribute(SQL_COPT_SS_PERF_QUERY, (SQLUINTEGER)SQL_PERF_START);
#endif

	//TODO: allow the isolation level to be configured
	set_attribute(SQL_ATTR_TXN_ISOLATION, SQL_TRANSACTION_READ_UNCOMMITTED);
}

void odbc::connection::close()
{
	if (_connection != nullptr)
	{
		::SQLDisconnect(_connection);
	}
}

_Success_(return != SQL_INVALID_HANDLE)
SQLHDBC odbc::connection::get_connection_handle() const
{
	return _connection;
}

void odbc::connection::set_attribute(_In_ long attribute, _In_ long value)
{
	RETCODE rc = ::SQLSetConnectAttrA(_connection, (SQLINTEGER) attribute, (SQLPOINTER) value, SQL_IS_INTEGER);

	process_return_code(_connection, SQL_HANDLE_DBC, rc, __LOC_A__ "Error while setting connection attribute.");
}

void odbc::connection::set_attribute(_In_ long attribute, _In_ unsigned long value)
{
	RETCODE rc = SQLSetConnectAttrA(_connection, (SQLINTEGER) attribute, (SQLPOINTER) value, SQL_IS_UINTEGER);

	process_return_code(_connection, SQL_HANDLE_DBC, rc, __LOC_A__ "Error while setting connection attribute.");
}

void odbc::connection::set_attribute(_In_ long attribute, _In_z_ const std::string &value)
{
	RETCODE rc = ::SQLSetConnectAttrA(_connection, (SQLINTEGER) attribute, (SQLPOINTER) value.c_str(), SQL_NTS);

	process_return_code(_connection, SQL_HANDLE_DBC, rc, __LOC_A__ "Error while setting connection attribute.");
}
