#include "stdafx.h"

#include "statement.h"

#include "binary_data.h"
#include "column.h"
#include "connection.h"
#include "parameter.h"


std::string GetSqlTypeName(const short type)
{
	std::string result;

	switch (type)
	{
	case SQL_CHAR:
		result = "SQL_CHAR";
		break;
	case SQL_VARCHAR:
		result = "SQL_VARCHAR";
		break;
	case SQL_LONGVARCHAR:
		result = "SQL_LONGVARCHAR";
		break;
	case SQL_WCHAR:
		result = "SQL_WCHAR";
		break;
	case SQL_WVARCHAR:
		result = "SQL_WVARCHAR";
		break;
	case SQL_WLONGVARCHAR:
		result = "SQL_WLONGVARCHAR";
		break;
	case SQL_SMALLINT:
		result = "SQL_SMALLINT";
		break;
	case SQL_INTEGER:
		result = "SQL_INTEGER";
		break;
	case SQL_REAL:
		result = "SQL_REAL";
		break;
	case SQL_DOUBLE:
		result = "SQL_DOUBLE";
		break;
	case SQL_BIT:
		result = "SQL_BIT";
		break;
	case SQL_TINYINT:
		result = "SQL_TINYINT";
		break;
	case SQL_BIGINT:
		result = "SQL_BIGINT";
		break;
	case SQL_BINARY:
		result = "SQL_BINARY";
		break;
	case SQL_VARBINARY:
		result = "SQL_VARBINARY";
		break;
	case SQL_C_DATE:
		result = "SQL_C_DATE";
		break;
	case SQL_C_TYPE_DATE:
		result = "SQL_C_TYPE_DATE";
		break;
	case SQL_C_TIME:
		result = "SQL_C_TIME";
		break;
	case SQL_C_TYPE_TIME:
		result = "SQL_C_TYPE_TIME";
		break;
	case SQL_C_TIMESTAMP:
		result = "SQL_C_TIMESTAMP";
		break;
	case SQL_C_TYPE_TIMESTAMP:
		result = "SQL_C_TYPE_TIMESTAMP";
		break;
	case SQL_NUMERIC:
		result = "SQL_NUMERIC";
		break;
	case SQL_GUID:
		result = "SQL_GUID";
		break;
	default:
		break;
	}

	return result;
}

odbc::statement::statement(const std::shared_ptr<odbc::connection> &connection) :
	  _connection(connection)
	, _statement(nullptr)
{
}

odbc::statement::statement(const std::shared_ptr<odbc::connection> &connection, _In_ const std::string &commandText) :
	  _connection(connection)
	, _commandText(commandText)
	, _statement(nullptr)
{
}

odbc::statement::statement(const odbc::statement &other) :
	  _connection(other._connection)
	, _commandText(other._commandText)
	, _statement(other._statement)
{
}

odbc::statement::~statement()
{
	_nameToIndex.clear();

	_parameters.clear();

	if (_statement != nullptr)
	{
		::SQLFreeStmt(_statement, SQL_UNBIND); //TODO: this call may not be necessary
		::SQLFreeStmt(_statement, SQL_CLOSE); //TODO: this call may not be necessary

		::SQLFreeHandle(SQL_HANDLE_STMT, _statement);

		_statement = nullptr;
	}

	for (short i = 0; i < _numberOfColumns; i++)
	{
		odbc::column &c = _columnBindings[i];

		if ((c.type == SQL_CHAR) || (c.type == SQL_VARCHAR) || (c.type == SQL_LONGVARCHAR) || (c.type == SQL_BINARY) || (c.type == SQL_VARBINARY) || (c.type == SQL_LONGVARBINARY))
		{
			::free(c.data.UnsignedAnsiString);
		}
		else if ((c.type == SQL_WCHAR) || (c.type == SQL_WVARCHAR) || (c.type == SQL_WLONGVARCHAR))
		{
			::free(c.data.UnicodeString);
		}
	}
}

odbc::statement &odbc::statement::operator =(const odbc::statement &other)
{
	if (this != &other)
	{
		_connection = other._connection;
		_commandText = other._commandText;
	}

	return *this;
}

