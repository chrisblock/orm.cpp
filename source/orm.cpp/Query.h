#pragma once

#include <memory>
#include <string>
#include <vector>

#include "BinaryExpressionSqlPredicateBuilder.h"
#include "BinaryOperators.h"
#include "FromClause.h"
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
		, _dialect(other._dialect)
		, _executor(other._executor)
		, _predicateBuilder(other._predicateBuilder)
		, _connectionString(other._connectionString)
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
			_dialect = other._dialect;
			_executor = other._executor;
			_predicateBuilder = other._predicateBuilder;
			_connectionString = other._connectionString;
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
			_predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::And, _predicateBuilder, expression.GetSqlPredicateBuilder());
		}

		return *this;
	};

	void Execute(std::vector<T> &items)
	{
		static_assert(std::has_default_constructor<T>::value, "Type must have a default constructor.");
		static_assert(std::has_copy_constructor<T>::value, "Type must have copy constructor.");
		static_assert(std::has_copy_assign<T>::value, "Type must have assignment operator.");

		SqlPredicate predicate;

		std::shared_ptr<ClassMap<T>> mapping = _registry.GetMapping<T>();

		SqlProjection projection = mapping->GetProjection();

		if (_predicateBuilder != nullptr)
		{
			predicate = _predicateBuilder->Build(_registry);
		}

		FromClause fromClause;

		SqlTable table;

		table.SetSchema(mapping->GetSchema());
		table.SetTable(mapping->GetTable());

		fromClause.SetMainTable(table);

		SqlStatement statement = _dialect->BuildSelectStatement(projection, fromClause, predicate);

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
