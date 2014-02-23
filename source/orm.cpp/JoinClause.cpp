#include "stdafx.h"

#include "JoinClause.h"

JoinClause::JoinClause() :
	  _isOuterJoin(false)
{
}

JoinClause::JoinClause(const JoinClause &other) :
	  _isOuterJoin(other._isOuterJoin)
	, _sourceTable(other._sourceTable)
	, _sourceColumn(other._sourceColumn)
	, _destinationTable(other._destinationTable)
	, _destinationColumn(other._destinationColumn)
{
}

JoinClause::~JoinClause()
{
}

JoinClause &JoinClause::operator =(const JoinClause &other)
{
	if (this != &other)
	{
		_isOuterJoin = other._isOuterJoin;
		_sourceTable = other._sourceTable;
		_sourceColumn = other._sourceColumn;
		_destinationTable = other._destinationTable;
		_destinationColumn = other._destinationColumn;
	}

	return *this;
}

bool JoinClause::operator ==(const JoinClause &other) const
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

bool JoinClause::operator !=(const JoinClause &other) const
{
	bool result = !(*this == other);

	return result;
}

void JoinClause::SetIsOuterJoin(const bool isOuterJoin)
{
	_isOuterJoin = isOuterJoin;
}

bool JoinClause::IsOuterJoin() const
{
	return _isOuterJoin;
}

void JoinClause::SetSourceTable(const SqlTable &sourceTable)
{
	_sourceTable = sourceTable;
}

SqlTable &JoinClause::GetSourceTable()
{
	return _sourceTable;
}

const SqlTable &JoinClause::GetSourceTable() const
{
	return _sourceTable;
}

void JoinClause::SetSourceColumn(const SqlColumn &sourceColumn)
{
	_sourceColumn = sourceColumn;
}

SqlColumn &JoinClause::GetSourceColumn()
{
	return _sourceColumn;
}

const SqlColumn &JoinClause::GetSourceColumn() const
{
	return _sourceColumn;
}

void JoinClause::SetDestinationTable(const SqlTable &destinationTable)
{
	_destinationTable = destinationTable;
}

SqlTable &JoinClause::GetDestinationTable()
{
	return _destinationTable;
}

const SqlTable &JoinClause::GetDestinationTable() const
{
	return _destinationTable;
}

void JoinClause::SetDestinationColumn(const SqlColumn &destinationColumn)
{
	_destinationColumn = destinationColumn;
}

SqlColumn &JoinClause::GetDestinationColumn()
{
	return _destinationColumn;
}

const SqlColumn &JoinClause::GetDestinationColumn() const
{
	return _destinationColumn;
}
