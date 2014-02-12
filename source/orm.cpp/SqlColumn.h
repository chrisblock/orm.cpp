#pragma once

#include <string>

class SqlColumn
{
public:
	SqlColumn();
	SqlColumn(const SqlColumn &other);
	virtual ~SqlColumn();

	SqlColumn &operator =(const SqlColumn &other);

	void SetTable(const std::string &table);
	std::string GetTable() const;

	void SetColumn(const std::string &column);
	std::string GetColumn() const;

	void SetAlias(const std::string &alias);
	std::string GetAlias() const;

	std::string GetColumnString() const;

private:
	std::string _table;
	std::string _column;
	std::string _alias;
};
