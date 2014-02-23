#include "stdafx.h"

#include <SqlColumn.h>

TEST(SqlColumnTests, DefaultConstructor_SetsTableToEmptyString)
{
	SqlColumn column;

	EXPECT_EQ("", column.GetTable());
}

TEST(SqlColumnTests, DefaultConstructor_SetsColumnToEmptyString)
{
	SqlColumn column;

	EXPECT_EQ("", column.GetColumn());
}

TEST(SqlColumnTests, CopyConstructor_CopiesTable)
{
	SqlColumn expected;

	expected.SetTable("Table");

	SqlColumn actual(expected);

	EXPECT_EQ(expected.GetTable(), actual.GetTable());
}

TEST(SqlColumnTests, CopyConstructor_CopiesColumn)
{
	SqlColumn expected;

	expected.SetColumn("Column");

	SqlColumn actual(expected);

	EXPECT_EQ(expected.GetColumn(), actual.GetColumn());
}

TEST(SqlColumnTests, AssignmentOperator_AssignsTable)
{
	SqlColumn expected;

	expected.SetTable("Table");

	SqlColumn actual;

	actual = expected;

	EXPECT_EQ(expected.GetTable(), actual.GetTable());
}

TEST(SqlColumnTests, AssignmentOperator_AssignsColumn)
{
	SqlColumn expected;

	expected.SetColumn("Column");

	SqlColumn actual;

	actual = expected;

	EXPECT_EQ(expected.GetColumn(), actual.GetColumn());
}

TEST(SqlColumnTests, EqualsOperator_TableIsEqualColumnIsEqual_ReturnsTrue)
{
	SqlColumn left;

	left.SetTable("Table");
	left.SetColumn("Column");

	SqlColumn right;

	right.SetTable("Table");
	right.SetColumn("Column");

	EXPECT_TRUE(left == right);
}

TEST(SqlColumnTests, EqualsOperator_TableIsNotEqualColumnIsEqual_ReturnsFalse)
{
	SqlColumn left;

	left.SetTable("Table");
	left.SetColumn("Column");

	SqlColumn right;

	right.SetTable("NotTable");
	right.SetColumn("Column");

	EXPECT_FALSE(left == right);
}

TEST(SqlColumnTests, EqualsOperator_TableIsEqualColumnIsNotEqual_ReturnsFalse)
{
	SqlColumn left;

	left.SetTable("Table");
	left.SetColumn("Column");

	SqlColumn right;

	right.SetTable("Table");
	right.SetColumn("NotColumn");

	EXPECT_FALSE(left == right);
}

TEST(SqlColumnTests, NotEqualOperator_TableIsEqualColumnIsEqual_ReturnsFalse)
{
	SqlColumn left;

	left.SetTable("Table");
	left.SetColumn("Column");

	SqlColumn right;

	right.SetTable("Table");
	right.SetColumn("Column");

	EXPECT_FALSE(left != right);
}

TEST(SqlColumnTests, NotEqualOperator_TableIsNotEqualColumnIsEqual_ReturnsTrue)
{
	SqlColumn left;

	left.SetTable("Table");
	left.SetColumn("Column");

	SqlColumn right;

	right.SetTable("NotTable");
	right.SetColumn("Column");

	EXPECT_TRUE(left != right);
}

TEST(SqlColumnTests, NotEqualOperator_TableIsEqualColumnIsNotEqual_ReturnsTrue)
{
	SqlColumn left;

	left.SetTable("Table");
	left.SetColumn("Column");

	SqlColumn right;

	right.SetTable("Table");
	right.SetColumn("NotColumn");

	EXPECT_TRUE(left != right);
}

TEST(SqlColumnTests, GetColumnString_EmptyAliasEmptyTableEmptyColumn_ReturnsEmptyString)
{
	SqlColumn column;

	EXPECT_EQ("", column.GetColumnString());
}

TEST(SqlColumnTests, GetColumnString_EmptyAliasHasTableEmptyColumn_ReturnsTableDot)
{
	SqlColumn column;

	column.SetTable("Table");

	EXPECT_EQ("Table.", column.GetColumnString());
}

TEST(SqlColumnTests, GetColumnString_EmptyAliasHasTableHasColumn_ReturnsTableDoColumn)
{
	SqlColumn column;

	column.SetTable("Table");
	column.SetColumn("Column");

	EXPECT_EQ("Table.Column", column.GetColumnString());
}
