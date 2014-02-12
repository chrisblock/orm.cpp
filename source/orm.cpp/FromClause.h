#pragma once

#include <string>
#include <vector>

#include "SqlTable.h"

class FromClause
{
public:
	FromClause();
	FromClause(const FromClause &other);
	~FromClause();

	FromClause &operator =(const FromClause &other);

	void SetMainTable(const SqlTable &mainTable);
	SqlTable GetMainTable() const;

	void AddAdditionalTable(const SqlTable &additionalTable);

	std::string BuildSqlClause() const;

private:
	SqlTable _mainTable;
	std::vector<SqlTable> _additionalTables;
};
