#include "stdafx.h"

#include <sql_table.h>

TEST(SqlTableTests, DefaultConstructor_SetsSchemaToEmptyString)
{
	orm::sql::sql_table table;

	EXPECT_EQ("", table.GetSchema());
}

TEST(SqlTableTests, DefaultConstructor_SetsTableToEmptyString)
{
	orm::sql::sql_table table;

	EXPECT_EQ("", table.GetTable());
}

TEST(SqlTableTests, CopyConstructor_CopiesSchema)
{
	orm::sql::sql_table expected;

	expected.SetSchema("Schema");

	orm::sql::sql_table actual(expected);

	EXPECT_EQ(expected.GetSchema(), actual.GetSchema());
}

TEST(SqlTableTests, CopyConstructor_CopiesTable)
{
	orm::sql::sql_table expected;

	expected.SetTable("Table");

	orm::sql::sql_table actual(expected);

	EXPECT_EQ(expected.GetTable(), actual.GetTable());
}

TEST(SqlTableTests, AssignmentOperator_AssignsSchema)
{
	orm::sql::sql_table expected;

	expected.SetSchema("Schema");

	orm::sql::sql_table actual;

	actual = expected;

	EXPECT_EQ(expected.GetSchema(), actual.GetSchema());
}

TEST(SqlTableTests, AssignmentOperator_AssignsTable)
{
	orm::sql::sql_table expected;

	expected.SetTable("Table");

	orm::sql::sql_table actual;

	actual = expected;

	EXPECT_EQ(expected.GetTable(), actual.GetTable());
}

TEST(SqlTableTests, EqualsOperator_SchemaAndTableAreEqual_ReturnsTrue)
{
	orm::sql::sql_table left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	orm::sql::sql_table right;

	right.SetSchema("Schema");
	right.SetTable("Table");

	EXPECT_TRUE(left == right);
}

TEST(SqlTableTests, EqualsOperator_SchemaIsNotEqualTableIsEqual_ReturnsFalse)
{
	orm::sql::sql_table left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	orm::sql::sql_table right;

	right.SetSchema("NotSchema");
	right.SetTable("Table");

	EXPECT_FALSE(left == right);
}

TEST(SqlTableTests, EqualsOperator_SchemaIsEqualTableIsNotEqual_ReturnsFalse)
{
	orm::sql::sql_table left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	orm::sql::sql_table right;

	right.SetSchema("Schema");
	right.SetTable("NotTable");

	EXPECT_FALSE(left == right);
}

TEST(SqlTableTests, NotEqualsOperator_SchemaAndTableAreEqual_ReturnsFalse)
{
	orm::sql::sql_table left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	orm::sql::sql_table right;

	right.SetSchema("Schema");
	right.SetTable("Table");

	EXPECT_FALSE(left != right);
}

TEST(SqlTableTests, NotEqualsOperator_SchemaIsNotEqualTableIsEqual_ReturnsTrue)
{
	orm::sql::sql_table left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	orm::sql::sql_table right;

	right.SetSchema("NotSchema");
	right.SetTable("Table");

	EXPECT_TRUE(left != right);
}

TEST(SqlTableTests, NotEqualsOperator_SchemaIsEqualTableIsNotEqual_ReturnsTrue)
{
	orm::sql::sql_table left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	orm::sql::sql_table right;

	right.SetSchema("Schema");
	right.SetTable("NotTable");

	EXPECT_TRUE(left != right);
}

TEST(SqlTableTests, SetSchema_SetsSchema)
{
	static const char expected[] = "Schema";

	orm::sql::sql_table table;

	table.SetSchema(expected);

	EXPECT_EQ(expected, table.GetSchema());
}

TEST(SqlTableTests, SetSchema_DoesNotSetTable)
{
	static const char expected[] = "Schema";

	orm::sql::sql_table table;

	table.SetSchema(expected);

	EXPECT_EQ("", table.GetTable());
}

TEST(SqlTableTests, SetTable_SetsTable)
{
	static const char expected[] = "Table";

	orm::sql::sql_table table;

	table.SetTable(expected);

	EXPECT_EQ(expected, table.GetTable());
}

TEST(SqlTableTests, SetTable_DoesNotSetSchema)
{
	static const char expected[] = "Table";

	orm::sql::sql_table table;

	table.SetTable(expected);

	EXPECT_EQ("", table.GetSchema());
}
