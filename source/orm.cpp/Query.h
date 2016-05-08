#pragma once

#include <memory>
#include <string>
#include <vector>

#include "BinaryExpressionSqlPredicateBuilder.h"
#include "BinaryOperators.h"
#include "from_clause.h"
#include "ISqlDialect.h"
#include "ISqlExecutor.h"
#include "ISqlPredicateBuilder.h"
#include "Predicate.h"
#include "SqlPredicate.h"
#include "statement.h"
#include "projection.h"

namespace odbc
{
	class environment;
};

namespace orm
{
	template <typename T>
	class query
	{
	public:
		query()
		{
		};

		query(const std::shared_ptr<odbc::environment> &environment, const std::string &connectionString, const std::shared_ptr<ISqlDialect> &dialect, const std::shared_ptr<ISqlExecutor> &executor, const MappingRegistry &registry) :
			  _environment(environment)
			, _connectionString(connectionString)
			, _dialect(dialect)
			, _executor(executor)
			, _registry(registry)
		{
		};

		query(const query &other) :
			  _environment(other._environment)
			, _dialect(other._dialect)
			, _executor(other._executor)
			, _predicateBuilder(other._predicateBuilder)
			, _connectionString(other._connectionString)
			, _registry(other._registry)
		{
		};

		query(query &&other) :
			  query()
		{
			swap(*this, other);
		};

		virtual ~query()
		{
		};

		query &operator =(query other)
		{
			swap(*this, other);

			return *this;
		};

		friend void swap(query &left, query &right)
		{
			using std::swap;

			swap(left._connectionString, right._connectionString);
			swap(left._dialect, right._dialect);
			swap(left._environment, right._environment);
			swap(left._executor, right._executor);
			swap(left._predicateBuilder, right._predicateBuilder);
			swap(left._registry, right._registry);
		};

		query &Where(const Predicate<T> &expression)
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

		void Execute(std::vector<T> &items) const
		{
			static_assert(std::is_default_constructible<T>::value, "Type must have a default constructor.");
			static_assert(std::is_copy_constructible<T>::value, "Type must have copy constructor.");
			static_assert(std::is_copy_assignable<T>::value, "Type must have assignment operator.");

			SqlPredicate predicate;

			std::shared_ptr<ClassMap<T>> mapping = _registry.GetMapping<T>();

			orm::sql::projection projection = mapping->GetProjection();

			if (_predicateBuilder != nullptr)
			{
				predicate = _predicateBuilder->Build(_registry);
			}

			orm::sql::from_clause fromClause;

			orm::sql::sql_table table;

			table.SetSchema(mapping->GetSchema());
			table.SetTable(mapping->GetTable());

			fromClause.SetMainTable(table);

			orm::sql::statement statement = _dialect->BuildSelectStatement(projection, fromClause, predicate);

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
};