void odbc::statement::add_parameter(const std::shared_ptr<odbc::parameter> &parameter)
{
	_parameters.push_back(parameter);
}

std::string odbc::statement::get_command_text() const
{
	return _commandText;
}

void odbc::statement::set_command_text(_In_ const std::string &commandText)
{
	_commandText = commandText;
}

void odbc::statement::execute()
{
	if (_statement == nullptr)
	{
		RETCODE rc = ::SQLAllocHandle(SQL_HANDLE_STMT, _connection->get_connection_handle(), &_statement);

		process_return_code(_connection->get_connection_handle(), SQL_HANDLE_DBC, rc, __LOC_A__ "Error allocating the SQL statement.");

		prepare();

		bind_parameters();

		rc = ::SQLExecute(_statement);

		process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error executing statement.");
	}
}

bool odbc::statement::next()
{
	if (_statement == nullptr)
	{
		execute();

		read_number_of_columns();
		process_columns();
	}

	RETCODE rc = ::SQLFetch(_statement);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error while fetching the next row of data.");

	bool result = (rc != SQL_NO_DATA_FOUND);

	if (result)
	{
		fetch_unbound_column_data();
	}

	return result;
}

uint32_t odbc::statement::get_rows_affected() const
{
	uint32_t result = 0;

	if (_statement != nullptr)
	{
		SQLINTEGER rows = 0;

		RETCODE rc = ::SQLRowCount(_statement, &rows);

		process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error while determining the number of rows affected.");

		result = rows;
	}

	return result;
}

uint32_t odbc::statement::get_number_of_columns() const
{
	uint32_t result = 0;

	if (_statement != nullptr)
	{
		result = _numberOfColumns;
	}

	return result;
}


bool odbc::statement::is_column_null(const std::string &columnName) const
{
	uint32_t columnIndex = get_column_index(columnName);

	bool result = is_column_null(columnIndex);

	return result;
}

bool odbc::statement::is_column_null(const uint32_t columnIndex) const
{
	odbc::column &column = get_column(columnIndex);

	bool result = (column.indicator == SQL_NULL_DATA);

	return result;
}



void odbc::statement::get(const char *columnName, std::string &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<std::string> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, std::string &value) const
{
	std::shared_ptr<std::string> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<std::string> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if ((column.c_type != SQL_C_CHAR) && (column.c_type != SQL_C_WCHAR))
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		std::shared_ptr<std::string> result = std::make_shared<std::string>();

		if (column.c_type == SQL_C_WCHAR)
		{
			*result = convert_to_string((const wchar_t *) column.data.UnicodeString);
		}
		else
		{
			*result = convert_to_string((const char *)column.data.UnsignedAnsiString);
		}

		value = result;
	}
}



void odbc::statement::get(const char *columnName, std::wstring &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<std::wstring> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, std::wstring &value) const
{
	std::shared_ptr<std::wstring> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<std::wstring> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if ((column.c_type != SQL_C_CHAR) && (column.c_type != SQL_C_WCHAR))
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		std::shared_ptr<std::wstring> result = std::make_shared<std::wstring>();

		if (column.c_type == SQL_C_WCHAR)
		{
			*result = convert_to_wstring((const wchar_t *) column.data.UnicodeString);
		}
		else
		{
			*result = convert_to_wstring((const char *) column.data.UnsignedAnsiString);
		}

		value = result;
	}
}



void odbc::statement::get(const char *columnName, bool &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<bool> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, bool &value) const
{
	std::shared_ptr<bool> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<bool> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_BIT)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		bool result = (column.data.UnsignedCharacter != '\0');

		value = std::make_shared<bool>(result);
	}
}



void odbc::statement::get(const char *columnName, int8_t &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<int8_t> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, int8_t &value) const
{
	std::shared_ptr<int8_t> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<int8_t> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_STINYINT)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<int8_t>(column.data.Character);
	}
}



void odbc::statement::get(const char *columnName, uint8_t &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<uint8_t> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, uint8_t &value) const
{
	std::shared_ptr<uint8_t> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<uint8_t> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_UTINYINT)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<uint8_t>(column.data.UnsignedCharacter);
	}
}



