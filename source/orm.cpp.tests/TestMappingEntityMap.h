#pragma once

#include <ClassMap.h>

#include "TestMappingEntity.h"

class TestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	TestMappingEntityMap();
	virtual ~TestMappingEntityMap();
};
