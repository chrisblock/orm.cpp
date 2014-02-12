#pragma once

#include "BaseExpression.h"

// TODO: make this have another template argument to differentiate the source (useful for things like Expression<T, bool> to specify predicates that accept type T,
//         to limit the number of types T in a constraint, and allow compile-time type safety for comparison expressions)????
template <typename T>
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
