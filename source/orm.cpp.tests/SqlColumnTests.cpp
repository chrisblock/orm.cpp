#include "stdafx.h"

#include <sql_column.h>

TEST(SqlColumnTests, DefaultConstructor_SetsTableToEmptyString)
{
	orm::sql::sql_column column;

	EXPECT_EQ("", column.GetTable());
}

TEST(SqlColumnTests, DefaultConstructor_SetsColumnToEmptyString)
{
	orm::sql::sql_column column;

	EXPECT_EQ("", column.GetColumn());
}

TEST(SqlColumnTests, CopyConstructor_CopiesTable)
{
	orm::sql::sql_column expected;

	expected.SetTable("Table");

	orm::sql::sql_column actual(expected);

	EXPECT_EQ(expected.GetTable(), actual.GetTable());
}

TEST(SqlColumnTests, CopyConstructor_CopiesColumn)
{
	orm::sql::sql_column expected;

	expected.SetColumn("Column");

	orm::sql::sql_column actual(expected);

	EXPECT_EQ(expected.GetColumn(), actual.GetColumn());
}

TEST(SqlColumnTests, AssignmentOperator_AssignsTable)
{
	orm::sql::sql_column expected;

	expected.SetTable("Table");

	orm::sql::sql_column actual;

	actual = expected;

	EXPECT_EQ(expected.GetTable(), actual.GetTable());
}

TEST(SqlColumnTests, AssignmentOperator_AssignsColumn)
{
	orm::sql::sql_column expected;

	expected.SetColumn("Column");

	orm::sql::sql_column actual;

	actual = expected;

	EXPECT_EQ(expected.GetColumn(), actual.GetColumn());
}

TEST(SqlColumnTests, EqualsOperator_TableIsEqualColumnIsEqual_ReturnsTrue)
{
	orm::sql::sql_column left;

	left.SetTable("Table");
	left.SetColumn("Column");

	orm::sql::sql_column right;

	right.SetTable("Table");
	right.SetColumn("Column");

	EXPECT_TRUE(left == right);
}

TEST(SqlColumnTests, EqualsOperator_TableIsNotEqualColumnIsEqual_ReturnsFalse)
{
	orm::sql::sql_column left;

	left.SetTable("Table");
	left.SetColumn("Column");

	orm::sql::sql_column right;

	right.SetTable("NotTable");
	right.SetColumn("Column");

	EXPECT_FALSE(left == right);
}

TEST(SqlColumnTests, EqualsOperator_TableIsEqualColumnIsNotEqual_ReturnsFalse)
{
	orm::sql::sql_column left;

	left.SetTable("Table");
	left.SetColumn("Column");

	orm::sql::sql_column right;

	right.SetTable("Table");
	right.SetColumn("NotColumn");

	EXPECT_FALSE(left == right);
}

TEST(SqlColumnTests, NotEqualOperator_TableIsEqualColumnIsEqual_ReturnsFalse)
{
	orm::sql::sql_column left;

	left.SetTable("Table");
	left.SetColumn("Column");

	orm::sql::sql_column right;

	right.SetTable("Table");
	right.SetColumn("Column");

	EXPECT_FALSE(left != right);
}

TEST(SqlColumnTests, NotEqualOperator_TableIsNotEqualColumnIsEqual_ReturnsTrue)
{
	orm::sql::sql_column left;

	left.SetTable("Table");
	left.SetColumn("Column");

	orm::sql::sql_column right;

	right.SetTable("NotTable");
	right.SetColumn("Column");

	EXPECT_TRUE(left != right);
}

TEST(SqlColumnTests, NotEqualOperator_TableIsEqualColumnIsNotEqual_ReturnsTrue)
{
	orm::sql::sql_column left;

	left.SetTable("Table");
	left.SetColumn("Column");

	orm::sql::sql_column right;

	right.SetTable("Table");
	right.SetColumn("NotColumn");

	EXPECT_TRUE(left != right);
}

TEST(SqlColumnTests, GetColumnString_EmptyAliasEmptyTableEmptyColumn_ReturnsEmptyString)
{
	orm::sql::sql_column column;

	EXPECT_EQ("", column.GetColumnString());
}

TEST(SqlColumnTests, GetColumnString_EmptyAliasHasTableEmptyColumn_ReturnsTableDot)
{
	orm::sql::sql_column column;

	column.SetTable("Table");

	EXPECT_EQ("Table.", column.GetColumnString());
}

TEST(SqlColumnTests, GetColumnString_EmptyAliasHasTableHasColumn_ReturnsTableDoColumn)
{
	orm::sql::sql_column column;

	column.SetTable("Table");
	column.SetColumn("Column");

	EXPECT_EQ("Table.Column", column.GetColumnString());
}
