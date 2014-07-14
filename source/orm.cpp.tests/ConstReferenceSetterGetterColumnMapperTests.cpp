#include "stdafx.h"

#include <ConstReferenceSetterGetterColumnMapper.h>

#include "TestMappingEntity.h"

TEST(ConstReferenceSetterGetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	ConstReferenceSetterGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");

	EXPECT_EQ("ConstReferenceSetterGetter", mapper.GetColumnName());
}

TEST(ConstReferenceSetterGetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	ConstReferenceSetterGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::_field));
}

TEST(ConstReferenceSetterGetterColumnMapperTests, IsForMember_GetterMember_ReturnsTrue)
{
	ConstReferenceSetterGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterGetterGetter));
}

TEST(ConstReferenceSetterGetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	ConstReferenceSetterGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterConstGetterGetter));
}

TEST(ConstReferenceSetterGetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	ConstReferenceSetterGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterReferenceGetterGetter));
}

TEST(ConstReferenceSetterGetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	ConstReferenceSetterGetterColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::ConstReferenceSetterGetterSetter, &TestMappingEntity::ConstReferenceSetterGetterGetter, "ConstReferenceSetterGetter");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter));
}
