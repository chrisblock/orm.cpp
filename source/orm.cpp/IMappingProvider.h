#pragma once

#include <string>

class IMappingProvider
{
public:
	IMappingProvider();
	IMappingProvider(const IMappingProvider &other);
	virtual ~IMappingProvider();

	IMappingProvider &operator =(const IMappingProvider &other);

	virtual std::string GetMappedType() const = 0;
	virtual std::string GetSchema() const;
	virtual std::string GetTable() const;

protected:
	void Schema(const std::string &schema);
	void Table(const std::string &table);

private:
	std::string _schema;
	std::string _table;
};
