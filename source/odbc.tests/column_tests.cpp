#include "stdafx.h"

#include <column.h>
#include <sql_c_type.h>
#include <sql_indicator.h>
#include <sql_type.h>

TEST(column_tests, DefaultConstructor__SetsTypeToInteger)
{
	odbc::column c;

	EXPECT_EQ(odbc::sql_type::sql_integer, c.get_type());
}

TEST(column_tests, DefaultConstructor__SetsCTypeToSignedLong)
{
	odbc::column c;

	EXPECT_EQ(odbc::sql_c_type::sql_c_slong, c.get_c_type());
}

TEST(column_tests, DefaultConstructor__SetsWidthToZero)
{
	odbc::column c;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, DefaultConstructor__SetsIndicatorToNull)
{
	odbc::column c;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, DefaultConstructor__SetsValueToZero)
{
	odbc::column c;

	odbc::column_data &data = c.get_data();

	std::uint8_t *bytes = reinterpret_cast<std::uint8_t *>(&data);

	const static size_t s = sizeof (odbc::column_data);

	EXPECT_EQ(24U, s);

	EXPECT_EQ(0, bytes[0]);
	EXPECT_EQ(0, bytes[1]);
	EXPECT_EQ(0, bytes[2]);
	EXPECT_EQ(0, bytes[3]);
	EXPECT_EQ(0, bytes[4]);
	EXPECT_EQ(0, bytes[5]);
	EXPECT_EQ(0, bytes[6]);
	EXPECT_EQ(0, bytes[7]);
	EXPECT_EQ(0, bytes[8]);
	EXPECT_EQ(0, bytes[9]);
	EXPECT_EQ(0, bytes[10]);
	EXPECT_EQ(0, bytes[11]);
	EXPECT_EQ(0, bytes[12]);
	EXPECT_EQ(0, bytes[13]);
	EXPECT_EQ(0, bytes[14]);
	EXPECT_EQ(0, bytes[15]);
	EXPECT_EQ(0, bytes[16]);
	EXPECT_EQ(0, bytes[17]);
	EXPECT_EQ(0, bytes[18]);
	EXPECT_EQ(0, bytes[19]);
	EXPECT_EQ(0, bytes[20]);
	EXPECT_EQ(0, bytes[21]);
	EXPECT_EQ(0, bytes[22]);
	EXPECT_EQ(0, bytes[23]);
}

TEST(column_tests, AssignmentOperator__bool__SetsTypeCorrectly)
{
	bool expected = false;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bit, c.get_type());
}

TEST(column_tests, AssignmentOperator__bool__SetsCTypeCorrectly)
{
	bool expected = false;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_bit, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__bool__SetsWidthCorrectly)
{
	bool expected = false;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (bool), c.get_width());
}

TEST(column_tests, AssignmentOperator__bool__SetsIndicatorCorrectly)
{
	bool expected = false;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (bool), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__bool__SetsValueCorrectly)
{
	bool expected = false;

	odbc::column c;

	c = expected;

	bool actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__null__SetsTypeCorrectly)
{
	std::shared_ptr<bool> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bit, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__null__SetsCTypeCorrectly)
{
	std::shared_ptr<bool> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_bit, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__null__SetsWidthCorrectly)
{
	std::shared_ptr<bool> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<bool> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__null__SetsValueCorrectly)
{
	std::shared_ptr<bool> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<bool> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__SetsTypeCorrectly)
{
	std::shared_ptr<bool> expected = std::make_shared<bool>(true);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bit, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__SetsCTypeCorrectly)
{
	std::shared_ptr<bool> expected = std::make_shared<bool>(true);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_bit, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__SetsWidthCorrectly)
{
	std::shared_ptr<bool> expected = std::make_shared<bool>(true);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (bool), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__SetsIndicatorCorrectly)
{
	std::shared_ptr<bool> expected = std::make_shared<bool>(true);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (bool), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__bool__SetsValueCorrectly)
{
	std::shared_ptr<bool> expected = std::make_shared<bool>(true);

	odbc::column c;

	c = expected;

	std::shared_ptr<bool> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__int8_t__SetsTypeCorrectly)
{
	std::int8_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_tinyint, c.get_type());
}

