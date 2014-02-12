#pragma once

#include <memory>
#include <string>

#include "ClassMap.h"
#include "MappingRegistry.h"
#include "Query.h"

namespace odbc
{
	class environment;
};

class Session
{
public:
	Session(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const MappingRegistry &registry);
	Session(const Session &other);
	~Session();

	Session &operator =(const Session &other);

	template <typename TEntity>
	Query<TEntity> QueryOver()
	{
		Query<TEntity> query;

		return query;
	};

	template <typename TEntity>
	void Insert(const TEntity &entity)
	{
	};

	template <typename TEntity>
	void Update(const TEntity &entity)
	{
	};

	template <typename TEntity>
	void Delete(const TEntity &entity)
	{
		std::shared_ptr<ClassMap<TEntity>> map = _registry.GetMapping<TEntity>();
	};

private:
	std::shared_ptr<odbc::environment> _environment;
	std::string _connectionString;
	MappingRegistry _registry;
};
