#include "stdafx.h"

#include <Query.h>

#include <ExpressionOperators.h>
#include <MakeExpression.h>
#include <MappingRegistry.h>
#include <SqlServerDialect.h>

#include "MockSqlExecutor.h"
#include "TestSessionEntity.h"
#include "TestSessionMappingRegistrar.h"

class QueryTests : public testing::Test
{
protected:
	virtual void SetUp()
	{
		_registrar.Register(_registry);
	};

	virtual void TearDown()
	{
	};

	std::string _connectionString;
	std::shared_ptr<odbc::environment> _environment;
	TestSessionMappingRegistrar _registrar;
	MappingRegistry _registry;
};

TEST_F(QueryTests, Execute_NoPredicate_HasStatementWithNoWhereClause)
{
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	orm::query<TestSessionEntity> query(_environment, _connectionString, dialect, executor, _registry);

	std::vector<TestSessionEntity> entities;

	query.Execute(entities);

	orm::sql::statement statement = executor->GetLastStatement();

	EXPECT_EQ(1, entities.size());
	EXPECT_EQ("SELECT TestSessionTable.Id, TestSessionTable.Column1, TestSessionTable.Column2 FROM dbo.TestSessionTable", statement.GetSql());
}

TEST_F(QueryTests, Execute_IdGreaterThanFortyTwo_StatementWithWhereClauseWithIdGreaterThanParameterAndOneParameter)
{
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	orm::query<TestSessionEntity> query(_environment, _connectionString, dialect, executor, _registry);

	Predicate<TestSessionEntity> predicate = ::MakeExpression(&TestSessionEntity::_id) > 42;

	orm::query<TestSessionEntity> q = query.Where(predicate);

	std::vector<TestSessionEntity> entities;

	q.Execute(entities);

	orm::sql::statement statement = executor->GetLastStatement();

	EXPECT_EQ(1, entities.size());
	EXPECT_EQ("SELECT TestSessionTable.Id, TestSessionTable.Column1, TestSessionTable.Column2 FROM dbo.TestSessionTable WHERE (TestSessionTable.Id > ?)", statement.GetSql());
	EXPECT_EQ(1, statement.GetNumberOfParameters());
}

TEST_F(QueryTests, Execute_IdLessThanColumn2_StatementWithWhereClauseWithIdLessThanColumnTwoAndZeroParameters)
{
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	orm::query<TestSessionEntity> query(_environment, _connectionString, dialect, executor, _registry);

	Predicate<TestSessionEntity> predicate = ::MakeExpression(&TestSessionEntity::_id) < &TestSessionEntity::_column2;

	orm::query<TestSessionEntity> q = query.Where(predicate);

	std::vector<TestSessionEntity> entities;

	q.Execute(entities);

	orm::sql::statement statement = executor->GetLastStatement();

	EXPECT_EQ(1, entities.size());
	EXPECT_EQ("SELECT TestSessionTable.Id, TestSessionTable.Column1, TestSessionTable.Column2 FROM dbo.TestSessionTable WHERE (TestSessionTable.Id < TestSessionTable.Column2)", statement.GetSql());
	EXPECT_EQ(0, statement.GetNumberOfParameters());
}

TEST_F(QueryTests, Execute_IdLessThanColumn2AndColumn1IsNotEqualTo42_StatementWithWhereClauseWithIdLessThanColumnTwoAndColumn1IsNotEqualToParameterAndOneParameters)
{
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	orm::query<TestSessionEntity> query(_environment, _connectionString, dialect, executor, _registry);

	Predicate<TestSessionEntity> predicate = ::MakeExpression(&TestSessionEntity::_id) < &TestSessionEntity::_column2;

	std::int8_t fortyTwo = 42;

	orm::query<TestSessionEntity> q = query.Where(predicate)
		.Where(::MakeExpression(&TestSessionEntity::_column1) != fortyTwo);

	std::vector<TestSessionEntity> entities;

	q.Execute(entities);

	orm::sql::statement statement = executor->GetLastStatement();

	EXPECT_EQ(1, entities.size());
	EXPECT_EQ("SELECT TestSessionTable.Id, TestSessionTable.Column1, TestSessionTable.Column2 FROM dbo.TestSessionTable WHERE ((TestSessionTable.Id < TestSessionTable.Column2) AND (TestSessionTable.Column1 <> ?))", statement.GetSql());
	EXPECT_EQ(1, statement.GetNumberOfParameters());
}
