#include "stdafx.h"

#include "from_clause.h"

#include <algorithm>
#include <functional>

#include "join_clause.h"

void orm::sql::swap(orm::sql::from_clause &left, orm::sql::from_clause &right)
{
	using std::swap;

	swap(left._joins, right._joins);
	swap(left._mainTable, right._mainTable);
}

orm::sql::from_clause::from_clause()
{
}

orm::sql::from_clause::from_clause(const orm::sql::from_clause &other) :
	  _mainTable(other._mainTable)
	, _joins(other._joins)
{
}

orm::sql::from_clause::from_clause(orm::sql::from_clause &&other) :
	  orm::sql::from_clause()
{
	swap(*this, other);
}

orm::sql::from_clause::~from_clause()
{
}

orm::sql::from_clause &orm::sql::from_clause::operator =(orm::sql::from_clause other)
{
	swap(*this, other);

	return *this;
}

void orm::sql::from_clause::SetMainTable(const orm::sql::sql_table &mainTable)
{
	_mainTable = mainTable;
}

orm::sql::sql_table &orm::sql::from_clause::GetMainTable()
{
	return _mainTable;
}

const orm::sql::sql_table &orm::sql::from_clause::GetMainTable() const
{
	return _mainTable;
}

// TODO: verify correctness of join
//         if the source table is already in the from clause
//         if the join is already in the from clause
//         if the source column's table matches the source table
//         if the destination column's table matches the destination table
void orm::sql::from_clause::AddJoin(const orm::sql::join_clause &join)
{
	_joins.push_back(join);
}

std::vector<orm::sql::join_clause> &orm::sql::from_clause::GetJoins()
{
	return _joins;
}

const std::vector<orm::sql::join_clause> &orm::sql::from_clause::GetJoins() const
{
	return _joins;
}

std::string orm::sql::from_clause::BuildSqlClause() const
{
	std::string result;

	if ((_mainTable.GetSchema().empty() == false) && (_mainTable.GetTable().empty() == false))
	{
		result.append("FROM ");
		result.append(_mainTable.GetSchema());
		result.append(".");
		result.append(_mainTable.GetTable());

		std::function<void (const orm::sql::join_clause &)> fn = [&result] (const orm::sql::join_clause &join)
		{
			if (join.IsOuterJoin())
			{
				result.append(" LEFT OUTER JOIN ");
			}
			else
			{
				result.append(" INNER JOIN ");
			}

			result.append(join.GetDestinationTable().GetSchema());
			result.append(".");
			result.append(join.GetDestinationTable().GetTable());
			result.append(" ON ");
			result.append(join.GetDestinationColumn().GetTable());
			result.append(".");
			result.append(join.GetDestinationColumn().GetColumn());
			result.append(" = ");
			result.append(join.GetSourceColumn().GetTable());
			result.append(".");
			result.append(join.GetSourceColumn().GetColumn());
		};

		std::for_each(_joins.cbegin(), _joins.cend(), fn);
	}

	return result;
}
