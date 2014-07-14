#include "stdafx.h"

#include <ConstSetterReferenceGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ConstSetterReferenceGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ConstSetterReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");

	EXPECT_EQ("ConstSetterReferenceGetter", mapper.GetColumnName());
}

TEST(ConstSetterReferenceGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ConstSetterReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::_field));
}

TEST(ConstSetterReferenceGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ConstSetterReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterGetterGetter));
}

TEST(ConstSetterReferenceGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ConstSetterReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterConstGetterGetter));
}

TEST(ConstSetterReferenceGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsTrue)
{
	ConstSetterReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterReferenceGetterGetter));
}

TEST(ConstSetterReferenceGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ConstSetterReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterReferenceGetterSetter, &TestMappingEntity::ConstSetterReferenceGetterGetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterConstReferenceGetterGetter));
}
