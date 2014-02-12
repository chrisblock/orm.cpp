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
		virtual ~parameter();

		parameter &operator =(_In_ const parameter &other);

		std::string get_name() const;
		void set_name(_In_z_ const char *name);

		int16_t get_type() const;

		void *get_value() const;

		int32_t get_length() const;

		int32_t *get_nullable_indicator();

		bool is_null() const;

		void set(_In_ const char value);
		void set(_In_ const wchar_t value);

		void set(_In_opt_z_ const char *value);
		void set(_In_opt_z_ const wchar_t *value);

		void set(_In_ const std::shared_ptr<std::string> &value);
		void set(_In_ const std::string &value);

		void set(_In_ const std::shared_ptr<std::wstring> &value);
		void set(_In_ const std::wstring &value);

		void set(_In_ const std::shared_ptr<int8_t> &value);
		void set(_In_ const int8_t value);

		void set(_In_ const std::shared_ptr<uint8_t> &value);
		void set(_In_ const uint8_t value);

		void set(_In_ const std::shared_ptr<int16_t> &value);
		void set(_In_ const int16_t value);

		void set(_In_ const std::shared_ptr<uint16_t> &value);
		void set(_In_ const uint16_t value);

		void set(_In_ const std::shared_ptr<int32_t> &value);
		void set(_In_ const int32_t value);

		void set(_In_ const std::shared_ptr<uint32_t> &value);
		void set(_In_ const uint32_t value);

		void set(_In_ const std::shared_ptr<int64_t> &value);
		void set(_In_ const int64_t value);

		void set(_In_ const std::shared_ptr<uint64_t> &value);
		void set(_In_ const uint64_t value);

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

		void set(_In_ const std::shared_ptr<odbc::Time> &value);
		void set(_In_ const odbc::Time &value);

		void set(_In_ const std::shared_ptr<odbc::DateTime> &value);
		void set(_In_ const odbc::DateTime &value);

		void set(_In_ const std::shared_ptr<odbc::Numeric> &value);
		void set(_In_ const odbc::Numeric &value);

		void set(_In_ const std::shared_ptr<GUID> &value);
		void set(_In_ const GUID &value);

	private:
		std::string _name;
		odbc::column _value;
		int32_t _length;

		void set_null(_In_ int16_t type);
	};
};
