#include "stdafx.h"

#include <connection.h>
#include <environment.h>
#include <statement.h>

#define CONNECTION_STRING "Driver={SQL Server Native Client 11.0}; Server=(local); Database=OdbcCppTestDatabase; Trusted_Connection=Yes;"

class select_tests : public testing::Test
{
protected:
	virtual void SetUp()
	{
		_environment = std::make_shared<odbc::environment>();
	};

	virtual void TearDown()
	{
		_environment.reset();
	};

	std::shared_ptr<odbc::environment> _environment;
};

TEST_F(select_tests, test)
{
	std::shared_ptr<odbc::connection> conn = std::make_shared<odbc::connection>(_environment, CONNECTION_STRING);

	conn->open();

	odbc::statement stmt(conn, "SELECT [Id], [BitColumn], [TinyIntColumn], [SmallIntColumn], [IntColumn], [BigIntColumn] FROM [dbo].[IntegerTypeTable]");

	while (stmt.next())
	{
		std::int32_t id = 0;
		stmt.get("Id", id);

		bool bit = false;
		stmt.get("BitColumn", bit);
	}

	conn->close();
}
