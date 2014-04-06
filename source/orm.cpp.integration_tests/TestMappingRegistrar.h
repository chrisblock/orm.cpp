#pragma once

#include <MappingRegistrar.h>

#define DECLARE_TEST_MAPPING_REGISTRAR(ColumnType) \
	class ColumnType ## _ColumnTestsMappingRegistrar : public MappingRegistrar \
	{ \
	public: \
		ColumnType ## _ColumnTestsMappingRegistrar(); \
		ColumnType ## _ColumnTestsMappingRegistrar(const ColumnType ## _ColumnTestsMappingRegistrar &other); \
		virtual ~ColumnType ## _ColumnTestsMappingRegistrar(); \
	\
		ColumnType ## _ColumnTestsMappingRegistrar &operator =(const ColumnType ## _ColumnTestsMappingRegistrar &other); \
	};

#define IMPLEMENT_TEST_MAPPING_REGISTRAR(ColumnType) \
	ColumnType ## _ColumnTestsMappingRegistrar::ColumnType ## _ColumnTestsMappingRegistrar() \
	{ \
		Register<ColumnType ## _ColumnTestsEntity, ColumnType ## _ColumnTestsEntityMap>(); \
	} \
	\
	ColumnType ## _ColumnTestsMappingRegistrar::ColumnType ## _ColumnTestsMappingRegistrar(const ColumnType ## _ColumnTestsMappingRegistrar &other) : \
		  MappingRegistrar(other) \
	{ \
	} \
	\
	ColumnType ## _ColumnTestsMappingRegistrar::~ColumnType ## _ColumnTestsMappingRegistrar() \
	{ \
	} \
	\
	ColumnType ## _ColumnTestsMappingRegistrar &ColumnType ## _ColumnTestsMappingRegistrar::operator =(const ColumnType ## _ColumnTestsMappingRegistrar &other) \
	{ \
		if (this != &other) \
		{ \
			MappingRegistrar::operator =(other); \
		} \
		\
		return *this; \
	}
