#include "stdafx.h"

#include <ConstReferenceSetterReferenceGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ConstReferenceSetterReferenceGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ConstReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");

	EXPECT_EQ("ConstReferenceSetterReferenceGetter", mapper.GetColumnName());
}

TEST(ConstReferenceSetterReferenceGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ConstReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::_field));
}

TEST(ConstReferenceSetterReferenceGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ConstReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstReferenceSetterGetterGetter));
}

TEST(ConstReferenceSetterReferenceGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ConstReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstReferenceSetterConstGetterGetter));
}

TEST(ConstReferenceSetterReferenceGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsTrue)
{
	ConstReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstReferenceSetterReferenceGetterGetter));
}

TEST(ConstReferenceSetterReferenceGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ConstReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterReferenceGetterGetter, "ConstReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter));
}
