#pragma once

#include <vector>

#include "Expression.h"
#include "IQuery.h"

template <typename T>
class Query : public IQuery
{
public:
	Query()
	{
	};

	Query(const Query<T> &other)
	{
		other;
	};

	virtual ~Query()
	{
	};

	Query<T> &operator =(const Query<T> &other)
	{
		if (this != other)
		{
		}

		return *this;
	};

	Query<T> &Where(const Expression<bool> &expression)
	{
	};

	void Execute()
	{
	};

	void Execute(std::vector<T> &items)
	{
	};

private:
};
