#include "stdafx.h"

#include "decompose.h"

class test_class
{
public:
	test_class() :
		  field(0)
		, _value(42)
	{
	};

	test_class(const test_class &other) :
		  field(other.field)
		, _value(other._value)
	{
	};

	test_class(test_class &&other) :
		  test_class()
	{
		swap(*this, other);
	};

	~test_class()
	{
	};

	test_class &operator =(test_class other)
	{
		swap(*this, other);

		return *this;
	};

	friend void swap(test_class &left, test_class &right);

	std::int32_t field;

	std::int32_t get_by_value()
	{
		return _value;
	};

	std::int32_t const_get_by_value() const
	{
		return _value;
	};

	std::int32_t volatile_get_by_value() volatile
	{
		return _value;
	};

	std::int32_t const_volatile_get_by_value() const volatile
	{
		return _value;
	};

	std::int32_t &get_by_reference()
	{
		return _value;
	};

	const std::int32_t &const_get_by_reference() const
	{
		return _value;
	};

	volatile std::int32_t &volatile_get_by_reference() volatile
	{
		return _value;
	};

	const volatile std::int32_t &const_volatile_get_by_reference() const volatile
	{
		return _value;
	};

	void set_by_value(std::int32_t value)
	{
		_value = value;
	};

	void set_by_const_value(const std::int32_t value)
	{
		_value = value;
	};

	void set_by_reference(std::int32_t &value)
	{
		_value = value;
	};

	void set_by_const_reference(const std::int32_t &value)
	{
		_value = value;
	};

private:
	std::int32_t _value;
};

void swap(test_class &left, test_class &right)
{
	using std::swap;

	swap(left._value, right._value);
};

class decompose_tests : public ::testing::Test
{
protected:
	virtual void SetUp() override
	{
	};

	virtual void TearDown() override
	{
	};
};

TEST_F(decompose_tests, field_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::field);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, field_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::field);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, get_by_value_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::get_by_value);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, get_by_value_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::get_by_value);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, const_get_by_value_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::const_get_by_value);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, const_get_by_value_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::const_get_by_value);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, volatile_get_by_value_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::volatile_get_by_value);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, volatile_get_by_value_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::volatile_get_by_value);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, const_volatile_get_by_value_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::const_volatile_get_by_value);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, const_volatile_get_by_value_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::const_volatile_get_by_value);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, get_by_reference_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::get_by_reference);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, get_by_reference_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::get_by_reference);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, const_get_by_reference_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::const_get_by_reference);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, const_get_by_reference_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::const_get_by_reference);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, volatile_get_by_reference_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::volatile_get_by_reference);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, volatile_get_by_reference_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::volatile_get_by_reference);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, const_volatile_get_by_reference_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::const_volatile_get_by_reference);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, const_volatile_get_by_reference_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::const_volatile_get_by_reference);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, set_by_value_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::set_by_value);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, set_by_value_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::set_by_value);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, set_by_const_value_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::set_by_const_value);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, set_by_const_value_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::set_by_const_value);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, set_by_reference_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::set_by_reference);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, set_by_reference_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::set_by_reference);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, set_by_const_reference_returns_correct_entity_type)
{
	auto result = member_types::decompose(&test_class::set_by_const_reference);

	auto expected = std::is_same<test_class, decltype(result)::entity_type>::value;

	EXPECT_TRUE(expected);
}

TEST_F(decompose_tests, set_by_const_reference_returns_correct_property_type)
{
	auto result = member_types::decompose(&test_class::set_by_const_reference);

	auto expected = std::is_same<std::int32_t, decltype(result)::property_type>::value;

	EXPECT_TRUE(expected);
}
