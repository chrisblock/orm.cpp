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



void TestExpressionEntity::SetterGetterSetter(std::int32_t field)
{
	_setterGetter = field;
}

std::int32_t TestExpressionEntity::SetterGetterGetter()
{
	return _setterGetter;
}



void TestExpressionEntity::SetterConstGetterSetter(std::int32_t field)
{
	_setterConstGetter = field;
}

std::int32_t TestExpressionEntity::SetterConstGetterGetter() const
{
	return _setterConstGetter;
}



void TestExpressionEntity::SetterReferenceGetterSetter(std::int32_t field)
{
	_setterReferenceGetter = field;
}

std::int32_t &TestExpressionEntity::SetterReferenceGetterGetter()
{
	return _setterReferenceGetter;
}



void TestExpressionEntity::SetterConstReferenceGetterSetter(std::int32_t field)
{
	_setterConstReferenceGetter = field;
}

const std::int32_t &TestExpressionEntity::SetterConstReferenceGetterGetter() const
{
	return _setterConstReferenceGetter;
}



void TestExpressionEntity::ConstSetterGetterSetter(const std::int32_t field)
{
	_constSetterGetter = field;
}

std::int32_t TestExpressionEntity::ConstSetterGetterGetter()
{
	return _constSetterGetter;
}



void TestExpressionEntity::ConstSetterConstGetterSetter(const std::int32_t field)
{
	_constSetterConstGetter = field;
}

std::int32_t TestExpressionEntity::ConstSetterConstGetterGetter() const
{
	return _constSetterConstGetter;
}



void TestExpressionEntity::ConstSetterReferenceGetterSetter(const std::int32_t field)
{
	_constSetterReferenceGetter = field;
}

std::int32_t &TestExpressionEntity::ConstSetterReferenceGetterGetter()
{
	return _constSetterReferenceGetter;
}



void TestExpressionEntity::ConstSetterConstReferenceGetterSetter(const std::int32_t field)
{
	_constSetterConstReferenceGetter = field;
}

const std::int32_t &TestExpressionEntity::ConstSetterConstReferenceGetterGetter() const
{
	return _constSetterConstReferenceGetter;
}



void TestExpressionEntity::ReferenceSetterGetterSetter(std::int32_t &field)
{
	_referenceSetterGetter = field;
}

std::int32_t TestExpressionEntity::ReferenceSetterGetterGetter()
{
	return _referenceSetterGetter;
}



void TestExpressionEntity::ReferenceSetterConstGetterSetter(std::int32_t &field)
{
	_referenceSetterConstGetter = field;
}

std::int32_t TestExpressionEntity::ReferenceSetterConstGetterGetter() const
{
	return _referenceSetterConstGetter;
}



void TestExpressionEntity::ReferenceSetterReferenceGetterSetter(std::int32_t &field)
{
	_referenceSetterReferenceGetter = field;
}

std::int32_t &TestExpressionEntity::ReferenceSetterReferenceGetterGetter()
{
	return _referenceSetterReferenceGetter;
}



void TestExpressionEntity::ReferenceSetterConstReferenceGetterSetter(std::int32_t &field)
{
	_referenceSetterConstReferenceGetter = field;
}

const std::int32_t &TestExpressionEntity::ReferenceSetterConstReferenceGetterGetter() const
{
	return _referenceSetterConstReferenceGetter;
}



void TestExpressionEntity::ConstReferenceSetterGetterSetter(const std::int32_t &field)
{
	_constReferenceSetterGetter = field;
}

std::int32_t TestExpressionEntity::ConstReferenceSetterGetterGetter()
{
	return _constReferenceSetterGetter;
}



void TestExpressionEntity::ConstReferenceSetterConstGetterSetter(const std::int32_t &field)
{
	_constReferenceSetterConstGetter = field;
}

std::int32_t TestExpressionEntity::ConstReferenceSetterConstGetterGetter() const
{
	return _constReferenceSetterConstGetter;
}



void TestExpressionEntity::ConstReferenceSetterReferenceGetterSetter(const std::int32_t &field)
{
	_constReferenceSetterReferenceGetter = field;
}

std::int32_t &TestExpressionEntity::ConstReferenceSetterReferenceGetterGetter()
{
	return _constReferenceSetterReferenceGetter;
}



void TestExpressionEntity::ConstReferenceSetterConstReferenceGetterSetter(const std::int32_t &field)
{
	_constReferenceSetterConstReferenceGetter = field;
}

const std::int32_t &TestExpressionEntity::ConstReferenceSetterConstReferenceGetterGetter() const
{
	return _constReferenceSetterConstReferenceGetter;
}
