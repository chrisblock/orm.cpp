#pragma once

#include "ISqlDialect.h"

class IRecord;
class SqlPredicate;

namespace orm
{
	namespace sql
	{
		class projection;
		class statement;
	};
};

class SqlServerDialect : public ISqlDialect
{
public:
	SqlServerDialect();
	SqlServerDialect(const SqlServerDialect &other);
	virtual ~SqlServerDialect();

	SqlServerDialect &operator =(const SqlServerDialect &other);

	virtual orm::sql::statement BuildSelectStatement(const orm::sql::projection &projection, const orm::sql::from_clause &fromClause, const SqlPredicate &predicate) const override;
	virtual orm::sql::statement BuildInsertStatement(const IRecord &record) const override;
	virtual orm::sql::statement BuildUpdateStatement(const IRecord &record) const override;
	virtual orm::sql::statement BuildDeleteStatement(const IRecord &record) const override;
};
