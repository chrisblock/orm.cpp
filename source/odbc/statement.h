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
		statement(const std::shared_ptr<odbc::connection> &connection);
		statement(const std::shared_ptr<odbc::connection> &connection, _In_ const std::string &commandText);
		statement(const statement &other);
		virtual ~statement();

		statement &operator =(const statement &other);

		void add_parameter(const std::shared_ptr<odbc::parameter> &parameter);

		std::string get_command_text() const;
		void set_command_text(_In_ const std::string &commandText);

		void execute();
		bool next();
		uint32_t get_rows_affected() const;
		uint32_t get_number_of_columns() const;

		bool is_column_null(const std::string &columnName) const;
		bool is_column_null(const uint32_t columnIndex) const;

		void get(const char *columnName, std::string &value) const;
		void get(const char *columnName, std::shared_ptr<std::string> &value) const;
		void get(const uint32_t columnIndex, std::string &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<std::string> &value) const;

		void get(const char *columnName, std::wstring &value) const;
		void get(const char *columnName, std::shared_ptr<std::wstring> &value) const;
		void get(const uint32_t columnIndex, std::wstring &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<std::wstring> &value) const;

		void get(const char *columnName, bool &value) const;
		void get(const char *columnName, std::shared_ptr<bool> &value) const;
		void get(const uint32_t columnIndex, bool &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<bool> &value) const;

		void get(const char *columnName, int8_t &value) const;
		void get(const char *columnName, std::shared_ptr<int8_t> &value) const;
		void get(const uint32_t columnIndex, int8_t &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<int8_t> &value) const;

		void get(const char *columnName, uint8_t &value) const;
		void get(const char *columnName, std::shared_ptr<uint8_t> &value) const;
		void get(const uint32_t columnIndex, uint8_t &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<uint8_t> &value) const;

		void get(const char *columnName, int16_t &value) const;
		void get(const char *columnName, std::shared_ptr<int16_t> &value) const;
		void get(const uint32_t columnIndex, int16_t &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<int16_t> &value) const;

		void get(const char *columnName, uint16_t &value) const;
		void get(const char *columnName, std::shared_ptr<uint16_t> &value) const;
		void get(const uint32_t columnIndex, uint16_t &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<uint16_t> &value) const;

		void get(const char *columnName, int32_t &value) const;
		void get(const char *columnName, std::shared_ptr<int32_t> &value) const;
		void get(const uint32_t columnIndex, int32_t &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<int32_t> &value) const;

		void get(const char *columnName, uint32_t &value) const;
		void get(const char *columnName, std::shared_ptr<uint32_t> &value) const;
		void get(const uint32_t columnIndex, uint32_t &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<uint32_t> &value) const;

		void get(const char *columnName, int64_t &value) const;
		void get(const char *columnName, std::shared_ptr<int64_t> &value) const;
		void get(const uint32_t columnIndex, int64_t &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<int64_t> &value) const;

		void get(const char *columnName, uint64_t &value) const;
		void get(const char *columnName, std::shared_ptr<uint64_t> &value) const;
		void get(const uint32_t columnIndex, uint64_t &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<uint64_t> &value) const;

		void get(const char *columnName, float &value) const;
		void get(const char *columnName, std::shared_ptr<float> &value) const;
		void get(const uint32_t columnIndex, float &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<float> &value) const;

		void get(const char *columnName, double &value) const;
		void get(const char *columnName, std::shared_ptr<double> &value) const;
		void get(const uint32_t columnIndex, double &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<double> &value) const;

		void get(const char *columnName, odbc::binary_data &value) const;
		void get(const char *columnName, std::shared_ptr<odbc::binary_data> &value) const;
		void get(const uint32_t columnIndex, odbc::binary_data &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<odbc::binary_data> &value) const;

		void get(const char *columnName, odbc::date &value) const;
		void get(const char *columnName, std::shared_ptr<odbc::date> &value) const;
		void get(const uint32_t columnIndex, odbc::date &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<odbc::date> &value) const;

		void get(const char *columnName, odbc::Time &value) const;
		void get(const char *columnName, std::shared_ptr<odbc::Time> &value) const;
		void get(const uint32_t columnIndex, odbc::Time &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<odbc::Time> &value) const;

		void get(const char *columnName, odbc::DateTime &value) const;
		void get(const char *columnName, std::shared_ptr<odbc::DateTime> &value) const;
		void get(const uint32_t columnIndex, odbc::DateTime &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<odbc::DateTime> &value) const;

		void get(const char *columnName, odbc::Numeric &value) const;
		void get(const char *columnName, std::shared_ptr<odbc::Numeric> &value) const;
		void get(const uint32_t columnIndex, odbc::Numeric &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<odbc::Numeric> &value) const;

		void get(const char *columnName, GUID &value) const;
		void get(const char *columnName, std::shared_ptr<GUID> &value) const;
		void get(const uint32_t columnIndex, GUID &value) const;
		void get(const uint32_t columnIndex, std::shared_ptr<GUID> &value) const;

	private:
		void *_statement;
		std::shared_ptr<odbc::connection> _connection;
		std::string _commandText;
		std::vector<std::shared_ptr<odbc::parameter>> _parameters;

		std::map<std::string, uint32_t, case_insensitive_less> _nameToIndex;

		uint16_t _numberOfColumns;
		std::unique_ptr<odbc::column[]> _columnBindings;

		void prepare();
		void bind_parameters();
		void read_number_of_columns();
		void process_columns();
		std::string read_column_name(unsigned short columnIndex);
		void read_column_type(odbc::column &column);
		void bind_column(odbc::column &column);
		void fetch_unbound_column_data();
		void reset_column(odbc::column &column);
		void fetch_unbound_column_data(odbc::column &column);

		uint32_t get_column_index(const std::string &columnName) const;
		odbc::column &get_column(const uint32_t columnIndex) const;
		odbc::column &get_column(const std::string &columnName) const;
	};
};
