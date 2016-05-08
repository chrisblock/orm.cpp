#pragma once

#include <functional>
#include <string>

namespace case_insensitive
{
	class less
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class less_equal
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class greater
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class greater_equal
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class equal
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class not_equal_to
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};
};
