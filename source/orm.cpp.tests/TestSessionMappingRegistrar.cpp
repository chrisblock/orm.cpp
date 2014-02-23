#include "stdafx.h"

#include "TestSessionMappingRegistrar.h"

#include "TestSessionEntity.h"
#include "TestSessionEntityMap.h"

TestSessionMappingRegistrar::TestSessionMappingRegistrar()
{
	Register<TestSessionEntity, TestSessionEntityMap>();
}

TestSessionMappingRegistrar::TestSessionMappingRegistrar(const TestSessionMappingRegistrar &other) :
	  MappingRegistrar(other)
{
}

TestSessionMappingRegistrar::~TestSessionMappingRegistrar()
{
}

TestSessionMappingRegistrar &TestSessionMappingRegistrar::operator = (const TestSessionMappingRegistrar &other)
{
	if (this != &other)
	{
		MappingRegistrar::operator =(other);
	}

	return *this;
}
