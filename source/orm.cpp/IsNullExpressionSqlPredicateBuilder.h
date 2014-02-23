#pragma once

#include "ISqlPredicateBuilder.h"

#include <memory>

class IsNullExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	IsNullExpressionSqlPredicateBuilder(const std::shared_ptr<ISqlPredicateBuilder> &expressionPredicateBuilder, const bool isNegated = false);
	IsNullExpressionSqlPredicateBuilder(const IsNullExpressionSqlPredicateBuilder &other);
	virtual ~IsNullExpressionSqlPredicateBuilder();

	IsNullExpressionSqlPredicateBuilder &operator =(const IsNullExpressionSqlPredicateBuilder &other);

	virtual SqlPredicate Build(const MappingRegistry &) const;

private:
	std::shared_ptr<ISqlPredicateBuilder> _expressionPredicateBuilder;
	bool _isNegated;
};
