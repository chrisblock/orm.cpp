#pragma once

#include <memory>
#include <string>

#include "ClassMap.h"
#include "ISqlDialect.h"
#include "ISqlExecutor.h"
#include "MappingRegistry.h"
#include "Query.h"
#include "Record.h"
#include "SqlStatement.h"

namespace odbc
{
	class environment;
};

class Session
{
public:
	Session(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const std::shared_ptr<ISqlDialect> &dialect, const std::shared_ptr<ISqlExecutor> &executor, const MappingRegistry &registry);
	Session(const Session &other);
	~Session();

	Session &operator =(const Session &other);

	template <typename TEntity>
	Query<TEntity> QueryOver() const
	{
		Query<TEntity> query(_environment, _connectionString, _dialect, _executor, _registry);

		return query;
	};

	template <typename TEntity>
	uint32_t Insert(TEntity &entity) const
	{
		std::shared_ptr<ClassMap<TEntity>> map = _registry.GetMapping<TEntity>();

		Record record;

		map->WriteEntityToRecord(entity, record);

		SqlStatement statement = _dialect->BuildInsertStatement(record);

		uint32_t result = ExecuteSql(statement);

		return result;
	};

	template <typename TEntity>
	uint32_t Update(TEntity &entity) const
	{
		std::shared_ptr<ClassMap<TEntity>> map = _registry.GetMapping<TEntity>();

		Record record;

		map->WriteEntityToRecord(entity, record);

		SqlStatement statement = _dialect->BuildUpdateStatement(record);

		uint32_t result = ExecuteSql(statement);

		return result;
	};

	template <typename TEntity>
	uint32_t Delete(TEntity &entity) const
	{
		std::shared_ptr<ClassMap<TEntity>> map = _registry.GetMapping<TEntity>();

		Record record;

		map->WriteEntityToRecord(entity, record);

		SqlStatement statement = _dialect->BuildDeleteStatement(record);

		uint32_t result = ExecuteSql(statement);

		return result;
	};

private:
	uint32_t ExecuteSql(const SqlStatement &statement) const;

	std::shared_ptr<ISqlDialect> _dialect;
	std::shared_ptr<ISqlExecutor> _executor;
	std::shared_ptr<odbc::environment> _environment;
	std::string _connectionString;
	MappingRegistry _registry;
};
