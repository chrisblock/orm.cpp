#pragma once

#include "ISqlPredicateBuilder.h"

#include <memory>

#include "BinaryOperators.h"

class BinaryExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	BinaryExpressionSqlPredicateBuilder(BinaryOperators::Operators op, const std::shared_ptr<ISqlPredicateBuilder> &left, const std::shared_ptr<ISqlPredicateBuilder> &right);

	BinaryExpressionSqlPredicateBuilder(const BinaryExpressionSqlPredicateBuilder &other);

	virtual ~BinaryExpressionSqlPredicateBuilder();

	BinaryExpressionSqlPredicateBuilder &operator =(const BinaryExpressionSqlPredicateBuilder &other);

	virtual SqlPredicate Build(const MappingRegistry &registry) const override;

protected:
	BinaryOperators::Operators _operator;
	std::shared_ptr<ISqlPredicateBuilder> _left;
	std::shared_ptr<ISqlPredicateBuilder> _right;
};
