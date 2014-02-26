#pragma once

#include "ClassMap.h"
#include "MappingRegistry.h"
#include "member_types.h"
#include "SqlColumn.h"

template <typename TEntity, typename TProperty>
class FieldMemberExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	typedef typename member_types<TEntity, TProperty>::field field;

	FieldMemberExpressionSqlPredicateBuilder(field field) :
		  _field(field)
	{
	};

	FieldMemberExpressionSqlPredicateBuilder(const FieldMemberExpressionSqlPredicateBuilder &other) :
		  _field(other._field)
	{
	};

	virtual ~FieldMemberExpressionSqlPredicateBuilder()
	{
	};

	FieldMemberExpressionSqlPredicateBuilder &operator =(const FieldMemberExpressionSqlPredicateBuilder &other)
	{
		if (this != &other)
		{
			_field = other._field;
		}

		return *this;
	};

	virtual SqlPredicate Build(const MappingRegistry &registry) const
	{
		std::shared_ptr<ClassMap<TEntity>> map = registry.GetMapping<TEntity>();

		SqlColumn column = map->GetMappedColumn<TProperty>(_field);

		SqlPredicate result(column.GetColumnString());

		return result;
	};

private:
	field _field;
};
