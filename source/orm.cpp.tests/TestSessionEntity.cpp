#include "stdafx.h"

#include "TestSessionEntity.h"

TestSessionEntity::TestSessionEntity() :
	  _id(0)
	, _column1(0)
	, _column2(0)
{
}

TestSessionEntity::TestSessionEntity(const TestSessionEntity &other) :
	  _id(other._id)
	, _column1(other._column1)
	, _column2(other._column2)
{
}

TestSessionEntity::~TestSessionEntity()
{
}

TestSessionEntity &TestSessionEntity::operator =(const TestSessionEntity &other)
{
	if (this != &other)
	{
		_id = other._id;
		_column1 = other._column1;
		_column2 = other._column2;
	}

	return *this;
}
