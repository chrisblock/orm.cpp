#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

template <typename T>
class ClassMap;
class IMappingProvider;

class MappingRegistry
{
public:
	MappingRegistry();
	MappingRegistry(const MappingRegistry &other);
	~MappingRegistry();

	MappingRegistry &operator =(const MappingRegistry &other);

	void Register(const std::string &entityTypeName, const std::function<std::shared_ptr<IMappingProvider> ()> &mapCreator);

	template <typename T>
	std::shared_ptr<ClassMap<T>> GetMapping() const
	{
		const char *entityTypeName = typeid (T).name();

		std::shared_ptr<IMappingProvider> mapping = GetMapping(entityTypeName);

		return std::static_pointer_cast<ClassMap<T>>(mapping);
	};

private:
	std::map<std::string, std::function<std::shared_ptr<IMappingProvider> ()>> _mapCreators;

	std::shared_ptr<IMappingProvider> GetMapping(const std::string &entityTypeName) const;
};
