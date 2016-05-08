#include "stdafx.h"

#include <environment.h>

class environment_tests : public testing::Test
{
protected:
	virtual void SetUp()
	{
	};

	virtual void TearDown()
	{
	};
};

TEST_F(environment_tests, DefaultConstructor__CreatesNewSqlEnvironment)
{
	odbc::environment env;

	EXPECT_NE((void *)SQL_INVALID_HANDLE, env.get_environment_handle());
}

TEST_F(environment_tests, DefaultConstructor__SetsOdbcVersionTo380)
{
	odbc::environment env;

	std::int32_t expected = SQL_OV_ODBC3_80;
	std::int32_t version = 0;

	env.get_attribute(SQL_ATTR_ODBC_VERSION, version);

	EXPECT_EQ(expected, version);
}
