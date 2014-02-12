#pragma once

#include <string>

class BinaryOperators
{
public:
	BinaryOperators() = delete;

	enum Operators
	{
		And,
		Or,
		Equal,
		NotEqual,
		LessThan,
		LessThanOrEqualTo,
		GreaterThan,
		GreaterThanOrEqualTo
	};

	static std::string ToString(const Operators op);
};
