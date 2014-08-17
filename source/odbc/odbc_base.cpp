#include "stdafx.h"

#include "odbc_base.h"

#include <codecvt>
#include <functional>
#include <locale>
#include <map>

#include "sql_c_type.h"
#include "sql_type.h"

odbc::odbc_base::odbc_base()
{
}

odbc::odbc_base::odbc_base(const odbc::odbc_base &other)
{
	other;
}

odbc::odbc_base::~odbc_base()
{
}

std::string odbc::odbc_base::convert_to_string(_In_z_ const char *str) const
{
	std::string result(str);

	return result;
}

std::string odbc::odbc_base::convert_to_string(_In_z_ const wchar_t *str) const
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

	std::string result = converter.to_bytes(str);

	return result;
}

std::wstring odbc::odbc_base::convert_to_wstring(_In_z_ const char *str) const
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

	std::wstring result = converter.from_bytes(str);

	return result;
}

std::wstring odbc::odbc_base::convert_to_wstring(_In_z_ const wchar_t *str) const
{
	std::wstring result(str);

	return result;
}

bool odbc::odbc_base::are_types_convertible(const std::int16_t parameterCType, const std::int16_t sqlDataType) const
{
	bool result = false;

	// TODO: convert this to a static std::map<>???

	if ((parameterCType == SQL_C_CHAR) || (parameterCType == SQL_C_WCHAR) || (parameterCType == SQL_C_BINARY))
	{
		result = true;
	}
	else
	{
		switch (parameterCType)
		{
		case SQL_C_BIT:
		case SQL_C_NUMERIC:
		case SQL_C_STINYINT:
		case SQL_C_UTINYINT:
		case SQL_C_TINYINT:
		case SQL_C_SBIGINT:
		case SQL_C_UBIGINT:
		case SQL_C_SSHORT:
		case SQL_C_USHORT:
		case SQL_C_SLONG:
		case SQL_C_ULONG:
		case SQL_C_LONG:
		case SQL_C_FLOAT:
		case SQL_C_DOUBLE:
			switch (sqlDataType)
			{
			case SQL_CHAR:
			case SQL_VARCHAR:
			case SQL_LONGVARCHAR:
			case SQL_WCHAR:
			case SQL_WVARCHAR:
			case SQL_WLONGVARCHAR:
			case SQL_DECIMAL:
			case SQL_BIT:
			case SQL_TINYINT:
			case SQL_SMALLINT:
			case SQL_INTEGER:
			case SQL_BIGINT:
			case SQL_REAL:
			case SQL_FLOAT:
			case SQL_DOUBLE:
				result = true;
				break;
			default:
				break;
			}
			break;
		case SQL_C_TYPE_DATE:
			switch (sqlDataType)
			{
			case SQL_CHAR:
			case SQL_VARCHAR:
			case SQL_LONGVARCHAR:
			case SQL_WCHAR:
			case SQL_WVARCHAR:
			case SQL_WLONGVARCHAR:
			case SQL_TYPE_DATE:
			case SQL_TYPE_TIMESTAMP:
				result = true;
				break;
			default:
				break;
			}
			break;
		case SQL_C_TYPE_TIME:
			switch (sqlDataType)
			{
			case SQL_CHAR:
			case SQL_VARCHAR:
			case SQL_LONGVARCHAR:
			case SQL_WCHAR:
			case SQL_WVARCHAR:
			case SQL_WLONGVARCHAR:
			case SQL_TYPE_TIME:
			case SQL_TYPE_TIMESTAMP:
				result = true;
				break;
			default:
				break;
			}
			break;
		case SQL_C_TYPE_TIMESTAMP:
			switch (sqlDataType)
			{
			case SQL_CHAR:
			case SQL_VARCHAR:
			case SQL_LONGVARCHAR:
			case SQL_WCHAR:
			case SQL_WVARCHAR:
			case SQL_WLONGVARCHAR:
			case SQL_TYPE_DATE:
			case SQL_TYPE_TIME:
			case SQL_TYPE_TIMESTAMP:
				result = true;
				break;
			default:
				break;
			}
			break;
		case SQL_C_GUID:
			result = (sqlDataType == SQL_GUID);
			break;
		default:
			break;
		}
	}

	// TODO: finish implementing the table at http://msdn.microsoft.com/en-us/library/ms716298(v=vs.85).aspx
	//    the interval types seem...tricky, so i've ignored them for now
	//result = (parameterCType == get_c_type(sqlDataType));

	return result;
}

