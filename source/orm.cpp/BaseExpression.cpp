#include "stdafx.h"

#include "BaseExpression.h"

#include "ISqlPredicateBuilder.h"
#include "MappingRegistry.h"
#include "SqlPredicate.h"

BaseExpression::BaseExpression()
{
}

BaseExpression::BaseExpression(const std::shared_ptr<ISqlPredicateBuilder> &predicateBuilder) :
	  _predicateBuilder(predicateBuilder)
{
}

BaseExpression::BaseExpression(const BaseExpression &other) :
	  _predicateBuilder(other._predicateBuilder)
{
}

BaseExpression::~BaseExpression()
{
}

BaseExpression &BaseExpression::operator =(const BaseExpression &other)
{
	if (this != &other)
	{
		_predicateBuilder = other._predicateBuilder;
	}

	return *this;
}

SqlPredicate BaseExpression::GetSqlPredicate(const MappingRegistry &registry) const
{
	SqlPredicate result = _predicateBuilder->Build(registry);

	return result;
}

std::shared_ptr<ISqlPredicateBuilder> BaseExpression::GetSqlPredicateBuilder() const
{
	return _predicateBuilder;
}
