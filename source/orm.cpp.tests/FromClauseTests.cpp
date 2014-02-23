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

TEST(BuildSqlClause, BuildSqlClause)
{
	FromClause from;

	from.BuildSqlClause();
}
