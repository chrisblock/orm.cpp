#include "stdafx.h"

#include <from_clause.h>
#include <join_clause.h>
#include <sql_table.h>

TEST(FromClauseTests, DefaultConstructor_MainTableIsEmpty)
{
	orm::sql::from_clause clause;

	orm::sql::sql_table table;

	EXPECT_EQ(table, clause.GetMainTable());
}

TEST(FromClauseTests, DefaultConstructor_HasNoJoins)
{
	orm::sql::from_clause clause;

	const std::vector<orm::sql::join_clause> &joins = clause.GetJoins();

	EXPECT_EQ(0, joins.size());
}

TEST(FromClauseTests, CopyConstructor_CopiesMainTable)
{
	orm::sql::from_clause expected;

	orm::sql::sql_table table;

	table.SetSchema("dbo");
	table.SetTable("Table");

	expected.SetMainTable(table);

	orm::sql::from_clause actual(expected);

	EXPECT_EQ(expected.GetMainTable(), actual.GetMainTable());
}

TEST(FromClauseTests, CopyConstructor_CopiesJoins)
{
	orm::sql::from_clause expected;

	orm::sql::sql_table source;

	source.SetSchema("dbo");
	source.SetTable("Table");

	orm::sql::sql_table destination;

	destination.SetSchema("dbo");
	destination.SetTable("Table");

	orm::sql::join_clause join;

	join.SetSourceTable(source);
	join.SetDestinationTable(destination);

	expected.AddJoin(join);

	orm::sql::from_clause actual(expected);

	EXPECT_EQ(expected.GetJoins(), actual.GetJoins());
}

TEST(BuildSqlClause, BuildSqlClause_NoTables_ReturnsEmptyString)
{
	orm::sql::from_clause from;

	EXPECT_EQ("", from.BuildSqlClause());
}

TEST(BuildSqlClause, BuildSqlClause_MainTableSet_ReturnsSimpleFromClause)
{
	orm::sql::from_clause from;

	orm::sql::sql_table table;
	table.SetSchema("dbo");
	table.SetTable("Table");

	from.SetMainTable(table);

	EXPECT_EQ("FROM dbo.Table", from.BuildSqlClause());
}

TEST(BuildSqlClause, BuildSqlClause_MainTableSetWithOneInnerJoin_ReturnsFromClauseWithInnerJoin)
{
	orm::sql::from_clause from;

	orm::sql::sql_table mainTable;
	mainTable.SetSchema("dbo");
	mainTable.SetTable("MainTable");

	orm::sql::sql_column mainColumn;

	mainColumn.SetTable("MainTable");
	mainColumn.SetColumn("Id");

	from.SetMainTable(mainTable);

	orm::sql::sql_table destinationTable;
	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("MainTableId");

	orm::sql::join_clause join;

	join.SetSourceTable(mainTable);
	join.SetSourceColumn(mainColumn);

	join.SetDestinationTable(destinationTable);
	join.SetDestinationColumn(destinationColumn);

	from.AddJoin(join);

	EXPECT_EQ("FROM dbo.MainTable INNER JOIN dbo.DestinationTable ON DestinationTable.MainTableId = MainTable.Id", from.BuildSqlClause());
}

TEST(BuildSqlClause, BuildSqlClause_MainTableSetWithOneOuterJoin_ReturnsFromClauseWithOuterJoin)
{
	orm::sql::from_clause from;

	orm::sql::sql_table mainTable;
	mainTable.SetSchema("dbo");
	mainTable.SetTable("MainTable");

	orm::sql::sql_column mainColumn;

	mainColumn.SetTable("MainTable");
	mainColumn.SetColumn("Id");

	from.SetMainTable(mainTable);

	orm::sql::sql_table destinationTable;
	destinationTable.SetSchema("dbo");
	destinationTable.SetTable("DestinationTable");

	orm::sql::sql_column destinationColumn;

	destinationColumn.SetTable("DestinationTable");
	destinationColumn.SetColumn("MainTableId");

	orm::sql::join_clause join;

	join.SetIsOuterJoin(true);

	join.SetSourceTable(mainTable);
	join.SetSourceColumn(mainColumn);

	join.SetDestinationTable(destinationTable);
	join.SetDestinationColumn(destinationColumn);

	from.AddJoin(join);

	EXPECT_EQ("FROM dbo.MainTable LEFT OUTER JOIN dbo.DestinationTable ON DestinationTable.MainTableId = MainTable.Id", from.BuildSqlClause());
}
