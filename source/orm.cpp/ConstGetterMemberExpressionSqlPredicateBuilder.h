#pragma once

#include "ISqlPredicateBuilder.h"

#include "ClassMap.h"
#include "MappingRegistry.h"
#include "member_types.h"

template <typename TEntity, typename TProperty>
class ConstGetterMemberExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	typedef typename member_types<TEntity, TProperty>::const_getter const_getter;

	ConstGetterMemberExpressionSqlPredicateBuilder(const_getter getter) :
		  _getter(getter)
	{
	};

	ConstGetterMemberExpressionSqlPredicateBuilder(const ConstGetterMemberExpressionSqlPredicateBuilder &other) :
		  _getter(other._getter)
	{
	};

	virtual ~ConstGetterMemberExpressionSqlPredicateBuilder()
	{
	};

	ConstGetterMemberExpressionSqlPredicateBuilder &operator =(const ConstGetterMemberExpressionSqlPredicateBuilder &other)
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
	const_getter _getter;
};
