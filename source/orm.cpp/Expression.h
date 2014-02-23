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

	virtual ~Expression()
	{
	};

	Expression &operator =(const Expression &other)
	{
		if (this != &other)
		{
			BaseExpression::operator =(other);
		}

		return *this;
	};
};
