#include "stdafx.h"

#include "case_insensitive.h"

bool case_insensitive::less::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result < 0;
}

bool case_insensitive::less_equal::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result <= 0;
}

bool case_insensitive::greater::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result > 0;
}

bool case_insensitive::greater_equal::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result >= 0;
}

bool case_insensitive::equal::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result == 0;
}

bool case_insensitive::not_equal_to::operator ()(const std::string &left, const std::string &right) const
{
	int result = ::_stricmp(left.c_str(), right.c_str());

	return result != 0;
}
