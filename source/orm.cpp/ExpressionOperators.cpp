#include "stdafx.h"

#include "ExpressionOperators.h"

Expression<bool> operator &&(const Expression<bool> &left, const bool right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::And, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

Expression<bool> operator &&(const bool left, const Expression<bool> &right)
{
	std::shared_ptr<ISqlPredicateBuilder> l = std::make_shared<ConstantExpressionSqlPredicateBuilder>(left);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::And, l, right.GetSqlPredicateBuilder());

	Expression<bool> result(predicateBuilder);

	return result;
}

Expression<bool> operator &&(const Expression<bool> &left, const Expression<bool> &right)
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::And, left.GetSqlPredicateBuilder(), right.GetSqlPredicateBuilder());

	Expression<bool> result(predicateBuilder);

	return result;
}

Expression<bool> operator ||(const Expression<bool> &left, const bool right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Or, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

Expression<bool> operator ||(const bool left, const Expression<bool> &right)
{
	std::shared_ptr<ISqlPredicateBuilder> l = std::make_shared<ConstantExpressionSqlPredicateBuilder>(left);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Or, l, right.GetSqlPredicateBuilder());

	Expression<bool> result(predicateBuilder);

	return result;
}

Expression<bool> operator ||(const Expression<bool> &left, const Expression<bool> &right)
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Or, left.GetSqlPredicateBuilder(), right.GetSqlPredicateBuilder());

	Expression<bool> result(predicateBuilder);

	return result;
}
