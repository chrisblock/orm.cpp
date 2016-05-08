#pragma once

#include "ClassMap.h"
#include "MappingRegistry.h"
#include "sql_column.h"

template <typename TEntity, typename TField>
class FieldMemberExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	typedef TEntity entity_type;
	typedef TField field_type;

	FieldMemberExpressionSqlPredicateBuilder(field_type field) :
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

	virtual SqlPredicate Build(const MappingRegistry &registry) const override
	{
		std::shared_ptr<ClassMap<TEntity>> map = registry.GetMapping<TEntity>();

		orm::sql::sql_column column = map->GetMappedColumn(_field);

		SqlPredicate result(column.GetColumnString());

		return result;
	};

private:
	field_type _field;
};
