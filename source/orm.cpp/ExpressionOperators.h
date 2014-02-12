#pragma once

#include "Expression.h"

#include "BinaryOperators.h"
#include "member_types.h"

#include "ISqlPredicateBuilder.h"
#include "BinaryExpressionSqlPredicateBuilder.h"
#include "ConstantExpressionSqlPredicateBuilder.h"
#include "IsNullExpressionSqlPredicateBuilder.h"
#include "GetterMemberExpressionSqlPredicateBuilder.h"
#include "ConstGetterMemberExpressionSqlPredicateBuilder.h"
#include "ReferenceGetterMemberExpressionSqlPredicateBuilder.h"
#include "ConstReferenceGetterMemberExpressionSqlPredicateBuilder.h"

Expression<bool> operator &&(const Expression<bool> &left, const bool right);

Expression<bool> operator &&(const bool left, const Expression<bool> &right);

Expression<bool> operator &&(const Expression<bool> &left, const Expression<bool> &right);

Expression<bool> operator ||(const Expression<bool> &left, const bool right);

Expression<bool> operator ||(const bool left, const Expression<bool> &right);

Expression<bool> operator ||(const Expression<bool> &left, const Expression<bool> &right);

template <typename T>
static Expression<bool> operator ==(const Expression<T> &left, const std::nullptr_t &)
{
	std::shared_ptr<IsNullExpressionSqlPredicateBuilder> predicate = std::make_shared<IsNullExpressionSqlPredicateBuilder>(left.GetSqlPredicateBuilder());

	Expression<bool> result(predicate);

	return result;
}

template <typename T>
static Expression<bool> operator ==(const std::nullptr_t &, const Expression<T> &right)
{
	std::shared_ptr<IsNullExpressionSqlPredicateBuilder> predicate = std::make_shared<IsNullExpressionSqlPredicateBuilder>(right.GetSqlPredicateBuilder());

	Expression<bool> result(predicate);

	return result;
}

template <typename T>
static Expression<bool> operator !=(const Expression<T> &left, const std::nullptr_t &)
{
	std::shared_ptr<IsNullExpressionSqlPredicateBuilder> predicate = std::make_shared<IsNullExpressionSqlPredicateBuilder>(left.GetSqlPredicateBuilder(), true);

	Expression<bool> result(predicate);

	return result;
}

template <typename T>
static Expression<bool> operator !=(const std::nullptr_t &, const Expression<T> &right)
{
	std::shared_ptr<IsNullExpressionSqlPredicateBuilder> predicate = std::make_shared<IsNullExpressionSqlPredicateBuilder>(right.GetSqlPredicateBuilder(), true);

	Expression<bool> result(predicate);

	return result;
}

template <typename T>
static Expression<bool> operator ==(const Expression<T> &left, const T &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Equal, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
//static Expression<bool> operator ==(const Expression<TProperty> &left, typename member_types<TEntity, TProperty>::getter right)
static Expression<bool> operator ==(const Expression<TProperty> &left, TProperty (TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Equal, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
//static Expression<bool> operator ==(const Expression<TProperty> &left, typename member_types<TEntity, TProperty>::const_getter right)
static Expression<bool> operator ==(const Expression<TProperty> &left, TProperty (TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Equal, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
//static Expression<bool> operator ==(const Expression<TProperty> &left, typename member_types<TEntity, TProperty>::reference_getter right)
static Expression<bool> operator ==(const Expression<TProperty> &left, TProperty &(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Equal, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
//static Expression<bool> operator ==(const Expression<TProperty> &left, typename member_types<TEntity, TProperty>::const_reference_getter right)
static Expression<bool> operator ==(const Expression<TProperty> &left, const TProperty &(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Equal, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename T>
static Expression<bool> operator ==(const Expression<T> &left, const Expression<T> &right)
{
	Expression<bool> result(BinaryOperators::Equal, left, right);

	return result;
}

template <typename T>
static Expression<bool> operator !=(const Expression<T> &left, const T &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::NotEqual, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator !=(const Expression<TProperty> &left, TProperty (TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::NotEqual, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator !=(const Expression<TProperty> &left, TProperty (TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::NotEqual, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator !=(const Expression<TProperty> &left, TProperty &(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::NotEqual, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator !=(const Expression<TProperty> &left, const TProperty &(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::NotEqual, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename T>
static Expression<bool> operator !=(const Expression<T> &left, const Expression<T> &right)
{
	Expression<bool> result(BinaryOperators::NotEqual, left, right);

	return result;
}

template <typename T>
static Expression<bool> operator <(const Expression<T> &left, const T &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator <(const Expression<TProperty> &left, TProperty(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator <(const Expression<TProperty> &left, TProperty(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator <(const Expression<TProperty> &left, TProperty &(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator <(const Expression<TProperty> &left, const TProperty &(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename T>
static Expression<bool> operator <(const Expression<T> &left, const Expression<T> &right)
{
	Expression<bool> result(BinaryOperators::LessThan, left, right);

	return result;
}

template <typename T>
static Expression<bool> operator <=(const Expression<T> &left, const T &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator <=(const Expression<TProperty> &left, TProperty(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator <=(const Expression<TProperty> &left, TProperty(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator <=(const Expression<TProperty> &left, TProperty &(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator <=(const Expression<TProperty> &left, const TProperty &(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename T>
static Expression<bool> operator <=(const Expression<T> &left, const Expression<T> &right)
{
	Expression<bool> result(BinaryOperators::LessThanOrEqualTo, left, right);

	return result;
}

template <typename T>
static Expression<bool> operator >(const Expression<T> &left, const T &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator >(const Expression<TProperty> &left, TProperty(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator >(const Expression<TProperty> &left, TProperty(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator >(const Expression<TProperty> &left, TProperty &(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator >(const Expression<TProperty> &left, const TProperty &(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThan, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename T>
static Expression<bool> operator >(const Expression<T> &left, const Expression<T> &right)
{
	Expression<bool> result(BinaryOperators::GreaterThan, left, right);

	return result;
}

template <typename T>
static Expression<bool> operator >=(const Expression<T> &left, const T &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator >=(const Expression<TProperty> &left, TProperty(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator >=(const Expression<TProperty> &left, TProperty(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator >=(const Expression<TProperty> &left, TProperty &(TEntity::*right)())
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Expression<bool> operator >=(const Expression<TProperty> &left, const TProperty &(TEntity::*right)() const)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstReferenceGetterMemberExpressionSqlPredicateBuilder<TEntity, TProperty>>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Expression<bool> result(predicateBuilder);

	return result;
}

template <typename T>
static Expression<bool> operator >=(const Expression<T> &left, const Expression<T> &right)
{
	Expression<bool> result(BinaryOperators::GreaterThanOrEqualTo, left, right);

	return result;
}
