#pragma once

#include "ISqlDialect.h"

class IRecord;
class SqlPredicate;
class SqlProjection;
class SqlStatement;

class SqlServerDialect : public ISqlDialect
{
public:
	SqlServerDialect();
	SqlServerDialect(const SqlServerDialect &other);
	virtual ~SqlServerDialect();

	SqlServerDialect &operator =(const SqlServerDialect &other);

	virtual SqlStatement BuildSelectStatement(const SqlProjection &projection, const FromClause &fromClause, const SqlPredicate &predicate) const;
	virtual SqlStatement BuildInsertStatement(const IRecord &record) const;
	virtual SqlStatement BuildUpdateStatement(const IRecord &record) const;
	virtual SqlStatement BuildDeleteStatement(const IRecord &record) const;
};
