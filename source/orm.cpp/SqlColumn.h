#pragma once

#include <string>

class SqlColumn
{
public:
	SqlColumn();
	SqlColumn(const SqlColumn &other);
	virtual ~SqlColumn();

	SqlColumn &operator =(const SqlColumn &other);
	bool operator ==(const SqlColumn &other) const;
	bool operator !=(const SqlColumn &other) const;

	void SetTable(const std::string &table);
	std::string GetTable() const;

	void SetColumn(const std::string &column);
	std::string GetColumn() const;

	std::string GetColumnString() const;

private:
	std::string _table;
	std::string _column;
};
