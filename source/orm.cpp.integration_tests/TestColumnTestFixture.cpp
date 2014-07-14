#include "stdafx.h"

#include "TestColumnTestFixture.h"

#include <environment.h>
#include <connection.h>
#include <statement.h>

#include <Session.h>
#include <SessionFactory.h>
#include <SessionFactoryBuilder.h>

TestColumnTestFixture::TestColumnTestFixture()
{
}

TestColumnTestFixture::~TestColumnTestFixture()
{
}

void TestColumnTestFixture::SetUp()
{
	DropTable();

	CreateTable();
}

void TestColumnTestFixture::TearDown()
{
	DropTable();
}

std::int32_t TestColumnTestFixture::GetRowCount() const
{
	std::string createTableCommand("SELECT COUNT(1) AS [Count] FROM [dbo].[");
	createTableCommand.append(GetTableName());
	createTableCommand.append("];");

	std::shared_ptr<odbc::environment> environment = std::make_shared<odbc::environment>();

	std::shared_ptr<odbc::connection> connection = std::make_shared<odbc::connection>(environment, GetConnectionString());

	connection->open();

	odbc::statement statement(connection, createTableCommand);

	std::int32_t result = -1;

	if (statement.next())
	{
		statement.get(0U, result);
	}

	connection->close();

	return result;
}

Session TestColumnTestFixture::CreateSession() const
{
	SessionFactoryBuilder builder;

	SessionFactory factory = builder.Build([this](SessionFactoryConfiguration &configuration)
	{
		configuration.SetDriver("SQL Server Native Client 11.0");
		configuration.SetServer("(local)");
		configuration.SetDatabase("OdbcCppTestDatabase");
		configuration.SetTrusted(true);
		configuration.ConfigureMappingRegistry(GetMappingRegistrar());
	});

	Session result = factory.Open();

	return result;
};

void TestColumnTestFixture::DropTable() const
{
	std::string dropTableCommand("IF EXISTS (SELECT TOP 1 NULL FROM [sys].[tables] WHERE [object_id] = OBJECT_ID('[dbo].[");
	dropTableCommand.append(GetTableName());
	dropTableCommand.append("]'))\n");
	dropTableCommand.append("BEGIN\n");
	dropTableCommand.append("DROP TABLE [dbo].[");
	dropTableCommand.append(GetTableName());
	dropTableCommand.append("]\n");
	dropTableCommand.append("END");

	std::shared_ptr<odbc::environment> environment = std::make_shared<odbc::environment>();

	std::shared_ptr<odbc::connection> connection = std::make_shared<odbc::connection>(environment, GetConnectionString());

	connection->open();

	odbc::statement statement(connection, dropTableCommand);

	statement.execute();

	connection->close();
}

void TestColumnTestFixture::CreateTable() const
{
	std::string createTableCommand("CREATE TABLE [dbo].[");
	createTableCommand.append(GetTableName());
	createTableCommand.append("]\n");
	createTableCommand.append("(\n");
	createTableCommand.append("[Id] INT IDENTITY(1, 1) PRIMARY KEY NOT NULL,\n");
	createTableCommand.append("[TestColumn] ");
	createTableCommand.append(GetColumnType());
	createTableCommand.append("\n)\n");

	std::shared_ptr<odbc::environment> environment = std::make_shared<odbc::environment>();

	std::shared_ptr<odbc::connection> connection = std::make_shared<odbc::connection>(environment, GetConnectionString());

	connection->open();

	odbc::statement statement(connection, createTableCommand);

	statement.execute();

	connection->close();
}
