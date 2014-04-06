#include "stdafx.h"

#include <initializer_list>

#include <environment.h>
#include <connection.h>
#include <statement.h>

#include <ClassMap.h>
#include <ExpressionOperators.h>
#include <MakeExpression.h>
#include <MappingRegistrar.h>
#include <Session.h>

#include "TestColumnEntity.h"
#include "TestColumnEntityMap.h"
#include "TestMappingRegistrar.h"
#include "TestColumnTestFixture.h"

#define CONNECTION_STRING	"Driver={SQL Server Native Client 11.0}; Server=(local); Database=OdbcCppTestDatabase; Trusted_Connection=Yes;"

#define TEST_FOR_COLUMN_TYPE(ColumnType, SqlType, DefaultValue, TestValue1, TestValue2, TestValue3) \
	DECLARE_TEST_COLUMN_ENTITY(ColumnType) \
	IMPLEMENT_TEST_COLUMN_ENTITY(ColumnType, DefaultValue) \
	DECLARE_TEST_COLUMN_ENTITY_MAP(ColumnType) \
	IMPLEMENT_TEST_COLUMN_ENTITY_MAP(ColumnType) \
	DECLARE_TEST_MAPPING_REGISTRAR(ColumnType) \
	IMPLEMENT_TEST_MAPPING_REGISTRAR(ColumnType) \
	IMPLEMENT_TEST_FIXTURE(ColumnType, SqlType) \
	IMPLEMENT_SELECT_TEST(ColumnType, TestValue1, TestValue2, TestValue3) \
	IMPLEMENT_INSERT_TEST(ColumnType, TestValue1) \
	IMPLEMENT_UPDATE_TEST(ColumnType, TestValue1, TestValue2, TestValue3) \
	IMPEMENT_DELETE_TEST(ColumnType, TestValue1, TestValue2, TestValue3)

TEST_FOR_COLUMN_TYPE(bool, "BIT", false, true, false, true)

TEST_FOR_COLUMN_TYPE(int32_t, "INT", 0, 1, 2, 3)

TEST_FOR_COLUMN_TYPE(int64_t, "BIGINT", 0LL, 1LL, 2LL, 3LL)

TEST_FOR_COLUMN_TYPE(float, "REAL", 0.0f, 1.2f, 3.4f, 4.5f)

TEST_FOR_COLUMN_TYPE(double, "FLOAT", 0.0, 1.2, 3.4, 4.5)
