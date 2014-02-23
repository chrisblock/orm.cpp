#include "stdafx.h"

#include <ConstSetterGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ConstSetterGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ConstSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "ConstSetterGetter");

	EXPECT_EQ("ConstSetterGetter", mapper.GetColumnName());
}

TEST(ConstSetterGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ConstSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "ConstSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::_field));
}

TEST(ConstSetterGetterColumnMapperTests, IsForMember_GetterMember_ReturnsTrue)
{
	ConstSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "ConstSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstSetterGetterGetter));
}

TEST(ConstSetterGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ConstSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "ConstSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstSetterConstGetterGetter));
}

TEST(ConstSetterGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ConstSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "ConstSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstSetterReferenceGetterGetter));
}

TEST(ConstSetterGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ConstSetterGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterGetterSetter, &TestMappingEntity::ConstSetterGetterGetter, "ConstSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstSetterConstReferenceGetterGetter));
}
