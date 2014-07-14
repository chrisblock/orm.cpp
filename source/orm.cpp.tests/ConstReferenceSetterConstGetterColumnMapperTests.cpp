#include "stdafx.h"

#include <ConstReferenceSetterConstGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ConstReferenceSetterConstGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ConstReferenceSetterConstGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");

	EXPECT_EQ("ConstReferenceSetterConstGetter", mapper.GetColumnName());
}

TEST(ConstReferenceSetterConstGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ConstReferenceSetterConstGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::_field));
}

TEST(ConstReferenceSetterConstGetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	ConstReferenceSetterConstGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterGetterGetter));
}

TEST(ConstReferenceSetterConstGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsTrue)
{
	ConstReferenceSetterConstGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterConstGetterGetter));
}

TEST(ConstReferenceSetterConstGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ConstReferenceSetterConstGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterReferenceGetterGetter));
}

TEST(ConstReferenceSetterConstGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ConstReferenceSetterConstGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterConstGetterSetter, &TestMappingEntity::ConstReferenceSetterConstGetterGetter, "ConstReferenceSetterConstGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter));
}
