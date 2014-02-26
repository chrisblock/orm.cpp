#include "stdafx.h"

#include <FromClause.h>
#include <JoinClause.h>
#include <SqlTable.h>

TEST(FromClauseTests, DefaultConstructor_MainTableIsEmpty)
{
	FromClause clause;

	SqlTable table;

	EXPECT_EQ(table, clause.GetMainTable());
}

TEST(FromClauseTests, DefaultConstructor_HasNoJoins)
{
	FromClause clause;

	const std::vector<JoinClause> &joins = clause.GetJoins();

	EXPECT_EQ(0, joins.size());
}

TEST(FromClauseTests, CopyConstructor_CopiesMainTable)
{
	FromClause expected;

	SqlTable table;

	table.SetSchema("dbo");
	table.SetTable("Table");

	expected.SetMainTable(table);

	FromClause actual(expected);

	EXPECT_EQ(expected.GetMainTable(), actual.GetMainTable());
}

TEST(FromClauseTests, CopyConstructor_CopiesJoins)
{
	FromClause expected;

	SqlTable source;

	source.SetSchema("dbo");
	source.SetTable("Table");

	SqlTable destination;

	destination.SetSchema("dbo");
	destination.SetTable("Table");

	JoinClause join;

	join.SetSourceTable(source);
	join.SetDestinationTable(destination);

	expected.AddJoin(join);

	FromClause actual(expected);

	EXPECT_EQ(expected.GetJoins(), actual.GetJoins());
}

TEST(BuildSqlClause, BuildSqlClause_NoTables_ReturnsEmptyString)
{
	FromClause from;

	EXPECT_EQ("", from.BuildSqlClause());
}

TEST(BuildSqlClause, BuildSqlClause_MainTableSet_ReturnsSimpleFromClause)
{
	FromClause from;

	SqlTable table;
	table.SetSchema("dbo");
	table.SetTable("Table");

	from.SetMainTable(table);

	EXPECT_EQ("FROM dbo.Table", from.BuildSqlClause());
}

TEST(BuildSqlClause, BuildSqlClause_MainTableSetWithOneInnerJoin_ReturnsFromClauseWithInnerJoin)
{
	FromClause from;

	SqlTable mainTable;
	mainTable.SetSchema("dbo");
	mainTable.SetTable("MainTable");

	SqlColumn mainColumn;

	mainColumn.SetTable("MainTable");
	mainColumn.SetColumn("Id");

	from.SetMainTable(mainTable);

	SqlTable destinationTable;
	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("MainTableId");

	JoinClause join;

	join.SetSourceTable(mainTable);
	join.SetSourceColumn(mainColumn);

	join.SetDestinationTable(destinationTable);
	join.SetDestinationColumn(destinationColumn);

	from.AddJoin(join);

	EXPECT_EQ("FROM dbo.MainTable INNER JOIN dbo.DestinationTable ON DestinationTable.MainTableId = MainTable.Id", from.BuildSqlClause());
}

TEST(BuildSqlClause, BuildSqlClause_MainTableSetWithOneOuterJoin_ReturnsFromClauseWithOuterJoin)
{
	FromClause from;

	SqlTable mainTable;
	mainTable.SetSchema("dbo");
	mainTable.SetTable("MainTable");

	SqlColumn mainColumn;

	mainColumn.SetTable("MainTable");
	mainColumn.SetColumn("Id");

	from.SetMainTable(mainTable);

	SqlTable destinationTable;
	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	SqlColumn destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("MainTableId");

	JoinClause join;

	join.SetIsOuterJoin(true);

	join.SetSourceTable(mainTable);
	join.SetSourceColumn(mainColumn);

	join.SetDestinationTable(destinationTable);
	join.SetDestinationColumn(destinationColumn);

	from.AddJoin(join);

	EXPECT_EQ("FROM dbo.MainTable LEFT OUTER JOIN dbo.DestinationTable ON DestinationTable.MainTableId = MainTable.Id", from.BuildSqlClause());
}
