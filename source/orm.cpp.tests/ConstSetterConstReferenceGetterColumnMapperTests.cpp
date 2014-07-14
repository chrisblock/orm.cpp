#include "stdafx.h"

#include <ConstSetterConstReferenceGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ConstSetterConstReferenceGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ConstSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	EXPECT_EQ("ConstSetterConstReferenceGetter", mapper.GetColumnName());
}

TEST(ConstSetterConstReferenceGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ConstSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::_field));
}

TEST(ConstSetterConstReferenceGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ConstSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterGetterGetter));
}

TEST(ConstSetterConstReferenceGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ConstSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterConstGetterGetter));
}

TEST(ConstSetterConstReferenceGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ConstSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterReferenceGetterGetter));
}

TEST(ConstSetterConstReferenceGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsTrue)
{
	ConstSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstSetterConstReferenceGetterSetter, &TestMappingEntity::ConstSetterConstReferenceGetterGetter, "ConstSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterConstReferenceGetterGetter));
}
