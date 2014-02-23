#pragma once

#include <string>
#include <vector>

#include "SqlTable.h"

class JoinClause;

class FromClause
{
public:
	FromClause();
	FromClause(const FromClause &other);
	~FromClause();

	FromClause &operator =(const FromClause &other);

	void SetMainTable(const SqlTable &mainTable);
	SqlTable &GetMainTable();
	const SqlTable &GetMainTable() const;

	// TODO: add overloads for this
	void AddJoin(const JoinClause &join);
	std::vector<JoinClause> &GetJoins();
	const std::vector<JoinClause> &GetJoins() const;

	std::string BuildSqlClause() const;

private:
	SqlTable _mainTable;
	std::vector<JoinClause> _joins;
};
