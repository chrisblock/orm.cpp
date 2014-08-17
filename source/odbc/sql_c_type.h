#pragma once

#include <cstdint>

namespace odbc
{
	class sql_c_type
	{
	public:
		static const sql_c_type sql_c_bit;
		static const sql_c_type sql_c_char;
		static const sql_c_type sql_c_wchar;
		static const sql_c_type sql_c_stinyint;
		static const sql_c_type sql_c_utinyint;
		static const sql_c_type sql_c_sshort;
		static const sql_c_type sql_c_ushort;
		static const sql_c_type sql_c_slong;
		static const sql_c_type sql_c_ulong;
		static const sql_c_type sql_c_sbigint;
		static const sql_c_type sql_c_ubigint;
		static const sql_c_type sql_c_float;
		static const sql_c_type sql_c_double;
		static const sql_c_type sql_c_binary;
		static const sql_c_type sql_c_date;
		static const sql_c_type sql_c_time;
		static const sql_c_type sql_c_datetime;
		static const sql_c_type sql_c_numeric;
		static const sql_c_type sql_c_guid;

		sql_c_type() = delete;
		sql_c_type(const sql_c_type &other);
		sql_c_type(sql_c_type &&other);
		~sql_c_type();

		sql_c_type &operator =(sql_c_type other);

		friend void swap(sql_c_type &left, sql_c_type &right);

		bool operator ==(const sql_c_type &other) const;
		bool operator !=(const sql_c_type &other) const;

		operator std::int16_t() const;

	private:
		sql_c_type(const std::int16_t type);

		std::int16_t _type;
	};

	void swap(sql_c_type &left, sql_c_type &right);
};
