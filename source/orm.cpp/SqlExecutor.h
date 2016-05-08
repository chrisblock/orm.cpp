#pragma once

#include "ISqlExecutor.h"

#include <cstdint>
#include <memory>
#include <string>

namespace orm
{
	namespace sql
	{
		class statement;
	}
}

class IDataReader;

class SqlExecutor : public ISqlExecutor
{
public:
	SqlExecutor();
	SqlExecutor(const SqlExecutor &other);
	virtual ~SqlExecutor();

	SqlExecutor &operator =(const SqlExecutor &other);

	virtual std::shared_ptr<IDataReader> ExecuteReader(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const orm::sql::statement &statement) const;
	virtual std::uint32_t ExecuteSql(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const orm::sql::statement &statement) const;
};
