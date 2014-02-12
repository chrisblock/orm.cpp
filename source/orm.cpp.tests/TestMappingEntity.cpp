#include "stdafx.h"

#include "TestMappingEntity.h"

TestMappingEntity::TestMappingEntity() :
	  _field(0)
	, _setterGetter(0)
	, _setterConstGetter(0)
	, _setterReferenceGetter(0)
	, _setterConstReferenceGetter(0)
	, _constSetterGetter(0)
	, _constSetterConstGetter(0)
	, _constSetterReferenceGetter(0)
	, _constSetterConstReferenceGetter(0)
	, _referenceSetterGetter(0)
	, _referenceSetterConstGetter(0)
	, _referenceSetterReferenceGetter(0)
	, _referenceSetterConstReferenceGetter(0)
	, _constReferenceSetterGetter(0)
	, _constReferenceSetterConstGetter(0)
	, _constReferenceSetterReferenceGetter(0)
	, _constReferenceSetterConstReferenceGetter(0)
{
}

TestMappingEntity::TestMappingEntity(const TestMappingEntity &other) :
	  _field(other._field)
	, _setterGetter(other._setterGetter)
	, _setterConstGetter(other._setterConstGetter)
	, _setterReferenceGetter(other._setterReferenceGetter)
	, _setterConstReferenceGetter(other._setterConstReferenceGetter)
	, _constSetterGetter(other._constSetterGetter)
	, _constSetterConstGetter(other._constSetterConstGetter)
	, _constSetterReferenceGetter(other._constSetterReferenceGetter)
	, _constSetterConstReferenceGetter(other._constSetterConstReferenceGetter)
	, _referenceSetterGetter(other._referenceSetterGetter)
	, _referenceSetterConstGetter(other._referenceSetterConstGetter)
	, _referenceSetterReferenceGetter(other._referenceSetterReferenceGetter)
	, _referenceSetterConstReferenceGetter(other._referenceSetterConstReferenceGetter)
	, _constReferenceSetterGetter(other._constReferenceSetterGetter)
	, _constReferenceSetterConstGetter(other._constReferenceSetterConstGetter)
	, _constReferenceSetterReferenceGetter(other._constReferenceSetterReferenceGetter)
	, _constReferenceSetterConstReferenceGetter(other._constReferenceSetterConstReferenceGetter)
{
}

TestMappingEntity::~TestMappingEntity()
{
}

TestMappingEntity &TestMappingEntity::operator =(const TestMappingEntity &other)
{
	if (this != &other)
	{
		_field = other._field;
		_setterGetter = other._setterGetter;
		_setterConstGetter = other._setterConstGetter;
		_setterReferenceGetter = other._setterReferenceGetter;
		_setterConstReferenceGetter = other._setterConstReferenceGetter;
		_constSetterGetter = other._constSetterGetter;
		_constSetterConstGetter = other._constSetterConstGetter;
		_constSetterReferenceGetter = other._constSetterReferenceGetter;
		_constSetterConstReferenceGetter = other._constSetterConstReferenceGetter;
		_referenceSetterGetter = other._referenceSetterGetter;
		_referenceSetterConstGetter = other._referenceSetterConstGetter;
		_referenceSetterReferenceGetter = other._referenceSetterReferenceGetter;
		_referenceSetterConstReferenceGetter = other._referenceSetterConstReferenceGetter;
		_constReferenceSetterGetter = other._constReferenceSetterGetter;
		_constReferenceSetterConstGetter = other._constReferenceSetterConstGetter;
		_constReferenceSetterReferenceGetter = other._constReferenceSetterReferenceGetter;
		_constReferenceSetterConstReferenceGetter = other._constReferenceSetterConstReferenceGetter;
	}

	return *this;
}



void TestMappingEntity::SetterGetterSetter(int32_t field)
{
	_setterGetter = field;
}

int32_t TestMappingEntity::SetterGetterGetter()
{
	return _setterGetter;
}



