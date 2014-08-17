#pragma once

#include "column.h"

#include <cstdint>
#include <memory>
#include <string>

namespace odbc
{
	class binary_data;
};

namespace odbc
{
	class parameter
	{
	public:
		parameter();
		parameter(_In_ const parameter &other);
		parameter(parameter &&other);
		virtual ~parameter();

		parameter &operator =(_In_ parameter other);

		friend void swap(parameter &left, parameter &right);

		std::string get_name() const;
		void set_name(_In_ const std::string &name);

		std::int16_t get_type() const;

		std::int16_t get_c_type() const;

		void *get_value() const;

		std::int32_t get_length() const;

		std::int32_t &get_nullable_indicator();

		bool is_null() const;

		void set(_In_ const char value);
		void set(_In_ const wchar_t value);

		void set(_In_opt_z_ const char *value);
		void set(_In_opt_z_ const wchar_t *value);

		void set(_In_ const std::shared_ptr<std::string> &value);
		void set(_In_ const std::string &value);

		void set(_In_ const std::shared_ptr<std::wstring> &value);
		void set(_In_ const std::wstring &value);

		void set(_In_ const std::shared_ptr<std::int8_t> &value);
		void set(_In_ const std::int8_t value);

		void set(_In_ const std::shared_ptr<std::uint8_t> &value);
		void set(_In_ const std::uint8_t value);

		void set(_In_ const std::shared_ptr<std::int16_t> &value);
		void set(_In_ const std::int16_t value);

		void set(_In_ const std::shared_ptr<std::uint16_t> &value);
		void set(_In_ const std::uint16_t value);

		void set(_In_ const std::shared_ptr<std::int32_t> &value);
		void set(_In_ const std::int32_t value);

		void set(_In_ const std::shared_ptr<std::uint32_t> &value);
		void set(_In_ const std::uint32_t value);

		void set(_In_ const std::shared_ptr<std::int64_t> &value);
		void set(_In_ const std::int64_t value);

		void set(_In_ const std::shared_ptr<std::uint64_t> &value);
		void set(_In_ const std::uint64_t value);

		void set(_In_ const std::shared_ptr<float> &value);
		void set(_In_ const float value);

		void set(_In_ const std::shared_ptr<double> &value);
		void set(_In_ const double value);

		void set(_In_ const std::shared_ptr<bool> &value);
		void set(_In_ const bool value);

		void set(_In_ const std::shared_ptr<odbc::binary_data> &value);
		void set(_In_ const odbc::binary_data &value);

		void set(_In_ const std::shared_ptr<odbc::date> &value);
		void set(_In_ const odbc::date &value);

		void set(_In_ const std::shared_ptr<odbc::time> &value);
		void set(_In_ const odbc::time &value);

		void set(_In_ const std::shared_ptr<odbc::date_time> &value);
		void set(_In_ const odbc::date_time &value);

		void set(_In_ const std::shared_ptr<odbc::numeric> &value);
		void set(_In_ const odbc::numeric &value);

		void set(_In_ const std::shared_ptr<GUID> &value);
		void set(_In_ const GUID &value);

	private:
		std::string _name;
		odbc::column _value;
	};

	void swap(parameter &left, parameter &right);
};
