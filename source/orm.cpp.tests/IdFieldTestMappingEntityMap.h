#pragma once

#include <ClassMap.h>

#include "TestMappingEntity.h"

class IdFieldTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdFieldTestMappingEntityMap();
	virtual ~IdFieldTestMappingEntityMap();
};

class IdSetterGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdSetterGetterTestMappingEntityMap();
	virtual ~IdSetterGetterTestMappingEntityMap();
};

class IdSetterConstGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdSetterConstGetterTestMappingEntityMap();
	virtual ~IdSetterConstGetterTestMappingEntityMap();
};

class IdSetterReferenceGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdSetterReferenceGetterTestMappingEntityMap();
	virtual ~IdSetterReferenceGetterTestMappingEntityMap();
};

class IdSetterConstReferenceGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdSetterConstReferenceGetterTestMappingEntityMap();
	virtual ~IdSetterConstReferenceGetterTestMappingEntityMap();
};

class IdConstSetterGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdConstSetterGetterTestMappingEntityMap();
	virtual ~IdConstSetterGetterTestMappingEntityMap();
};

class IdConstSetterConstGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdConstSetterConstGetterTestMappingEntityMap();
	virtual ~IdConstSetterConstGetterTestMappingEntityMap();
};

class IdConstSetterReferenceGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdConstSetterReferenceGetterTestMappingEntityMap();
	virtual ~IdConstSetterReferenceGetterTestMappingEntityMap();
};

class IdConstSetterConstReferenceGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdConstSetterConstReferenceGetterTestMappingEntityMap();
	virtual ~IdConstSetterConstReferenceGetterTestMappingEntityMap();
};

class IdConstReferenceSetterGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdConstReferenceSetterGetterTestMappingEntityMap();
	virtual ~IdConstReferenceSetterGetterTestMappingEntityMap();
};

class IdConstReferenceSetterConstGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdConstReferenceSetterConstGetterTestMappingEntityMap();
	virtual ~IdConstReferenceSetterConstGetterTestMappingEntityMap();
};

class IdConstReferenceSetterReferenceGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdConstReferenceSetterReferenceGetterTestMappingEntityMap();
	virtual ~IdConstReferenceSetterReferenceGetterTestMappingEntityMap();
};

class IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap : public ClassMap<TestMappingEntity>
{
public:
	IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap();
	virtual ~IdConstReferenceSetterConstReferenceGetterTestMappingEntityMap();
};
