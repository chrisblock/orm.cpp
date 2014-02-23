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

	void AddProjection(const SqlColumn &column);
	std::vector<SqlColumn> &GetProjections();
	const std::vector<SqlColumn> &GetProjections() const;

private:
	std::vector<SqlColumn> _projections;
};
