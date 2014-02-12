#include "stdafx.h"

#include "FromClause.h"

FromClause::FromClause()
{
}

FromClause::FromClause(const FromClause &other) :
	  _mainTable(other._mainTable)
	, _additionalTables(other._additionalTables)
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
		_additionalTables = other._additionalTables;
	}

	return *this;
}

void FromClause::SetMainTable(const SqlTable &mainTable)
{
	_mainTable = mainTable;
}

SqlTable FromClause::GetMainTable() const
{
	return _mainTable;
}

void FromClause::AddAdditionalTable(const SqlTable &additionalTable)
{
	_additionalTables.push_back(additionalTable);
}

std::string FromClause::BuildSqlClause() const
{
	std::string result;

	return result;
}
