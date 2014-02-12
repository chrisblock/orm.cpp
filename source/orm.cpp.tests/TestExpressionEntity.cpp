#include "stdafx.h"

#include "TestExpressionEntity.h"

TestExpressionEntity::TestExpressionEntity() :
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

TestExpressionEntity::TestExpressionEntity(const TestExpressionEntity &other) :
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

TestExpressionEntity::~TestExpressionEntity()
{
}

TestExpressionEntity &TestExpressionEntity::operator =(const TestExpressionEntity &other)
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



void TestExpressionEntity::SetterGetterSetter(int32_t field)
{
	_setterGetter = field;
}

int32_t TestExpressionEntity::SetterGetterGetter()
{
	return _setterGetter;
}



void TestExpressionEntity::SetterConstGetterSetter(int32_t field)
{
	_setterConstGetter = field;
}

int32_t TestExpressionEntity::SetterConstGetterGetter() const
{
	return _setterConstGetter;
}



void TestExpressionEntity::SetterReferenceGetterSetter(int32_t field)
{
	_setterReferenceGetter = field;
}

int32_t &TestExpressionEntity::SetterReferenceGetterGetter()
{
	return _setterReferenceGetter;
}



void TestExpressionEntity::SetterConstReferenceGetterSetter(int32_t field)
{
	_setterConstReferenceGetter = field;
}

const int32_t &TestExpressionEntity::SetterConstReferenceGetterGetter() const
{
	return _setterConstReferenceGetter;
}



void TestExpressionEntity::ConstSetterGetterSetter(const int32_t field)
{
	_constSetterGetter = field;
}

int32_t TestExpressionEntity::ConstSetterGetterGetter()
{
	return _constSetterGetter;
}



void TestExpressionEntity::ConstSetterConstGetterSetter(const int32_t field)
{
	_constSetterConstGetter = field;
}

int32_t TestExpressionEntity::ConstSetterConstGetterGetter() const
{
	return _constSetterConstGetter;
}



void TestExpressionEntity::ConstSetterReferenceGetterSetter(const int32_t field)
{
	_constSetterReferenceGetter = field;
}

int32_t &TestExpressionEntity::ConstSetterReferenceGetterGetter()
{
	return _constSetterReferenceGetter;
}



void TestExpressionEntity::ConstSetterConstReferenceGetterSetter(const int32_t field)
{
	_constSetterConstReferenceGetter = field;
}

const int32_t &TestExpressionEntity::ConstSetterConstReferenceGetterGetter() const
{
	return _constSetterConstReferenceGetter;
}



void TestExpressionEntity::ReferenceSetterGetterSetter(int32_t &field)
{
	_referenceSetterGetter = field;
}

int32_t TestExpressionEntity::ReferenceSetterGetterGetter()
{
	return _referenceSetterGetter;
}



void TestExpressionEntity::ReferenceSetterConstGetterSetter(int32_t &field)
{
	_referenceSetterConstGetter = field;
}

int32_t TestExpressionEntity::ReferenceSetterConstGetterGetter() const
{
	return _referenceSetterConstGetter;
}



void TestExpressionEntity::ReferenceSetterReferenceGetterSetter(int32_t &field)
{
	_referenceSetterReferenceGetter = field;
}

int32_t &TestExpressionEntity::ReferenceSetterReferenceGetterGetter()
{
	return _referenceSetterReferenceGetter;
}



void TestExpressionEntity::ReferenceSetterConstReferenceGetterSetter(int32_t &field)
{
	_referenceSetterConstReferenceGetter = field;
}

const int32_t &TestExpressionEntity::ReferenceSetterConstReferenceGetterGetter() const
{
	return _referenceSetterConstReferenceGetter;
}



void TestExpressionEntity::ConstReferenceSetterGetterSetter(const int32_t &field)
{
	_constReferenceSetterGetter = field;
}

int32_t TestExpressionEntity::ConstReferenceSetterGetterGetter()
{
	return _constReferenceSetterGetter;
}



void TestExpressionEntity::ConstReferenceSetterConstGetterSetter(const int32_t &field)
{
	_constReferenceSetterConstGetter = field;
}

int32_t TestExpressionEntity::ConstReferenceSetterConstGetterGetter() const
{
	return _constReferenceSetterConstGetter;
}



void TestExpressionEntity::ConstReferenceSetterReferenceGetterSetter(const int32_t &field)
{
	_constReferenceSetterReferenceGetter = field;
}

int32_t &TestExpressionEntity::ConstReferenceSetterReferenceGetterGetter()
{
	return _constReferenceSetterReferenceGetter;
}



void TestExpressionEntity::ConstReferenceSetterConstReferenceGetterSetter(const int32_t &field)
{
	_constReferenceSetterConstReferenceGetter = field;
}

const int32_t &TestExpressionEntity::ConstReferenceSetterConstReferenceGetterGetter() const
{
	return _constReferenceSetterConstReferenceGetter;
}
