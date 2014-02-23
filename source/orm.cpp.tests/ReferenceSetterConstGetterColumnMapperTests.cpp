#include "stdafx.h"

#include <ReferenceSetterConstGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ReferenceSetterConstGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ReferenceSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");

	EXPECT_EQ("ReferenceSetterConstGetter", mapper.GetColumnName());
}

TEST(ReferenceSetterConstGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ReferenceSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::_field));
}

TEST(ReferenceSetterConstGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ReferenceSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterGetterGetter));
}

TEST(ReferenceSetterConstGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsTrue)
{
	ReferenceSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterConstGetterGetter));
}

TEST(ReferenceSetterConstGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ReferenceSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterReferenceGetterGetter));
}

TEST(ReferenceSetterConstGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ReferenceSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstGetterSetter, &TestMappingEntity::ReferenceSetterConstGetterGetter, "ReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterConstReferenceGetterGetter));
}
