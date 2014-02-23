#pragma once

#include <memory>
#include <string>
#include <vector>

#include "IQuery.h"
#include "ISqlDialect.h"
#include "ISqlExecutor.h"
#include "ISqlPredicateBuilder.h"
#include "Predicate.h"
#include "SqlPredicate.h"
#include "SqlProjection.h"

namespace odbc
{
	class environment;
};

template <typename T>
class Query : public IQuery
{
public:
	Query(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const std::shared_ptr<ISqlDialect> &dialect, const std::shared_ptr<ISqlExecutor> &executor, const MappingRegistry &registry) :
		  _environment(environment)
		, _connectionString(connectionString)
		, _dialect(dialect)
		, _executor(executor)
		, _registry(registry)
	{
	};

	Query(const Query<T> &other) :
		  _environment(other._environment)
		, _connectionString(other._connectionString)
		, _dialect(other._dialect)
		, _executor(other._executor)
		, _registry(other._registry)
	{
	};

	virtual ~Query()
	{
	};

	Query<T> &operator =(const Query<T> &other)
	{
		if (this != other)
		{
			_environment = other._environment;
			_connectionString = other._connectionString;
			_dialect = other._dialect;
			_executor = other._executor;
			_registry = other._registry;
		}

		return *this;
	};

	Query<T> &Where(const Predicate<T> &expression)
	{
		if (_predicateBuilder == nullptr)
		{
			_predicateBuilder = expression.GetSqlPredicateBuilder();
		}
		else
		{
			//_predicateBuilder = std::make_shared<SqlBi
		}
	};

	int32_t Execute()
	{
	};

	void Execute(std::vector<T> &items)
	{
		SqlPredicate predicate;

		std::shared_ptr<ClassMap<T>> mapping = _registry.GetMapping<T>();

		SqlProjection projection = mapping->GetProjection();

		if (_predicateBuilder != nullptr)
		{
			predicate = _predicateBuilder->Build(_registry);
		}

		SqlStatement statement = _dialect->BuildSelectStatement(projection, predicate);

		std::shared_ptr<IDataReader> reader = _executor->ExecuteReader(_environment, _connectionString, statement);

		while (reader->Read())
		{
			T item;

			mapping->ReadEntityFromDataReader(item, reader);

			items.push_back(item);
		}
	};

private:
	std::shared_ptr<odbc::environment> _environment;
	std::shared_ptr<ISqlDialect> _dialect;
	std::shared_ptr<ISqlExecutor> _executor;
	std::shared_ptr<ISqlPredicateBuilder> _predicateBuilder;
	std::string _connectionString;
	MappingRegistry _registry;
};
