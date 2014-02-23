#include "stdafx.h"

#include <SqlTable.h>

TEST(SqlTableTests, DefaultConstructor_SetsSchemaToEmptyString)
{
	SqlTable table;

	EXPECT_EQ("", table.GetSchema());
}

TEST(SqlTableTests, DefaultConstructor_SetsTableToEmptyString)
{
	SqlTable table;

	EXPECT_EQ("", table.GetTable());
}

TEST(SqlTableTests, CopyConstructor_CopiesSchema)
{
	SqlTable expected;

	expected.SetSchema("Schema");

	SqlTable actual(expected);

	EXPECT_EQ(expected.GetSchema(), actual.GetSchema());
}

TEST(SqlTableTests, CopyConstructor_CopiesTable)
{
	SqlTable expected;

	expected.SetTable("Table");

	SqlTable actual(expected);

	EXPECT_EQ(expected.GetTable(), actual.GetTable());
}

TEST(SqlTableTests, AssignmentOperator_AssignsSchema)
{
	SqlTable expected;

	expected.SetSchema("Schema");

	SqlTable actual;

	actual = expected;

	EXPECT_EQ(expected.GetSchema(), actual.GetSchema());
}

TEST(SqlTableTests, AssignmentOperator_AssignsTable)
{
	SqlTable expected;

	expected.SetTable("Table");

	SqlTable actual;

	actual = expected;

	EXPECT_EQ(expected.GetTable(), actual.GetTable());
}

TEST(SqlTableTests, EqualsOperator_SchemaAndTableAreEqual_ReturnsTrue)
{
	SqlTable left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	SqlTable right;

	right.SetSchema("Schema");
	right.SetTable("Table");

	EXPECT_TRUE(left == right);
}

TEST(SqlTableTests, EqualsOperator_SchemaIsNotEqualTableIsEqual_ReturnsFalse)
{
	SqlTable left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	SqlTable right;

	right.SetSchema("NotSchema");
	right.SetTable("Table");

	EXPECT_FALSE(left == right);
}

TEST(SqlTableTests, EqualsOperator_SchemaIsEqualTableIsNotEqual_ReturnsFalse)
{
	SqlTable left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	SqlTable right;

	right.SetSchema("Schema");
	right.SetTable("NotTable");

	EXPECT_FALSE(left == right);
}

TEST(SqlTableTests, NotEqualsOperator_SchemaAndTableAreEqual_ReturnsFalse)
{
	SqlTable left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	SqlTable right;

	right.SetSchema("Schema");
	right.SetTable("Table");

	EXPECT_FALSE(left != right);
}

TEST(SqlTableTests, NotEqualsOperator_SchemaIsNotEqualTableIsEqual_ReturnsTrue)
{
	SqlTable left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	SqlTable right;

	right.SetSchema("NotSchema");
	right.SetTable("Table");

	EXPECT_TRUE(left != right);
}

TEST(SqlTableTests, NotEqualsOperator_SchemaIsEqualTableIsNotEqual_ReturnsTrue)
{
	SqlTable left;

	left.SetSchema("Schema");
	left.SetTable("Table");

	SqlTable right;

	right.SetSchema("Schema");
	right.SetTable("NotTable");

	EXPECT_TRUE(left != right);
}

TEST(SqlTableTests, SetSchema_SetsSchema)
{
	static const char expected[] = "Schema";

	SqlTable table;

	table.SetSchema(expected);

	EXPECT_EQ(expected, table.GetSchema());
}

TEST(SqlTableTests, SetSchema_DoesNotSetTable)
{
	static const char expected[] = "Schema";

	SqlTable table;

	table.SetSchema(expected);

	EXPECT_EQ("", table.GetTable());
}

TEST(SqlTableTests, SetTable_SetsTable)
{
	static const char expected[] = "Table";

	SqlTable table;

	table.SetTable(expected);

	EXPECT_EQ(expected, table.GetTable());
}

TEST(SqlTableTests, SetTable_DoesNotSetSchema)
{
	static const char expected[] = "Table";

	SqlTable table;

	table.SetTable(expected);

	EXPECT_EQ("", table.GetSchema());
}
