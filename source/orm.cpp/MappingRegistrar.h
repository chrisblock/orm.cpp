#pragma once

#include <functional>
#include <map>
#include <memory>

template <typename TEntity>
class ClassMap;
class IMappingProvider;
class MappingRegistry;

class MappingRegistrar
{
public:
	MappingRegistrar();
	MappingRegistrar(const MappingRegistrar &other);
	MappingRegistrar(MappingRegistrar &&other);
	virtual ~MappingRegistrar();

	MappingRegistrar &operator =(MappingRegistrar other);

	friend void swap(MappingRegistrar &left, MappingRegistrar &right);

	void Register(MappingRegistry &registry) const;

protected:
	template <typename TEntity, typename TMapping>
	void Register()
	{
		static_assert(std::is_base_of<ClassMap<TEntity>, TMapping>::value, "Must register a type that extends ClassMap<T> for the mapping of type T.");
		static_assert(std::is_base_of<IMappingProvider, TMapping>::value, "Cannot CreateMapping for types that do not inherit from IMappingProvider.");

		static_assert(std::is_default_constructible<TMapping>::value, "Mapping must be default constructable.");

		std::string entityTypeName = typeid (TEntity).name();

		Register(entityTypeName, std::make_shared<TMapping>);
	};

private:
	virtual void Register(const std::string &entityTypeName, const std::function<std::shared_ptr<IMappingProvider> ()> &mappingCreator);

	std::map<std::string, std::function<std::shared_ptr<IMappingProvider> ()>> _mappings;
};

void swap(MappingRegistrar &left, MappingRegistrar &right);
