#include "stdafx.h"

#include "TestExpressionEntityMap.h"

TestExpressionEntityMap::TestExpressionEntityMap()
{
	Schema("dbo");
	Table("TestTable");

	Map(&TestExpressionEntity::_field, "Field");

	Map(&TestExpressionEntity::SetterGetterSetter, &TestExpressionEntity::SetterGetterGetter, "SetterGetter");
	Map(&TestExpressionEntity::SetterConstGetterSetter, &TestExpressionEntity::SetterConstGetterGetter, "SetterConstGetter");
	Map(&TestExpressionEntity::SetterReferenceGetterSetter, &TestExpressionEntity::SetterReferenceGetterGetter, "SetterReferenceGetter");
	Map(&TestExpressionEntity::SetterConstReferenceGetterSetter, &TestExpressionEntity::SetterConstReferenceGetterGetter, "SetterConstReferenceGetter");

	Map(&TestExpressionEntity::ConstSetterGetterSetter, &TestExpressionEntity::ConstSetterGetterGetter, "ConstSetterGetter");
	Map(&TestExpressionEntity::ConstSetterConstGetterSetter, &TestExpressionEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");
	Map(&TestExpressionEntity::ConstSetterReferenceGetterSetter, &TestExpressionEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");
	Map(&TestExpressionEntity::ConstSetterConstReferenceGetterSetter, &TestExpressionEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	/*
	Map(&TestExpressionEntity::ReferenceSetterGetterSetter, &TestExpressionEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");
	Map(&TestExpressionEntity::ReferenceSetterConstGetterSetter, &TestExpressionEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");
	Map(&TestExpressionEntity::ReferenceSetterReferenceGetterSetter, &TestExpressionEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");
	Map(&TestExpressionEntity::ReferenceSetterConstReferenceGetterSetter, &TestExpressionEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");
	*/

	Map(&TestExpressionEntity::ConstReferenceSetterGetterSetter, &TestExpressionEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");
	Map(&TestExpressionEntity::ConstReferenceSetterConstGetterSetter, &TestExpressionEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");
	Map(&TestExpressionEntity::ConstReferenceSetterReferenceGetterSetter, &TestExpressionEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");
	Map(&TestExpressionEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestExpressionEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");
}

TestExpressionEntityMap::~TestExpressionEntityMap()
{
}
