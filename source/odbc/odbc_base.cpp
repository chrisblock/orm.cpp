#include "stdafx.h"

#include "odbc_base.h"

#include <codecvt>
#include <functional>
#include <locale>
#include <map>

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

bool odbc::odbc_base::are_types_convertible(const int16_t parameterCType, const int16_t sqlDataType) const
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

int16_t odbc::odbc_base::get_c_type(const int16_t sqlType) const
{
	int16_t result = 0;

	switch (sqlType)
	{
	case SQL_CHAR:
		result = SQL_C_CHAR;
		break;
	case SQL_VARCHAR:
		result = SQL_C_CHAR;
		break;
	case SQL_LONGVARCHAR:
		result = SQL_C_CHAR;
		break;
	case SQL_WCHAR:
		result = SQL_C_WCHAR;
		break;
	case SQL_WVARCHAR:
		result = SQL_C_WCHAR;
		break;
	case SQL_WLONGVARCHAR:
		result = SQL_C_WCHAR;
		break;
	case SQL_BIT:
		result = SQL_C_BIT;
		break;
	case SQL_TINYINT:
		result = SQL_C_STINYINT;
		break;
	case SQL_SMALLINT:
		result = SQL_C_SSHORT;
		break;
	case SQL_INTEGER:
		result = SQL_C_SLONG;
		break;
	case SQL_BIGINT:
		result = SQL_C_SBIGINT;
		break;
	case SQL_REAL:
		result = SQL_C_FLOAT;
		break;
	case SQL_FLOAT:
		result = SQL_C_DOUBLE;
		break;
	case SQL_DOUBLE:
		result = SQL_C_DOUBLE;
		break;
	case SQL_DECIMAL:
		result = SQL_C_DOUBLE;
		break;
	case SQL_BINARY:
		result = SQL_C_BINARY;
		break;
	case SQL_VARBINARY:
		result = SQL_C_BINARY;
		break;
	case SQL_TYPE_DATE:
		result = SQL_C_TYPE_DATE;
		break;
	case SQL_TYPE_TIME:
		result = SQL_C_TYPE_TIME;
		break;
	case SQL_TYPE_TIMESTAMP:
		result = SQL_C_TYPE_TIMESTAMP;
		break;
	case SQL_NUMERIC:
		result = SQL_C_NUMERIC;
		break;
	case SQL_GUID:
		result = SQL_C_GUID;
		break;
	default:
		std::exception e("Sql type out of range.");

		throw e;
		break;
	}

	return result;
}

void odbc::odbc_base::process_return_code(_In_opt_ void *handle, _In_ int16_t handleType, _In_ int16_t returnCode, _In_z_ const char *errorMessage) const
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

void odbc::odbc_base::trace(_In_opt_ void *handle, _In_ int16_t handleType, _In_ int16_t returnCode) const
{
	std::string diagnostic = read_diagnostic_record(handle, handleType, returnCode);

	::OutputDebugStringA(diagnostic.c_str());
}

void odbc::odbc_base::trace_and_throw(_In_opt_ void *handle, _In_ int16_t handleType, _In_ int16_t returnCode, _In_z_ const char *errorMessage) const
{
	std::string diagnostic = read_diagnostic_record(handle, handleType, returnCode);

	std::string message(errorMessage);
	message.append("\n");
	message.append(diagnostic);

	::OutputDebugStringA(diagnostic.c_str());

	std::exception e(message.c_str());

	throw e;
}

void odbc::odbc_base::throw_unknown_return_code(_In_ int16_t returnCode, _In_z_ const char *errorMessage) const
{
	std::string message("Unknown SQL return code: ");

	message += std::to_string(returnCode);

	message += "\n";

	message += errorMessage;

	std::exception e(message.c_str());

	throw e;
}

std::string odbc::odbc_base::read_diagnostic_record(_In_opt_ void *handle, _In_ int16_t handleType, _In_ int16_t returnCode) const
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
