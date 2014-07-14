#include "stdafx.h"

#include "statement.h"

#include "binary_data.h"
#include "column.h"
#include "connection.h"
#include "parameter.h"

void odbc::swap(odbc::statement &left, odbc::statement &right)
{
	using std::swap;

	swap(left._columnBindings, right._columnBindings);
	swap(left._commandText, right._commandText);
	swap(left._connection, right._connection);
	swap(left._nameToIndex, right._nameToIndex);
	swap(left._numberOfColumns, right._numberOfColumns);
	swap(left._parameters, right._parameters);
	swap(left._statement, right._statement);
}

odbc::statement::statement() :
	  _statement(nullptr)
{
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

odbc::statement::statement(odbc::statement &&other) :
	  odbc::statement()
{
	swap(*this, other);
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
}

odbc::statement &odbc::statement::operator =(odbc::statement other)
{
	swap(*this, other);

	return *this;
}

void odbc::statement::add_parameter(const std::shared_ptr<odbc::parameter> &parameter)
{
	_parameters.push_back(parameter);
}

const std::string &odbc::statement::get_command_text() const
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

std::uint32_t odbc::statement::get_rows_affected() const
{
	std::uint32_t result = 0;

	if (_statement != nullptr)
	{
		SQLINTEGER rows = 0;

		RETCODE rc = ::SQLRowCount(_statement, &rows);

		process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error while determining the number of rows affected.");

		result = rows;
	}

	return result;
}

std::uint32_t odbc::statement::get_number_of_columns() const
{
	std::uint32_t result = 0;

	if (_statement != nullptr)
	{
		result = _numberOfColumns;
	}

	return result;
}



bool odbc::statement::is_column_null(const std::string &columnName) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	bool result = is_column_null(columnIndex);

	return result;
}

bool odbc::statement::is_column_null(const std::uint32_t columnIndex) const
{
	const odbc::column &column = get_column(columnIndex);

	bool result = column.is_null();

	return result;
}



void odbc::statement::get(const std::string &columnName, std::string &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::string> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::string &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::string> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::wstring &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::wstring> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::wstring &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::wstring> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, bool &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<bool> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, bool &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<bool> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::int8_t &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::int8_t> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::int8_t &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::int8_t> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::uint8_t &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::uint8_t> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::uint8_t &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::uint8_t> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::int16_t &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::int16_t> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::int16_t &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::int16_t> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::uint16_t &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::uint16_t> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::uint16_t &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::uint16_t> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::int32_t &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::int32_t> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::int32_t &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::int32_t> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::uint32_t &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::uint32_t> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::uint32_t &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::uint32_t> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::int64_t &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::int64_t> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::int64_t &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::int64_t> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, std::uint64_t &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<std::uint64_t> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, std::uint64_t &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<std::uint64_t> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, float &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<float> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, float &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<float> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, double &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<double> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, double &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<double> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, odbc::binary_data &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<odbc::binary_data> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, odbc::binary_data &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<odbc::binary_data> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, odbc::date &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<odbc::date> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, odbc::date &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<odbc::date> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, odbc::time &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<odbc::time> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, odbc::time &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<odbc::time> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, odbc::date_time &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<odbc::date_time> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, odbc::date_time &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<odbc::date_time> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, odbc::numeric &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<odbc::numeric> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, odbc::numeric &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<odbc::numeric> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::get(const std::string &columnName, GUID &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::string &columnName, std::shared_ptr<GUID> &value) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	get(columnIndex, value);
}

void odbc::statement::get(const std::uint32_t columnIndex, GUID &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}

void odbc::statement::get(const std::uint32_t columnIndex, std::shared_ptr<GUID> &value) const
{
	const odbc::column &column = get_column(columnIndex);

	value = column;
}



void odbc::statement::prepare()
{
	RETCODE rc = ::SQLPrepareA(_statement, (SQLCHAR *) _commandText.c_str(), SQL_NTS);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error preparing statement.");
}

