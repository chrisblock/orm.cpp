#include "stdafx.h"

#include <connection.h>
#include <environment.h>
#include <parameter.h>
#include <statement.h>

#define CONNECTION_STRING "Driver={SQL Server Native Client 11.0}; Server=(local); Database=OdbcCppTestDatabase; Trusted_Connection=Yes;"

class insert_tests : public testing::Test
{
protected:
	void SetUp()
	{
		_environment = std::make_shared<odbc::environment>();
	};

	void TearDown()
	{
		_environment.reset();
	};

	std::shared_ptr<odbc::environment> _environment;
};

TEST_F(insert_tests, inserts_into_identity_column_throws_exception)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	static const char sql[] =
		"INSERT INTO [dbo].[IntegerTypeTable] ([Id], [BitColumn], [TinyIntColumn], [SmallIntColumn], [IntColumn], [BigIntColumn])"
		"VALUES (1, 1, 2, 3, 4, 5)";

	odbc::statement stmt(conn, sql);

	EXPECT_THROW(stmt.execute(), std::exception);

	conn->close();
}

TEST_F(insert_tests, hard_coded_insert_statement_inserts_integers_successfully)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	static const char sql[] =
		"INSERT INTO [dbo].[IntegerTypeTable] ([BitColumn], [TinyIntColumn], [SmallIntColumn], [IntColumn], [BigIntColumn])"
		"VALUES (1, 2, 3, 4, 5)";

	odbc::statement stmt(conn, sql);

	stmt.execute();

	long rowsAffected = stmt.get_rows_affected();

	conn->close();

	EXPECT_EQ(1, rowsAffected);
}

TEST_F(insert_tests, insert_with_parameters_inserts_integers_successfully)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	static const char sql[] =
		"INSERT INTO [dbo].[IntegerTypeTable] ([BitColumn], [TinyIntColumn], [SmallIntColumn], [IntColumn], [BigIntColumn])"
		"VALUES (?, ?, ?, ?, ?)";

	odbc::statement stmt(conn, sql);

	std::shared_ptr<odbc::parameter> parameter1 = std::make_shared<odbc::parameter>();

	bool one = false;

	parameter1->set_name("BitColumn");
	parameter1->set(one);

	stmt.add_parameter(parameter1);

	std::shared_ptr<odbc::parameter> parameter2 = std::make_shared<odbc::parameter>();

	std::int8_t two = 8;

	parameter2->set_name("TinyIntColumn");
	parameter2->set(two);

	stmt.add_parameter(parameter2);

	std::shared_ptr<odbc::parameter> parameter3 = std::make_shared<odbc::parameter>();

	std::int16_t three = 16;

	parameter3->set_name("SmallIntColumn");
	parameter3->set(three);

	stmt.add_parameter(parameter3);

	std::shared_ptr<odbc::parameter> parameter4 = std::make_shared<odbc::parameter>();

	std::int32_t four = 32;

	parameter4->set_name("IntColumn");
	parameter4->set(four);

	stmt.add_parameter(parameter4);

	std::shared_ptr<odbc::parameter> parameter5 = std::make_shared<odbc::parameter>();

	std::int64_t five = 64;

	parameter5->set_name("BigIntColumn");
	parameter5->set(five);

	stmt.add_parameter(parameter5);

	stmt.execute();

	long rowsAffected = stmt.get_rows_affected();

	conn->close();

	EXPECT_EQ(1, rowsAffected);
}

TEST_F(insert_tests, hard_coded_insert_statement_inserts_strings_successfully)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	static const char sql[] =
		"INSERT INTO [dbo].[StringTypeTable] ([Character], [WideCharacter], [String], [WideString])"
		"VALUES ('A', N'A', 'Hello World', N'Hello World')";

	odbc::statement stmt(conn, sql);

	stmt.execute();

	long rowsAffected = stmt.get_rows_affected();

	conn->close();

	EXPECT_EQ(1, rowsAffected);
}

