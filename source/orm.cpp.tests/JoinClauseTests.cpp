#include "stdafx.h"

#include <join_clause.h>

#include <sql_column.h>
#include <sql_table.h>

TEST(JoinClauseTests, DefaultConstructor_SetsIsOuterJoinToFalse)
{
	orm::sql::join_clause join;

	EXPECT_EQ(false, join.IsOuterJoin());
}

TEST(JoinClauseTests, DefaultConstructor_SetsSourceTableToEmptyTable)
{
	orm::sql::join_clause join;

	orm::sql::sql_table expected;

	EXPECT_EQ(expected, join.GetSourceTable());
}

TEST(JoinClauseTests, DefaultConstructor_SetsSourceColumnToEmptyColumn)
{
	orm::sql::join_clause join;

	orm::sql::sql_column expected;

	EXPECT_EQ(expected, join.GetSourceColumn());
}

TEST(JoinClauseTests, DefaultConstructor_SetsDestinationTableToEmptyTable)
{
	orm::sql::join_clause join;

	orm::sql::sql_table expected;

	EXPECT_EQ(expected, join.GetDestinationTable());
}

TEST(JoinClauseTests, DefaultConstructor_SetsDestinationColumnToEmptyColumn)
{
	orm::sql::join_clause join;

	orm::sql::sql_column expected;

	EXPECT_EQ(expected, join.GetDestinationColumn());
}

TEST(JoinClauseTests, CopyConstructor_CopiesIsOuterJoin)
{
	orm::sql::join_clause expected;

	expected.SetIsOuterJoin(true);

	orm::sql::join_clause actual(expected);

	EXPECT_EQ(expected.IsOuterJoin(), actual.IsOuterJoin());
}

TEST(JoinClauseTests, CopyConstructor_CopiesSourceTable)
{
	orm::sql::join_clause expected;

	orm::sql::sql_table table;

	table.SetSchema("Schema");
	table.SetTable("Table");

	expected.SetSourceTable(table);

	orm::sql::join_clause actual(expected);

	EXPECT_EQ(expected.GetSourceTable(), actual.GetSourceTable());
}

TEST(JoinClauseTests, CopyConstructor_CopiesSourceColumn)
{
	orm::sql::join_clause expected;

	orm::sql::sql_column column;

	column.SetTable("Table");
	column.SetColumn("Column");

	expected.SetSourceColumn(column);

	orm::sql::join_clause actual(expected);

	EXPECT_EQ(expected.GetSourceColumn(), actual.GetSourceColumn());
}

TEST(JoinClauseTests, CopyConstructor_CopiesDestinationTable)
{
	orm::sql::join_clause expected;

	orm::sql::sql_table table;

	table.SetSchema("Schema");
	table.SetTable("Table");

	expected.SetDestinationTable(table);

	orm::sql::join_clause actual(expected);

	EXPECT_EQ(expected.GetDestinationTable(), actual.GetDestinationTable());
}

TEST(JoinClauseTests, CopyConstructor_CopiesDestinationColumn)
{
	orm::sql::join_clause expected;

	orm::sql::sql_column column;

	column.SetTable("Table");
	column.SetColumn("Column");

	expected.SetDestinationColumn(column);

	orm::sql::join_clause actual(expected);

	EXPECT_EQ(expected.GetDestinationColumn(), actual.GetDestinationColumn());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsIsOuterJoin)
{
	orm::sql::join_clause expected;

	expected.SetIsOuterJoin(true);

	orm::sql::join_clause actual;

	actual = expected;

	EXPECT_EQ(expected.IsOuterJoin(), actual.IsOuterJoin());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsSourceTable)
{
	orm::sql::join_clause expected;

	orm::sql::sql_table table;

	table.SetSchema("Schema");
	table.SetTable("Table");

	expected.SetSourceTable(table);

	orm::sql::join_clause actual;

	actual = expected;

	EXPECT_EQ(expected.GetSourceTable(), actual.GetSourceTable());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsSourceColumn)
{
	orm::sql::join_clause expected;

	orm::sql::sql_column column;

	column.SetTable("Table");
	column.SetColumn("Column");

	expected.SetSourceColumn(column);

	orm::sql::join_clause actual;

	actual = expected;

	EXPECT_EQ(expected.GetSourceColumn(), actual.GetSourceColumn());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsDestinationTable)
{
	orm::sql::join_clause expected;

	orm::sql::sql_table table;

	table.SetSchema("Schema");
	table.SetTable("Table");

	expected.SetDestinationTable(table);

	orm::sql::join_clause actual;

	actual = expected;

	EXPECT_EQ(expected.GetDestinationTable(), actual.GetDestinationTable());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsDestinationColumn)
{
	orm::sql::join_clause expected;

	orm::sql::sql_column column;

	column.SetTable("Table");
	column.SetColumn("Column");

	expected.SetDestinationColumn(column);

	orm::sql::join_clause actual;

	actual = expected;

	EXPECT_EQ(expected.GetDestinationColumn(), actual.GetDestinationColumn());
}

