#pragma once

#include "Expression.h"
#include "member_types.h"

#include "BinaryExpressionSqlPredicateBuilder.h"
#include "ConstantExpressionSqlPredicateBuilder.h"
#include "FieldMemberExpressionSqlPredicateBuilder.h"
#include "GetterMemberExpressionSqlPredicateBuilder.h"
#include "ConstGetterMemberExpressionSqlPredicateBuilder.h"
#include "ReferenceGetterMemberExpressionSqlPredicateBuilder.h"
#include "ConstReferenceGetterMemberExpressionSqlPredicateBuilder.h"

// TODO: implement some kind of constant expression thingy
/*
template <typename T>
Expression<T> MakeExpression(const T &value)
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<ConstantExpressionSqlPredicateBuilder>(value);

	Expression<T> result(predicateBuilder);

	return result;
}
*/

template <typename TEntity, typename TProperty>
Expression<TEntity, TProperty> MakeExpression(TProperty(TEntity::*field))
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<FieldMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(field);

	Expression<TEntity, TProperty> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
//Expression<TEntity, TProperty> MakeExpression(typename member_types<TEntity, TProperty>::getter getter)
Expression<TEntity, TProperty> MakeExpression(TProperty (TEntity::*getter)())
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(getter);

	Expression<TEntity, TProperty> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
//Expression<TEntity, TProperty> MakeExpression(typename member_types<TEntity, TProperty>::const_getter getter)
Expression<TEntity, TProperty> MakeExpression(TProperty(TEntity::*getter)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<ConstGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(getter);

	Expression<TEntity, TProperty> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
//Expression<TEntity, TProperty> MakeExpression(typename member_types<TEntity, TProperty>::reference_getter getter)
Expression<TEntity, TProperty> MakeExpression(TProperty &(TEntity::*getter)())
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<ReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(getter);

	Expression<TEntity, TProperty> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
//Expression<TEntity, TProperty> MakeExpression(typename member_types<TEntity, TProperty>::const_reference_getter getter)
Expression<TEntity, TProperty> MakeExpression(const TProperty &(TEntity::*getter)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<ConstReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(getter);

	Expression<TEntity, TProperty> result(predicateBuilder);

	return result;
}

#ifndef _E
#define _E(x) (::MakeExpression(x))
#endif
