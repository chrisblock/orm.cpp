#pragma once

#include <cstdint>
#include <guiddef.h>

namespace odbc
{
	typedef struct tagDateTime
	{
		short year;
		unsigned short month;
		unsigned short day;
		unsigned short hour;
		unsigned short minute;
		unsigned short second;
		unsigned long fraction;
	} DateTime;

	typedef struct tag_date
	{
		short year;
		unsigned short month;
		unsigned short day;
	} date;

	typedef struct tagTime
	{
		unsigned short hour;
		unsigned short minute;
		unsigned short second;
	} Time;

	typedef struct tagNumeric
	{
		unsigned char precision;
		char scale;
		unsigned char sign;	/* 1 if positive, 0 if negative */
		unsigned char val[16];
	} Numeric;

	typedef union tagColumnData {
		unsigned char *UnsignedAnsiString;
		wchar_t *UnicodeString;
		int16_t Short;
		uint16_t UnsignedShort;
		int32_t Long;
		uint32_t UnsignedLong;
		int8_t Character;
		uint8_t UnsignedCharacter;
		int64_t Int64Value;
		uint64_t UnsignedInt64Value;
		float Float;
		double Double;
		date Date;
		Time Time;
		DateTime DateTime;
		Numeric Numeric;
		GUID Guid;
	} column_data;

	typedef struct tagColumn {
		column_data data;
		int32_t width;
		int32_t indicator;
		uint16_t index;
		int16_t type;
		int16_t c_type;
		bool bound;
	} column;
};
