#pragma once

class TestSessionEntity
{
public:
	TestSessionEntity();
	TestSessionEntity(const TestSessionEntity &other);
	~TestSessionEntity();

	TestSessionEntity &operator =(const TestSessionEntity &other);

	int32_t _id;
	int8_t _column1;
	int32_t _column2;
};
