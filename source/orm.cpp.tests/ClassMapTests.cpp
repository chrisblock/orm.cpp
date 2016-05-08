#include "stdafx.h"

#include <functional>
#include <random>

#include <sql_column.h>

#include "MockDataReader.h"
#include "TestMappingEntityMap.h"

class ClassMapTests : public testing::Test
{
public:
	ClassMapTests()
	{
		_columns.push_back("Field");

		_columns.push_back("SetterGetter");
		_columns.push_back("SetterConstGetter");
		_columns.push_back("SetterReferenceGetter");
		_columns.push_back("SetterConstReferenceGetter");

		_columns.push_back("ConstSetterGetter");
		_columns.push_back("ConstSetterConstGetter");
		_columns.push_back("ConstSetterReferenceGetter");
		_columns.push_back("ConstSetterConstReferenceGetter");

		_columns.push_back("ReferenceSetterGetter");
		_columns.push_back("ReferenceSetterConstGetter");
		_columns.push_back("ReferenceSetterReferenceGetter");
		_columns.push_back("ReferenceSetterConstReferenceGetter");

		_columns.push_back("ConstReferenceSetterGetter");
		_columns.push_back("ConstReferenceSetterConstGetter");
		_columns.push_back("ConstReferenceSetterReferenceGetter");
		_columns.push_back("ConstReferenceSetterConstReferenceGetter");
	}

protected:
	virtual void SetUp() override
	{
	};

	virtual void TearDown() override
	{
	};

	std::vector<std::string> _columns;
};

TEST_F(ClassMapTests, GetSchemaName_ReturnsSchema)
{
	TestMappingEntityMap map;

	std::string schema = map.GetSchema();

	EXPECT_EQ("dbo", schema);
}

TEST_F(ClassMapTests, GetTableName_ReturnsTable)
{
	TestMappingEntityMap map;

	std::string table = map.GetTable();

	EXPECT_EQ("TestTable", table);
}

TEST_F(ClassMapTests, ReadEntityFromDataReader_AllColumnsReadSuccessfully)
{
	std::function<std::int32_t ()> valueGenerator = std::bind(std::uniform_int_distribution<std::int32_t>(1, 64), std::mt19937());

	std::map<std::string, std::int32_t> values;

	for (const auto &column : _columns)
	{
		values[column] = valueGenerator();
	}

	std::shared_ptr<IDataReader> reader = std::make_shared<MockDataReader>(values);

	TestMappingEntityMap map;

	TestMappingEntity entity;

	map.ReadEntityFromDataReader(entity, reader);

	EXPECT_EQ(values["Field"], entity._field);

	EXPECT_EQ(values["SetterGetter"], entity.SetterGetterGetter());
	EXPECT_EQ(values["SetterConstGetter"], entity.SetterConstGetterGetter());
	EXPECT_EQ(values["SetterReferenceGetter"], entity.SetterReferenceGetterGetter());
	EXPECT_EQ(values["SetterConstReferenceGetter"], entity.SetterConstReferenceGetterGetter());
	EXPECT_EQ(values["ConstSetterGetter"], entity.ConstSetterGetterGetter());
	EXPECT_EQ(values["ConstSetterConstGetter"], entity.ConstSetterConstGetterGetter());
	EXPECT_EQ(values["ConstSetterReferenceGetter"], entity.ConstSetterReferenceGetterGetter());
	EXPECT_EQ(values["ConstSetterConstReferenceGetter"], entity.ConstSetterConstReferenceGetterGetter());
	/*
	EXPECT_EQ(values["ReferenceSetterGetter"], entity.ReferenceSetterGetterGetter());
	EXPECT_EQ(values["ReferenceSetterConstGetter"], entity.ReferenceSetterConstGetterGetter());
	EXPECT_EQ(values["ReferenceSetterReferenceGetter"], entity.ReferenceSetterReferenceGetterGetter());
	EXPECT_EQ(values["ReferenceSetterConstReferenceGetter"], entity.ReferenceSetterConstReferenceGetterGetter());
	*/
	EXPECT_EQ(values["ConstReferenceSetterGetter"], entity.ConstReferenceSetterGetterGetter());
	EXPECT_EQ(values["ConstReferenceSetterConstGetter"], entity.ConstReferenceSetterConstGetterGetter());
	EXPECT_EQ(values["ConstReferenceSetterReferenceGetter"], entity.ConstReferenceSetterReferenceGetterGetter());
	EXPECT_EQ(values["ConstReferenceSetterConstReferenceGetter"], entity.ConstReferenceSetterConstReferenceGetterGetter());
}



TEST_F(ClassMapTests, GetMappedColumn_Field_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::_field);

	EXPECT_EQ("Field", column.GetColumn());
}



