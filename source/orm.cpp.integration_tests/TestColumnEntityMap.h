#pragma once

#include <ClassMap.h>

#define DECLARE_TEST_COLUMN_ENTITY_MAP(ColumnType) \
	class ColumnType ## _ColumnTestsEntityMap : public ClassMap<ColumnType ## _ColumnTestsEntity> \
	{ \
	public: \
		ColumnType ## _ColumnTestsEntityMap(); \
		ColumnType ## _ColumnTestsEntityMap(const ColumnType ## _ColumnTestsEntityMap &other); \
		virtual ~ColumnType ## _ColumnTestsEntityMap(); \
	\
		ColumnType ## _ColumnTestsEntityMap &operator =(const ColumnType ## _ColumnTestsEntityMap &other); \
	}; \

#define IMPLEMENT_TEST_COLUMN_ENTITY_MAP(ColumnType) \
	ColumnType ## _ColumnTestsEntityMap::ColumnType ## _ColumnTestsEntityMap() \
	{ \
		Schema("dbo"); \
		Table(#ColumnType "_ColumnTestsEntityTable"); \
	\
		Id(&ColumnType ## _ColumnTestsEntity::SetId, &ColumnType ## _ColumnTestsEntity::GetId, "Id") \
			.GeneratedBy(GenerationStrategy::Identity); \
	\
		Map(&ColumnType ## _ColumnTestsEntity::SetColumn, &ColumnType ## _ColumnTestsEntity::GetColumn, "TestColumn"); \
	} \
	\
	ColumnType ## _ColumnTestsEntityMap::ColumnType ## _ColumnTestsEntityMap(const ColumnType ## _ColumnTestsEntityMap &other) : \
		  ClassMap<ColumnType ## _ColumnTestsEntity>(other) \
	{ \
	} \
	\
	ColumnType ## _ColumnTestsEntityMap::~ColumnType ## _ColumnTestsEntityMap() \
	{ \
	} \
	\
	ColumnType ## _ColumnTestsEntityMap &ColumnType ## _ColumnTestsEntityMap::operator =(const ColumnType ## _ColumnTestsEntityMap &other) \
	{ \
		if (this != &other) \
		{ \
			ClassMap<ColumnType ## _ColumnTestsEntity>::operator =(other); \
		} \
	\
		return *this; \
	}
