#include "stdafx.h"

#include "MappingRegistry.h"

MappingRegistry::MappingRegistry()
{
}

MappingRegistry::MappingRegistry(const MappingRegistry &other) :
	  _mapCreators(other._mapCreators)
{
}

MappingRegistry::~MappingRegistry()
{
}

MappingRegistry &MappingRegistry::operator =(const MappingRegistry &other)
{
	if (this != &other)
	{
		_mapCreators = other._mapCreators;
	}

	return *this;
}

void MappingRegistry::Register(const std::string &entityTypeName, const std::function<std::shared_ptr<IMappingProvider>()> &mapCreator)
{
	_mapCreators[entityTypeName] = mapCreator;
}

std::shared_ptr<IMappingProvider> MappingRegistry::GetMapping(const std::string &entityTypeName) const
{
	auto iter = _mapCreators.find(entityTypeName);

	std::function<std::shared_ptr<IMappingProvider> ()> mappingCreator;

	if (iter == _mapCreators.cend())
	{
		std::string message("Could not find mapping for class '");
		message.append(entityTypeName);
		message.append("'.");

		std::exception e(message.c_str());

		throw e;
	}
	else
	{
		mappingCreator = iter->second;
	}

	std::shared_ptr<IMappingProvider> mapping = mappingCreator();

	return mapping;
}