TEST_F(ClassMapTests, GetMappedColumn_SetterGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::SetterGetterGetter);

	EXPECT_EQ("SetterGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_SetterGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::SetterGetterSetter);
//
//	EXPECT_EQ("SetterGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_SetterConstGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::SetterConstGetterGetter);

	EXPECT_EQ("SetterConstGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_SetterConstGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::SetterConstGetterSetter);
//
//	EXPECT_EQ("SetterConstGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_SetterReferenceGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::SetterReferenceGetterGetter);

	EXPECT_EQ("SetterReferenceGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_SetterReferenceGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::SetterReferenceGetterSetter);
//
//	EXPECT_EQ("SetterReferenceGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_SetterConstReferenceGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::SetterConstReferenceGetterGetter);

	EXPECT_EQ("SetterConstReferenceGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_SetterConstReferenceGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::SetterConstReferenceGetterSetter);
//
//	EXPECT_EQ("SetterConstReferenceGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_ConstSetterGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstSetterGetterGetter);

	EXPECT_EQ("ConstSetterGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_ConstSetterGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstSetterGetterSetter);
//
//	EXPECT_EQ("ConstSetterGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_ConstSetterConstGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstSetterConstGetterGetter);

	EXPECT_EQ("ConstSetterConstGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_ConstSetterConstGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstSetterConstGetterSetter);
//
//	EXPECT_EQ("ConstSetterConstGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_ConstSetterReferenceGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstSetterReferenceGetterGetter);

	EXPECT_EQ("ConstSetterReferenceGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_ConstSetterReferenceGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstSetterReferenceGetterSetter);
//
//	EXPECT_EQ("ConstSetterReferenceGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_ConstSetterConstReferenceGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstSetterConstReferenceGetterGetter);

	EXPECT_EQ("ConstSetterConstReferenceGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_ConstSetterConstReferenceGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstSetterConstReferenceGetterSetter);
//
//	EXPECT_EQ("ConstSetterConstReferenceGetter", column.GetColumn());
//}


/*
TEST_F(ClassMapTests, GetMappedColumn_ReferenceSetterGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ReferenceSetterGetterGetter);

	EXPECT_EQ("ReferenceSetterGetter", column.GetColumn());
}

TEST_F(ClassMapTests, GetMappedColumn_ReferenceSetterGetterSetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ReferenceSetterGetterSetter);

	EXPECT_EQ("ReferenceSetterGetter", column.GetColumn());
}



TEST_F(ClassMapTests, GetMappedColumn_ReferenceSetterConstGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ReferenceSetterConstGetterGetter);

	EXPECT_EQ("ReferenceSetterConstGetter", column.GetColumn());
}

TEST_F(ClassMapTests, GetMappedColumn_ReferenceSetterConstGetterSetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ReferenceSetterConstGetterSetter);

	EXPECT_EQ("ReferenceSetterConstGetter", column.GetColumn());
}



TEST_F(ClassMapTests, GetMappedColumn_ReferenceSetterReferenceGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ReferenceSetterReferenceGetterGetter);

	EXPECT_EQ("ReferenceSetterReferenceGetter", column.GetColumn());
}

TEST_F(ClassMapTests, GetMappedColumn_ReferenceSetterReferenceGetterSetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ReferenceSetterReferenceGetterSetter);

	EXPECT_EQ("ReferenceSetterReferenceGetter", column.GetColumn());
}



TEST_F(ClassMapTests, GetMappedColumn_ReferenceSetterConstReferenceGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ReferenceSetterConstReferenceGetterGetter);

	EXPECT_EQ("ReferenceSetterConstReferenceGetter", column.GetColumn());
}

TEST_F(ClassMapTests, GetMappedColumn_ReferenceSetterConstReferenceGetterSetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ReferenceSetterConstReferenceGetterSetter);

	EXPECT_EQ("ReferenceSetterConstReferenceGetter", column.GetColumn());
}
*/


TEST_F(ClassMapTests, GetMappedColumn_ConstReferenceSetterGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstReferenceSetterGetterGetter);

	EXPECT_EQ("ConstReferenceSetterGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_ConstReferenceSetterGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstReferenceSetterGetterSetter);
//
//	EXPECT_EQ("ConstReferenceSetterGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_ConstReferenceSetterConstGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstReferenceSetterConstGetterGetter);

	EXPECT_EQ("ConstReferenceSetterConstGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_ConstReferenceSetterConstGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstReferenceSetterConstGetterSetter);
//
//	EXPECT_EQ("ConstReferenceSetterConstGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_ConstReferenceSetterReferenceGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstReferenceSetterReferenceGetterGetter);

	EXPECT_EQ("ConstReferenceSetterReferenceGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_ConstReferenceSetterReferenceGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstReferenceSetterReferenceGetterSetter);
//
//	EXPECT_EQ("ConstReferenceSetterReferenceGetter", column.GetColumn());
//}



TEST_F(ClassMapTests, GetMappedColumn_ConstReferenceSetterConstReferenceGetterGetter_ReturnsCorrectColumn)
{
	TestMappingEntityMap map;

	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterGetter);

	EXPECT_EQ("ConstReferenceSetterConstReferenceGetter", column.GetColumn());
}

//TEST_F(ClassMapTests, GetMappedColumn_ConstReferenceSetterConstReferenceGetterSetter_ReturnsCorrectColumn)
//{
//	TestMappingEntityMap map;
//
//	orm::sql::sql_column column = map.GetMappedColumn(&TestMappingEntity::ConstReferenceSetterConstReferenceGetterSetter);
//
//	EXPECT_EQ("ConstReferenceSetterConstReferenceGetter", column.GetColumn());
//}
