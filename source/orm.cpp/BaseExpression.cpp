#include "stdafx.h"

#include "BaseExpression.h"

#include "ISqlPredicateBuilder.h"
#include "MappingRegistry.h"
#include "SqlPredicate.h"

void swap(BaseExpression &left, BaseExpression &right)
{
	using std::swap;

	swap(left._predicateBuilder, right._predicateBuilder);
}

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

BaseExpression::BaseExpression(BaseExpression &&other)
{
	swap(*this, other);
}

BaseExpression::~BaseExpression()
{
}

BaseExpression &BaseExpression::operator =(BaseExpression other)
{
	swap(*this, other);

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
