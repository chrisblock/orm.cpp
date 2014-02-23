#pragma once

class TestDatabaseConfiguration
{
public:
	TestDatabaseConfiguration() = delete;
	TestDatabaseConfiguration(const TestDatabaseConfiguration &other) = delete;
	~TestDatabaseConfiguration() = delete;

	TestDatabaseConfiguration &operator =(const TestDatabaseConfiguration &other) = delete;

	static const char Driver[];
	static const char Server[];
	static const char Database[];
	static const char Username[];
	static const char Password[];
	static const bool IsTrusted;
};
