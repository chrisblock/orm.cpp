#pragma once

#include "ISqlPredicateBuilder.h"

#include "ClassMap.h"
#include "MappingRegistry.h"
#include "member_types.h"

template <typename TEntity, typename TProperty>
class ReferenceGetterMemberExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	typedef typename member_types<TEntity, TProperty>::reference_getter reference_getter;

	ReferenceGetterMemberExpressionSqlPredicateBuilder(reference_getter getter) :
		  _getter(getter)
	{
	};

	ReferenceGetterMemberExpressionSqlPredicateBuilder(const ReferenceGetterMemberExpressionSqlPredicateBuilder &other) :
		  _getter(other._getter)
	{
	};

	virtual ~ReferenceGetterMemberExpressionSqlPredicateBuilder()
	{
	};

	ReferenceGetterMemberExpressionSqlPredicateBuilder &operator =(const ReferenceGetterMemberExpressionSqlPredicateBuilder &other)
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
	reference_getter _getter;
};
