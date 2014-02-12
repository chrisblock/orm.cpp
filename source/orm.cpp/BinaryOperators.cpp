#include "stdafx.h"

#include "BinaryOperators.h"

std::string BinaryOperators::ToString(const Operators op)
{
	std::string result;

	switch (op)
	{
	case BinaryOperators::And:
		result = "AND";
		break;
	case BinaryOperators::Or:
		result = "OR";
		break;
	case BinaryOperators::Equal:
		result = "=";
		break;
	case BinaryOperators::NotEqual:
		result = "<>";
		break;
	case BinaryOperators::LessThan:
		result = "<";
		break;
	case BinaryOperators::LessThanOrEqualTo:
		result = "<=";
		break;
	case BinaryOperators::GreaterThan:
		result = ">";
		break;
	case BinaryOperators::GreaterThanOrEqualTo:
		result = ">=";
		break;
	default:
		break;
	}

	return result;
}
