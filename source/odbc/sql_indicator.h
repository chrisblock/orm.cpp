#pragma once

#include <cstdint>

namespace odbc
{
	class sql_indicator
	{
	public:
		static const sql_indicator sql_null_data;
		static const sql_indicator sql_nts;

		sql_indicator() = delete;
		sql_indicator(const std::int32_t indicator);
		sql_indicator(const sql_indicator &other);
		sql_indicator(sql_indicator &&other);
		~sql_indicator();

		sql_indicator &operator =(sql_indicator other);

		friend void swap(sql_indicator &left, sql_indicator &right);

		bool operator ==(const sql_indicator &other) const;
		bool operator !=(const sql_indicator &other) const;

		operator std::int32_t &();
		operator const std::int32_t &() const;

	private:
		std::int32_t _indicator;
	};

	void swap(sql_indicator &left, sql_indicator &right);
};