TEST_F(insert_tests, insert_with_parameters_inserts_strings_successfully)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	static const char sql[] =
		"INSERT INTO [dbo].[StringTypeTable] ([Character], [WideCharacter], [String], [WideString])"
		"VALUES (?, ?, ?, ?)";

	odbc::statement stmt(conn, sql);

	std::shared_ptr<odbc::parameter> parameter1 = std::make_shared<odbc::parameter>();

	char one = 'A';

	parameter1->set_name("Character");
	parameter1->set(one);

	stmt.add_parameter(parameter1);

	std::shared_ptr<odbc::parameter> parameter2 = std::make_shared<odbc::parameter>();

	wchar_t two = L'A';

	parameter2->set_name("WideCharacter");
	parameter2->set(two);

	stmt.add_parameter(parameter2);

	std::shared_ptr<odbc::parameter> parameter3 = std::make_shared<odbc::parameter>();

	char three[] = "Hello World";

	parameter3->set_name("String");
	parameter3->set(three);

	stmt.add_parameter(parameter3);

	std::shared_ptr<odbc::parameter> parameter4 = std::make_shared<odbc::parameter>();

	wchar_t four[] = L"Hello World";

	parameter4->set_name("WideString");
	parameter4->set(four);

	stmt.add_parameter(parameter4);

	stmt.execute();

	long rowsAffected = stmt.get_rows_affected();

	conn->close();

	EXPECT_EQ(1, rowsAffected);
}

TEST_F(insert_tests, insert_with_parameters_inserts_and_converts_strings_successfully)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	static const char sql[] =
		"INSERT INTO [dbo].[StringTypeTable] ([Character], [WideCharacter], [String], [WideString])"
		"VALUES (?, ?, ?, ?)";

	odbc::statement stmt(conn, sql);

	std::shared_ptr<odbc::parameter> parameter1 = std::make_shared<odbc::parameter>();

	char one = 'A';

	parameter1->set_name("Character");
	parameter1->set(one);

	stmt.add_parameter(parameter1);

	std::shared_ptr<odbc::parameter> parameter2 = std::make_shared<odbc::parameter>();

	wchar_t two = L'A';

	parameter2->set_name("WideCharacter");
	parameter2->set(two);

	stmt.add_parameter(parameter2);

	std::shared_ptr<odbc::parameter> parameter3 = std::make_shared<odbc::parameter>();

	wchar_t three[] = L"Hello World";

	parameter3->set_name("String");
	parameter3->set(three);

	stmt.add_parameter(parameter3);

	std::shared_ptr<odbc::parameter> parameter4 = std::make_shared<odbc::parameter>();

	char four[] = "Hello World";

	parameter4->set_name("WideString");
	parameter4->set(four);

	stmt.add_parameter(parameter4);

	stmt.execute();

	long rowsAffected = stmt.get_rows_affected();

	conn->close();

	EXPECT_EQ(1, rowsAffected);
}

TEST_F(insert_tests, hard_coded_insert_statement_inserts_floating_point_numbers_successfully)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	static const char sql[] =
		"INSERT INTO [dbo].[FloatingPointTypeTable] ([Float], [Double], [Decimal], [SmallMoney], [Money])"
		"VALUES (1.2, 1.3, 1.4, 1.5, 1.6)";

	odbc::statement stmt(conn, sql);

	stmt.execute();

	long rowsAffected = stmt.get_rows_affected();

	conn->close();

	EXPECT_EQ(1, rowsAffected);
}

TEST_F(insert_tests, insert_with_parameters_inserts_floating_point_successfully)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	static const char sql[] =
		"INSERT INTO [dbo].[FloatingPointTypeTable] ([Float], [Double], [Decimal], [SmallMoney], [Money])"
		"VALUES (?, ?, ?, ?, ?)";

	odbc::statement stmt(conn, sql);

	std::shared_ptr<odbc::parameter> parameter1 = std::make_shared<odbc::parameter>();

	float one = 1.1F;

	parameter1->set_name("Float");
	parameter1->set(one);

	stmt.add_parameter(parameter1);

	std::shared_ptr<odbc::parameter> parameter2 = std::make_shared<odbc::parameter>();

	double two = 1.2;

	parameter2->set_name("Double");
	parameter2->set(two);

	stmt.add_parameter(parameter2);

	std::shared_ptr<odbc::parameter> parameter3 = std::make_shared<odbc::parameter>();

	double three = 1.3;

	parameter3->set_name("Decimal");
	parameter3->set(three);

	stmt.add_parameter(parameter3);

	std::shared_ptr<odbc::parameter> parameter4 = std::make_shared<odbc::parameter>();

	double four = 1.4;

	parameter4->set_name("SmallMoney");
	parameter4->set(four);

	stmt.add_parameter(parameter4);

	std::shared_ptr<odbc::parameter> parameter5 = std::make_shared<odbc::parameter>();

	double five = 1.5;

	parameter5->set_name("Money");
	parameter5->set(five);

	stmt.add_parameter(parameter5);

	stmt.execute();

	long rowsAffected = stmt.get_rows_affected();

	conn->close();

	EXPECT_EQ(1, rowsAffected);
}
