#pragma once

#include <cstdint>

namespace odbc
{
	class sql_type
	{
	public:
		static const sql_type sql_bit;
		static const sql_type sql_char;
		static const sql_type sql_varchar;
		static const sql_type sql_longvarchar;
		static const sql_type sql_wchar;
		static const sql_type sql_wvarchar;
		static const sql_type sql_wlongvarchar;
		static const sql_type sql_tinyint;
		static const sql_type sql_smallint;
		static const sql_type sql_integer;
		static const sql_type sql_bigint;
		static const sql_type sql_real;
		static const sql_type sql_float;
		static const sql_type sql_double;
		static const sql_type sql_decimal;
		static const sql_type sql_binary;
		static const sql_type sql_varbinary;
		static const sql_type sql_longvarbinary;
		static const sql_type sql_date;
		static const sql_type sql_time;
		static const sql_type sql_datetime;
		static const sql_type sql_numeric;
		static const sql_type sql_guid;

		sql_type() = delete;
		sql_type(const std::int16_t type);
		sql_type(const sql_type &other);
		sql_type(sql_type &&other);
		~sql_type();

		sql_type &operator =(sql_type other);

		friend void swap(sql_type &left, sql_type &right);

		bool operator ==(const sql_type &other) const;
		bool operator !=(const sql_type &other) const;

		operator std::int16_t() const;

	private:
		std::int16_t _type;
	};

	void swap(sql_type &left, sql_type &right);
};
