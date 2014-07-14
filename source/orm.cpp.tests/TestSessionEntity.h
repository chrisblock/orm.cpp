#pragma once

#include <cstdint>

class TestSessionEntity
{
public:
	TestSessionEntity();
	TestSessionEntity(const TestSessionEntity &other);
	~TestSessionEntity();

	TestSessionEntity &operator =(const TestSessionEntity &other);

	std::int32_t _id;
	std::int8_t _column1;
	std::int32_t _column2;
};
