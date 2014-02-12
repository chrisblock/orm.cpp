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
