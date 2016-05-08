#include "stdafx.h"

#include <GetterSetterColumnMapper.h>

#include <memory>

#include "TestMappingEntity.h"

class GetterSetterColumnMapperTests : public ::testing::Test
{
protected:
	virtual void SetUp() override
	{
	};

	virtual void TearDown() override
	{
	};

	template <typename TEntity, typename TGetter, typename TSetter>
	std::shared_ptr<GetterSetterColumnMapper<TEntity, TGetter, TSetter>> CreateGetterSetterColumnMapper(TGetter getter, TSetter setter, const std::string &column) const
	{
		auto result = std::make_shared<GetterSetterColumnMapper<TEntity, TGetter, TSetter>>(getter, setter, column);

		return result;
	};
};

TEST_F(GetterSetterColumnMapperTests, GetColumnName_ReturnsColumnName)
{
	auto mapper = CreateGetterSetterColumnMapper<TestMappingEntity>(&TestMappingEntity::ConstSetterReferenceGetterGetter, &TestMappingEntity::ConstSetterReferenceGetterSetter, "ConstSetterReferenceGetter");

	EXPECT_EQ("ConstSetterReferenceGetter", mapper->GetColumnName());
}

TEST_F(GetterSetterColumnMapperTests, IsForMember_FieldMember_ReturnsFalse)
{
	auto mapper = CreateGetterSetterColumnMapper<TestMappingEntity>(&TestMappingEntity::ConstSetterReferenceGetterGetter, &TestMappingEntity::ConstSetterReferenceGetterSetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::_field));
}

TEST_F(GetterSetterColumnMapperTests, IsForMember_GetterMember_ReturnsFalse)
{
	auto mapper = CreateGetterSetterColumnMapper<TestMappingEntity>(&TestMappingEntity::ConstSetterReferenceGetterGetter, &TestMappingEntity::ConstSetterReferenceGetterSetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::ConstSetterGetterGetter));
}

TEST_F(GetterSetterColumnMapperTests, IsForMember_ConstGetterMember_ReturnsFalse)
{
	auto mapper = CreateGetterSetterColumnMapper<TestMappingEntity>(&TestMappingEntity::ConstSetterReferenceGetterGetter, &TestMappingEntity::ConstSetterReferenceGetterSetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::ConstSetterConstGetterGetter));
}

TEST_F(GetterSetterColumnMapperTests, IsForMember_ReferenceGetterMember_ReturnsTrue)
{
	auto mapper = CreateGetterSetterColumnMapper<TestMappingEntity>(&TestMappingEntity::ConstSetterReferenceGetterGetter, &TestMappingEntity::ConstSetterReferenceGetterSetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_TRUE(iMapper.IsForMember(&TestMappingEntity::ConstSetterReferenceGetterGetter));
}

TEST_F(GetterSetterColumnMapperTests, IsForMember_ConstReferenceGetterMember_ReturnsFalse)
{
	auto mapper = CreateGetterSetterColumnMapper<TestMappingEntity>(&TestMappingEntity::ConstSetterReferenceGetterGetter, &TestMappingEntity::ConstSetterReferenceGetterSetter, "ConstSetterReferenceGetter");

	IColumnMapper<TestMappingEntity> &iMapper = *mapper;

	EXPECT_FALSE(iMapper.IsForMember(&TestMappingEntity::ConstSetterConstReferenceGetterGetter));
}