TEST(column_tests, AssignmentOperator__int8_t__SetsCTypeCorrectly)
{
	std::int8_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_stinyint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__int8_t__SetsWidthCorrectly)
{
	std::int8_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int8_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__int8_t__SetsIndicatorCorrectly)
{
	std::int8_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int8_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__int8_t__SetsValueCorrectly)
{
	std::int8_t expected = 42;

	odbc::column c;

	c = expected;

	std::int8_t actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::int8_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_tinyint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__null_SetsCTypeCorrectly)
{
	std::shared_ptr<std::int8_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_stinyint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::int8_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::int8_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__null__SetsValueCorrectly)
{
	std::shared_ptr<std::int8_t> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::int8_t> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__SetsTypeCorrectly)
{
	std::shared_ptr<std::int8_t> expected = std::make_shared<std::int8_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_tinyint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__SetsCTypeCorrectly)
{
	std::shared_ptr<std::int8_t> expected = std::make_shared<std::int8_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_stinyint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__SetsWidthCorrectly)
{
	std::shared_ptr<std::int8_t> expected = std::make_shared<std::int8_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int8_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::int8_t> expected = std::make_shared<std::int8_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int8_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int8_t__SetsValueCorrectly)
{
	std::shared_ptr<std::int8_t> expected = std::make_shared<std::int8_t>(42);

	odbc::column c;

	c = expected;

	std::shared_ptr<std::int8_t> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__uint8_t__SetsTypeCorrectly)
{
	std::uint8_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_tinyint, c.get_type());
}

TEST(column_tests, AssignmentOperator__uint8_t__SetsCTypeCorrectly)
{
	std::uint8_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_utinyint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__uint8_t__SetsWidthCorrectly)
{
	std::uint8_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint8_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__uint8_t__SetsIndicatorCorrectly)
{
	std::uint8_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint8_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__uint8_t__SetsValueCorrectly)
{
	std::uint8_t expected = 42;

	odbc::column c;

	c = expected;

	std::uint8_t actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::uint8_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_tinyint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__null_SetsCTypeCorrectly)
{
	std::shared_ptr<std::uint8_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_utinyint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::uint8_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::uint8_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__null__SetsValueCorrectly)
{
	std::shared_ptr<std::uint8_t> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::uint8_t> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__SetsTypeCorrectly)
{
	std::shared_ptr<std::uint8_t> expected = std::make_shared<std::uint8_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_tinyint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__SetsCTypeCorrectly)
{
	std::shared_ptr<std::uint8_t> expected = std::make_shared<std::uint8_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_utinyint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__SetsWidthCorrectly)
{
	std::shared_ptr<std::uint8_t> expected = std::make_shared<std::uint8_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint8_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::uint8_t> expected = std::make_shared<std::uint8_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint8_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint8_t__SetsValueCorrectly)
{
	std::shared_ptr<std::uint8_t> expected = std::make_shared<std::uint8_t>(42);

	odbc::column c;

	c = expected;

	std::shared_ptr<std::uint8_t> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__int16_t__SetsTypeCorrectly)
{
	std::int16_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_smallint, c.get_type());
}

TEST(column_tests, AssignmentOperator__int16_t__SetsCTypeCorrectly)
{
	std::int16_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_sshort, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__int16_t__SetsWidthCorrectly)
{
	std::int16_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int16_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__int16_t__SetsIndicatorCorrectly)
{
	std::int16_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int16_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__int16_t__SetsValueCorrectly)
{
	std::int16_t expected = 42;

	odbc::column c;

	c = expected;

	std::int16_t actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::int16_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_smallint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__null__SetsCTypeCorrectly)
{
	std::shared_ptr<std::int16_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_sshort, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::int16_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::int16_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__null__SetsValueCorrectly)
{
	std::shared_ptr<std::int16_t> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::int16_t> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__SetsTypeCorrectly)
{
	std::shared_ptr<std::int16_t> expected = std::make_shared<std::int16_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_smallint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__SetsCTypeCorrectly)
{
	std::shared_ptr<std::int16_t> expected = std::make_shared<std::int16_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_sshort, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__SetsWidthCorrectly)
{
	std::shared_ptr<std::int16_t> expected = std::make_shared<std::int16_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int16_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::int16_t> expected = std::make_shared<std::int16_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int16_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int16_t__SetsValueCorrectly)
{
	std::shared_ptr<std::int16_t> expected = std::make_shared<std::int16_t>(42);

	odbc::column c;

	c = expected;

	std::shared_ptr<std::int16_t> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__uint16_t__SetsTypeCorrectly)
{
	std::uint16_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_smallint, c.get_type());
}

