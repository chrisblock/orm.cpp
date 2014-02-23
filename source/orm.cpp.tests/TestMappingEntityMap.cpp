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

	Map(&TestMappingEntity::SetterGetterSetter, &TestMappingEntity::SetterGetterGetter, "SetterGetter");
	Map(&TestMappingEntity::SetterConstGetterSetter, &TestMappingEntity::SetterConstGetterGetter, "SetterConstGetter");
	Map(&TestMappingEntity::SetterReferenceGetterSetter, &TestMappingEntity::SetterReferenceGetterGetter, "SetterReferenceGetter");
	Map(&TestMappingEntity::SetterConstReferenceGetterSetter, &TestMappingEntity::SetterConstReferenceGetterGetter, "SetterConstReferenceGetter");

	Map(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "ConstSetterGetter");
	Map(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");
	Map(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");
	Map(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	/*
	Map(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");
	Map(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");
	Map(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");
	Map(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");
	*/

	Map(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");
	Map(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");
	Map(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");
	Map(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");
}

TestMappingEntityMap::~TestMappingEntityMap()
{
}