odbc::sql_c_type odbc::odbc_base::get_c_type(const odbc::sql_type &sqlType) const
{
	odbc::sql_c_type result = odbc::sql_c_type::sql_c_slong;

	switch (sqlType)
	{
	case SQL_CHAR:
		result = odbc::sql_c_type::sql_c_char;
		break;
	case SQL_VARCHAR:
		result = odbc::sql_c_type::sql_c_char;
		break;
	case SQL_LONGVARCHAR:
		result = odbc::sql_c_type::sql_c_char;
		break;
	case SQL_WCHAR:
		result = odbc::sql_c_type::sql_c_wchar;
		break;
	case SQL_WVARCHAR:
		result = odbc::sql_c_type::sql_c_wchar;
		break;
	case SQL_WLONGVARCHAR:
		result = odbc::sql_c_type::sql_c_wchar;
		break;
	case SQL_BIT:
		result = odbc::sql_c_type::sql_c_bit;
		break;
	case SQL_TINYINT:
		result = odbc::sql_c_type::sql_c_stinyint;
		break;
	case SQL_SMALLINT:
		result = odbc::sql_c_type::sql_c_sshort;
		break;
	case SQL_INTEGER:
		result = odbc::sql_c_type::sql_c_slong;
		break;
	case SQL_BIGINT:
		result = odbc::sql_c_type::sql_c_sbigint;
		break;
	case SQL_REAL:
		result = odbc::sql_c_type::sql_c_float;
		break;
	case SQL_FLOAT:
		result = odbc::sql_c_type::sql_c_double;
		break;
	case SQL_DOUBLE:
		result = odbc::sql_c_type::sql_c_double;
		break;
	case SQL_DECIMAL:
		result = odbc::sql_c_type::sql_c_double;
		break;
	case SQL_BINARY:
		result = odbc::sql_c_type::sql_c_binary;
		break;
	case SQL_VARBINARY:
		result = odbc::sql_c_type::sql_c_binary;
		break;
	case SQL_TYPE_DATE:
		result = odbc::sql_c_type::sql_c_date;
		break;
	case SQL_TYPE_TIME:
		result = odbc::sql_c_type::sql_c_time;
		break;
	case SQL_TYPE_TIMESTAMP:
		result = odbc::sql_c_type::sql_c_datetime;
		break;
	case SQL_NUMERIC:
		result = odbc::sql_c_type::sql_c_numeric;
		break;
	case SQL_GUID:
		result = odbc::sql_c_type::sql_c_guid;
		break;
	default:
		std::exception e("Sql type out of range.");

		throw e;
		break;
	}

	return result;
}

std::string odbc::odbc_base::get_c_type_name(const std::int16_t type)
{
#define SQL_C_TYPE_NAME_CASE(Variable, TypeName)		case TypeName: Variable = #TypeName; break

	std::string result;

	switch (type)
	{
		SQL_C_TYPE_NAME_CASE(result, SQL_C_BIT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_CHAR);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_WCHAR);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_UTINYINT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_STINYINT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_USHORT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_SSHORT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_ULONG);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_SLONG);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_UBIGINT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_SBIGINT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_FLOAT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_DOUBLE);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_TINYINT);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_BINARY);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_DATE);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_TYPE_DATE);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_TIME);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_TYPE_TIME);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_TIMESTAMP);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_TYPE_TIMESTAMP);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_NUMERIC);
		SQL_C_TYPE_NAME_CASE(result, SQL_C_GUID);
	default:
		break;
	}

	return result;
}

