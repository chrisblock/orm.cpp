#pragma once

#include <memory>
#include <string>

#include "ClassMap.h"
#include "ISqlDialect.h"
#include "ISqlExecutor.h"
#include "MappingRegistry.h"
#include "Query.h"
#include "Record.h"
#include "statement.h"

namespace odbc
{
	class environment;
}

namespace orm
{
	class session
	{
	public:
		session();
		session(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const std::shared_ptr<ISqlDialect> &dialect, const std::shared_ptr<ISqlExecutor> &executor, const MappingRegistry &registry);
		session(const session &other);
		session(session &&other);
		~session();

		session &operator =(session other);

		friend void swap(session &left, session &right);

		template <typename TEntity>
		orm::query<TEntity> QueryOver() const
		{
			orm::query<TEntity> query(_environment, _connectionString, _dialect, _executor, _registry);

			return query;
		};

		template <typename TEntity>
		std::uint32_t Insert(TEntity &entity) const
		{
			std::shared_ptr<ClassMap<TEntity>> map = _registry.GetMapping<TEntity>();

			Record record;

			map->WriteEntityToRecord(entity, record);

			orm::sql::statement statement = _dialect->BuildInsertStatement(record);

			std::uint32_t result = ExecuteSql(statement);

			return result;
		};

		template <typename TEntity>
		std::uint32_t Update(TEntity &entity) const
		{
			std::shared_ptr<ClassMap<TEntity>> map = _registry.GetMapping<TEntity>();

			Record record;

			map->WriteEntityToRecord(entity, record);

			orm::sql::statement statement = _dialect->BuildUpdateStatement(record);

			std::uint32_t result = ExecuteSql(statement);

			return result;
		};

		template <typename TEntity>
		std::uint32_t Delete(TEntity &entity) const
		{
			std::shared_ptr<ClassMap<TEntity>> map = _registry.GetMapping<TEntity>();

			Record record;

			map->WriteEntityToRecord(entity, record);

			orm::sql::statement statement = _dialect->BuildDeleteStatement(record);

			std::uint32_t result = ExecuteSql(statement);

			return result;
		};

	private:
		std::uint32_t ExecuteSql(const orm::sql::statement &statement) const;

		std::shared_ptr<ISqlDialect> _dialect;
		std::shared_ptr<ISqlExecutor> _executor;
		std::shared_ptr<odbc::environment> _environment;
		std::string _connectionString;
		MappingRegistry _registry;
	};

	void swap(session &left, session &right);
};
