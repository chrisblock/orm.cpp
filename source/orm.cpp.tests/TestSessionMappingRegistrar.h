#pragma once

#include <MappingRegistrar.h>

class TestSessionMappingRegistrar : public MappingRegistrar
{
public:
	TestSessionMappingRegistrar();
	TestSessionMappingRegistrar(const TestSessionMappingRegistrar &other);
	~TestSessionMappingRegistrar();

	TestSessionMappingRegistrar &operator =(const TestSessionMappingRegistrar &other);
};
