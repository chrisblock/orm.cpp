#pragma once

#include <string>

class SqlTable
{
public:
	SqlTable();
	SqlTable(const SqlTable &other);
	~SqlTable();

	SqlTable &operator =(const SqlTable &other);

	void SetSchema(const std::string &schema);
	std::string GetSchema() const;

	void SetTable(const std::string &table);
	std::string GetTable() const;

	void SetAreNullsAllowed(const bool areNullsAllowed);
	bool AreNullsAllowed() const;

private:
	bool _areNullsAllowed;
	std::string _schema;
	std::string _table;
};
