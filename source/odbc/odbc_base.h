#pragma once

#include <cstdint>
#include <string>

namespace odbc
{
	class odbc_base
	{
	public:
		odbc_base();
		odbc_base(const odbc::odbc_base &other);
		virtual ~odbc_base();

	protected:
		std::string convert_to_string(_In_z_ const char *str) const;
		std::string convert_to_string(_In_z_ const wchar_t *str) const;
		std::wstring convert_to_wstring(_In_z_ const char *str) const;
		std::wstring convert_to_wstring(_In_z_ const wchar_t *str) const;

		bool are_types_convertible(const std::int16_t left, const std::int16_t right) const;
		std::int16_t get_c_type(const std::int16_t type) const;
		std::string get_c_type_name(const std::int16_t type);
		std::string get_sql_type_name(const std::int16_t type);

		void process_return_code(_In_opt_ void *handle, _In_ std::int16_t handleType, _In_ std::int16_t returnCode, _In_z_ const char *errorMessage) const;

	private:
		void trace(_In_opt_ void *handle, _In_ std::int16_t handleType, _In_ std::int16_t returnCode) const;
		void trace_and_throw(_In_opt_ void *handle, _In_ std::int16_t handleType, _In_ std::int16_t returnCode, _In_z_ const char *errorMessage) const;
		void throw_unknown_return_code(_In_ std::int16_t returnCode, _In_z_ const char *errorMessage) const;

		std::string read_diagnostic_record(_In_opt_ void *handle, _In_ std::int16_t handleType, _In_ std::int16_t returnCode) const;
	};
};
