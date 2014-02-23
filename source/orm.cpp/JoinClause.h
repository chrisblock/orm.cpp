#pragma once

#include "SqlColumn.h"
#include "SqlTable.h"

class JoinClause
{
public:
	JoinClause();
	JoinClause(const JoinClause &other);
	~JoinClause();

	JoinClause &operator =(const JoinClause &other);
	bool operator ==(const JoinClause &other) const;
	bool operator !=(const JoinClause &other) const;

	void SetIsOuterJoin(const bool isOuterJoin);
	bool IsOuterJoin() const;

	void SetSourceTable(const SqlTable &sourceTable);
	SqlTable &GetSourceTable();
	const SqlTable &GetSourceTable() const;

	void SetSourceColumn(const SqlColumn &sourceColumn);
	SqlColumn &GetSourceColumn();
	const SqlColumn &GetSourceColumn() const;

	void SetDestinationTable(const SqlTable &destinationTable);
	SqlTable &GetDestinationTable();
	const SqlTable &GetDestinationTable() const;

	void SetDestinationColumn(const SqlColumn &destinationColumn);
	SqlColumn &GetDestinationColumn();
	const SqlColumn &GetDestinationColumn() const;

private:
	bool _isOuterJoin;
	SqlTable _sourceTable;
	SqlTable _destinationTable;
	SqlColumn _sourceColumn;
	SqlColumn _destinationColumn;
};
