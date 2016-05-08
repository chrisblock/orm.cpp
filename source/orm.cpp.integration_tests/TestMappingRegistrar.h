#pragma once

#include <MappingRegistrar.h>

#define DECLARE_TEST_MAPPING_REGISTRAR(ColumnType) \
	class ColumnType ## _ColumnTestsMappingRegistrar : public MappingRegistrar \
	{ \
	public: \
		ColumnType ## _ColumnTestsMappingRegistrar(); \
	};

#define IMPLEMENT_TEST_MAPPING_REGISTRAR(ColumnType) \
	ColumnType ## _ColumnTestsMappingRegistrar::ColumnType ## _ColumnTestsMappingRegistrar() \
	{ \
		Register<ColumnType ## _ColumnTestsEntity, ColumnType ## _ColumnTestsEntityMap>(); \
	}
