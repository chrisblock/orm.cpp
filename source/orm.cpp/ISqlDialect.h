#pragma once

#include <string>
#include <vector>

namespace orm
{
	namespace sql
	{
		class from_clause;
		class projection;
		class statement;
	};
};

class IRecord;
class SqlPredicate;

class ISqlDialect
{
public:
	virtual ~ISqlDialect();

	virtual orm::sql::statement BuildSelectStatement(const orm::sql::projection &projection, const orm::sql::from_clause &fromClause, const SqlPredicate &predicate) const = 0;
	virtual orm::sql::statement BuildInsertStatement(const IRecord &record) const = 0;
	virtual orm::sql::statement BuildUpdateStatement(const IRecord &record) const = 0;
	virtual orm::sql::statement BuildDeleteStatement(const IRecord &record) const = 0;
};
