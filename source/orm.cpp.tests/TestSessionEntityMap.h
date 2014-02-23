#pragma once

#include "ClassMap.h"
#include "TestSessionEntity.h"

class TestSessionEntityMap : public ClassMap<TestSessionEntity>
{
public:
	TestSessionEntityMap();
	virtual ~TestSessionEntityMap();
};
