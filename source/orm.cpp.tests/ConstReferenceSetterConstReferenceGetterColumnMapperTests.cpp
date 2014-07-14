#include "stdafx.h"

#include <ConstReferenceSetterConstReferenceGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ConstReferenceSetterConstReferenceGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ConstReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");

	EXPECT_EQ("ConstReferenceSetterConstReferenceGetter", mapper.GetColumnName());
}

TEST(ConstReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ConstReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::_field));
}

TEST(ConstReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ConstReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterGetterGetter));
}

TEST(ConstReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ConstReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterConstGetterGetter));
}

TEST(ConstReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ConstReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterReferenceGetterGetter));
}

TEST(ConstReferenceSetterConstReferenceGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsTrue)
{
	ConstReferenceSetterConstReferenceGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter, &TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter, "ConstReferenceSetterConstReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter));
}
