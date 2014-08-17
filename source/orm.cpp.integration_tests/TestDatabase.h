#pragma once

class TestDatabase
{
public:
	TestDatabase();
	TestDatabase(const std::string &name);
	TestDatabase(const TestDatabase &other) = delete;
	TestDatabase(TestDatabase &&other);
	~TestDatabase();

	TestDatabase &operator =(TestDatabase other) = delete;

	friend void swap(TestDatabase &left, TestDatabase &right);

private:
	std::string _name;

	static void CreateDatabase(const std::string &name);
	static void DropDatabase(const std::string &name);
};

void swap(TestDatabase &left, TestDatabase &right);