TEST(JoinClauseTests, EqualOperator_SourceTableIsEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsTrue)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_TRUE(left == right);
}

TEST(JoinClauseTests, EqualOperator_SourceTableIsNotEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsFalse)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	orm::sql::sql_table alternateSourceTable;

	alternateSourceTable.SetSchema("dbo");
	alternateSourceTable.SetTable("NotSourceTable");

	right.SetSourceTable(alternateSourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_FALSE(left == right);
}

TEST(JoinClauseTests, EqualOperator_SourceTableIsEqualSourceColumnIsNotEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsFalse)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	orm::sql::sql_column alternateSourceColumn;

	alternateSourceColumn.SetTable("SourceTable");
	alternateSourceColumn.SetColumn("NotSourceTableColumn");

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(alternateSourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_FALSE(left == right);
}

TEST(JoinClauseTests, EqualOperator_SourceTableIsEqualSourceColumnIsEqualDestinationTableIsNotEqualDestinationColumnIsEqual_ReturnsFalse)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	orm::sql::sql_table alternateDestinationTable;

	alternateDestinationTable.SetSchema("dbo");
	alternateDestinationTable.SetTable("NotDestinationTable");

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(alternateDestinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_FALSE(left == right);
}

TEST(JoinClauseTests, EqualOperator_SourceTableIsEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsNotEqual_ReturnsFalse)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	orm::sql::sql_column alternateDestinationColumn;

	alternateDestinationColumn.SetTable("DestinationTable");
	alternateDestinationColumn.SetColumn("NotDestinationTableColumn");

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(alternateDestinationColumn);

	EXPECT_FALSE(left == right);
}

TEST(JoinClauseTests, NotEqualOperator_SourceTableIsEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsFalse)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_FALSE(left != right);
}

TEST(JoinClauseTests, NotEqualOperator_SourceTableIsNotEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsTrue)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	orm::sql::sql_table alternateSourceTable;

	alternateSourceTable.SetSchema("dbo");
	alternateSourceTable.SetTable("NotSourceTable");

	right.SetSourceTable(alternateSourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_TRUE(left != right);
}

TEST(JoinClauseTests, NotEqualOperator_SourceTableIsEqualSourceColumnIsNotEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsTrue)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	orm::sql::sql_column alternateSourceColumn;

	alternateSourceColumn.SetTable("SourceTable");
	alternateSourceColumn.SetColumn("NotSourceTableColumn");

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(alternateSourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_TRUE(left != right);
}

TEST(JoinClauseTests, NotEqualOperator_SourceTableIsEqualSourceColumnIsEqualDestinationTableIsNotEqualDestinationColumnIsEqual_ReturnsTrue)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	orm::sql::sql_table alternateDestinationTable;

	alternateDestinationTable.SetSchema("dbo");
	alternateDestinationTable.SetTable("NotDestinationTable");

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(alternateDestinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_TRUE(left != right);
}

TEST(JoinClauseTests, NotEqualOperator_SourceTableIsEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsNotEqual_ReturnsTrue)
{
	orm::sql::sql_table sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	orm::sql::sql_column sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	orm::sql::sql_table destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	orm::sql::join_clause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	orm::sql::join_clause right;

	orm::sql::sql_column alternateDestinationColumn;

	alternateDestinationColumn.SetTable("DestinationTable");
	alternateDestinationColumn.SetColumn("NotDestinationTableColumn");

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(alternateDestinationColumn);

	EXPECT_TRUE(left != right);
}