void odbc::statement::get(const char *columnName, int16_t &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<int16_t> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, int16_t &value) const
{
	std::shared_ptr<int16_t> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<int16_t> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_SSHORT)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<int16_t>(column.data.Short);
	}
}



void odbc::statement::get(const char *columnName, uint16_t &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<uint16_t> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, uint16_t &value) const
{
	std::shared_ptr<uint16_t> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<uint16_t> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_USHORT)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<uint16_t>(column.data.UnsignedShort);
	}
}



void odbc::statement::get(const char *columnName, int32_t &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<int32_t> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, int32_t &value) const
{
	std::shared_ptr<int32_t> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<int32_t> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_SLONG)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<int32_t>(column.data.Long);
	}
}



void odbc::statement::get(const char *columnName, uint32_t &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<uint32_t> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, uint32_t &value) const
{
	std::shared_ptr<uint32_t> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<uint32_t> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_ULONG)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<uint32_t>(column.data.UnsignedLong);
	}
}



void odbc::statement::get(const char *columnName, int64_t &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<int64_t> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, int64_t &value) const
{
	std::shared_ptr<int64_t> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<int64_t> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_SBIGINT)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<int64_t>(column.data.Int64Value);
	}
}



void odbc::statement::get(const char *columnName, uint64_t &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<uint64_t> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, uint64_t &value) const
{
	std::shared_ptr<uint64_t> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<uint64_t> &value) const
{
	odbc::column &column = get_column(columnIndex);

	// TODO: this type is not a SQL data type, so data read by the ODBC driver will never be of this type
	if (column.c_type != SQL_C_UBIGINT)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<uint64_t>(column.data.UnsignedLong);
	}
}



void odbc::statement::get(const char *columnName, float &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<float> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, float &value) const
{
	std::shared_ptr<float> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<float> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_FLOAT)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<float>(column.data.Float);
	}
}



void odbc::statement::get(const char *columnName, double &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<double> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, double &value) const
{
	std::shared_ptr<double> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<double> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_DOUBLE)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<double>(column.data.Double);
	}
}



void odbc::statement::get(const char *columnName, odbc::binary_data &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<odbc::binary_data> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, odbc::binary_data &value) const
{
	std::shared_ptr<odbc::binary_data> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<odbc::binary_data> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_BINARY)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<odbc::binary_data>(column.data.UnsignedAnsiString, column.indicator);
	}
}



void odbc::statement::get(const char *columnName, odbc::date &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<odbc::date> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, odbc::date &value) const
{
	std::shared_ptr<odbc::date> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<odbc::date> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_TYPE_DATE)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<odbc::date>(column.data.Date);
	}
}



void odbc::statement::get(const char *columnName, odbc::Time &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<odbc::Time> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, odbc::Time &value) const
{
	std::shared_ptr<odbc::Time> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<odbc::Time> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_TYPE_TIME)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<odbc::Time>(column.data.Time);
	}
}



void odbc::statement::get(const char *columnName, odbc::DateTime &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<odbc::DateTime> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, odbc::DateTime &value) const
{
	std::shared_ptr<odbc::DateTime> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<odbc::DateTime> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_TYPE_TIMESTAMP)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<odbc::DateTime>(column.data.DateTime);
	}
}



void odbc::statement::get(const char *columnName, odbc::Numeric &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<odbc::Numeric> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, odbc::Numeric &value) const
{
	std::shared_ptr<odbc::Numeric> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<odbc::Numeric> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_NUMERIC)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<odbc::Numeric>(column.data.Numeric);
	}
}



void odbc::statement::get(const char *columnName, GUID &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const char *columnName, std::shared_ptr<GUID> &value) const
{
	uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const uint32_t columnIndex, GUID &value) const
{
	std::shared_ptr<GUID> v;

	get(columnIndex, v);

	if (v == nullptr)
	{
		std::exception e(__LOC_A__ "Column value was NULL when a non-Nullable value type was specified.");

		throw e;
	}
	else
	{
		value = *v;
	}
}

void odbc::statement::get(const uint32_t columnIndex, std::shared_ptr<GUID> &value) const
{
	odbc::column &column = get_column(columnIndex);

	if (column.c_type != SQL_C_GUID)
	{
		std::exception e(__LOC_A__ "Column is not of the type specified.");

		throw e;
	}

	value.reset();

	if (column.indicator != SQL_NULL_DATA)
	{
		value = std::make_shared<GUID>(column.data.Guid);
	}
}


