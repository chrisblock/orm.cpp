#include "stdafx.h"

#include <Session.h>
#include <SqlServerDialect.h>

#include "MockSqlExecutor.h"
#include "TestSessionMappingRegistrar.h"
#include "TestSessionEntity.h"

class SessionTests : public testing::Test
{
protected:
	virtual void SetUp()
	{
		_registrar.Register(_registry);
	};

	virtual void TearDown()
	{
	};

	TestSessionMappingRegistrar _registrar;
	MappingRegistry _registry;
};

TEST_F(SessionTests, QueryOver)
{
	std::shared_ptr<odbc::environment> environment;
	std::string connectionString;
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	executor->SetColumnValue("Id", 1);
	executor->SetColumnValue("Column1", 2);
	executor->SetColumnValue("Column2", 3);

	Session session(environment, connectionString, dialect, executor, _registry);

	Query<TestSessionEntity> query = session.QueryOver<TestSessionEntity>();

	std::vector<TestSessionEntity> entities;

	query.Execute(entities);

	TestSessionEntity first = entities.front();

	SqlStatement statement = executor->GetLastStatement();

	EXPECT_EQ(1, entities.size());

	EXPECT_EQ(1, first._id);
	EXPECT_EQ(2, first._column1);
	EXPECT_EQ(3, first._column2);

	EXPECT_EQ("SELECT TestSessionTable.Id, TestSessionTable.Column1, TestSessionTable.Column2 FROM dbo.TestSessionTable", statement.GetSql());
}

TEST_F(SessionTests, Insert_FilledEntity_GeneratesCorrectSql)
{
	std::shared_ptr<odbc::environment> environment;
	std::string connectionString;
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	Session session(environment, connectionString, dialect, executor, _registry);

	TestSessionEntity entity;

	entity._id = 1;
	entity._column1 = 2;
	entity._column2 = 3;

	session.Insert(entity);

	SqlStatement statement = executor->GetLastStatement();

	EXPECT_EQ("INSERT INTO dbo.TestSessionTable (Id, Column1, Column2) VALUES (?, ?, ?)", statement.GetSql());
}

TEST_F(SessionTests, Update_FilledEntity_GeneratesCorrectSql)
{
	std::shared_ptr<odbc::environment> environment;
	std::string connectionString;
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	Session session(environment, connectionString, dialect, executor, _registry);

	TestSessionEntity entity;

	entity._id = 1;
	entity._column1 = 2;
	entity._column2 = 3;

	session.Update(entity);

	SqlStatement statement = executor->GetLastStatement();

	EXPECT_EQ("UPDATE dbo.TestSessionTable SET Column1 = ?, Column2 = ? WHERE Id = ?", statement.GetSql());
}

TEST_F(SessionTests, Delete_FilledEntity_GeneratesCorrectSql)
{
	std::shared_ptr<odbc::environment> environment;
	std::string connectionString;
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	Session session(environment, connectionString, dialect, executor, _registry);

	TestSessionEntity entity;

	entity._id = 1;
	entity._column1 = 2;
	entity._column2 = 3;

	session.Delete(entity);

	SqlStatement statement = executor->GetLastStatement();

	EXPECT_EQ("DELETE FROM dbo.TestSessionTable WHERE Id = ?", statement.GetSql());
}
