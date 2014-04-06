#pragma once

#include <string>
#include <vector>

#define IMPLEMENT_TEST_FIXTURE(ColumnType, ColumnSqlType) \
	class ColumnType ## _ColumnTests : public TestColumnTestFixture \
	{ \
	protected: \
		virtual std::string GetConnectionString() const \
		{ \
			std::string connectionString(CONNECTION_STRING); \
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
		std::vector<ColumnType> values = { TestValue1, TestValue2, TestValue3 }; \
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
		EXPECT_EQ(TestValue1, entities.at(0).GetColumn()); \
		EXPECT_EQ(2, entities.at(1).GetId()); \
		EXPECT_EQ(TestValue2, entities.at(1).GetColumn()); \
		EXPECT_EQ(3, entities.at(2).GetId()); \
		EXPECT_EQ(TestValue3, entities.at(2).GetColumn()); \
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
		std::vector<ColumnType> values = { TestValue1, TestValue2 }; \
	\
		InsertTestRecords<ColumnType>(values); \
	\
		Session session = CreateSession(); \
	\
		ColumnType ## _ColumnTestsEntity one; \
	\
		one.SetId(2); \
		one.SetColumn(TestValue3); \
	\
		int32_t numberUpdated = 0; \
	\
		numberUpdated += session.Update(one); \
	\
		std::vector<ColumnType ## _ColumnTestsEntity> entities; \
	\
		int32_t id = 2; \
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
		EXPECT_EQ(TestValue3, entities.front().GetColumn()); \
	}

#define IMPEMENT_DELETE_TEST(ColumnType, TestValue1, TestValue2, TestValue3) \
	TEST_F(ColumnType ## _ColumnTests, Delete) \
	{ \
		std::vector<ColumnType> values = { TestValue1, TestValue2, TestValue3 }; \
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
		int32_t numberDeleted = 0; \
	\
		numberDeleted += session.Delete(one); \
		numberDeleted += session.Delete(two); \
	\
		EXPECT_EQ(2, numberDeleted); \
		EXPECT_EQ(1, GetRowCount()); \
	}

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
	virtual int32_t GetRowCount() const;

	virtual const MappingRegistrar &GetMappingRegistrar() const = 0;
	virtual std::string GetConnectionString() const = 0;
	virtual std::string GetTableName() const = 0;
	virtual std::string GetColumnType() const = 0;

	template <typename T>
	void InsertTestRecords(const std::vector<T> &values)
	{
		std::string command;

		for (std::vector<T>::const_iterator iter = values.cbegin(); iter != values.cend(); iter++)
		{
			command.append("INSERT INTO [dbo].[");
			command.append(GetTableName());
			command.append("] ([TestColumn]) VALUES (");
			command.append(std::to_string(*iter));
			command.append(")\n");
		}

		std::shared_ptr<odbc::environment> environment = std::make_shared<odbc::environment>();

		std::shared_ptr<odbc::connection> connection = std::make_shared<odbc::connection>(environment, GetConnectionString());

		connection->open();

		odbc::statement statement(connection, command);

		statement.execute();

		connection->close();
	};

private:
	virtual void DropTable() const;
	virtual void CreateTable() const;
};
