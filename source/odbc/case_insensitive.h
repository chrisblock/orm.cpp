#pragma once

#include <functional>
#include <string>

class case_insensitive_less : public std::function<bool(const std::string &left, const std::string &right)>
{
public:
	bool operator ()(const std::string &left, const std::string &right) const;
};

class case_insensitive_less_equal : public std::function<bool(const std::string &left, const std::string &right)>
{
public:
	bool operator ()(const std::string &left, const std::string &right) const;
};

class case_insensitive_greater : public std::function<bool(const std::string &left, const std::string &right)>
{
public:
	bool operator ()(const std::string &left, const std::string &right) const;
};

class case_insensitive_greater_equal : public std::function<bool(const std::string &left, const std::string &right)>
{
public:
	bool operator ()(const std::string &left, const std::string &right) const;
};

class case_insensitive_equal : public std::function<bool(const std::string &left, const std::string &right)>
{
public:
	bool operator ()(const std::string &left, const std::string &right) const;
};

class case_insensitive_not_equal_to : public std::function<bool(const std::string &left, const std::string &right)>
{
public:
	bool operator ()(const std::string &left, const std::string &right) const;
};
