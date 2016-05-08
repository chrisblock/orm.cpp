#pragma once

#include <cstdint>
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
	SqlPredicate(const SqlPredicate &other);
	SqlPredicate(SqlPredicate &&other);
	virtual ~SqlPredicate();

	SqlPredicate &operator =(SqlPredicate other);

	friend void swap(SqlPredicate &left, SqlPredicate &right);

	bool IsEmpty() const;

	void SetPredicate(const std::string &predicate);
	std::string GetPredicate() const;

	std::uint32_t GetNumberOfParameters() const;
	void AddParameter(const std::shared_ptr<odbc::parameter> &parameter);
	std::shared_ptr<odbc::parameter> GetParameter(const std::uint32_t index) const;

	std::vector<std::shared_ptr<odbc::parameter>>::const_iterator begin() const;
	std::vector<std::shared_ptr<odbc::parameter>>::const_iterator cbegin() const;

	std::vector<std::shared_ptr<odbc::parameter>>::const_iterator end() const;
	std::vector<std::shared_ptr<odbc::parameter>>::const_iterator cend() const;

private:
	std::string _predicate;
	std::vector<std::shared_ptr<odbc::parameter>> _parameters;
};

void swap(SqlPredicate &left, SqlPredicate &right);
