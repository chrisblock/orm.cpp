#include "stdafx.h"

#include "TestExpressionMappingRegistrar.h"

#include "TestExpressionEntity.h"
#include "TestExpressionEntityMap.h"

TestExpressionMappingRegistrar::TestExpressionMappingRegistrar()
{
	Register<TestExpressionEntity, TestExpressionEntityMap>();
}

TestExpressionMappingRegistrar::~TestExpressionMappingRegistrar()
{
}