void odbc::statement::prepare()
{
	RETCODE rc = ::SQLPrepareA(_statement, (SQLCHAR *) _commandText.c_str(), SQL_NTS);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error preparing statement.");
}

void odbc::statement::bind_parameters()
{
	int16_t numberOfParameters = 0;

	RETCODE rc = ::SQLNumParams(_statement, &numberOfParameters);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading number of parameters.");

	if ((numberOfParameters > 0) && ((uint16_t) numberOfParameters > _parameters.size()))
	{
		std::exception e(__LOC_A__ "Too few parameters supplied to statement.");

		throw e;
	}

	for (int16_t i = 0; i < numberOfParameters; i++)
	{
		const std::shared_ptr<odbc::parameter> &p = _parameters[i];

		int16_t sqlDataType = 0;
		SQLUINTEGER parameterSize = 0;
		int16_t decimalDigits = 0;
		int16_t nullableIndicator = 0;
		// nullableIndicator is in (SQL_NO_NULLS, SQL_NULLABLE, SQL_NULLABLE_UNKNOWN)

		rc = ::SQLDescribeParam(_statement, i + 1, &sqlDataType, &parameterSize, &decimalDigits, &nullableIndicator);

		process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error getting parameter information.");

		if ((nullableIndicator == SQL_NO_NULLS) && p->is_null())
		{
			std::exception e(__LOC_A__ "NULL-valued parameter passed into parameter that is marked NOT NULL by the data source.");

			throw e;
		}

		// TODO: this will fail if p->is_null()
		if (are_types_convertible(p->get_type(), sqlDataType) == false)
		{
			std::string message(__LOC_A__ "Supplied value for parameter (#");

			message += std::to_string(i);
			message += " named '";
			message += p->get_name();
			message += "' is not convertible to the expected SQL type (";
			message += GetSqlTypeName(sqlDataType);
			message += ").";

			std::exception e(message.c_str());

			throw e;
		}

		SQLINTEGER *value = (SQLINTEGER *) p->get_nullable_indicator();
		// this needs to be a certain value depending on the value of the parameter:
		//   SQL_NULL_DATA if the parameter is null
		//   SQL_NTS if the parameter value is a null terminated string
		//   the length of the parameter otherwise...which is complicated

		rc = ::SQLBindParameter(_statement, i + 1, SQL_PARAM_INPUT, p->get_type(), sqlDataType, parameterSize, decimalDigits, p->get_value(), p->get_length(), value);

		process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error binding parameter.");
	}
}

void odbc::statement::read_number_of_columns()
{
	SQLSMALLINT numberOfColumns = 0;

	RETCODE rc = ::SQLNumResultCols(_statement, &numberOfColumns);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading number of columns in result.");

	_numberOfColumns = numberOfColumns;
}

void odbc::statement::process_columns()
{
	_columnBindings.reset(new odbc::column[_numberOfColumns]);

	::memset(_columnBindings.get(), 0x00000000, sizeof (odbc::column) * _numberOfColumns);

	for (SQLUSMALLINT i = 0; i < _numberOfColumns; i++)
	{
		_columnBindings[i].index = i + 1;

		read_column_type(_columnBindings[i]);

		std::string name = read_column_name(i);

		//std::string hi = GetSqlTypeName(_columnBindings[i].type);

		//::printf("%s: %s\n", name.c_str(), hi.c_str());

		_nameToIndex[name] = i;

		bind_column(_columnBindings[i]);
	}
}

void odbc::statement::read_column_type(odbc::column &column)
{
	RETCODE rc = ::SQLColAttributeA(_statement, column.index, SQL_DESC_CONCISE_TYPE, nullptr, 0, nullptr, &column.type);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading column type.");

	column.c_type = get_c_type(column.type);

	rc = ::SQLColAttributeA(_statement, column.index, SQL_DESC_LENGTH, nullptr, 0, nullptr, &column.width);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading column width.");
}

