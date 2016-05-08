#include "stdafx.h"

#include "BinaryExpressionSqlPredicateBuilder.h"

#include <parameter.h>

#include "SqlPredicate.h"

BinaryExpressionSqlPredicateBuilder::BinaryExpressionSqlPredicateBuilder(BinaryOperators::Operators op, const std::shared_ptr<ISqlPredicateBuilder> &left, const std::shared_ptr<ISqlPredicateBuilder> &right) :
	  _operator(op)
	, _left(left)
	, _right(right)
{
}

BinaryExpressionSqlPredicateBuilder::BinaryExpressionSqlPredicateBuilder(const BinaryExpressionSqlPredicateBuilder &other) :
	  ISqlPredicateBuilder(other)
	, _operator(other._operator)
	, _left(other._left)
	, _right(other._right)
{
}

BinaryExpressionSqlPredicateBuilder::~BinaryExpressionSqlPredicateBuilder()
{
}

BinaryExpressionSqlPredicateBuilder &BinaryExpressionSqlPredicateBuilder::operator =(const BinaryExpressionSqlPredicateBuilder &other)
{
	if (this != &other)
	{
		_operator = other._operator;
		_left = other._left;
		_right = other._right;
	}

	return *this;
}

SqlPredicate BinaryExpressionSqlPredicateBuilder::Build(const MappingRegistry &registry) const
{
	SqlPredicate result;

	SqlPredicate leftPredicate = _left->Build(registry);
	SqlPredicate rightPredicate = _right->Build(registry);

	for (std::shared_ptr<odbc::parameter> p : leftPredicate)
	{
		result.AddParameter(p);
	}

	for (std::shared_ptr<odbc::parameter> p : rightPredicate)
	{
		result.AddParameter(p);
	}

	std::string predicate("(");

	predicate += leftPredicate.GetPredicate();

	predicate += " ";

	predicate += BinaryOperators::ToString(_operator);

	predicate += " ";

	predicate += rightPredicate.GetPredicate();

	predicate += ")";

	result.SetPredicate(predicate);

	return result;
}
