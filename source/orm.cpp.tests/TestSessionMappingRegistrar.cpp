#include "stdafx.h"

#include "TestSessionMappingRegistrar.h"

TestSessionMappingRegistrar::TestSessionMappingRegistrar()
{
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