TEST(column_tests, AssignmentOperator__uint16_t__SetsCTypeCorrectly)
{
	std::uint16_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ushort, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__uint16_t__SetsWidthCorrectly)
{
	std::uint16_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint16_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__uint16_t__SetsIndicatorCorrectly)
{
	std::uint16_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint16_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__uint16_t__SetsValueCorrectly)
{
	std::uint16_t expected = 42;

	odbc::column c;

	c = expected;

	std::uint16_t actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::uint16_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_smallint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__null__SetsCTypeCorrectly)
{
	std::shared_ptr<std::uint16_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ushort, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::uint16_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::uint16_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__null__SetsValueCorrectly)
{
	std::shared_ptr<std::uint16_t> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::uint16_t> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__SetsTypeCorrectly)
{
	std::shared_ptr<std::uint16_t> expected = std::make_shared<std::uint16_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_smallint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__SetsCTypeCorrectly)
{
	std::shared_ptr<std::uint16_t> expected = std::make_shared<std::uint16_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ushort, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__SetsWidthCorrectly)
{
	std::shared_ptr<std::uint16_t> expected = std::make_shared<std::uint16_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint16_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::uint16_t> expected = std::make_shared<std::uint16_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint16_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint16_t__SetsValueCorrectly)
{
	std::shared_ptr<std::uint16_t> expected = std::make_shared<std::uint16_t>(42);

	odbc::column c;

	c = expected;

	std::shared_ptr<std::uint16_t> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__int32_t__SetsTypeCorrectly)
{
	std::int32_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_integer, c.get_type());
}

TEST(column_tests, AssignmentOperator__int32_t__SetsCTypeCorrectly)
{
	std::int32_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_slong, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__int32_t__SetsWidthCorrectly)
{
	std::int32_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int32_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__int32_t__SetsIndicatorCorrectly)
{
	std::int32_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int32_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__int32_t__SetsValueCorrectly)
{
	std::int32_t expected = 42;

	odbc::column c;

	c = expected;

	std::int32_t actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::int32_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_integer, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__null__SetsCTypeCorrectly)
{
	std::shared_ptr<std::int32_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_slong, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::int32_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::int32_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__null__SetsValueCorrectly)
{
	std::shared_ptr<std::int32_t> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::int32_t> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__SetsTypeCorrectly)
{
	std::shared_ptr<std::int32_t> expected = std::make_shared<std::int32_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_integer, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__SetsCTypeCorrectly)
{
	std::shared_ptr<std::int32_t> expected = std::make_shared<std::int32_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_slong, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__SetsWidthCorrectly)
{
	std::shared_ptr<std::int32_t> expected = std::make_shared<std::int32_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int32_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::int32_t> expected = std::make_shared<std::int32_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int32_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int32_t__SetsValueCorrectly)
{
	std::shared_ptr<std::int32_t> expected = std::make_shared<std::int32_t>(42);

	odbc::column c;

	c = expected;

	std::shared_ptr<std::int32_t> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__uint32_t__SetsTypeCorrectly)
{
	std::uint32_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_integer, c.get_type());
}

TEST(column_tests, AssignmentOperator__uint32_t__SetsCTypeCorrectly)
{
	std::uint32_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ulong, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__uint32_t__SetsWidthCorrectly)
{
	std::uint32_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint32_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__uint32_t__SetsIndicatorCorrectly)
{
	std::uint32_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint32_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__uint32_t__SetsValueCorrectly)
{
	std::uint32_t expected = 42;

	odbc::column c;

	c = expected;

	std::uint32_t actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::uint32_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_integer, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__null__SetsCTypeCorrectly)
{
	std::shared_ptr<std::uint32_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ulong, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::uint32_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::uint32_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__null__SetsValueCorrectly)
{
	std::shared_ptr<std::uint32_t> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::uint32_t> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__SetsTypeCorrectly)
{
	std::shared_ptr<std::uint32_t> expected = std::make_shared<std::uint32_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_integer, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__SetsCTypeCorrectly)
{
	std::shared_ptr<std::uint32_t> expected = std::make_shared<std::uint32_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ulong, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__SetsWidthCorrectly)
{
	std::shared_ptr<std::uint32_t> expected = std::make_shared<std::uint32_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint32_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::uint32_t> expected = std::make_shared<std::uint32_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint32_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint32_t__SetsValueCorrectly)
{
	std::shared_ptr<std::uint32_t> expected = std::make_shared<std::uint32_t>(42);

	odbc::column c;

	c = expected;

	std::shared_ptr<std::uint32_t> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__int64_t__SetsTypeCorrectly)
{
	std::int64_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bigint, c.get_type());
}