void TestMappingEntity::SetterConstGetterSetter(int32_t field)
{
	_setterConstGetter = field;
}

int32_t TestMappingEntity::SetterConstGetterGetter() const
{
	return _setterConstGetter;
}



void TestMappingEntity::SetterReferenceGetterSetter(int32_t field)
{
	_setterReferenceGetter = field;
}

int32_t &TestMappingEntity::SetterReferenceGetterGetter()
{
	return _setterReferenceGetter;
}



void TestMappingEntity::SetterConstReferenceGetterSetter(int32_t field)
{
	_setterConstReferenceGetter = field;
}

const int32_t &TestMappingEntity::SetterConstReferenceGetterGetter() const
{
	return _setterConstReferenceGetter;
}



void TestMappingEntity::ConstSetterGetterSetter(const int32_t field)
{
	_constSetterGetter = field;
}

int32_t TestMappingEntity::ConstSetterGetterGetter()
{
	return _constSetterGetter;
}



void TestMappingEntity::ConstSetterConstGetterSetter(const int32_t field)
{
	_constSetterConstGetter = field;
}

int32_t TestMappingEntity::ConstSetterConstGetterGetter() const
{
	return _constSetterConstGetter;
}



void TestMappingEntity::ConstSetterReferenceGetterSetter(const int32_t field)
{
	_constSetterReferenceGetter = field;
}

int32_t &TestMappingEntity::ConstSetterReferenceGetterGetter()
{
	return _constSetterReferenceGetter;
}



void TestMappingEntity::ConstSetterConstReferenceGetterSetter(const int32_t field)
{
	_constSetterConstReferenceGetter = field;
}

const int32_t &TestMappingEntity::ConstSetterConstReferenceGetterGetter() const
{
	return _constSetterConstReferenceGetter;
}



void TestMappingEntity::ReferenceSetterGetterSetter(int32_t &field)
{
	_referenceSetterGetter = field;
}

int32_t TestMappingEntity::ReferenceSetterGetterGetter()
{
	return _referenceSetterGetter;
}



void TestMappingEntity::ReferenceSetterConstGetterSetter(int32_t &field)
{
	_referenceSetterConstGetter = field;
}

int32_t TestMappingEntity::ReferenceSetterConstGetterGetter() const
{
	return _referenceSetterConstGetter;
}



void TestMappingEntity::ReferenceSetterReferenceGetterSetter(int32_t &field)
{
	_referenceSetterReferenceGetter = field;
}

int32_t &TestMappingEntity::ReferenceSetterReferenceGetterGetter()
{
	return _referenceSetterReferenceGetter;
}



void TestMappingEntity::ReferenceSetterConstReferenceGetterSetter(int32_t &field)
{
	_referenceSetterConstReferenceGetter = field;
}

const int32_t &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter() const
{
	return _referenceSetterConstReferenceGetter;
}



void TestMappingEntity::ConstReferenceSetterGetterSetter(const int32_t &field)
{
	_constReferenceSetterGetter = field;
}

int32_t TestMappingEntity::ConstReferenceSetterGetterGetter()
{
	return _constReferenceSetterGetter;
}



void TestMappingEntity::ConstReferenceSetterConstGetterSetter(const int32_t &field)
{
	_constReferenceSetterConstGetter = field;
}

int32_t TestMappingEntity::ConstReferenceSetterConstGetterGetter() const
{
	return _constReferenceSetterConstGetter;
}



void TestMappingEntity::ConstReferenceSetterReferenceGetterSetter(const int32_t &field)
{
	_constReferenceSetterReferenceGetter = field;
}

int32_t &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter()
{
	return _constReferenceSetterReferenceGetter;
}



void TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter(const int32_t &field)
{
	_constReferenceSetterConstReferenceGetter = field;
}

const int32_t &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter() const
{
	return _constReferenceSetterConstReferenceGetter;
}
