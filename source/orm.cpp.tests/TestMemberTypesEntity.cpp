#include "stdafx.h"

#include "TestMemberTypesEntity.h"

TestMemberTypesEntity::TestMemberTypesEntity() :
	  _integer(0)
{
}

TestMemberTypesEntity::TestMemberTypesEntity(const TestMemberTypesEntity &other) :
	  _integer(other._integer)
{
}

TestMemberTypesEntity::~TestMemberTypesEntity()
{
}

TestMemberTypesEntity &TestMemberTypesEntity::operator =(const TestMemberTypesEntity &other)
{
	if (this != &other)
	{
		_integer = other._integer;
	}

	return *this;
}

int TestMemberTypesEntity::Getter()
{
	return _integer;
}

int TestMemberTypesEntity::ConstAccessor() const
{
	return _integer;
}

int &TestMemberTypesEntity::ReferenceAccessor()
{
	return _integer;
}

const int &TestMemberTypesEntity::ConstReferenceAccessor() const
{
	return _integer;
}

void TestMemberTypesEntity::Setter(int integer)
{
	_integer = integer;
}

void TestMemberTypesEntity::ConstSetter(const int integer)
{
	_integer = integer;
}

void TestMemberTypesEntity::ReferenceSetter(int &integer)
{
	_integer = integer;
}

void TestMemberTypesEntity::ConstReferenceSetter(const int &integer)
{
	_integer = integer;
}
