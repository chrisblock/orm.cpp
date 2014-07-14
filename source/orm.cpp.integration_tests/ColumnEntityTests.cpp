#include "stdafx.h"

#include "TestColumnTestFixture.h"

using namespace std;

TEST_FOR_COLUMN_TYPE(bool, "BIT", false, true, false, true)

TEST_FOR_COLUMN_TYPE(int8_t, "TINYINT", 0, 1, 2, 3)

//TEST_FOR_COLUMN_TYPE(std::uint8_t, "TINYINT", 0U, 1U, 2U, 3U)

TEST_FOR_COLUMN_TYPE(int16_t, "SMALLINT", 0, 1, 2, 3)

//TEST_FOR_COLUMN_TYPE(uint16_t, "SMALLINT", 0U, 1U, 2U, 3U)

TEST_FOR_COLUMN_TYPE(int32_t, "INT", 0, 1, 2, 3)

//TEST_FOR_COLUMN_TYPE(std::uint32_t, "INT", 0U, 1U, 2U, 3U)

TEST_FOR_COLUMN_TYPE(int64_t, "BIGINT", 0LL, 1LL, 2LL, 3LL)

//TEST_FOR_COLUMN_TYPE(std::uint64_t, "BIGINT", 0ULL, 1ULL, 2ULL, 3ULL)

TEST_FOR_COLUMN_TYPE(float, "REAL", 0.0f, 1.2f, 3.4f, 4.5f)

TEST_FOR_COLUMN_TYPE(double, "FLOAT", 0.0, 1.2, 3.4, 4.5)

TEST_FOR_COLUMN_TYPE(string, "VARCHAR(255)", "", "Hello, World.", "Goodbye, World.", "Look! A Test!")

TEST_FOR_COLUMN_TYPE(wstring, "NVARCHAR(255)", L"", L"Hello, World.", L"Goodbye, World.", L"Look! A Test!")

TEST_FOR_COLUMN_TYPE(Guid, "UNIQUEIDENTIFIER", Guid::Empty, Guid::NewGuid(), Guid::NewGuid(), Guid::NewGuid())