std::string odbc::odbc_base::get_sql_type_name(const std::int16_t type)
{
#define SQL_TYPE_NAME_CASE(Variable, TypeName)		case TypeName: Variable = #TypeName; break

	std::string result;

	switch (type)
	{
		SQL_TYPE_NAME_CASE(result, SQL_CHAR);
		SQL_TYPE_NAME_CASE(result, SQL_VARCHAR);
		SQL_TYPE_NAME_CASE(result, SQL_LONGVARCHAR);
		SQL_TYPE_NAME_CASE(result, SQL_WCHAR);
		SQL_TYPE_NAME_CASE(result, SQL_WVARCHAR);
		SQL_TYPE_NAME_CASE(result, SQL_WLONGVARCHAR);
		SQL_TYPE_NAME_CASE(result, SQL_DECIMAL);
		SQL_TYPE_NAME_CASE(result, SQL_NUMERIC);
		SQL_TYPE_NAME_CASE(result, SQL_SMALLINT);
		SQL_TYPE_NAME_CASE(result, SQL_INTEGER);
		SQL_TYPE_NAME_CASE(result, SQL_REAL);
		SQL_TYPE_NAME_CASE(result, SQL_FLOAT);
		SQL_TYPE_NAME_CASE(result, SQL_DOUBLE);
		SQL_TYPE_NAME_CASE(result, SQL_BIT);
		SQL_TYPE_NAME_CASE(result, SQL_TINYINT);
		SQL_TYPE_NAME_CASE(result, SQL_BIGINT);
		SQL_TYPE_NAME_CASE(result, SQL_BINARY);
		SQL_TYPE_NAME_CASE(result, SQL_VARBINARY);
		SQL_TYPE_NAME_CASE(result, SQL_LONGVARBINARY);
		SQL_TYPE_NAME_CASE(result, SQL_TYPE_DATE);
		SQL_TYPE_NAME_CASE(result, SQL_TYPE_TIME);
		SQL_TYPE_NAME_CASE(result, SQL_TYPE_TIMESTAMP);
		//SQL_TYPE_NAME_CASE(result, SQL_TYPE_UTCDATETIME);
		//SQL_TYPE_NAME_CASE(result, SQL_TYPE_UTCTIME);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_MONTH);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_YEAR);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_YEAR_TO_MONTH);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_DAY);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_HOUR);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_MINUTE);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_SECOND);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_DAY_TO_HOUR);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_DAY_TO_MINUTE);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_DAY_TO_SECOND);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_HOUR_TO_MINUTE);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_HOUR_TO_SECOND);
		SQL_TYPE_NAME_CASE(result, SQL_INTERVAL_MINUTE_TO_SECOND);
		SQL_TYPE_NAME_CASE(result, SQL_GUID);
	default:
		break;
	}

	return result;
}

void odbc::odbc_base::process_return_code(_In_opt_ void *handle, _In_ std::int16_t handleType, _In_ std::int16_t returnCode, _In_z_ const char *errorMessage) const
{
	switch (returnCode)
	{
	case SQL_SUCCESS:
		trace(handle, handleType, returnCode);
		break;
	case SQL_SUCCESS_WITH_INFO:
		trace(handle, handleType, returnCode);
		break;
	case SQL_ERROR:
		trace_and_throw(handle, handleType, returnCode, errorMessage);
		break;
	case SQL_INVALID_HANDLE:
		trace_and_throw(handle, handleType, returnCode, errorMessage);
		break;
	case SQL_NO_DATA:
		trace(handle, handleType, returnCode);
		break;
	case SQL_NEED_DATA:
		trace(handle, handleType, returnCode);
		break;
	case SQL_STILL_EXECUTING:
		trace(handle, handleType, returnCode);
		break;
	default:
		throw_unknown_return_code(returnCode, errorMessage);
		break;
	}
}

void odbc::odbc_base::trace(_In_opt_ void *handle, _In_ std::int16_t handleType, _In_ std::int16_t returnCode) const
{
	std::string diagnostic = read_diagnostic_record(handle, handleType, returnCode);

	::OutputDebugStringA(diagnostic.c_str());
}

void odbc::odbc_base::trace_and_throw(_In_opt_ void *handle, _In_ std::int16_t handleType, _In_ std::int16_t returnCode, _In_z_ const char *errorMessage) const
{
	std::string diagnostic = read_diagnostic_record(handle, handleType, returnCode);

	std::string message(errorMessage);
	message.append("\n");
	message.append(diagnostic);

	::OutputDebugStringA(diagnostic.c_str());

	std::exception e(message.c_str());

	throw e;
}

void odbc::odbc_base::throw_unknown_return_code(_In_ std::int16_t returnCode, _In_z_ const char *errorMessage) const
{
	std::string message("Unknown SQL return code: ");

	message += std::to_string(returnCode);

	message += "\n";

	message += errorMessage;

	std::exception e(message.c_str());

	throw e;
}

std::string odbc::odbc_base::read_diagnostic_record(_In_opt_ void *handle, _In_ std::int16_t handleType, _In_ std::int16_t returnCode) const
{
	std::string result;
	SQLSMALLINT record = 0;
	SQLINTEGER error = 0;
	SQLCHAR message[1000] = {};
	SQLCHAR state[SQL_SQLSTATE_SIZE + 1] = {};

	if (returnCode == SQL_INVALID_HANDLE)
	{
		std::exception e("Invalid handle!");

		throw e;
	}

	while (::SQLGetDiagRecA(handleType, handle, ++record, state, &error, message, (SQLSMALLINT) _countof(message), (SQLSMALLINT *) nullptr) == SQL_SUCCESS)
	{
		// Hide data truncated..
		if (::strcmp((const char *) state, "01004"))
		{
			result += "[";
			result += (const char *) state;
			result += "] ";

			result += (const char *) message;

			result += " (";

			result += std::to_string(error);
			result += ")\n";
		}
	}

	return result;
}
