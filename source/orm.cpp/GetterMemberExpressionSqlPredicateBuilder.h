#pragma once

#include "ISqlPredicateBuilder.h"

#include "ClassMap.h"
#include "MappingRegistry.h"
#include "sql_column.h"

template <typename TEntity, typename TGetter>
class GetterMemberExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	typedef TEntity entity_type;
	typedef TGetter getter_type;

	GetterMemberExpressionSqlPredicateBuilder(getter_type getter) :
		  _getter(getter)
	{
	};

	GetterMemberExpressionSqlPredicateBuilder(const GetterMemberExpressionSqlPredicateBuilder &other) :
		  _getter(other._getter)
	{
	};

	virtual ~GetterMemberExpressionSqlPredicateBuilder()
	{
	};

	GetterMemberExpressionSqlPredicateBuilder &operator =(const GetterMemberExpressionSqlPredicateBuilder &other)
	{
		if (this != &other)
		{
			_getter = other._getter;
		}

		return *this;
	};

	virtual SqlPredicate Build(const MappingRegistry &registry) const override
	{
		std::shared_ptr<ClassMap<TEntity>> map = registry.GetMapping<TEntity>();

		orm::sql::sql_column column = map->GetMappedColumn(_getter);

		SqlPredicate result(column.GetColumnString());

		return result;
	};

private:
	getter_type _getter;
};
