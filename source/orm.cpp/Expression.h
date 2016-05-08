#pragma once

#include "BaseExpression.h"

template <typename T, typename TResult>
class Expression : public BaseExpression
{
public:
	Expression() :
		  BaseExpression()
	{
	};

	Expression(const std::shared_ptr<ISqlPredicateBuilder> &predicateBuilder) :
		  BaseExpression(predicateBuilder)
	{
	};

	Expression(const Expression &other) :
		  BaseExpression(other)
	{
	};

	Expression(Expression &&other) :
		  Expression()
	{
		swap(*this, other);
	};

	virtual ~Expression()
	{
	};

	Expression &operator =(Expression other)
	{
		swap(*this, other);

		return *this;
	};

	friend void swap(Expression &left, Expression &right)
	{
		using std::swap;

		swap(static_cast<BaseExpression &>(left), static_cast<BaseExpression &>(right));
	};
};
