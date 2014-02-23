#include "stdafx.h"

#include <ConstSetterConstGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ConstSetterConstGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ConstSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");

	EXPECT_EQ("ConstSetterConstGetter", mapper.GetColumnName());
}

TEST(ConstSetterConstGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ConstSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::_field));
}

TEST(ConstSetterConstGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ConstSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstSetterGetterGetter));
}

TEST(ConstSetterConstGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsTrue)
{
	ConstSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstSetterConstGetterGetter));
}

TEST(ConstSetterConstGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ConstSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstSetterReferenceGetterGetter));
}

TEST(ConstSetterConstGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ConstSetterConstGetterColumnMapper<TestMappingEntity, int32_t> mapper(&TestMappingEntity::ConstSetterConstGetterSetter, &TestMappingEntity::ConstSetterConstGetterGetter, "ConstSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<int32_t>(&TestMappingEntity::ConstSetterConstReferenceGetterGetter));
}
