#include "stdafx.h"

#include "TestExpressionEntityMap.h"

TestExpressionEntityMap::TestExpressionEntityMap()
{
	Schema("dbo");
	Table("TestTable");

	Map(&TestExpressionEntity::_field, "Field");

	Map(&TestExpressionEntity::SetterGetterGetter, &TestExpressionEntity::SetterGetterSetter, "SetterGetter");
	Map(&TestExpressionEntity::SetterConstGetterGetter, &TestExpressionEntity::SetterConstGetterSetter, "SetterConstGetter");
	Map(&TestExpressionEntity::SetterReferenceGetterGetter, &TestExpressionEntity::SetterReferenceGetterSetter, "SetterReferenceGetter");
	Map(&TestExpressionEntity::SetterConstReferenceGetterGetter, &TestExpressionEntity::SetterConstReferenceGetterSetter, "SetterConstReferenceGetter");

	Map(&TestExpressionEntity::ConstSetterGetterGetter, &TestExpressionEntity::ConstSetterGetterSetter, "ConstSetterGetter");
	Map(&TestExpressionEntity::ConstSetterConstGetterGetter, &TestExpressionEntity::ConstSetterConstGetterSetter, "ConstSetterConstGetter");
	Map(&TestExpressionEntity::ConstSetterReferenceGetterGetter, &TestExpressionEntity::ConstSetterReferenceGetterSetter, "ConstSetterReferenceGetter");
	Map(&TestExpressionEntity::ConstSetterConstReferenceGetterGetter, &TestExpressionEntity::ConstSetterConstReferenceGetterSetter, "ConstSetterConstReferenceGetter");

	Map(&TestExpressionEntity::ReferenceSetterGetterGetter, &TestExpressionEntity::ReferenceSetterGetterSetter, "ReferenceSetterGetter");
	Map(&TestExpressionEntity::ReferenceSetterConstGetterGetter, &TestExpressionEntity::ReferenceSetterConstGetterSetter, "ReferenceSetterConstGetter");
	Map(&TestExpressionEntity::ReferenceSetterReferenceGetterGetter, &TestExpressionEntity::ReferenceSetterReferenceGetterSetter, "ReferenceSetterReferenceGetter");
	Map(&TestExpressionEntity::ReferenceSetterConstReferenceGetterGetter, &TestExpressionEntity::ReferenceSetterConstReferenceGetterSetter, "ReferenceSetterConstReferenceGetter");

	Map(&TestExpressionEntity::ConstReferenceSetterGetterGetter, &TestExpressionEntity::ConstReferenceSetterGetterSetter, "ConstReferenceSetterGetter");
	Map(&TestExpressionEntity::ConstReferenceSetterConstGetterGetter, &TestExpressionEntity::ConstReferenceSetterConstGetterSetter, "ConstReferenceSetterConstGetter");
	Map(&TestExpressionEntity::ConstReferenceSetterReferenceGetterGetter, &TestExpressionEntity::ConstReferenceSetterReferenceGetterSetter, "ConstReferenceSetterReferenceGetter");
	Map(&TestExpressionEntity::ConstReferenceSetterConstReferenceGetterGetter, &TestExpressionEntity::ConstReferenceSetterConstReferenceGetterSetter, "ConstReferenceSetterConstReferenceGetter");
}
