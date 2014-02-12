#pragma once

#include <memory>
#include <string>
#include <vector>

namespace odbc
{
	class parameter;
};

class SqlPredicate
{
public:
	SqlPredicate();
	SqlPredicate(const std::string &predicate);
	SqlPredicate(const std::string &predicate, const std::vector<std::shared_ptr<odbc::parameter>> &parameters);
	virtual ~SqlPredicate();

	SqlPredicate &operator =(const SqlPredicate &other);

	void SetPredicate(const std::string &predicate);
	std::string GetPredicate() const;

	uint32_t GetNumberOfParameters() const;
	void AddParameter(const std::shared_ptr<odbc::parameter> &parameter);
	std::shared_ptr<odbc::parameter> GetParameter(const uint32_t index) const;

	std::vector<std::shared_ptr<odbc::parameter>>::const_iterator GetBegin() const;
	std::vector<std::shared_ptr<odbc::parameter>>::const_iterator GetEnd() const;

private:
	std::string _tableName;
	std::string _predicate;
	std::vector<std::shared_ptr<odbc::parameter>> _parameters;
};
