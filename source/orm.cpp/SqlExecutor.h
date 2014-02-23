#pragma once

#include "ISqlExecutor.h"

#include <memory>
#include <string>

class IDataReader;
class SqlStatement;

class SqlExecutor : public ISqlExecutor
{
public:
	SqlExecutor();
	SqlExecutor(const SqlExecutor &other);
	virtual ~SqlExecutor();

	SqlExecutor &operator =(const SqlExecutor &other);

	virtual std::shared_ptr<IDataReader> ExecuteReader(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const SqlStatement &statement) const;
	virtual uint32_t ExecuteSql(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const SqlStatement &statement) const;
};
