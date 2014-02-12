#pragma once

#include "ISqlPredicateBuilder.h"

#include "ClassMap.h"
#include "MappingRegistry.h"
#include "member_types.h"
#include "SqlColumn.h"

template <typename TEntity, typename TProperty>
class GetterMemberExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	typedef typename member_types<TEntity, TProperty>::getter getter;

	GetterMemberExpressionSqlPredicateBuilder(getter getter) :
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

	virtual SqlPredicate Build(const MappingRegistry &registry) const
	{
		std::shared_ptr<ClassMap<TEntity>> map = registry.GetMapping<TEntity>();

		SqlColumn column = map->GetMappedColumn<TProperty>(_getter);

		SqlPredicate result(column.GetColumnString());

		return result;
	};

private:
	getter _getter;
};
