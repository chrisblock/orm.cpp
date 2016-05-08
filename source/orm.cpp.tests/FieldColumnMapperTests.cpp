#include "stdafx.h"

#include <FieldColumnMapper.h>

#include <memory>

#include "TestMappingEntity.h"

class FieldColumnMapperTests : public ::testing::Test
{
protected:
	virtual void SetUp() override
	{
	};

	virtual void TearDown() override
	{
	};

	template <typename TEntity, typename TField>
	std::shared_ptr<FieldColumnMapper<TEntity, TField>> CreateFieldColumnMapper(TField field, const std::string &column) const
	{
		auto result = std::make_shared<FieldColumnMapper<TEntity, TField>>(field, column);

		return result;
	};
};

TEST_F(FieldColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	EXPECT_EQ("Field", mapper->GetColumnName());
}

TEST_F(FieldColumnMapperTests, IsForMember_FieldMember_ReturnsTrue)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_TRUE(iMapper.IsForMember(&TestMappingEntity::_field));
}

TEST_F(FieldColumnMapperTests, IsForMember_SetterMember_ReturnsFalse)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::SetterGetterSetter));
}

TEST_F(FieldColumnMapperTests, IsForMember_ConstSetterMember_ReturnsFalse)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::ConstSetterGetterSetter));
}

TEST_F(FieldColumnMapperTests, IsForMember_ReferenceSetterMember_ReturnsFalse)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::ReferenceSetterGetterSetter));
}

TEST_F(FieldColumnMapperTests, IsForMember_ConstReferenceSetterMember_ReturnsFalse)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::ConstReferenceSetterGetterSetter));
}

TEST_F(FieldColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::SetterGetterGetter));
}

TEST_F(FieldColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::SetterConstGetterGetter));
}

TEST_F(FieldColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsFalse)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::SetterReferenceGetterGetter));
}

TEST_F(FieldColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	auto mapper = CreateFieldColumnMapper<TestMappingEntity>(&TestMappingEntity::_field, "Field");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::SetterConstReferenceGetterGetter));
}
