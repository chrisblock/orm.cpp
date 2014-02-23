#include "stdafx.h"

#include <MakeExpression.h>
#include <MappingRegistry.h>

#include "TestExpressionEntity.h"
#include "TestExpressionMappingRegistrar.h"

class MakeExpressionTests : public testing::Test
{
public:
	MakeExpressionTests()
	{
		TestExpressionMappingRegistrar registrar;

		registrar.Register(_registry);
	};

protected:
	MappingRegistry _registry;
};

/*
TEST_F(MakeExpressionTests, MakeExpression_Constant)
{
	Expression<int32_t> expr = ::MakeExpression(7);

	SqlPredicate predicate = expr.GetSqlPredicate(_registry);

	EXPECT_EQ(1, predicate.GetNumberOfParameters());
	EXPECT_EQ("?", predicate.GetPredicate());
}
*/

TEST_F(MakeExpressionTests, MakeExpression_SetterGetterGetter)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	SqlPredicate predicate = expr.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("TestTable.SetterGetter", predicate.GetPredicate());
}

TEST_F(MakeExpressionTests, MakeExpression_SetterConstGetterGetter)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterConstGetterGetter);

	SqlPredicate predicate = expr.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("TestTable.SetterConstGetter", predicate.GetPredicate());
}

TEST_F(MakeExpressionTests, MakeExpression_SetterReferenceGetterGetter)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterReferenceGetterGetter);

	SqlPredicate predicate = expr.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("TestTable.SetterReferenceGetter", predicate.GetPredicate());
}

TEST_F(MakeExpressionTests, MakeExpression_SetterConstReferenceGetterGetter)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterConstReferenceGetterGetter);

	SqlPredicate predicate = expr.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("TestTable.SetterConstReferenceGetter", predicate.GetPredicate());
}
