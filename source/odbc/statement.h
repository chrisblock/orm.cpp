#pragma once

#include "odbc_base.h"

#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "case_insensitive.h"
#include "column.h"

namespace odbc
{
	class binary_data;
	class connection;
	class parameter;
};

namespace odbc
{
	class statement : public odbc::odbc_base
	{
	public:
		statement();
		statement(const std::shared_ptr<odbc::connection> &connection);
		statement(const std::shared_ptr<odbc::connection> &connection, _In_ const std::string &commandText);
		statement(const statement &other);
		statement(statement &&other);
		virtual ~statement();

		statement &operator =(statement other);

		friend void swap(statement &left, statement &right);

		void add_parameter(const std::shared_ptr<odbc::parameter> &parameter);

		const std::string &get_command_text() const;
		void set_command_text(_In_ const std::string &commandText);

		void execute();
		bool next();
		std::uint32_t get_rows_affected() const;
		std::uint32_t get_number_of_columns() const;

		bool is_column_null(const std::string &columnName) const;
		bool is_column_null(const std::uint32_t columnIndex) const;

		void get(const std::string &columnName, std::string &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::string> &value) const;
		void get(const std::uint32_t columnIndex, std::string &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::string> &value) const;

		void get(const std::string &columnName, std::wstring &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::wstring> &value) const;
		void get(const std::uint32_t columnIndex, std::wstring &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::wstring> &value) const;

		void get(const std::string &columnName, bool &value) const;
		void get(const std::string &columnName, std::shared_ptr<bool> &value) const;
		void get(const std::uint32_t columnIndex, bool &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<bool> &value) const;

		void get(const std::string &columnName, std::int8_t &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::int8_t> &value) const;
		void get(const std::uint32_t columnIndex, std::int8_t &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::int8_t> &value) const;

		void get(const std::string &columnName, std::uint8_t &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::uint8_t> &value) const;
		void get(const std::uint32_t columnIndex, std::uint8_t &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::uint8_t> &value) const;

		void get(const std::string &columnName, std::int16_t &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::int16_t> &value) const;
		void get(const std::uint32_t columnIndex, std::int16_t &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::int16_t> &value) const;

		void get(const std::string &columnName, std::uint16_t &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::uint16_t> &value) const;
		void get(const std::uint32_t columnIndex, std::uint16_t &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::uint16_t> &value) const;

		void get(const std::string &columnName, std::int32_t &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::int32_t> &value) const;
		void get(const std::uint32_t columnIndex, std::int32_t &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::int32_t> &value) const;

		void get(const std::string &columnName, std::uint32_t &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::uint32_t> &value) const;
		void get(const std::uint32_t columnIndex, std::uint32_t &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::uint32_t> &value) const;

		void get(const std::string &columnName, std::int64_t &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::int64_t> &value) const;
		void get(const std::uint32_t columnIndex, std::int64_t &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::int64_t> &value) const;

		void get(const std::string &columnName, std::uint64_t &value) const;
		void get(const std::string &columnName, std::shared_ptr<std::uint64_t> &value) const;
		void get(const std::uint32_t columnIndex, std::uint64_t &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<std::uint64_t> &value) const;

		void get(const std::string &columnName, float &value) const;
		void get(const std::string &columnName, std::shared_ptr<float> &value) const;
		void get(const std::uint32_t columnIndex, float &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<float> &value) const;

		void get(const std::string &columnName, double &value) const;
		void get(const std::string &columnName, std::shared_ptr<double> &value) const;
		void get(const std::uint32_t columnIndex, double &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<double> &value) const;

		void get(const std::string &columnName, odbc::binary_data &value) const;
		void get(const std::string &columnName, std::shared_ptr<odbc::binary_data> &value) const;
		void get(const std::uint32_t columnIndex, odbc::binary_data &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<odbc::binary_data> &value) const;

		void get(const std::string &columnName, odbc::date &value) const;
		void get(const std::string &columnName, std::shared_ptr<odbc::date> &value) const;
		void get(const std::uint32_t columnIndex, odbc::date &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<odbc::date> &value) const;

		void get(const std::string &columnName, odbc::time &value) const;
		void get(const std::string &columnName, std::shared_ptr<odbc::time> &value) const;
		void get(const std::uint32_t columnIndex, odbc::time &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<odbc::time> &value) const;

		void get(const std::string &columnName, odbc::date_time &value) const;
		void get(const std::string &columnName, std::shared_ptr<odbc::date_time> &value) const;
		void get(const std::uint32_t columnIndex, odbc::date_time &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<odbc::date_time> &value) const;

		void get(const std::string &columnName, odbc::numeric &value) const;
		void get(const std::string &columnName, std::shared_ptr<odbc::numeric> &value) const;
		void get(const std::uint32_t columnIndex, odbc::numeric &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<odbc::numeric> &value) const;

		void get(const std::string &columnName, GUID &value) const;
		void get(const std::string &columnName, std::shared_ptr<GUID> &value) const;
		void get(const std::uint32_t columnIndex, GUID &value) const;
		void get(const std::uint32_t columnIndex, std::shared_ptr<GUID> &value) const;

	private:
		void *_statement;
		std::shared_ptr<odbc::connection> _connection;
		std::string _commandText;
		std::vector<std::shared_ptr<odbc::parameter>> _parameters;

		std::map<std::string, std::uint32_t, case_insensitive::less> _nameToIndex;

		std::uint16_t _numberOfColumns;
		std::unique_ptr<odbc::column[]> _columnBindings;

		void prepare();
		void bind_parameters();
		void read_number_of_columns();
		void process_columns();
		std::string read_column_name(const std::uint16_t columnIndex);
		void read_column_type(const std::uint16_t index, odbc::column &column);
		void bind_column(const std::uint16_t index, odbc::column &column);
		void fetch_unbound_column_data();
		void fetch_unbound_column_data(const std::uint16_t index, odbc::column &column);

		std::uint32_t get_column_index(const std::string &columnName) const;
		const odbc::column &get_column(const std::uint32_t columnIndex) const;
		const odbc::column &get_column(const std::string &columnName) const;
	};

	void swap(statement &left, statement &right);
};
