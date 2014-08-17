#include "stdafx.h"

#include <binary_data.h>

class binary_data_tests : public testing::Test
{
protected:
	virtual void SetUp()
	{
	};

	virtual void TearDown()
	{
	};
};

TEST_F(binary_data_tests, DefaultConstructor_SetsNullData)
{
	odbc::binary_data b;

	EXPECT_EQ(nullptr, b.data());
}

TEST_F(binary_data_tests, DefaultConstructor_SetsZeroLength)
{
	odbc::binary_data b;

	EXPECT_EQ(0U, b.length());
}
