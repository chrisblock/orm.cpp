#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace odbc
{
	class environment;
}

namespace orm
{
	namespace sql
	{
		class statement;
	}
}

class IDataReader;

class ISqlExecutor
{
public:
	virtual ~ISqlExecutor();

	virtual std::shared_ptr<IDataReader> ExecuteReader(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const orm::sql::statement &statement) const = 0;
	virtual std::uint32_t ExecuteSql(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const orm::sql::statement &statement) const = 0;
};
