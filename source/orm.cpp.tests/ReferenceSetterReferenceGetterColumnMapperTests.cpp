#include "stdafx.h"

#include <ReferenceSetterReferenceGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ReferenceSetterReferenceGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");

	EXPECT_EQ("ReferenceSetterReferenceGetter", mapper.GetColumnName());
}

TEST(ReferenceSetterReferenceGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::_field));
}

TEST(ReferenceSetterReferenceGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterGetterGetter));
}

TEST(ReferenceSetterReferenceGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterConstGetterGetter));
}

TEST(ReferenceSetterReferenceGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsTrue)
{
	ReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterReferenceGetterGetter));
}

TEST(ReferenceSetterReferenceGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ReferenceSetterReferenceGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterReferenceGetterSetter, &TestMappingEntity::ReferenceSetterReferenceGetterGetter, "ReferenceSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterConstReferenceGetterGetter));
}
