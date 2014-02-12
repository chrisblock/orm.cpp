#include "stdafx.h"

#include "case_insensitive.h"

bool case_insensitive_less::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result < 0;
}

bool case_insensitive_less_equal::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result <= 0;
}

bool case_insensitive_greater::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result > 0;
}

bool case_insensitive_greater_equal::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result >= 0;
}

bool case_insensitive_equal::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result == 0;
}

bool case_insensitive_not_equal_to::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result != 0;
}
