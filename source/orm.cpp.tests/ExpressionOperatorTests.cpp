#include "stdafx.h"

#include <functional>

#include <ExpressionOperators.h>
#include <MakeExpression.h>
#include <MappingRegistry.h>
#include <SqlPredicate.h>

#include "TestExpressionEntity.h"
#include "TestExpressionEntityMap.h"
#include "TestExpressionMappingRegistrar.h"

class ExpressionOperatorTests : public testing::Test
{
public:
	ExpressionOperatorTests()
	{
		TestExpressionMappingRegistrar registrar;

		registrar.Register(_registry);
	};

protected:
	MappingRegistry _registry;
};

TEST_F(ExpressionOperatorTests, EqualOperator_Expression_Constant_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSix = expr == 6;

	SqlPredicate predicate = setterGetterIsEqualToSix.GetSqlPredicate(_registry);

	EXPECT_EQ(1, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter = ?)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, EqualOperator_Expression_Field_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToField = expr == &TestExpressionEntity::_field;

	SqlPredicate predicate = setterGetterIsEqualToField.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter = TestTable.Field)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, EqualOperator_Expression_Getter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSetterGetter = expr == &TestExpressionEntity::SetterGetterGetter;

	SqlPredicate predicate = setterGetterIsEqualToSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter = TestTable.SetterGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, EqualOperator_Expression_ConstGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSetterConstGetter = expr == &TestExpressionEntity::SetterConstGetterGetter;

	SqlPredicate predicate = setterGetterIsEqualToSetterConstGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter = TestTable.SetterConstGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, EqualOperator_Expression_ReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSetterReferenceGetter = expr == &TestExpressionEntity::SetterReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsEqualToSetterReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter = TestTable.SetterReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, EqualOperator_Expression_ConstReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSetterConstReferenceGetter = expr == &TestExpressionEntity::SetterConstReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsEqualToSetterConstReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter = TestTable.SetterConstReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, NotEqualOperator_Expression_Constant_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsNotEqualToSix = expr != 6;

	SqlPredicate predicate = setterGetterIsNotEqualToSix.GetSqlPredicate(_registry);

	EXPECT_EQ(1, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <> ?)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, NotEqualOperator_Expression_Field_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsNotEqualToField = expr != &TestExpressionEntity::_field;

	SqlPredicate predicate = setterGetterIsNotEqualToField.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <> TestTable.Field)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, NotEqualOperator_Expression_Getter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsNotEqualToSetterGetter = expr != &TestExpressionEntity::SetterGetterGetter;

	SqlPredicate predicate = setterGetterIsNotEqualToSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <> TestTable.SetterGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, NotEqualOperator_Expression_ConstGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsNotEqualToSetterConstGetter = expr != &TestExpressionEntity::SetterConstGetterGetter;

	SqlPredicate predicate = setterGetterIsNotEqualToSetterConstGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <> TestTable.SetterConstGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, NotEqualOperator_Expression_ReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsNotEqualToSetterReferenceGetter = expr != &TestExpressionEntity::SetterReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsNotEqualToSetterReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <> TestTable.SetterReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, NotEqualOperator_Expression_ConstReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsNotEqualToSetterConstReferenceGetter = expr != &TestExpressionEntity::SetterConstReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsNotEqualToSetterConstReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <> TestTable.SetterConstReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOperator_Expression_Constant_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanSix = expr < 6;

	SqlPredicate predicate = setterGetterIsLessThanSix.GetSqlPredicate(_registry);

	EXPECT_EQ(1, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter < ?)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOperator_Expression_Field_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanField = expr < &TestExpressionEntity::_field;

	SqlPredicate predicate = setterGetterIsLessThanField.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter < TestTable.Field)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOperator_Expression_Getter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanSetterGetter = expr < &TestExpressionEntity::SetterGetterGetter;

	SqlPredicate predicate = setterGetterIsLessThanSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter < TestTable.SetterGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOperator_Expression_ConstGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanSetterConstGetter = expr < &TestExpressionEntity::SetterConstGetterGetter;

	SqlPredicate predicate = setterGetterIsLessThanSetterConstGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter < TestTable.SetterConstGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOperator_Expression_ReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanSetterReferenceGetter = expr < &TestExpressionEntity::SetterReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsLessThanSetterReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter < TestTable.SetterReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOperator_Expression_ConstReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanSetterConstReferenceGetter = expr < &TestExpressionEntity::SetterConstReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsLessThanSetterConstReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter < TestTable.SetterConstReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOrEqualToOperator_Expression_Constant_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanOrEqualToSix = expr <= 6;

	SqlPredicate predicate = setterGetterIsLessThanOrEqualToSix.GetSqlPredicate(_registry);

	EXPECT_EQ(1, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <= ?)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOrEqualToOperator_Expression_Field_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanOrEqualToField = expr <= &TestExpressionEntity::_field;

	SqlPredicate predicate = setterGetterIsLessThanOrEqualToField.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <= TestTable.Field)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOrEqualToOperator_Expression_Getter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanOrEqualToSetterGetter = expr <= &TestExpressionEntity::SetterGetterGetter;

	SqlPredicate predicate = setterGetterIsLessThanOrEqualToSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <= TestTable.SetterGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOrEqualToOperator_Expression_ConstGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanOrEqualToSetterConstGetter = expr <= &TestExpressionEntity::SetterConstGetterGetter;

	SqlPredicate predicate = setterGetterIsLessThanOrEqualToSetterConstGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <= TestTable.SetterConstGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOrEqualToOperator_Expression_ReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanOrEqualToSetterReferenceGetter = expr <= &TestExpressionEntity::SetterReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsLessThanOrEqualToSetterReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <= TestTable.SetterReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, LessThanOrEqualToOperator_Expression_ConstReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsLessThanOrEqualToSetterConstReferenceGetter = expr <= &TestExpressionEntity::SetterConstReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsLessThanOrEqualToSetterConstReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter <= TestTable.SetterConstReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOperator_Expression_Constant_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanSix = expr > 6;

	SqlPredicate predicate = setterGetterIsGreaterThanSix.GetSqlPredicate(_registry);

	EXPECT_EQ(1, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter > ?)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOperator_Expression_Field_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanField = expr > &TestExpressionEntity::_field;

	SqlPredicate predicate = setterGetterIsGreaterThanField.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter > TestTable.Field)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOperator_Expression_Getter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanSetterGetter = expr > &TestExpressionEntity::SetterGetterGetter;

	SqlPredicate predicate = setterGetterIsGreaterThanSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter > TestTable.SetterGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOperator_Expression_ConstGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanSetterConstGetter = expr > &TestExpressionEntity::SetterConstGetterGetter;

	SqlPredicate predicate = setterGetterIsGreaterThanSetterConstGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter > TestTable.SetterConstGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOperator_Expression_ReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanSetterReferenceGetter = expr > &TestExpressionEntity::SetterReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsGreaterThanSetterReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter > TestTable.SetterReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOperator_Expression_ConstReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanSetterConstReferenceGetter = expr > &TestExpressionEntity::SetterConstReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsGreaterThanSetterConstReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter > TestTable.SetterConstReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOrEqualToOperator_Expression_Constant_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanOrEqualToSix = expr >= 6;

	SqlPredicate predicate = setterGetterIsGreaterThanOrEqualToSix.GetSqlPredicate(_registry);

	EXPECT_EQ(1, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter >= ?)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOrEqualToOperator_Expression_Field_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanOrEqualToField = expr >= &TestExpressionEntity::_field;

	SqlPredicate predicate = setterGetterIsGreaterThanOrEqualToField.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter >= TestTable.Field)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOrEqualToOperator_Expression_Getter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanOrEqualToSetterGetter = expr >= &TestExpressionEntity::SetterGetterGetter;

	SqlPredicate predicate = setterGetterIsGreaterThanOrEqualToSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter >= TestTable.SetterGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOrEqualToOperator_Expression_ConstGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanOrEqualToSetterConstGetter = expr >= &TestExpressionEntity::SetterConstGetterGetter;

	SqlPredicate predicate = setterGetterIsGreaterThanOrEqualToSetterConstGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter >= TestTable.SetterConstGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOrEqualToOperator_Expression_ReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanOrEqualToSetterReferenceGetter = expr >= &TestExpressionEntity::SetterReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsGreaterThanOrEqualToSetterReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter >= TestTable.SetterReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, GreaterThanOrEqualToOperator_Expression_ConstReferenceGetter_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsGreaterThanOrEqualToSetterConstReferenceGetter = expr >= &TestExpressionEntity::SetterConstReferenceGetterGetter;

	SqlPredicate predicate = setterGetterIsGreaterThanOrEqualToSetterConstReferenceGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter >= TestTable.SetterConstReferenceGetter)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, AndOperator_Exoression_Constant_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSixAndTrue = (expr == 6) && true;

	SqlPredicate predicate = setterGetterIsEqualToSixAndTrue.GetSqlPredicate(_registry);

	EXPECT_EQ(2, predicate.GetNumberOfParameters());
	EXPECT_EQ("((TestTable.SetterGetter = ?) AND ?)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, AndOperator_Constant_Exoression_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> falseAndSetterGetterIsEqualToSix = false && (expr == 6);

	SqlPredicate predicate = falseAndSetterGetterIsEqualToSix.GetSqlPredicate(_registry);

	EXPECT_EQ(2, predicate.GetNumberOfParameters());
	EXPECT_EQ("(? AND (TestTable.SetterGetter = ?))", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, AndOperator_Exoression_Expression_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSixAndSetterGetterNotEqualToFortyTwo = (expr == 6) && (expr != 42);

	SqlPredicate predicate = setterGetterIsEqualToSixAndSetterGetterNotEqualToFortyTwo.GetSqlPredicate(_registry);

	EXPECT_EQ(2, predicate.GetNumberOfParameters());
	EXPECT_EQ("((TestTable.SetterGetter = ?) AND (TestTable.SetterGetter <> ?))", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, OrOperator_Exoression_Constant_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSixOrTrue = (expr == 6) || true;

	SqlPredicate predicate = setterGetterIsEqualToSixOrTrue.GetSqlPredicate(_registry);

	EXPECT_EQ(2, predicate.GetNumberOfParameters());
	EXPECT_EQ("((TestTable.SetterGetter = ?) OR ?)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, OrOperator_Constant_Exoression_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> falsOrSetterGetterIsEqualToSix = false || (expr == 6);

	SqlPredicate predicate = falsOrSetterGetterIsEqualToSix.GetSqlPredicate(_registry);

	EXPECT_EQ(2, predicate.GetNumberOfParameters());
	EXPECT_EQ("(? OR (TestTable.SetterGetter = ?))", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, OrOperator_Exoression_Expression_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> setterGetterIsEqualToSixAndOrSetterGetterIsNotEqualToFortyTwo = (expr == 6) || (expr != 42);

	SqlPredicate predicate = setterGetterIsEqualToSixAndOrSetterGetterIsNotEqualToFortyTwo.GetSqlPredicate(_registry);

	EXPECT_EQ(2, predicate.GetNumberOfParameters());
	EXPECT_EQ("((TestTable.SetterGetter = ?) OR (TestTable.SetterGetter <> ?))", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, EqualToOperator_null_Expression_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> nullIsEqualToSetterGetter = (nullptr == expr);

	SqlPredicate predicate = nullIsEqualToSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter IS NULL)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, EqualToOperator_Expression_null_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> nullIsEqualToSetterGetter = (expr == nullptr);

	SqlPredicate predicate = nullIsEqualToSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter IS NULL)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, NotEqualToOperator_null_Expression_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> nullIsNotEqualToSetterGetter = (nullptr != expr);

	SqlPredicate predicate = nullIsNotEqualToSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter IS NOT NULL)", predicate.GetPredicate());
}

TEST_F(ExpressionOperatorTests, NotEqualToOperator_Expression_null_ReturnsCorrectPredicate)
{
	Expression<TestExpressionEntity, int32_t> expr = ::MakeExpression(&TestExpressionEntity::SetterGetterGetter);

	Predicate<TestExpressionEntity> nullIsNotEqualToSetterGetter = (expr != nullptr);

	SqlPredicate predicate = nullIsNotEqualToSetterGetter.GetSqlPredicate(_registry);

	EXPECT_EQ(0, predicate.GetNumberOfParameters());
	EXPECT_EQ("(TestTable.SetterGetter IS NOT NULL)", predicate.GetPredicate());
}
