#include "stdafx.h"

#include "IdFieldTestMappingEntityMap.h"

IdFieldTestMappingEntityMap::IdFieldTestMappingEntityMap()
{
	Id(&TestMappingEntity::_field, "IdField")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdFieldTestMappingEntityMap::~IdFieldTestMappingEntityMap()
{
}

IdSetterGetterTestMappingEntityMap::IdSetterGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::_field, "IdSetterGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdSetterGetterTestMappingEntityMap::~IdSetterGetterTestMappingEntityMap()
{
}

IdSetterConstGetterTestMappingEntityMap::IdSetterConstGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::SetterConstGetterGetter, &TestMappingEntity::SetterConstGetterSetter, "IdSetterConstGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdSetterConstGetterTestMappingEntityMap::~IdSetterConstGetterTestMappingEntityMap()
{
}

IdSetterReferenceGetterTestMappingEntityMap::IdSetterReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::SetterReferenceGetterGetter, &TestMappingEntity::SetterReferenceGetterSetter, "IdSetterReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdSetterReferenceGetterTestMappingEntityMap::~IdSetterReferenceGetterTestMappingEntityMap()
{
}

IdSetterConstReferenceGetterTestMappingEntityMap::IdSetterConstReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::SetterConstReferenceGetterGetter, &TestMappingEntity::SetterConstReferenceGetterSetter, "IdSetterConstReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdSetterConstReferenceGetterTestMappingEntityMap::~IdSetterConstReferenceGetterTestMappingEntityMap()
{
}

IdConstSetterGetterTestMappingEntityMap::IdConstSetterGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstSetterGetterGetter, &TestMappingEntity::ConstSetterGetterSetter, "IdConstSetterGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstSetterGetterTestMappingEntityMap::~IdConstSetterGetterTestMappingEntityMap()
{
}

IdConstSetterConstGetterTestMappingEntityMap::IdConstSetterConstGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstSetterConstGetterGetter, &TestMappingEntity::ConstSetterConstGetterSetter, "IdConstSetterConstGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstSetterConstGetterTestMappingEntityMap::~IdConstSetterConstGetterTestMappingEntityMap()
{
}

IdConstSetterReferenceGetterTestMappingEntityMap::IdConstSetterReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstSetterReferenceGetterGetter, &TestMappingEntity::ConstSetterReferenceGetterSetter, "IdConstSetterReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstSetterReferenceGetterTestMappingEntityMap::~IdConstSetterReferenceGetterTestMappingEntityMap()
{
}

IdConstSetterConstReferenceGetterTestMappingEntityMap::IdConstSetterConstReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstSetterConstReferenceGetterGetter, &TestMappingEntity::ConstSetterConstReferenceGetterSetter, "IdConstSetterConstReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstSetterConstReferenceGetterTestMappingEntityMap::~IdConstSetterConstReferenceGetterTestMappingEntityMap()
{
}

IdConstReferenceSetterGetterTestMappingEntityMap::IdConstReferenceSetterGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstReferenceSetterGetterGetter, &TestMappingEntity::ConstReferenceSetterGetterSetter, "IdConstReferenceSetterGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstReferenceSetterGetterTestMappingEntityMap::~IdConstReferenceSetterGetterTestMappingEntityMap()
{
}

IdConstReferenceSetterConstGetterTestMappingEntityMap::IdConstReferenceSetterConstGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstReferenceSetterConstGetterGetter, &TestMappingEntity::ConstReferenceSetterConstGetterSetter, "IdConstReferenceSetterConstGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstReferenceSetterConstGetterTestMappingEntityMap::~IdConstReferenceSetterConstGetterTestMappingEntityMap()
{
}

IdConstReferenceSetterReferenceGetterTestMappingEntityMap::IdConstReferenceSetterReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, "IdConstReferenceSetterReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstReferenceSetterReferenceGetterTestMappingEntityMap::~IdConstReferenceSetterReferenceGetterTestMappingEntityMap()
{
}

IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap::IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, "IdConstReferenceSetterConstReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap::~IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap()
{
}
