#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace odbc
{
	class environment;
};

class IDataReader;
class SqlStatement;

class ISqlExecutor
{
public:
	virtual ~ISqlExecutor();

	virtual std::shared_ptr<IDataReader> ExecuteReader(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const SqlStatement &statement) const = 0;
	virtual std::uint32_t ExecuteSql(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const SqlStatement &statement) const = 0;
};
