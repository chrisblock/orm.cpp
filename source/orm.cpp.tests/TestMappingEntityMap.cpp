#include "stdafx.h"

#include "TestMappingEntityMap.h"

TestMappingEntityMap::TestMappingEntityMap()
{
	Schema("dbo");
	Table("TestTable");

	Id<int32_t>(&TestMappingEntity::_field, "IdField")
		.GeneratedBy(GenerationStrategy::Assigned);

	Id<int32_t>(&TestMappingEntity::SetterGetterSetter, &TestMappingEntity::SetterGetterGetter, "IdSetterGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::SetterConstGetterSetter, &TestMappingEntity::SetterConstGetterGetter, "IdSetterConstGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::SetterReferenceGetterSetter, &TestMappingEntity::SetterReferenceGetterGetter, "IdSetterReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::SetterConstReferenceGetterSetter, &TestMappingEntity::SetterConstReferenceGetterGetter, "IdSetterConstReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);

	Id<int32_t>(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "IdConstSetterGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "IdConstSetterConstGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "IdConstSetterReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "IdConstSetterConstReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);

	/*
	Id<int32_t>(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "IdReferenceSetterGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "IdReferenceSetterConstGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "IdReferenceSetterReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "IdReferenceSetterConstReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);
	*/

	Id<int32_t>(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "IdConstReferenceSetterGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "IdConstReferenceSetterConstGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "IdConstReferenceSetterReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);
	Id<int32_t>(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "IdConstReferenceSetterConstReferenceGetter").GeneratedBy(GenerationStrategy::Assigned);

	Map<int32_t>(&TestMappingEntity::_field, "Field");

	Map<int32_t>(&TestMappingEntity::SetterGetterSetter, &TestMappingEntity::SetterGetterGetter, "SetterGetter");
	Map<int32_t>(&TestMappingEntity::SetterConstGetterSetter, &TestMappingEntity::SetterConstGetterGetter, "SetterConstGetter");
	Map<int32_t>(&TestMappingEntity::SetterReferenceGetterSetter, &TestMappingEntity::SetterReferenceGetterGetter, "SetterReferenceGetter");
	Map<int32_t>(&TestMappingEntity::SetterConstReferenceGetterSetter, &TestMappingEntity::SetterConstReferenceGetterGetter, "SetterConstReferenceGetter");

	Map<int32_t>(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "ConstSetterGetter");
	Map<int32_t>(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");
	Map<int32_t>(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");
	Map<int32_t>(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	/*
	Map<int32_t>(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");
	Map<int32_t>(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");
	Map<int32_t>(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");
	Map<int32_t>(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");
	*/

	Map<int32_t>(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");
	Map<int32_t>(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");
	Map<int32_t>(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");
	Map<int32_t>(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");
}

TestMappingEntityMap::~TestMappingEntityMap()
{
}
