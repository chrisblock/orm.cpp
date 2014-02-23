#include "stdafx.h"

#include <ReferenceSetterGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ReferenceSetterGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ReferenceSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");

	EXPECT_EQ("ReferenceSetterGetter", mapper.GetColumnName());
}

TEST(ReferenceSetterGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ReferenceSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::_field));
}

TEST(ReferenceSetterGetterColumnMapperTests, IsForMember_GetterMember_ReturnsTrue)
{
	ReferenceSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterGetterGetter));
}

TEST(ReferenceSetterGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ReferenceSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterConstGetterGetter));
}

TEST(ReferenceSetterGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ReferenceSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterReferenceGetterGetter));
}

TEST(ReferenceSetterGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ReferenceSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ReferenceSetterGetterSetter, &TestMappingEntity::ReferenceSetterGetterGetter, "ReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ReferenceSetterConstReferenceGetterGetter));
}
