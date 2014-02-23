#pragma once

#include <string>

class SqlTable
{
public:
	SqlTable();
	SqlTable(const SqlTable &other);
	~SqlTable();

	SqlTable &operator =(const SqlTable &other);
	bool operator ==(const SqlTable &other) const;
	bool operator !=(const SqlTable &other) const;

	void SetSchema(const std::string &schema);
	std::string GetSchema() const;

	void SetTable(const std::string &table);
	std::string GetTable() const;

private:
	std::string _schema;
	std::string _table;
};
