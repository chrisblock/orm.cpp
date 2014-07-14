#include "stdafx.h"

#include "TestDatabase.h"

#include <connection.h>
#include <environment.h>
#include <statement.h>

void swap(TestDatabase &left, TestDatabase &right)
{
	using std::swap;

	swap(left._name, right._name);
}

TestDatabase::TestDatabase()
{
}

TestDatabase::TestDatabase(const std::string &name) :
	  _name(name)
{
	DropDatabase();

	CreateDatabase();
}

TestDatabase::TestDatabase(TestDatabase &&other) :
	  TestDatabase()
{
	swap(*this, other);
}

TestDatabase::~TestDatabase()
{
	DropDatabase();
}

void TestDatabase::CreateDatabase() const
{
	if (_name.empty() == false)
	{
		std::shared_ptr<odbc::environment> e = std::make_shared<odbc::environment>();

		std::shared_ptr<odbc::connection> c = std::make_shared<odbc::connection>(e);

		c->open("Driver={SQL Server Native Client 11.0}; Server=(local); Trusted_Connection=Yes;");

		std::string command("CREATE DATABASE [");
		command.append(_name);
		command.append("]; ALTER DATABASE [");
		command.append(_name);
		command.append("] SET RECOVERY SIMPLE;");

		odbc::statement s(c, command);

		s.execute();

		c->close();
	}
}

void TestDatabase::DropDatabase() const
{
	if (_name.empty() == false)
	{
		std::shared_ptr<odbc::environment> e = std::make_shared<odbc::environment>();

		std::shared_ptr<odbc::connection> c = std::make_shared<odbc::connection>(e);

		c->open("Driver={SQL Server Native Client 11.0}; Server=(local); Trusted_Connection=Yes;");

		std::string command("IF EXISTS (SELECT TOP 1 NULL FROM [sys].[databases] WHERE [name] = '");
		command.append(_name);
		command.append("') DROP DATABASE [");
		command.append(_name);
		command.append("];");

		odbc::statement s(c, command);

		s.execute();

		c->close();
	}
}
