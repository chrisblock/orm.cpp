#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace odbc
{
	class parameter;
};

class SqlStatement
{
public:
	SqlStatement();
	SqlStatement(const SqlStatement &other);
	virtual ~SqlStatement();

	SqlStatement &operator =(const SqlStatement &other);

	void SetSql(const std::string &sql);
	std::string GetSql() const;

	uint32_t GetNumberOfParameters() const;
	void AddParameter(const std::shared_ptr<odbc::parameter> &parameter);
	std::vector<std::shared_ptr<odbc::parameter>> &GetParameters();
	const std::vector<std::shared_ptr<odbc::parameter>> &GetParameters() const;

private:
	std::string _sql;
	std::vector<std::shared_ptr<odbc::parameter>> _parameters;
};
