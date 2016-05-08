#include "stdafx.h"

#include "join_clause.h"

void orm::sql::swap(orm::sql::join_clause &left, orm::sql::join_clause &right)
{
	using std::swap;

	swap(left._destinationColumn, right._destinationColumn);
	swap(left._destinationTable, right._destinationTable);
	swap(left._isOuterJoin, right._isOuterJoin);
	swap(left._sourceColumn, right._sourceColumn);
	swap(left._sourceTable, right._sourceTable);
}

orm::sql::join_clause::join_clause() :
	  _isOuterJoin(false)
{
}

orm::sql::join_clause::join_clause(const orm::sql::join_clause &other) :
	  _isOuterJoin(other._isOuterJoin)
	, _sourceTable(other._sourceTable)
	, _sourceColumn(other._sourceColumn)
	, _destinationTable(other._destinationTable)
	, _destinationColumn(other._destinationColumn)
{
}

orm::sql::join_clause::join_clause(orm::sql::join_clause &&other) :
	  orm::sql::join_clause()
{
	swap(*this, other);
}

orm::sql::join_clause::~join_clause()
{
}

orm::sql::join_clause &orm::sql::join_clause::operator =(orm::sql::join_clause other)
{
	swap(*this, other);

	return *this;
}

bool orm::sql::join_clause::operator ==(const orm::sql::join_clause &other) const
{
	bool result = (this == &other);

	if (this != &other)
	{
		result = (_sourceTable == other._sourceTable)
			&& (_sourceColumn == other._sourceColumn)
			&& (_destinationTable == other._destinationTable)
			&& (_destinationColumn == other._destinationColumn);
	}

	return result;
}

bool orm::sql::join_clause::operator !=(const orm::sql::join_clause &other) const
{
	bool result = !(*this == other);

	return result;
}

void orm::sql::join_clause::SetIsOuterJoin(const bool isOuterJoin)
{
	_isOuterJoin = isOuterJoin;
}

bool orm::sql::join_clause::IsOuterJoin() const
{
	return _isOuterJoin;
}

void orm::sql::join_clause::SetSourceTable(const orm::sql::sql_table &sourceTable)
{
	_sourceTable = sourceTable;
}

orm::sql::sql_table &orm::sql::join_clause::GetSourceTable()
{
	return _sourceTable;
}

const orm::sql::sql_table &orm::sql::join_clause::GetSourceTable() const
{
	return _sourceTable;
}

void orm::sql::join_clause::SetSourceColumn(const orm::sql::sql_column &sourceColumn)
{
	_sourceColumn = sourceColumn;
}

orm::sql::sql_column &orm::sql::join_clause::GetSourceColumn()
{
	return _sourceColumn;
}

const orm::sql::sql_column &orm::sql::join_clause::GetSourceColumn() const
{
	return _sourceColumn;
}

void orm::sql::join_clause::SetDestinationTable(const orm::sql::sql_table &destinationTable)
{
	_destinationTable = destinationTable;
}

orm::sql::sql_table &orm::sql::join_clause::GetDestinationTable()
{
	return _destinationTable;
}

const orm::sql::sql_table &orm::sql::join_clause::GetDestinationTable() const
{
	return _destinationTable;
}

void orm::sql::join_clause::SetDestinationColumn(const orm::sql::sql_column &destinationColumn)
{
	_destinationColumn = destinationColumn;
}

orm::sql::sql_column &orm::sql::join_clause::GetDestinationColumn()
{
	return _destinationColumn;
}

const orm::sql::sql_column &orm::sql::join_clause::GetDestinationColumn() const
{
	return _destinationColumn;
}
