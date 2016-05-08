#include "stdafx.h"

#include "TestMappingEntityMap.h"

TestMappingEntityMap::TestMappingEntityMap()
{
	Schema("dbo");
	Table("TestTable");

	// TODO: stop using Id like this, and make different maps that test the different overloads of Id
	/*
	Id(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "IdReferenceSetterGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "IdReferenceSetterConstGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "IdReferenceSetterReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "IdReferenceSetterConstReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);
	*/

	Map(&TestMappingEntity::_field, "Field");

	Map(&TestMappingEntity::SetterGetterGetter, &TestMappingEntity::SetterGetterSetter, "SetterGetter");
	Map(&TestMappingEntity::SetterConstGetterGetter, &TestMappingEntity::SetterConstGetterSetter, "SetterConstGetter");
	Map(&TestMappingEntity::SetterReferenceGetterGetter, &TestMappingEntity::SetterReferenceGetterSetter, "SetterReferenceGetter");
	Map(&TestMappingEntity::SetterConstReferenceGetterGetter, &TestMappingEntity::SetterConstReferenceGetterSetter, "SetterConstReferenceGetter");

	Map(&TestMappingEntity::ConstSetterGetterGetter, &TestMappingEntity::ConstSetterGetterSetter, "ConstSetterGetter");
	Map(&TestMappingEntity::ConstSetterConstGetterGetter, &TestMappingEntity::ConstSetterConstGetterSetter, "ConstSetterConstGetter");
	Map(&TestMappingEntity::ConstSetterReferenceGetterGetter, &TestMappingEntity::ConstSetterReferenceGetterSetter, "ConstSetterReferenceGetter");
	Map(&TestMappingEntity::ConstSetterConstReferenceGetterGetter, &TestMappingEntity::ConstSetterConstReferenceGetterSetter, "ConstSetterConstReferenceGetter");

	Map(&TestMappingEntity::ReferenceSetterGetterGetter, &TestMappingEntity::ReferenceSetterGetterSetter, "ReferenceSetterGetter");
	Map(&TestMappingEntity::ReferenceSetterConstGetterGetter, &TestMappingEntity::ReferenceSetterConstGetterSetter, "ReferenceSetterConstGetter");
	Map(&TestMappingEntity::ReferenceSetterReferenceGetterGetter, &TestMappingEntity::ReferenceSetterReferenceGetterSetter, "ReferenceSetterReferenceGetter");
	Map(&TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, "ReferenceSetterConstReferenceGetter");

	Map(&TestMappingEntity::ConstReferenceSetterGetterGetter, &TestMappingEntity::ConstReferenceSetterGetterSetter, "ConstReferenceSetterGetter");
	Map(&TestMappingEntity::ConstReferenceSetterConstGetterGetter, &TestMappingEntity::ConstReferenceSetterConstGetterSetter, "ConstReferenceSetterConstGetter");
	Map(&TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, "ConstReferenceSetterReferenceGetter");
	Map(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, "ConstReferenceSetterConstReferenceGetter");
}
