#pragma once

#include "odbc_base.h"

#include <cstdint>
#include <functional>
#include <guiddef.h>
#include <memory>

#include "sql_c_type.h"
#include "sql_type.h"
#include "sql_indicator.h"

namespace odbc
{
	class binary_data;
};

namespace odbc
{
	typedef GUID guid;

	typedef struct tagDateTime
	{
		std::int16_t year;
		std::uint16_t month;
		std::uint16_t day;
		std::uint16_t hour;
		std::uint16_t minute;
		std::uint16_t second;
		std::uint32_t fraction;
	} date_time;

	typedef struct tag_date
	{
		std::int16_t year;
		std::uint16_t month;
		std::uint16_t day;
	} date;

	typedef struct tagTime
	{
		std::uint16_t hour;
		std::uint16_t minute;
		std::uint16_t second;
	} time;

	typedef struct tagNumeric
	{
		std::uint8_t precision;
		std::int8_t scale;
		std::uint8_t sign;	/* 1 if positive, 0 if negative */
		std::uint8_t val[16];
	} numeric;

	typedef union tagColumnData {
		unsigned char *UnsignedAnsiString;
		wchar_t *UnicodeString;
		std::int16_t Short;
		std::uint16_t UnsignedShort;
		std::int32_t Long;
		std::uint32_t UnsignedLong;
		std::int8_t Character;
		std::uint8_t UnsignedCharacter;
		std::int64_t Int64Value;
		std::uint64_t UnsignedInt64Value;
		float Float;
		double Double;
		date Date;
		time Time;
		date_time DateTime;
		numeric Numeric;
		guid Guid;
	} column_data;

	class column : public odbc::odbc_base
	{
	public:
		column();
		column(const column &other);
		column(column &&other);
		virtual ~column();

		column &operator =(column other);

		column &operator =(bool value);
		column &operator =(float value);
		column &operator =(double value);
		column &operator =(std::int8_t value);
		column &operator =(std::uint8_t value);
		column &operator =(std::int16_t value);
		column &operator =(std::uint16_t value);
		column &operator =(std::int32_t value);
		column &operator =(std::uint32_t value);
		column &operator =(std::int64_t value);
		column &operator =(std::uint64_t value);
		column &operator =(std::string value);
		column &operator =(std::wstring value);

		column &operator =(odbc::binary_data value);
		column &operator =(odbc::date_time value);
		column &operator =(odbc::date value);
		column &operator =(odbc::time value);
		column &operator =(odbc::guid value);
		column &operator =(odbc::numeric value);

		column &operator =(std::shared_ptr<bool> value);
		column &operator =(std::shared_ptr<float> value);
		column &operator =(std::shared_ptr<double> value);
		column &operator =(std::shared_ptr<std::int8_t> value);
		column &operator =(std::shared_ptr<std::uint8_t> value);
		column &operator =(std::shared_ptr<std::int16_t> value);
		column &operator =(std::shared_ptr<std::uint16_t> value);
		column &operator =(std::shared_ptr<std::int32_t> value);
		column &operator =(std::shared_ptr<std::uint32_t> value);
		column &operator =(std::shared_ptr<std::int64_t> value);
		column &operator =(std::shared_ptr<std::uint64_t> value);
		column &operator =(std::shared_ptr<std::string> value);
		column &operator =(std::shared_ptr<std::wstring> value);

		column &operator =(std::shared_ptr<odbc::binary_data> value);
		column &operator =(std::shared_ptr<odbc::date_time> value);
		column &operator =(std::shared_ptr<odbc::date> value);
		column &operator =(std::shared_ptr<odbc::time> value);
		column &operator =(std::shared_ptr<odbc::guid> value);
		column &operator =(std::shared_ptr<odbc::numeric> value);

		operator bool() const;
		operator float() const;
		operator double() const;
		operator std::int8_t() const;
		operator std::uint8_t() const;
		operator std::int16_t() const;
		operator std::uint16_t() const;
		operator std::int32_t() const;
		operator std::uint32_t() const;
		operator std::int64_t() const;
		operator std::uint64_t() const;
		operator std::string() const;
		operator std::wstring() const;

		operator odbc::binary_data() const;
		operator odbc::date_time() const;
		operator odbc::date() const;
		operator odbc::time() const;
		operator odbc::guid() const;
		operator odbc::numeric() const;

		operator std::shared_ptr<bool>() const;
		operator std::shared_ptr<float>() const;
		operator std::shared_ptr<double>() const;
		operator std::shared_ptr<std::int8_t>() const;
		operator std::shared_ptr<std::uint8_t>() const;
		operator std::shared_ptr<std::int16_t>() const;
		operator std::shared_ptr<std::uint16_t>() const;
		operator std::shared_ptr<std::int32_t>() const;
		operator std::shared_ptr<std::uint32_t>() const;
		operator std::shared_ptr<std::int64_t>() const;
		operator std::shared_ptr<std::uint64_t>() const;
		operator std::shared_ptr<std::string>() const;
		operator std::shared_ptr<std::wstring>() const;

		operator std::shared_ptr<odbc::binary_data>() const;
		operator std::shared_ptr<odbc::date_time>() const;
		operator std::shared_ptr<odbc::date>() const;
		operator std::shared_ptr<odbc::time>() const;
		operator std::shared_ptr<odbc::guid>() const;
		operator std::shared_ptr<odbc::numeric>() const;

		friend void swap(column &left, column &right);

		odbc::column_data &get_data();
		const odbc::column_data &get_data() const;

		std::int32_t get_width() const;
		void set_width(const std::int32_t width);

		bool is_null() const;
		sql_indicator &get_indicator();
		const sql_indicator &get_indicator() const;
		void set_indicator(const sql_indicator indicator);

		const sql_type &get_type() const;
		void set_type(const sql_type &type);

		const sql_c_type &get_c_type() const;
		void set_c_type(const sql_c_type &type);

		bool bind(const std::function<bool (const std::int16_t, void *, const std::int32_t, std::int32_t &)> &binder);

		void reset();

		bool is_bound() const;
		void set_is_bound(const bool bound);

	private:
		static column_data empty_column_data;

		void set_null(const sql_type &type, const sql_c_type &c_type);

		column_data _data;
		std::int32_t _width;
		sql_indicator _indicator;
		sql_type _type;
		sql_c_type _c_type;
		bool _bound;
	};

	void swap(column &left, column &right);
};
