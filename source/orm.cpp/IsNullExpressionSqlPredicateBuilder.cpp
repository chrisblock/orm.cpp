#include "stdafx.h"

#include "IsNullExpressionSqlPredicateBuilder.h"

#include "SqlPredicate.h"

IsNullExpressionSqlPredicateBuilder::IsNullExpressionSqlPredicateBuilder(const std::shared_ptr<ISqlPredicateBuilder> &expressionPredicateBuilder, const bool isNegated) :
	  _expressionPredicateBuilder(expressionPredicateBuilder)
	, _isNegated(isNegated)
{
}

IsNullExpressionSqlPredicateBuilder::IsNullExpressionSqlPredicateBuilder(const IsNullExpressionSqlPredicateBuilder &other) :
	  ISqlPredicateBuilder(other)
	,_expressionPredicateBuilder(other._expressionPredicateBuilder)
	, _isNegated(other._isNegated)
{
}

IsNullExpressionSqlPredicateBuilder::~IsNullExpressionSqlPredicateBuilder()
{
}

IsNullExpressionSqlPredicateBuilder &IsNullExpressionSqlPredicateBuilder::operator =(const IsNullExpressionSqlPredicateBuilder &other)
{
	if (this != &other)
	{
		_expressionPredicateBuilder = other._expressionPredicateBuilder;
		_isNegated = other._isNegated;
	}

	return *this;
}

SqlPredicate IsNullExpressionSqlPredicateBuilder::Build(const MappingRegistry &registry) const
{
	SqlPredicate result;

	SqlPredicate expressionPredicate = _expressionPredicateBuilder->Build(registry);

	for (auto iter = expressionPredicate.GetBegin(); iter != expressionPredicate.GetEnd(); iter++)
	{
		std::shared_ptr<odbc::parameter> p = *iter;
		result.AddParameter(p);
	}

	std::string predicate("(");

	predicate += expressionPredicate.GetPredicate();

	predicate += " IS ";

	if (_isNegated)
	{
		predicate += "NOT ";
	}

	predicate += "NULL)";

	result.SetPredicate(predicate);

	return result;
}
