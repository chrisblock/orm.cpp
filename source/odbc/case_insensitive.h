#pragma once

#include <functional>
#include <string>

namespace case_insensitive
{
	class less : public std::function < bool(const std::string &left, const std::string &right) >
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class less_equal : public std::function < bool(const std::string &left, const std::string &right) >
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class greater : public std::function < bool(const std::string &left, const std::string &right) >
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class greater_equal : public std::function < bool(const std::string &left, const std::string &right) >
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class equal : public std::function < bool(const std::string &left, const std::string &right) >
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};

	class not_equal_to : public std::function < bool(const std::string &left, const std::string &right) >
	{
	public:
		bool operator ()(const std::string &left, const std::string &right) const;
	};
};
