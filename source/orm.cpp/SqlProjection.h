#pragma once

#include <string>
#include <vector>

class SqlColumn;

class SqlProjection
{
public:
	SqlProjection();
	SqlProjection(const SqlProjection &other);
	virtual ~SqlProjection();

	SqlProjection &operator =(const SqlProjection &other);

private:
	std::vector<SqlColumn> _projections;
};