TEST(column_tests, AssignmentOperator__int64_t__SetsCTypeCorrectly)
{
	std::int64_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_sbigint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__int64_t__SetsWidthCorrectly)
{
	std::int64_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int64_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__int64_t__SetsIndicatorCorrectly)
{
	std::int64_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int64_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__int64_t__SetsValueCorrectly)
{
	std::int64_t expected = 42;

	odbc::column c;

	c = expected;

	std::int64_t actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::int64_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bigint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__null__SetsCTypeCorrectly)
{
	std::shared_ptr<std::int64_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_sbigint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::int64_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::int64_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__null__SetsValueCorrectly)
{
	std::shared_ptr<std::int64_t> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::int64_t> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__SetsTypeCorrectly)
{
	std::shared_ptr<std::int64_t> expected = std::make_shared<std::int64_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bigint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__SetsCTypeCorrectly)
{
	std::shared_ptr<std::int64_t> expected = std::make_shared<std::int64_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_sbigint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__SetsWidthCorrectly)
{
	std::shared_ptr<std::int64_t> expected = std::make_shared<std::int64_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int64_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::int64_t> expected = std::make_shared<std::int64_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::int64_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__int64_t__SetsValueCorrectly)
{
	std::shared_ptr<std::int64_t> expected = std::make_shared<std::int64_t>(42);

	odbc::column c;

	c = expected;

	std::shared_ptr<std::int64_t> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__uint64_t__SetsTypeCorrectly)
{
	std::uint64_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bigint, c.get_type());
}

TEST(column_tests, AssignmentOperator__uint64_t__SetsCTypeCorrectly)
{
	std::uint64_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ubigint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__uint64_t__SetsWidthCorrectly)
{
	std::uint64_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint64_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__uint64_t__SetsIndicatorCorrectly)
{
	std::uint64_t expected = 42;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint64_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__uint64_t__SetsValueCorrectly)
{
	std::uint64_t expected = 42;

	odbc::column c;

	c = expected;

	std::uint64_t actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::uint64_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bigint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__null__SetsCTypeCorrectly)
{
	std::shared_ptr<std::uint64_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ubigint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::uint64_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::uint64_t> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__null__SetsValueCorrectly)
{
	std::shared_ptr<std::uint64_t> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::uint64_t> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__SetsTypeCorrectly)
{
	std::shared_ptr<std::uint64_t> expected = std::make_shared<std::uint64_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_bigint, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__SetsCTypeCorrectly)
{
	std::shared_ptr<std::uint64_t> expected = std::make_shared<std::uint64_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_ubigint, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__SetsWidthCorrectly)
{
	std::shared_ptr<std::uint64_t> expected = std::make_shared<std::uint64_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint64_t), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::uint64_t> expected = std::make_shared<std::uint64_t>(42);

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (std::uint64_t), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__uint64_t__SetsValueCorrectly)
{
	std::shared_ptr<std::uint64_t> expected = std::make_shared<std::uint64_t>(42);

	odbc::column c;

	c = expected;

	std::shared_ptr<std::uint64_t> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__date__SetsTypeCorrectly)
{
	odbc::date expected = {};

	expected.month = 11;
	expected.day = 24;
	expected.year = 2010;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_date, c.get_type());
}

TEST(column_tests, AssignmentOperator__date__SetsCTypeCorrectly)
{
	odbc::date expected = {};

	expected.month = 11;
	expected.day = 24;
	expected.year = 2010;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_date, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__date__SetsWidthCorrectly)
{
	odbc::date expected = {};

	expected.month = 11;
	expected.day = 24;
	expected.year = 2010;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::date), c.get_width());
}