void odbc::statement::bind_parameters()
{
	std::int16_t numberOfParameters = 0;

	RETCODE rc = ::SQLNumParams(_statement, &numberOfParameters);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading number of parameters.");

	if ((numberOfParameters > 0) && ((std::uint16_t) numberOfParameters > _parameters.size()))
	{
		std::exception e(__LOC_A__ "Too few parameters supplied to statement.");

		throw e;
	}

	for (std::int16_t i = 0; i < numberOfParameters; i++)
	{
		const std::shared_ptr<odbc::parameter> &p = _parameters[i];

		std::int16_t sqlDataType = 0;
		SQLUINTEGER parameterSize = 0;
		std::int16_t decimalDigits = 0;
		std::int16_t nullableIndicator = 0;
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
			message += get_sql_type_name(sqlDataType);
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
	_columnBindings = std::make_unique<odbc::column[]>(_numberOfColumns);

	for (std::uint16_t i = 0; i < _numberOfColumns; i++)
	{
		read_column_type(i + 1, _columnBindings[i]);

		std::string name = read_column_name(i + 1);

		//std::string hi = GetSqlTypeName(_columnBindings[i].type);

		//::printf("%s: %s\n", name.c_str(), hi.c_str());

		_nameToIndex[name] = i;

		bind_column(i + 1, _columnBindings[i]);
	}
}

void odbc::statement::read_column_type(const std::uint16_t index, odbc::column &column)
{
	std::int32_t type = 0;
	std::int32_t width = 0;

	RETCODE rc = ::SQLColAttributeA(_statement, index, SQL_DESC_CONCISE_TYPE, nullptr, 0, nullptr, &type);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading column type.");

	column.set_type((std::int16_t) type);

	rc = ::SQLColAttributeA(_statement, index, SQL_DESC_LENGTH, nullptr, 0, nullptr, &width);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading column width.");

	column.set_width(width);
}

std::string odbc::statement::read_column_name(const std::uint16_t columnIndex)
{
	// static const SQLUSMALLINT bufferLength = GetMaxColumnNameLength(_connection);

	// TODO: read this from the driver using ::SQLGetInfo and SQL_MAXIMUM_COLUMN_NAME_LENGTH ??
	const int bufferLength = 256;

	//unique_ptr<TCHAR[]> buffer(new TCHAR[bufferLength]);
	char buffer[bufferLength] = {};

	RETCODE rc = ::SQLColAttributeA(_statement, columnIndex, SQL_DESC_NAME, (SQLPOINTER) buffer, bufferLength, nullptr, nullptr);

	process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading column name.");

	std::string result(buffer);

	return result;
}

void odbc::statement::bind_column(const std::uint16_t index, odbc::column &c)
{
	std::function<bool (const std::int16_t, void *, const std::int32_t, std::int32_t &)> binder = [=] (const std::int16_t type, void *buffer, const std::int32_t length, std::int32_t &indicator)
	{
		RETCODE rc = ::SQLBindCol(_statement, index, type, buffer, length, (SQLINTEGER *)&indicator);

		process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error binding column.");

		return true;
	};

	c.bind(binder);
}

void odbc::statement::fetch_unbound_column_data()
{
	for (SQLUSMALLINT i = 0; i < _numberOfColumns; i++)
	{
		odbc::column &c = _columnBindings[i];

		if (c.is_bound() == false)
		{
			c.reset();

			fetch_unbound_column_data(i + 1, c);
		}
	}
}

void odbc::statement::fetch_unbound_column_data(const std::uint16_t index, odbc::column &column)
{
	const int numberOfCharactersToFetch = 1000;

	RETCODE rc = SQL_SUCCESS;

	if (column.get_c_type() == SQL_C_WCHAR)
	{
		wchar_t buf[numberOfCharactersToFetch] = {};

		std::int32_t indicator = 0;

		std::shared_ptr<std::wstring> str;

		do
		{
			rc = ::SQLGetData(_statement, index, SQL_C_WCHAR, buf, numberOfCharactersToFetch, reinterpret_cast<SQLINTEGER *>(&indicator));

			process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading unbound LOB column data.");

			if (indicator != SQL_NULL_DATA)
			{
				if (str == nullptr)
				{
					str = std::make_shared<std::wstring>();
				}

				str->append(buf, numberOfCharactersToFetch);
			}
		}
		while (rc == SQL_SUCCESS_WITH_INFO);

		column = str;
	}
	else
	{
		char buf[numberOfCharactersToFetch] = {};

		std::int32_t indicator = 0;

		std::shared_ptr<std::string> str;

		do
		{
			rc = ::SQLGetData(_statement, index, SQL_C_CHAR, buf, numberOfCharactersToFetch, reinterpret_cast<SQLINTEGER *>(&indicator));

			process_return_code(_statement, SQL_HANDLE_STMT, rc, __LOC_A__ "Error reading unbound LOB column data.");

			if (column.get_indicator() != SQL_NULL_DATA)
			{
				if (str == nullptr)
				{
					str = std::make_shared<std::string>();
				}

				str->append(buf, numberOfCharactersToFetch);
			}
		}
		while (rc == SQL_SUCCESS_WITH_INFO);

		column = str;
	}
}

std::uint32_t odbc::statement::get_column_index(const std::string &columnName) const
{
	std::map<std::string, std::uint32_t, case_insensitive::less>::const_iterator indexPair = _nameToIndex.find(columnName);

	if (indexPair == _nameToIndex.end())
	{
		std::string message("Column '");

		message.append(columnName);

		message.append("' is not in the result set for this query.");

		std::exception e(message.c_str());

		throw e;
	}

	std::uint32_t columnIndex = indexPair->second;

	return columnIndex;
}

const odbc::column &odbc::statement::get_column(const std::string &columnName) const
{
	std::uint32_t columnIndex = get_column_index(columnName);

	const odbc::column &result = get_column(columnIndex);

	return result;
}

const odbc::column &odbc::statement::get_column(const std::uint32_t columnIndex) const
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
