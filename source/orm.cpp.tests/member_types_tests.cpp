#include "stdafx.h"

#include <member_types.h>

#include "TestMemberTypesEntity.h"

TEST(member_types_tests, field_type_works)
{
	member_types<TestMemberTypesEntity, int>::field field = &TestMemberTypesEntity::_integer;

	ASSERT_EQ(&TestMemberTypesEntity::_integer, field);
}

TEST(member_types_tests, getter_type_works)
{
	member_types<TestMemberTypesEntity, int>::getter intAccessor = &TestMemberTypesEntity::Accessor;

	ASSERT_EQ(&TestMemberTypesEntity::Accessor, intAccessor);
}

TEST(member_types_tests, const_getter_type_works)
{
	member_types<TestMemberTypesEntity, int>::const_getter constIntAccessor = &TestMemberTypesEntity::ConstAccessor;

	ASSERT_EQ(&TestMemberTypesEntity::ConstAccessor, constIntAccessor);
}

TEST(member_types_tests, reference_getter_type_works)
{
	member_types<TestMemberTypesEntity, int>::reference_getter referenceAccessor = &TestMemberTypesEntity::ReferenceAccessor;

	ASSERT_EQ(&TestMemberTypesEntity::ReferenceAccessor, referenceAccessor);
}

TEST(member_types_tests, const_reference_getter_type_works)
{
	member_types<TestMemberTypesEntity, int>::const_reference_getter constReferenceAccessor = &TestMemberTypesEntity::ConstReferenceAccessor;

	ASSERT_EQ(&TestMemberTypesEntity::ConstReferenceAccessor, constReferenceAccessor);
}

/*
TEST(member_types_tests, setter_type_works)
{
	member_types<TestMemberTypesEntity, int>::setter setter = &TestMemberTypesEntity::Setter;

	ASSERT_EQ(&TestMemberTypesEntity::Setter, setter);
}
*/

TEST(member_types_tests, const_setter_type_works)
{
	member_types<TestMemberTypesEntity, int>::const_setter constSetter = &TestMemberTypesEntity::ConstSetter;

	ASSERT_EQ(&TestMemberTypesEntity::ConstSetter, constSetter);
}

/*
TEST(member_types_tests, reference_setter_type_works)
{
	member_types<TestMemberTypesEntity, int>::reference_setter referenceSetter = &TestMemberTypesEntity::ReferenceSetter;

	ASSERT_EQ(&TestMemberTypesEntity::ReferenceSetter, referenceSetter);
}
*/

TEST(member_types_tests, const_reference_setter_type_works)
{
	member_types<TestMemberTypesEntity, int>::const_reference_setter constReferenceSetter = &TestMemberTypesEntity::ConstReferenceSetter;

	ASSERT_EQ(&TestMemberTypesEntity::ConstReferenceSetter, constReferenceSetter);
}

TEST(member_types_tests, to_string_different_members_not_equal)
{
	std::string expected = member_types<TestMemberTypesEntity, int>::to_string(&TestMemberTypesEntity::Accessor);
	std::string actual = member_types<TestMemberTypesEntity, int>::to_string(&TestMemberTypesEntity::Setter);

	EXPECT_NE(expected, actual);
}

TEST(member_types_tests, to_string_same_members_equal)
{
	std::string expected = member_types<TestMemberTypesEntity, int>::to_string(&TestMemberTypesEntity::Accessor);
	std::string actual = member_types<TestMemberTypesEntity, int>::to_string(&TestMemberTypesEntity::Accessor);

	EXPECT_EQ(expected, actual);
}