TEST(column_tests, AssignmentOperator__date__SetsIndicatorCorrectly)
{
	odbc::date expected = {};

	expected.month = 11;
	expected.day = 24;
	expected.year = 2010;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::date), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__date__SetsValueCorrectly)
{
	odbc::date expected = {};

	expected.month = 11;
	expected.day = 24;
	expected.year = 2010;

	odbc::column c;

	c = expected;

	odbc::date actual = c;

	EXPECT_EQ(expected.month, actual.month);
	EXPECT_EQ(expected.day, actual.day);
	EXPECT_EQ(expected.year, actual.year);
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__null__SetsTypeCorrectly)
{
	std::shared_ptr<odbc::date> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_date, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__null__SetsCTypeCorrectly)
{
	std::shared_ptr<odbc::date> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_date, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__null__SetsWidthCorrectly)
{
	std::shared_ptr<odbc::date> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<odbc::date> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__null__SetsValueCorrectly)
{
	std::shared_ptr<odbc::date> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<odbc::date> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__SetsTypeCorrectly)
{
	std::shared_ptr<odbc::date> expected = std::make_shared<odbc::date>();

	expected->month = 11;
	expected->day = 24;
	expected->year = 2010;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_date, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__SetsCTypeCorrectly)
{
	std::shared_ptr<odbc::date> expected = std::make_shared<odbc::date>();

	expected->month = 11;
	expected->day = 24;
	expected->year = 2010;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_date, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__SetsWidthCorrectly)
{
	std::shared_ptr<odbc::date> expected = std::make_shared<odbc::date>();

	expected->month = 11;
	expected->day = 24;
	expected->year = 2010;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::date), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__SetsIndicatorCorrectly)
{
	std::shared_ptr<odbc::date> expected = std::make_shared<odbc::date>();

	expected->month = 11;
	expected->day = 24;
	expected->year = 2010;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::date), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date__SetsValueCorrectly)
{
	std::shared_ptr<odbc::date> expected = std::make_shared<odbc::date>();

	expected->month = 11;
	expected->day = 24;
	expected->year = 2010;

	odbc::column c;

	c = expected;

	std::shared_ptr<odbc::date> actual = c;

	EXPECT_EQ(expected->month, actual->month);
	EXPECT_EQ(expected->day, actual->day);
	EXPECT_EQ(expected->year, actual->year);
}

TEST(column_tests, AssignmentOperator__time__SetsTypeCorrectly)
{
	odbc::time expected = {};

	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_time, c.get_type());
}

TEST(column_tests, AssignmentOperator__time__SetsCTypeCorrectly)
{
	odbc::time expected = {};

	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_time, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__time__SetsWidthCorrectly)
{
	odbc::time expected = {};

	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::time), c.get_width());
}

TEST(column_tests, AssignmentOperator__time__SetsIndicatorCorrectly)
{
	odbc::time expected = {};

	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::time), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__time__SetsValueCorrectly)
{
	odbc::time expected = {};

	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;

	odbc::column c;

	c = expected;

	odbc::time actual = c;

	EXPECT_EQ(expected.hour, actual.hour);
	EXPECT_EQ(expected.minute, actual.minute);
	EXPECT_EQ(expected.second, actual.second);
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__null__SetsTypeCorrectly)
{
	std::shared_ptr<odbc::time> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_time, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__null__SetsCTypeCorrectly)
{
	std::shared_ptr<odbc::time> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_time, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__null__SetsWidthCorrectly)
{
	std::shared_ptr<odbc::time> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<odbc::time> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__null__SetsValueCorrectly)
{
	std::shared_ptr<odbc::time> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<odbc::time> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__SetsTypeCorrectly)
{
	std::shared_ptr<odbc::time> expected = std::make_shared<odbc::time>();

	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_time, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__SetsCTypeCorrectly)
{
	std::shared_ptr<odbc::time> expected = std::make_shared<odbc::time>();

	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_time, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__SetsWidthCorrectly)
{
	std::shared_ptr<odbc::time> expected = std::make_shared<odbc::time>();

	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::time), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__SetsIndicatorCorrectly)
{
	std::shared_ptr<odbc::time> expected = std::make_shared<odbc::time>();

	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::time), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__time__SetsValueCorrectly)
{
	std::shared_ptr<odbc::time> expected = std::make_shared<odbc::time>();

	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;

	odbc::column c;

	c = expected;

	std::shared_ptr<odbc::time> actual = c;

	EXPECT_EQ(expected->hour, actual->hour);
	EXPECT_EQ(expected->minute, actual->minute);
	EXPECT_EQ(expected->second, actual->second);
}

TEST(column_tests, AssignmentOperator__date_time__SetsTypeCorrectly)
{
	odbc::date_time expected = {};

	expected.month = 11;
	expected.day = 22;
	expected.year = 2010;
	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;
	expected.fraction = 123;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_datetime, c.get_type());
}

