#include "stdafx.h"

#include <statement.h>

class statement_tests : public testing::Test
{
protected:
	virtual void SetUp()
	{
	};

	virtual void TearDown()
	{
	};
};

TEST_F(statement_tests, DefaultConstructor__SetNumberOfColumnsToZero)
{
	odbc::statement stmt;

	EXPECT_EQ(0, stmt.get_number_of_columns());
}

TEST_F(statement_tests, DefaultConstructor__SetCommandTextToEmptyString)
{
	odbc::statement stmt;

	EXPECT_EQ(std::string(), stmt.get_command_text());
}

TEST_F(statement_tests, DefaultConstructor__SetsEmptyParameterList)
{
	odbc::statement stmt;

	EXPECT_EQ(0, stmt.get_parameters().size());
}
