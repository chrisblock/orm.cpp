#include "stdafx.h"

#include "FromClause.h"

#include <algorithm>
#include <functional>

#include "JoinClause.h"

FromClause::FromClause()
{
}

FromClause::FromClause(const FromClause &other) :
	  _mainTable(other._mainTable)
	, _joins(other._joins)
{
}

FromClause::~FromClause()
{
}

FromClause &FromClause::operator =(const FromClause &other)
{
	if (this != &other)
	{
		_mainTable = other._mainTable;
		_joins = other._joins;
	}

	return *this;
}

void FromClause::SetMainTable(const SqlTable &mainTable)
{
	_mainTable = mainTable;
}

SqlTable &FromClause::GetMainTable()
{
	return _mainTable;
}

const SqlTable &FromClause::GetMainTable() const
{
	return _mainTable;
}

// TODO: verify correctness of join
//         if the source table is already in the from clause
//         if the join is already in the from clause
//         if the source column's table matches the source table
//         if the destination column's table matches the destination table
void FromClause::AddJoin(const JoinClause &join)
{
	_joins.push_back(join);
}

std::vector<JoinClause> &FromClause::GetJoins()
{
	return _joins;
}

const std::vector<JoinClause> &FromClause::GetJoins() const
{
	return _joins;
}

std::string FromClause::BuildSqlClause() const
{
	std::string result;

	if ((_mainTable.GetSchema().empty() == false) && (_mainTable.GetTable().empty() == false))
	{
		result.append("FROM ");
		result.append(_mainTable.GetSchema());
		result.append(".");
		result.append(_mainTable.GetTable());

		std::function<void (const JoinClause &)> fn = [&result] (const JoinClause &join)
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