TEST(column_tests, AssignmentOperator__date_time__SetsCTypeCorrectly)
{
	odbc::date_time expected = {};

	expected.month = 11;
	expected.day = 22;
	expected.year = 2010;
	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;
	expected.fraction = 123;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_datetime, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__date_time__SetsWidthCorrectly)
{
	odbc::date_time expected = {};

	expected.month = 11;
	expected.day = 22;
	expected.year = 2010;
	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;
	expected.fraction = 123;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::date_time), c.get_width());
}

TEST(column_tests, AssignmentOperator__date_time__SetsIndicatorCorrectly)
{
	odbc::date_time expected = {};

	expected.month = 11;
	expected.day = 22;
	expected.year = 2010;
	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;
	expected.fraction = 123;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::date_time), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__date_time__SetsValueCorrectly)
{
	odbc::date_time expected = {};

	expected.month = 11;
	expected.day = 22;
	expected.year = 2010;
	expected.hour = 15;
	expected.minute = 30;
	expected.second = 45;
	expected.fraction = 123;

	odbc::column c;

	c = expected;

	odbc::date_time actual = c;

	EXPECT_EQ(expected.month, actual.month);
	EXPECT_EQ(expected.day, actual.day);
	EXPECT_EQ(expected.year, actual.year);
	EXPECT_EQ(expected.hour, actual.hour);
	EXPECT_EQ(expected.minute, actual.minute);
	EXPECT_EQ(expected.second, actual.second);
	EXPECT_EQ(expected.fraction, actual.fraction);
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__null__SetsTypeCorrectly)
{
	std::shared_ptr<odbc::date_time> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_datetime, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__null__SetsCTypeCorrectly)
{
	std::shared_ptr<odbc::date_time> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_datetime, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__null__SetsWidthCorrectly)
{
	std::shared_ptr<odbc::date_time> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<odbc::date_time> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__null__SetsValueCorrectly)
{
	std::shared_ptr<odbc::date_time> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<odbc::date_time> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__SetsTypeCorrectly)
{
	std::shared_ptr<odbc::date_time> expected = std::make_shared<odbc::date_time>();

	expected->month = 11;
	expected->day = 22;
	expected->year = 2010;
	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;
	expected->fraction = 123;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_datetime, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__SetsCTypeCorrectly)
{
	std::shared_ptr<odbc::date_time> expected = std::make_shared<odbc::date_time>();

	expected->month = 11;
	expected->day = 22;
	expected->year = 2010;
	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;
	expected->fraction = 123;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_datetime, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__SetsWidthCorrectly)
{
	std::shared_ptr<odbc::date_time> expected = std::make_shared<odbc::date_time>();

	expected->month = 11;
	expected->day = 22;
	expected->year = 2010;
	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;
	expected->fraction = 123;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::date_time), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__SetsIndicatorCorrectly)
{
	std::shared_ptr<odbc::date_time> expected = std::make_shared<odbc::date_time>();

	expected->month = 11;
	expected->day = 22;
	expected->year = 2010;
	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;
	expected->fraction = 123;

	odbc::column c;

	c = expected;

	EXPECT_EQ(sizeof (odbc::date_time), c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__date_time__SetsValueCorrectly)
{
	std::shared_ptr<odbc::date_time> expected = std::make_shared<odbc::date_time>();

	expected->month = 11;
	expected->day = 22;
	expected->year = 2010;
	expected->hour = 15;
	expected->minute = 30;
	expected->second = 45;
	expected->fraction = 123;

	odbc::column c;

	c = expected;

	std::shared_ptr<odbc::date_time> actual = c;

	EXPECT_EQ(expected->month, actual->month);
	EXPECT_EQ(expected->day, actual->day);
	EXPECT_EQ(expected->year, actual->year);
	EXPECT_EQ(expected->hour, actual->hour);
	EXPECT_EQ(expected->minute, actual->minute);
	EXPECT_EQ(expected->second, actual->second);
	EXPECT_EQ(expected->fraction, actual->fraction);
}

TEST(column_tests, AssignmentOperator__string__SetsTypeCorrectly)
{
	std::string expected = "Hello, World.";

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_char, c.get_type());
}

TEST(column_tests, AssignmentOperator__string__SetsCTypeCorrectly)
{
	std::string expected = "Hello, World.";

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_char, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__string__SetsWidthCorrectly)
{
	std::string expected = "Hello, World.";

	odbc::column c;

	c = expected;

	EXPECT_EQ((expected.length() + 1) * sizeof (std::string::value_type), c.get_width());
}

