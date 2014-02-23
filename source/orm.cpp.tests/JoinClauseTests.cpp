#include "stdafx.h"

#include <JoinClause.h>

#include <SqlColumn.h>
#include <SqlTable.h>

TEST(JoinClauseTests, DefaultConstructor_SetsIsOuterJoinToFalse)
{
	JoinClause join;

	EXPECT_EQ(false, join.IsOuterJoin());
}

TEST(JoinClauseTests, DefaultConstructor_SetsSourceTableToEmptyTable)
{
	JoinClause join;

	SqlTable expected;

	EXPECT_EQ(expected, join.GetSourceTable());
}

TEST(JoinClauseTests, DefaultConstructor_SetsSourceColumnToEmptyColumn)
{
	JoinClause join;

	SqlColumn expected;

	EXPECT_EQ(expected, join.GetSourceColumn());
}

TEST(JoinClauseTests, DefaultConstructor_SetsDestinationTableToEmptyTable)
{
	JoinClause join;

	SqlTable expected;

	EXPECT_EQ(expected, join.GetDestinationTable());
}

TEST(JoinClauseTests, DefaultConstructor_SetsDestinationColumnToEmptyColumn)
{
	JoinClause join;

	SqlColumn expected;

	EXPECT_EQ(expected, join.GetDestinationColumn());
}

TEST(JoinClauseTests, CopyConstructor_CopiesIsOuterJoin)
{
	JoinClause expected;

	expected.SetIsOuterJoin(true);

	JoinClause actual(expected);

	EXPECT_EQ(expected.IsOuterJoin(), actual.IsOuterJoin());
}

TEST(JoinClauseTests, CopyConstructor_CopiesSourceTable)
{
	JoinClause expected;

	SqlTable table;

	table.SetSchema("Schema");
	table.SetTable("Table");

	expected.SetSourceTable(table);

	JoinClause actual(expected);

	EXPECT_EQ(expected.GetSourceTable(), actual.GetSourceTable());
}

TEST(JoinClauseTests, CopyConstructor_CopiesSourceColumn)
{
	JoinClause expected;

	SqlColumn column;

	column.SetTable("Table");
	column.SetColumn("Column");

	expected.SetSourceColumn(column);

	JoinClause actual(expected);

	EXPECT_EQ(expected.GetSourceColumn(), actual.GetSourceColumn());
}

TEST(JoinClauseTests, CopyConstructor_CopiesDestinationTable)
{
	JoinClause expected;

	SqlTable table;

	table.SetSchema("Schema");
	table.SetTable("Table");

	expected.SetDestinationTable(table);

	JoinClause actual(expected);

	EXPECT_EQ(expected.GetDestinationTable(), actual.GetDestinationTable());
}

TEST(JoinClauseTests, CopyConstructor_CopiesDestinationColumn)
{
	JoinClause expected;

	SqlColumn column;

	column.SetTable("Table");
	column.SetColumn("Column");

	expected.SetDestinationColumn(column);

	JoinClause actual(expected);

	EXPECT_EQ(expected.GetDestinationColumn(), actual.GetDestinationColumn());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsIsOuterJoin)
{
	JoinClause expected;

	expected.SetIsOuterJoin(true);

	JoinClause actual;

	actual = expected;

	EXPECT_EQ(expected.IsOuterJoin(), actual.IsOuterJoin());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsSourceTable)
{
	JoinClause expected;

	SqlTable table;

	table.SetSchema("Schema");
	table.SetTable("Table");

	expected.SetSourceTable(table);

	JoinClause actual;

	actual = expected;

	EXPECT_EQ(expected.GetSourceTable(), actual.GetSourceTable());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsSourceColumn)
{
	JoinClause expected;

	SqlColumn column;

	column.SetTable("Table");
	column.SetColumn("Column");

	expected.SetSourceColumn(column);

	JoinClause actual;

	actual = expected;

	EXPECT_EQ(expected.GetSourceColumn(), actual.GetSourceColumn());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsDestinationTable)
{
	JoinClause expected;

	SqlTable table;

	table.SetSchema("Schema");
	table.SetTable("Table");

	expected.SetDestinationTable(table);

	JoinClause actual;

	actual = expected;

	EXPECT_EQ(expected.GetDestinationTable(), actual.GetDestinationTable());
}

TEST(JoinClauseTests, AssignmentOperator_AssignsDestinationColumn)
{
	JoinClause expected;

	SqlColumn column;

	column.SetTable("Table");
	column.SetColumn("Column");

	expected.SetDestinationColumn(column);

	JoinClause actual;

	actual = expected;

	EXPECT_EQ(expected.GetDestinationColumn(), actual.GetDestinationColumn());
}

TEST(JoinClauseTests, EqualOperator_SourceTableIsEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsTrue)
{
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_TRUE(left == right);
}

TEST(JoinClauseTests, EqualOperator_SourceTableIsNotEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsFalse)
{
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	SqlTable alternateSourceTable;

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
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	SqlColumn alternateSourceColumn;

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
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	SqlTable alternateDestinationTable;

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
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	SqlColumn alternateDestinationColumn;

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
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(destinationColumn);

	EXPECT_FALSE(left != right);
}

TEST(JoinClauseTests, NotEqualOperator_SourceTableIsNotEqualSourceColumnIsEqualDestinationTableIsEqualDestinationColumnIsEqual_ReturnsTrue)
{
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	SqlTable alternateSourceTable;

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
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	SqlColumn alternateSourceColumn;

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
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	SqlTable alternateDestinationTable;

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
	SqlTable sourceTable;

	sourceTable.SetSchema("dbo");
	sourceTable.SetTable("SourceTable");

	SqlColumn sourceColumn;

	sourceColumn.SetTable("SourceTable");
	sourceColumn.SetColumn("SourceTableColumn");

	SqlTable destinationTable;

	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("DestinationTableColumn");

	JoinClause left;

	left.SetSourceTable(sourceTable);
	left.SetSourceColumn(sourceColumn);

	left.SetDestinationTable(destinationTable);
	left.SetDestinationColumn(destinationColumn);

	JoinClause right;

	SqlColumn alternateDestinationColumn;

	alternateDestinationColumn.SetTable("DestinationTable");
	alternateDestinationColumn.SetColumn("NotDestinationTableColumn");

	right.SetSourceTable(sourceTable);
	right.SetSourceColumn(sourceColumn);

	right.SetDestinationTable(destinationTable);
	right.SetDestinationColumn(alternateDestinationColumn);

	EXPECT_TRUE(left != right);
}
