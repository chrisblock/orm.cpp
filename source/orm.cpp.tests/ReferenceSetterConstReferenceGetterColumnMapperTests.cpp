#include "stdafx.h"

#include <ReferenceSetterConstReferenceGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ReferenceSetterConstReferenceGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");

	EXPECT_EQ("ReferenceSetterConstReferenceGetter", mapper.GetColumnName());
}

TEST(ReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::_field));
}

TEST(ReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterGetterGetter));
}

TEST(ReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterConstGetterGetter));
}

TEST(ReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterReferenceGetterGetter));
}

TEST(ReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsTrue)
{
	ReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ReferenceSetterConstReferenceGetterGetter, "ReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterConstReferenceGetterGetter));
}