TEST(column_tests, AssignmentOperator__string__SetsIndicatorCorrectly)
{
	std::string expected = "Hello, World.";

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_nts, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__string__SetsValueCorrectly)
{
	std::string expected = "Hello, World.";

	odbc::column c;

	c = expected;

	std::string actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::string> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_char, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__null__SetsCTypeCorrectly)
{
	std::shared_ptr<std::string> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_char, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::string> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::string> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__null__SetsValueCorrectly)
{
	std::shared_ptr<std::string> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::string> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__SetsTypeCorrectly)
{
	std::shared_ptr<std::string> expected = std::make_shared<std::string>("Hello, World.");

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_char, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__SetsCTypeCorrectly)
{
	std::shared_ptr<std::string> expected = std::make_shared<std::string>("Hello, World.");

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_char, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__SetsWidthCorrectly)
{
	std::shared_ptr<std::string> expected = std::make_shared<std::string>("Hello, World.");

	odbc::column c;

	c = expected;

	EXPECT_EQ((expected->length() + 1) * sizeof (std::string::value_type), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::string> expected = std::make_shared<std::string>("Hello, World.");

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_nts, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__string__SetsValueCorrectly)
{
	std::shared_ptr<std::string> expected = std::make_shared<std::string>("Hello, World.");

	odbc::column c;

	c = expected;

	std::shared_ptr<std::string> actual = c;

	EXPECT_EQ(*expected, *actual);
}

TEST(column_tests, AssignmentOperator__wstring__SetsTypeCorrectly)
{
	std::wstring expected = L"Hello, World.";

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_wchar, c.get_type());
}

TEST(column_tests, AssignmentOperator__wstring__SetsCTypeCorrectly)
{
	std::wstring expected = L"Hello, World.";

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_wchar, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__wstring__SetsWidthCorrectly)
{
	std::wstring expected = L"Hello, World.";

	odbc::column c;

	c = expected;

	EXPECT_EQ((expected.length() + 1) * sizeof (std::wstring::value_type), c.get_width());
}

TEST(column_tests, AssignmentOperator__wstring__SetsIndicatorCorrectly)
{
	std::wstring expected = L"Hello, World.";

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_nts, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__wstring__SetsValueCorrectly)
{
	std::wstring expected = L"Hello, World.";

	odbc::column c;

	c = expected;

	std::wstring actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__null__SetsTypeCorrectly)
{
	std::shared_ptr<std::wstring> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_wchar, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__null__SetsCTypeCorrectly)
{
	std::shared_ptr<std::wstring> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_wchar, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__null__SetsWidthCorrectly)
{
	std::shared_ptr<std::wstring> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(0, c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__null__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::wstring> expected;

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_null_data, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__null__SetsValueCorrectly)
{
	std::shared_ptr<std::wstring> expected;

	odbc::column c;

	c = expected;

	std::shared_ptr<std::wstring> actual = c;

	EXPECT_EQ(expected, actual);
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__SetsTypeCorrectly)
{
	std::shared_ptr<std::wstring> expected = std::make_shared<std::wstring>(L"Hello, World.");

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_type::sql_wchar, c.get_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__SetsCTypeCorrectly)
{
	std::shared_ptr<std::wstring> expected = std::make_shared<std::wstring>(L"Hello, World.");

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_c_type::sql_c_wchar, c.get_c_type());
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__SetsWidthCorrectly)
{
	std::shared_ptr<std::wstring> expected = std::make_shared<std::wstring>(L"Hello, World.");

	odbc::column c;

	c = expected;

	EXPECT_EQ((expected->length() + 1) * sizeof (std::wstring::value_type), c.get_width());
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__SetsIndicatorCorrectly)
{
	std::shared_ptr<std::wstring> expected = std::make_shared<std::wstring>(L"Hello, World.");

	odbc::column c;

	c = expected;

	EXPECT_EQ(odbc::sql_indicator::sql_nts, c.get_indicator());
}

TEST(column_tests, AssignmentOperator__shared_ptr__wstring__SetsValueCorrectly)
{
	std::shared_ptr<std::wstring> expected = std::make_shared<std::wstring>(L"Hello, World.");

	odbc::column c;

	c = expected;

	std::shared_ptr<std::wstring> actual = c;

	EXPECT_EQ(*expected, *actual);
}
