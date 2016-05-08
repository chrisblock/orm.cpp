#include "stdafx.h"

#include "projection.h"

#include "sql_column.h"

void orm::sql::swap(orm::sql::projection &left, orm::sql::projection &right)
{
	using std::swap;

	swap(left._projections, right._projections);
}

orm::sql::projection::projection()
{
}

orm::sql::projection::projection(const orm::sql::projection &other) :
	  _projections(other._projections)
{
}

orm::sql::projection::projection(orm::sql::projection &&other) :
	  orm::sql::projection()
{
	swap(*this, other);
}

orm::sql::projection::~projection()
{
}

orm::sql::projection &orm::sql::projection::operator =(orm::sql::projection other)
{
	swap(*this, other);

	return *this;
}

void orm::sql::projection::AddProjection(const orm::sql::sql_column &column)
{
	_projections.push_back(column);
}

std::vector<orm::sql::sql_column> &orm::sql::projection::GetProjections()
{
	return _projections;
}

const std::vector<orm::sql::sql_column> &orm::sql::projection::GetProjections() const
{
	return _projections;
}
