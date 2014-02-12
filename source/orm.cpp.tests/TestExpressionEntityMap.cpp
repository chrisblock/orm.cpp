#include "stdafx.h"

#include "TestExpressionEntityMap.h"

TestExpressionEntityMap::TestExpressionEntityMap()
{
	Schema("dbo");
	Table("TestTable");

	Map<int32_t>(&TestExpressionEntity::_field, "Field");

	Map<int32_t>(&TestExpressionEntity::SetterGetterSetter, &TestExpressionEntity::SetterGetterGetter, "SetterGetter");
	Map<int32_t>(&TestExpressionEntity::SetterConstGetterSetter, &TestExpressionEntity::SetterConstGetterGetter, "SetterConstGetter");
	Map<int32_t>(&TestExpressionEntity::SetterReferenceGetterSetter, &TestExpressionEntity::SetterReferenceGetterGetter, "SetterReferenceGetter");
	Map<int32_t>(&TestExpressionEntity::SetterConstReferenceGetterSetter, &TestExpressionEntity::SetterConstReferenceGetterGetter, "SetterConstReferenceGetter");

	Map<int32_t>(&TestExpressionEntity::ConstSetterGetterSetter, &TestExpressionEntity::ConstSetterGetterGetter, "ConstSetterGetter");
	Map<int32_t>(&TestExpressionEntity::ConstSetterConstGetterSetter, &TestExpressionEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");
	Map<int32_t>(&TestExpressionEntity::ConstSetterReferenceGetterSetter, &TestExpressionEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");
	Map<int32_t>(&TestExpressionEntity::ConstSetterConstReferenceGetterSetter, &TestExpressionEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	/*
	Map<int32_t>(&TestExpressionEntity::ReferenceSetterGetterSetter, &TestExpressionEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");
	Map<int32_t>(&TestExpressionEntity::ReferenceSetterConstGetterSetter, &TestExpressionEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");
	Map<int32_t>(&TestExpressionEntity::ReferenceSetterReferenceGetterSetter, &TestExpressionEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");
	Map<int32_t>(&TestExpressionEntity::ReferenceSetterConstReferenceGetterSetter, &TestExpressionEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");
	*/

	Map<int32_t>(&TestExpressionEntity::ConstReferenceSetterGetterSetter, &TestExpressionEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");
	Map<int32_t>(&TestExpressionEntity::ConstReferenceSetterConstGetterSetter, &TestExpressionEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");
	Map<int32_t>(&TestExpressionEntity::ConstReferenceSetterReferenceGetterSetter, &TestExpressionEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");
	Map<int32_t>(&TestExpressionEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestExpressionEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");
}

TestExpressionEntityMap::~TestExpressionEntityMap()
{
}
