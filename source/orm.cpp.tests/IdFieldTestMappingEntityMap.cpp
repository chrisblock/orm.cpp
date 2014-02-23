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
	Id(&TestMappingEntity::SetterConstGetterSetter, &TestMappingEntity::SetterConstGetterGetter, "IdSetterConstGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdSetterConstGetterTestMappingEntityMap::~IdSetterConstGetterTestMappingEntityMap()
{
}

IdSetterReferenceGetterTestMappingEntityMap::IdSetterReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::SetterReferenceGetterSetter, &TestMappingEntity::SetterReferenceGetterGetter, "IdSetterReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdSetterReferenceGetterTestMappingEntityMap::~IdSetterReferenceGetterTestMappingEntityMap()
{
}

IdSetterConstReferenceGetterTestMappingEntityMap::IdSetterConstReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::SetterConstReferenceGetterSetter, &TestMappingEntity::SetterConstReferenceGetterGetter, "IdSetterConstReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdSetterConstReferenceGetterTestMappingEntityMap::~IdSetterConstReferenceGetterTestMappingEntityMap()
{
}

IdConstSetterGetterTestMappingEntityMap::IdConstSetterGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "IdConstSetterGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstSetterGetterTestMappingEntityMap::~IdConstSetterGetterTestMappingEntityMap()
{
}

IdConstSetterConstGetterTestMappingEntityMap::IdConstSetterConstGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "IdConstSetterConstGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstSetterConstGetterTestMappingEntityMap::~IdConstSetterConstGetterTestMappingEntityMap()
{
}

IdConstSetterReferenceGetterTestMappingEntityMap::IdConstSetterReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "IdConstSetterReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstSetterReferenceGetterTestMappingEntityMap::~IdConstSetterReferenceGetterTestMappingEntityMap()
{
}

IdConstSetterConstReferenceGetterTestMappingEntityMap::IdConstSetterConstReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "IdConstSetterConstReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstSetterConstReferenceGetterTestMappingEntityMap::~IdConstSetterConstReferenceGetterTestMappingEntityMap()
{
}

IdConstReferenceSetterGetterTestMappingEntityMap::IdConstReferenceSetterGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "IdConstReferenceSetterGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstReferenceSetterGetterTestMappingEntityMap::~IdConstReferenceSetterGetterTestMappingEntityMap()
{
}

IdConstReferenceSetterConstGetterTestMappingEntityMap::IdConstReferenceSetterConstGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "IdConstReferenceSetterConstGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstReferenceSetterConstGetterTestMappingEntityMap::~IdConstReferenceSetterConstGetterTestMappingEntityMap()
{
}

IdConstReferenceSetterReferenceGetterTestMappingEntityMap::IdConstReferenceSetterReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "IdConstReferenceSetterReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstReferenceSetterReferenceGetterTestMappingEntityMap::~IdConstReferenceSetterReferenceGetterTestMappingEntityMap()
{
}

IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap::IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap()
{
	Id(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "IdConstReferenceSetterConstReferenceGetter")
		.GeneratedBy(GenerationStrategy::Assigned);
}

IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap::~IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap()
{
}
