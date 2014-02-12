#pragma once

#include "ISqlPredicateBuilder.h"

#include "ClassMap.h"
#include "MappingRegistry.h"
#include "member_types.h"

template <typename TEntity, typename TProperty>
class ConstReferenceGetterMemberExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	typedef typename member_types<TEntity, TProperty>::const_reference_getter const_reference_getter;

	ConstReferenceGetterMemberExpressionSqlPredicateBuilder(const_reference_getter getter) :
		  _getter(getter)
	{
	};

	ConstReferenceGetterMemberExpressionSqlPredicateBuilder(const ConstReferenceGetterMemberExpressionSqlPredicateBuilder &other) :
		  _getter(other._getter)
	{
	};

	virtual ~ConstReferenceGetterMemberExpressionSqlPredicateBuilder()
	{
	};

	ConstReferenceGetterMemberExpressionSqlPredicateBuilder &operator =(const ConstReferenceGetterMemberExpressionSqlPredicateBuilder &other)
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
	const_reference_getter _getter;
};
