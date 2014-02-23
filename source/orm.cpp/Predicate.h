#pragma once

#include "Expression.h"

template <typename T>
class Predicate : public Expression<T, bool>
{
public:
	Predicate() :
		  Expression()
	{
	};

	Predicate(const Predicate &other) :
		  Expression(other)
	{
	};

	Predicate(const std::shared_ptr<ISqlPredicateBuilder> &predicateBuilder) :
		  Expression(predicateBuilder)
	{
	};

	virtual ~Predicate()
	{
	};

	Predicate &operator =(const Predicate &other)
	{
		if (this != &other)
		{
			Expression::operator =(other);
		}

		return *this;
	};
};
