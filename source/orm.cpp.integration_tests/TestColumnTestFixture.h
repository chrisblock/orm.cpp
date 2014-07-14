#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include <connection.h>
#include <environment.h>
#include <parameter.h>
#include <statement.h>

#include <ClassMap.h>
#include <ExpressionOperators.h>
#include <Guid.h>
#include <MakeExpression.h>
#include <MappingRegistrar.h>
#include <Session.h>

#include "TestColumnEntity.h"
#include "TestColumnEntityMap.h"
#include "TestMappingRegistrar.h"

#define IMPLEMENT_TEST_FIXTURE(ColumnType, ColumnSqlType) \
	class ColumnType ## _ColumnTests : public TestColumnTestFixture \
	{ \
	protected: \
		virtual std::string GetConnectionString() const \
		{ \
			std::string connectionString("Driver={SQL Server Native Client 11.0}; Server=(local); Database=OdbcCppTestDatabase; Trusted_Connection=Yes;"); \
	\
			return connectionString; \
		}; \
	\
		virtual std::string GetTableName() const \
		{ \
			std::string tableName(#ColumnType "_ColumnTestsEntityTable"); \
	\
			return tableName; \
		}; \
	\
		virtual std::string GetColumnType() const \
		{ \
			std::string columnType(ColumnSqlType); \
	\
			return columnType; \
		}; \
	\
		virtual const MappingRegistrar &GetMappingRegistrar() const \
		{ \
			return _registrar; \
		}; \
	\
	private: \
		ColumnType ## _ColumnTestsMappingRegistrar _registrar; \
	};

#define IMPLEMENT_SELECT_TEST(ColumnType, TestValue1, TestValue2, TestValue3) \
	TEST_F(ColumnType ## _ColumnTests, Select) \
	{ \
		const ColumnType variable1 = TestValue1; \
		const ColumnType variable2 = TestValue2; \
		const ColumnType variable3 = TestValue3; \
	\
		std::vector<ColumnType> values = { variable1, variable2, variable3 }; \
	\
		InsertTestRecords<ColumnType>(values); \
	\
		Session session = CreateSession(); \
	\
		std::vector<ColumnType ## _ColumnTestsEntity> entities; \
	\
		session \
			.QueryOver<ColumnType ## _ColumnTestsEntity>() \
			.Execute(entities); \
	\
		EXPECT_EQ(values.size(), entities.size()); \
	\
		std::vector<ColumnType>::const_iterator iter = values.cbegin(); \
	\
		std::vector<ColumnType ## _ColumnTestsEntity>::const_iterator jter = entities.cbegin(); \
	\
		EXPECT_EQ(1, entities.at(0).GetId()); \
		EXPECT_EQ(variable1, entities.at(0).GetColumn()); \
		EXPECT_EQ(2, entities.at(1).GetId()); \
		EXPECT_EQ(variable2, entities.at(1).GetColumn()); \
		EXPECT_EQ(3, entities.at(2).GetId()); \
		EXPECT_EQ(variable3, entities.at(2).GetColumn()); \
	}

// TODO: make this work
// EXPECT_EQ(1, entity.GetId());

#define IMPLEMENT_INSERT_TEST(ColumnType, TestValue1) \
	TEST_F(ColumnType ## _ColumnTests, Insert) \
	{ \
		Session session = CreateSession(); \
	\
		ColumnType ## _ColumnTestsEntity entity; \
	\
		entity.SetColumn(TestValue1); \
	\
		session.Insert(entity); \
	\
		EXPECT_EQ(1, GetRowCount()); \
	}

#define IMPLEMENT_UPDATE_TEST(ColumnType, TestValue1, TestValue2, TestValue3) \
	TEST_F(ColumnType ## _ColumnTests, Update) \
	{ \
		const ColumnType variable1 = TestValue1; \
		const ColumnType variable2 = TestValue2; \
		const ColumnType variable3 = TestValue3; \
	\
		std::vector<ColumnType> values = { variable1, variable2 }; \
	\
		InsertTestRecords<ColumnType>(values); \
	\
		Session session = CreateSession(); \
	\
		ColumnType ## _ColumnTestsEntity one; \
	\
		one.SetId(2); \
		one.SetColumn(variable3); \
	\
		std::int32_t numberUpdated = 0; \
	\
		numberUpdated += session.Update(one); \
	\
		std::vector<ColumnType ## _ColumnTestsEntity> entities; \
	\
		std::int32_t id = 2; \
	\
		session.QueryOver<ColumnType ## _ColumnTestsEntity>() \
			.Where(::MakeExpression(&ColumnType ## _ColumnTestsEntity::GetId) == id) \
			.Execute(entities); \
	\
		EXPECT_EQ(1, numberUpdated); \
		EXPECT_EQ(1, entities.size()); \
		EXPECT_EQ(2, GetRowCount()); \
	\
		EXPECT_EQ(2, entities.front().GetId()); \
		EXPECT_EQ(variable3, entities.front().GetColumn()); \
	}

#define IMPEMENT_DELETE_TEST(ColumnType, TestValue1, TestValue2, TestValue3) \
	TEST_F(ColumnType ## _ColumnTests, Delete) \
	{ \
		const ColumnType variable1 = TestValue1; \
		const ColumnType variable2 = TestValue2; \
		const ColumnType variable3 = TestValue3; \
	\
		std::vector<ColumnType> values = { variable1, variable2, variable3 }; \
	\
		InsertTestRecords<ColumnType>(values); \
	\
		Session session = CreateSession(); \
	\
		ColumnType ## _ColumnTestsEntity one; \
	\
		one.SetId(1); \
	\
		ColumnType ## _ColumnTestsEntity two; \
	\
		two.SetId(2); \
	\
		std::int32_t numberDeleted = 0; \
	\
		numberDeleted += session.Delete(one); \
		numberDeleted += session.Delete(two); \
	\
		EXPECT_EQ(2, numberDeleted); \
		EXPECT_EQ(1, GetRowCount()); \
	}

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

class MappingRegistrar;
class Session;

class TestColumnTestFixture : public testing::Test
{
public:
	TestColumnTestFixture();
	~TestColumnTestFixture();

protected:
	virtual void SetUp();
	virtual void TearDown();

	virtual Session CreateSession() const;
	virtual std::int32_t GetRowCount() const;

	virtual const MappingRegistrar &GetMappingRegistrar() const = 0;
	virtual std::string GetConnectionString() const = 0;
	virtual std::string GetTableName() const = 0;
	virtual std::string GetColumnType() const = 0;

	template <typename T>
	void InsertTestRecords(const std::vector<T> &values)
	{
		std::string command;

		std::vector<std::shared_ptr<odbc::parameter>> parameters;

		for (std::vector<T>::const_iterator iter = values.cbegin(); iter != values.cend(); iter++)
		{
			std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

			parameter->set_name("TestColumn");
			parameter->set(*iter);

			parameters.push_back(parameter);

			command.append("INSERT INTO [dbo].[");
			command.append(GetTableName());
			command.append("] ([TestColumn]) VALUES (?)\n");
		}

		std::shared_ptr<odbc::environment> environment = std::make_shared<odbc::environment>();

		std::shared_ptr<odbc::connection> connection = std::make_shared<odbc::connection>(environment, GetConnectionString());

		connection->open();

		odbc::statement statement(connection, command);

		for (std::vector<std::shared_ptr<odbc::parameter>>::const_iterator iter = parameters.cbegin(); iter != parameters.cend(); iter++)
		{
			statement.add_parameter(*iter);
		}

		statement.execute();

		connection->close();
	};

private:
	virtual void DropTable() const;
	virtual void CreateTable() const;
};
