#pragma once

class TestSessionEntity
{
public:
	TestSessionEntity();
	TestSessionEntity(const TestSessionEntity &other);
	~TestSessionEntity();

	TestSessionEntity &operator =(const TestSessionEntity &other);
};
