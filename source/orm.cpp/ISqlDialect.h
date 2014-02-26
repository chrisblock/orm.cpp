#pragma once

#include <string>
#include <vector>

class FromClause;
class IRecord;
class SqlPredicate;
class SqlProjection;
class SqlStatement;

class ISqlDialect
{
public:
	virtual ~ISqlDialect();

	virtual SqlStatement BuildSelectStatement(const SqlProjection &projection, const FromClause &fromClause, const SqlPredicate &predicate) const = 0;
	virtual SqlStatement BuildInsertStatement(const IRecord &record) const = 0;
	virtual SqlStatement BuildUpdateStatement(const IRecord &record) const = 0;
	virtual SqlStatement BuildDeleteStatement(const IRecord &record) const = 0;
};
