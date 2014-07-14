#include "stdafx.h"

#include <FieldColumnMapper.h>

#include <member_types.h>

#include "TestMappingEntity.h"

TEST(FieldColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");

	EXPECT_EQ("Field", mapper.GetColumnName());
}

TEST(FieldColumnMapperTests, IsForMember_FieldMember_ReturnsTrue)
{
	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_TRUE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::_field));
}

//TEST(FieldColumnMapperTests, IsForMember_SetterMember_ReturnsFalse)
//{
//	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");
//
//	IColumnMapper<TestMappingEntity> &iMapper = mapper;
//
//	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::SetterGetterSetter));
//}

//TEST(FieldColumnMapperTests, IsForMember_ConstSetterMember_ReturnsFalse)
//{
//	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");
//
//	IColumnMapper<TestMappingEntity> &iMapper = mapper;
//
//	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstSetterGetterSetter));
//}

//TEST(FieldColumnMapperTests, IsForMember_ReferenceSetterMember_ReturnsFalse)
//{
//	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");
//
//	IColumnMapper<TestMappingEntity> &iMapper = mapper;
//
//	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ReferenceSetterGetterSetter));
//}

//TEST(FieldColumnMapperTests, IsForMember_ConstReferenceSetterMember_ReturnsFalse)
//{
//	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");
//
//	IColumnMapper<TestMappingEntity> &iMapper = mapper;
//
//	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::ConstReferenceSetterGetterSetter));
//}

TEST(FieldColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::SetterGetterGetter));
}

TEST(FieldColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::SetterConstGetterGetter));
}

TEST(FieldColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::SetterReferenceGetterGetter));
}

TEST(FieldColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	FieldColumnMapper<TestMappingEntity, std::int32_t> mapper(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = mapper;

	EXPECT_FALSE(iMapper.IsForMember<std::int32_t>(&TestMappingEntity::SetterConstReferenceGetterGetter));
}