/*
SQLUSMALLINT GetMaxColumnNameLength(const shared_ptr<OdbcConnection> &connection)
{
	SQLUSMALLINT result = 0;

	RETCODE rc = ::SQLGetInfo(connection->GetConnectionHandle(), SQL_MAXIMUM_COLUMN_NAME_LENGTH, &result, sizeof (SQLUSMALLINT), nullptr);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading max column name length.");

	return result;
}
*/

std::string odbc::statement::read_column_name(SQLUSMALLINT columnIndex)
{
	// static const SQLUSMALLINT bufferLength = GetMaxColumnNameLength(_connection);

	// TODO: read this from the driver using ::SQLGetInfo and SQL_MAXIMUM_COLUMN_NAME_LENGTH ??
	const int bufferLength = 256;

	//unique_ptr<TCHAR[]> buffer(new TCHAR[bufferLength]);
	char buffer[bufferLength] = {};

	RETCODE rc = ::SQLColAttributeA(_statement, columnIndex + 1, SQL_DESC_NAME, (SQLPOINTER) buffer, bufferLength, NULL, NULL);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading column name.");

	std::string result(buffer);

	return result;
}

void odbc::statement::bind_column(odbc::column &c)
{
	c.bound = true;

	SQLPOINTER buffer = (SQLPOINTER) &c.data;
	SQLINTEGER bufferLength = sizeof (odbc::column_data);

	// TODO: i hate the way this function is structured; i need to split it out into tinier functions

	if ((c.c_type == SQL_C_CHAR) || (c.c_type == SQL_C_WCHAR) || (c.c_type == SQL_C_BINARY))
	{
		if ((c.width == 0) && ((c.type == SQL_VARCHAR) || (c.type == SQL_WVARCHAR) || (c.type == SQL_LONGVARCHAR) || (c.type == SQL_WLONGVARCHAR) || (c.type == SQL_VARBINARY) || (c.type == SQL_LONGVARBINARY)))
		{
			c.bound = false;
		}
		else
		{
			c.width += 1; // include space for the null terminator

			if (c.c_type == SQL_C_WCHAR)
			{
				bufferLength = c.width * sizeof (wchar_t);
				buffer = (wchar_t *) ::calloc(c.width, sizeof (wchar_t));
				c.data.UnicodeString = (wchar_t *) buffer;
			}
			else
			{
				bufferLength = c.width * sizeof (unsigned char);
				buffer = (unsigned char *) ::calloc(c.width, sizeof (unsigned char));
				c.data.UnsignedAnsiString = (unsigned char *) buffer;
			}
		}
	}

	if (c.bound == true)
	{
		RETCODE rc = ::SQLBindCol(_statement, c.index, c.c_type, buffer, bufferLength, (SQLINTEGER *) &c.indicator);

		process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error binding column.");
	}
}

void odbc::statement::fetch_unbound_column_data()
{
	for (SQLUSMALLINT i = 0; i < _numberOfColumns; i++)
	{
		odbc::column &c = _columnBindings[i];

		if (c.bound == false)
		{
			reset_column(c);
			fetch_unbound_column_data(c);
		}
	}
}

void odbc::statement::reset_column(odbc::column &column)
{
	if ((column.c_type == SQL_C_CHAR) || (column.c_type == SQL_C_BINARY))
	{
		::free(column.data.UnsignedAnsiString);
	}
	else if (column.c_type == SQL_C_WCHAR)
	{
		::free(column.data.UnicodeString);
	}

	::memset(&column.data, 0x00000000, sizeof (odbc::column_data));

	column.width = 1;
}

//template <typename T>
//T *FetchUnboundData(void *statement, Column &column, size_t (*len)(const T *, size_t), errno_t (*cat)(T *, rsize_t, const T *))
//{
//	const int numberOfCharactersToFetch = 1000;
//
//	T *result = nullptr;
//
//	T buf[numberOfCharactersToFetch] = {};
//
//	RETCODE rc;
//
//	do
//	{
//		rc = ::SQLGetData(statement, column.index, SQL_C_WCHAR, buf, numberOfCharactersToFetch, &column.indicator);
//
//		process_return_code(statement, SQL_HANDLE_STMT, rc, __LOC__ _T("Error reading unbound LOB column data."));
//
//		if (column.indicator != SQL_NULL_DATA)
//		{
//			column.width += (*len)(buf, numberOfCharactersToFetch);
//
//			if (result == nullptr)
//			{
//				result = (T *) ::calloc(column.width, sizeof (T));
//			}
//
//			// TODO: i don't know if the size argument wcscat_s wants bytes or characters...for now, i assume characters
//			(*cat)(result, column.width, buf);
//		}
//	}
//	while (rc == SQL_SUCCESS_WITH_INFO);
//
//	return result;
//}

