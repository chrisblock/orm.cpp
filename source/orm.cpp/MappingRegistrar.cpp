#include "stdafx.h"

#include "MappingRegistrar.h"

//#include "IMappingProvider.h"
#include "MappingRegistry.h"

MappingRegistrar::MappingRegistrar()
{
}

MappingRegistrar::MappingRegistrar(const MappingRegistrar &other) :
	  _mappings(other._mappings)
{
}

MappingRegistrar::~MappingRegistrar()
{
	_mappings.clear();
}

MappingRegistrar &MappingRegistrar::operator =(const MappingRegistrar &other)
{
	if (this != &other)
	{
		_mappings = other._mappings;
	}

	return *this;
}

void MappingRegistrar::Register(MappingRegistry &registry) const
{
	for (auto iter = _mappings.cbegin(); iter != _mappings.cend(); iter++)
	{
		registry.Register(iter->first, iter->second);
	}
}

void MappingRegistrar::Register(const std::string &entityTypeName, const std::function<std::shared_ptr<IMappingProvider> ()> &mappingCreator)
{
	_mappings[entityTypeName] = mappingCreator;
}
