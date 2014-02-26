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

TEST_F(QueryTests, Test)
{
	std::shared_ptr<ISqlDialect> dialect = std::make_shared<SqlServerDialect>();
	std::shared_ptr<MockSqlExecutor> executor = std::make_shared<MockSqlExecutor>();

	Query<TestSessionEntity> query(_environment, _connectionString, dialect, executor, _registry);

	Predicate<TestSessionEntity> predicate = ::MakeExpression(&TestSessionEntity::_id) > 42;

	Query<TestSessionEntity> q = query.Where(predicate);

	std::vector<TestSessionEntity> entities;

	q.Execute(entities);

	SqlStatement statement = executor->GetLastStatement();

	EXPECT_EQ(1, entities.size());
	EXPECT_EQ("SELECT TestSessionTable.Id, TestSessionTable.Column1, TestSessionTable.Column2 FROM dbo.TestSessionTable WHERE TestSessionTable.Id > ?", statement.GetSql());
}
