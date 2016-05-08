#include "stdafx.h"

#include <to_string.h>

#include "TestMemberTypesEntity.h"

class to_string_tests : public ::testing::Test
{
protected:
	virtual void SetUp() override
	{
	};

	virtual void TearDown() override
	{
	};
};

TEST_F(to_string_tests, different_members_not_equal)
{
	std::string expected = member_types::to_string(&TestMemberTypesEntity::Getter);
	std::string actual = member_types::to_string(&TestMemberTypesEntity::Setter);

	EXPECT_NE(expected, actual);
}

TEST_F(to_string_tests, same_members_equal)
{
	std::string expected = member_types::to_string(&TestMemberTypesEntity::Getter);
	std::string actual = member_types::to_string(&TestMemberTypesEntity::Getter);

	EXPECT_EQ(expected, actual);
}
