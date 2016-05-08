#include "stdafx.h"

#include "MappingRegistrar.h"

//#include "IMappingProvider.h"
#include "MappingRegistry.h"

void swap(MappingRegistrar &left, MappingRegistrar &right)
{
	using std::swap;

	swap(left._mappings, right._mappings);
}

MappingRegistrar::MappingRegistrar()
{
}

MappingRegistrar::MappingRegistrar(const MappingRegistrar &other) :
	  _mappings(other._mappings)
{
}

MappingRegistrar::MappingRegistrar(MappingRegistrar &&other) :
	  MappingRegistrar()
{
	swap(*this, other);
}

MappingRegistrar::~MappingRegistrar()
{
	_mappings.clear();
}

MappingRegistrar &MappingRegistrar::operator =(MappingRegistrar other)
{
	swap(*this, other);

	return *this;
}

void MappingRegistrar::Register(MappingRegistry &registry) const
{
	for (auto iter = _mappings.cbegin(); iter != _mappings.cend(); ++iter)
	{
		registry.Register(iter->first, iter->second);
	}
}

void MappingRegistrar::Register(const std::string &entityTypeName, const std::function<std::shared_ptr<IMappingProvider> ()> &mappingCreator)
{
	_mappings[entityTypeName] = mappingCreator;
}
