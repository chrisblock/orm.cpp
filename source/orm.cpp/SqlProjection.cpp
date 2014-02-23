#include "stdafx.h"

#include "SqlProjection.h"

#include "SqlColumn.h"

SqlProjection::SqlProjection()
{
}

SqlProjection::SqlProjection(const SqlProjection &other) :
	  _projections(other._projections)
{
}

SqlProjection::~SqlProjection()
{
}

SqlProjection &SqlProjection::operator =(const SqlProjection &other)
{
	if (this != &other)
	{
		_projections = other._projections;
	}

	return *this;
}

void SqlProjection::AddProjection(const SqlColumn &column)
{
	_projections.push_back(column);
}

std::vector<SqlColumn> &SqlProjection::GetProjections()
{
	return _projections;
}

const std::vector<SqlColumn> &SqlProjection::GetProjections() const
{
	return _projections;
}