void odbc::statement::fetch_unbound_column_data(odbc::column &column)
{
	const int numberOfCharactersToFetch = 1000;

	RETCODE rc = 0;

	if (column.c_type == SQL_C_WCHAR)
	{
		//column.data.UnicodeString = FetchUnboundData(_statement, column, &::wcsnlen_s, &::wcscat_s);

		wchar_t buf[numberOfCharactersToFetch] = {};

		do
		{
			rc = ::SQLGetData(_statement, column.index, SQL_C_WCHAR, buf, numberOfCharactersToFetch, (SQLINTEGER *) &column.indicator);

			process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading unbound LOB column data.");

			if (column.indicator != SQL_NULL_DATA)
			{
				column.width += ::wcsnlen_s(buf, numberOfCharactersToFetch);

				if (column.data.UnsignedAnsiString == nullptr)
				{
					column.data.UnsignedAnsiString = (unsigned char *) ::calloc(column.width, sizeof (unsigned char));
				}
				else
				{
					wchar_t *tmp = (wchar_t *) ::realloc(column.data.UnicodeString, column.width * sizeof (wchar_t));

					if (tmp != nullptr)
					{
						column.data.UnicodeString = tmp;
					}
				}

				::wcscat_s(column.data.UnicodeString, column.width, buf);
			}
		}
		while (rc == SQL_SUCCESS_WITH_INFO);
	}
	else
	{
		//column.data.UnsignedAnsiString = (UCHAR *) FetchUnboundData(_statement, column, &::strnlen_s, &::strcat_s);

		char buf[numberOfCharactersToFetch] = {};

		do
		{
			rc = ::SQLGetData(_statement, column.index, SQL_C_CHAR, buf, numberOfCharactersToFetch, (SQLINTEGER *) &column.indicator);

			process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading unbound LOB column data.");

			if (column.indicator != SQL_NULL_DATA)
			{
				column.width += ::strnlen_s(buf, numberOfCharactersToFetch);

				if (column.data.UnsignedAnsiString == nullptr)
				{
					column.data.UnsignedAnsiString = (unsigned char *) ::calloc(column.width, sizeof (unsigned char));
				}
				else
				{
					unsigned char *tmp = (unsigned char *) ::realloc(column.data.UnsignedAnsiString, column.width * sizeof (unsigned char));

					if (tmp != nullptr)
					{
						column.data.UnsignedAnsiString = tmp;
					}
				}

				::strcat_s((CHAR *) column.data.UnsignedAnsiString, column.width, buf);
			}
		}
		while (rc == SQL_SUCCESS_WITH_INFO);
	}
}

uint32_t odbc::statement::get_column_index(const std::string &columnName) const
{
	std::map<std::string, uint32_t, case_insensitive_less>::const_iterator indexPair = _nameToIndex.find(columnName);

	if (indexPair == _nameToIndex.end())
	{
		std::string message("Column '");

		message.append(columnName);

		message.append("' is not in the result set for this query.");

		std::exception e(message.c_str());

		throw e;
	}

	uint32_t columnIndex = indexPair->second;

	return columnIndex;
}

odbc::column &odbc::statement::get_column(const std::string &columnName) const
{
	uint32_t columnIndex = get_column_index(columnName);

	odbc::column &result = get_column(columnIndex);

	return result;
}

odbc::column &odbc::statement::get_column(const uint32_t columnIndex) const
{
	if (columnIndex >= _numberOfColumns)
	{
		std::string message("Column index '");
		message.append(std::to_string(columnIndex));
		message.append("' is not in the result set for this query.");

		std::exception e(message.c_str());

		throw e;
	}

	odbc::column &result = _columnBindings[columnIndex];

	return result;
}
