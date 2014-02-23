#include "stdafx.h"

#include "FromClause.h"

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

	return result;
}
