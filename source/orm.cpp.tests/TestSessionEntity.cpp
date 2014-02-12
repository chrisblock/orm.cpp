#include "stdafx.h"

#include "TestSessionEntity.h"

TestSessionEntity::TestSessionEntity()
{
}

TestSessionEntity::TestSessionEntity(const TestSessionEntity &other)
{
	other;
}

TestSessionEntity::~TestSessionEntity()
{
}

TestSessionEntity &TestSessionEntity::operator =(const TestSessionEntity &other)
{
	if (this != &other)
	{
	}

	return *this;
}
