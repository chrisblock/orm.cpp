#pragma once

#include "Expression.h"
#include "Predicate.h"

#include "BinaryOperators.h"

#include "BinaryExpressionSqlPredicateBuilder.h"
#include "ConstantExpressionSqlPredicateBuilder.h"
#include "decomposer.h"
#include "FieldMemberExpressionSqlPredicateBuilder.h"
#include "GetterMemberExpressionSqlPredicateBuilder.h"
#include "IsNullExpressionSqlPredicateBuilder.h"
#include "ISqlPredicateBuilder.h"

template <typename TEntity>
Predicate<TEntity> operator &&(const Predicate<TEntity> &left, const bool right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::And, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity>
Predicate<TEntity> operator &&(const bool left, const Predicate<TEntity> &right)
{
	std::shared_ptr<ISqlPredicateBuilder> l = std::make_shared<ConstantExpressionSqlPredicateBuilder>(left);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::And, l, right.GetSqlPredicateBuilder());

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity>
Predicate<TEntity> operator &&(const Predicate<TEntity> &left, const Predicate<TEntity> &right)
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::And, left.GetSqlPredicateBuilder(), right.GetSqlPredicateBuilder());

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity>
Predicate<TEntity> operator ||(const Predicate<TEntity> &left, const bool right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Or, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity>
Predicate<TEntity> operator ||(const bool left, const Predicate<TEntity> &right)
{
	std::shared_ptr<ISqlPredicateBuilder> l = std::make_shared<ConstantExpressionSqlPredicateBuilder>(left);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Or, l, right.GetSqlPredicateBuilder());

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity>
Predicate<TEntity> operator ||(const Predicate<TEntity> &left, const Predicate<TEntity> &right)
{
	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Or, left.GetSqlPredicateBuilder(), right.GetSqlPredicateBuilder());

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator ==(const Expression<TEntity, TProperty> &left, const std::nullptr_t &)
{
	std::shared_ptr<IsNullExpressionSqlPredicateBuilder> predicate = std::make_shared<IsNullExpressionSqlPredicateBuilder>(left.GetSqlPredicateBuilder());

	Predicate<TEntity> result(predicate);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator ==(const std::nullptr_t &, const Expression<TEntity, TProperty> &right)
{
	std::shared_ptr<IsNullExpressionSqlPredicateBuilder> predicate = std::make_shared<IsNullExpressionSqlPredicateBuilder>(right.GetSqlPredicateBuilder());

	Predicate<TEntity> result(predicate);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator !=(const Expression<TEntity, TProperty> &left, const std::nullptr_t &)
{
	std::shared_ptr<IsNullExpressionSqlPredicateBuilder> predicate = std::make_shared<IsNullExpressionSqlPredicateBuilder>(left.GetSqlPredicateBuilder(), true);

	Predicate<TEntity> result(predicate);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator !=(const std::nullptr_t &, const Expression<TEntity, TProperty> &right)
{
	std::shared_ptr<IsNullExpressionSqlPredicateBuilder> predicate = std::make_shared<IsNullExpressionSqlPredicateBuilder>(right.GetSqlPredicateBuilder(), true);

	Predicate<TEntity> result(predicate);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator ==(const Expression<TEntity, TProperty> &left, const TProperty &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Equal, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty, typename TMember>
static Predicate<TEntity> operator ==(const Expression<TEntity, TProperty> &left, TMember right)
{
	static_assert(std::is_member_pointer<TMember>::value, "right must be a member pointer.");
	static_assert(std::is_same<TProperty, typename std::result_of<member_types::decomposer (TMember)>::type::property_type>::value, "left and right must result in the same type.");

	std::shared_ptr<ISqlPredicateBuilder> r;

	if (std::is_member_function_pointer<TMember>::value)
	{
		r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}
	else
	{
		r = std::make_shared<FieldMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::Equal, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator ==(const Expression<TEntity, TProperty> &left, const Expression<TEntity, TProperty> &right)
{
	Predicate<TEntity> result(BinaryOperators::Equal, left, right);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator !=(const Expression<TEntity, TProperty> &left, const TProperty &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::NotEqual, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty, typename TMember>
static Predicate<TEntity> operator !=(const Expression<TEntity, TProperty> &left, TMember right)
{
	static_assert(std::is_member_pointer<TMember>::value, "right must be a member pointer.");
	static_assert(std::is_same<TProperty, typename std::result_of<member_types::decomposer (TMember)>::type::property_type>::value, "left and right must result in the same type.");

	std::shared_ptr<ISqlPredicateBuilder> r;

	if (std::is_member_function_pointer<TMember>::value)
	{
		r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}
	else
	{
		r = std::make_shared<FieldMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::NotEqual, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator !=(const Expression<TEntity, TProperty> &left, const Expression<TEntity, TProperty> &right)
{
	Predicate<TEntity> result(BinaryOperators::NotEqual, left, right);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator <(const Expression<TEntity, TProperty> &left, const TProperty &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThan, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty, typename TMember>
static Predicate<TEntity> operator <(const Expression<TEntity, TProperty> &left, TMember right)
{
	static_assert(std::is_member_pointer<TMember>::value, "right must be a member pointer.");
	static_assert(std::is_same<TProperty, typename std::result_of<member_types::decomposer (TMember)>::type::property_type>::value, "left and right must result in the same type.");

	std::shared_ptr<ISqlPredicateBuilder> r;

	if (std::is_member_function_pointer<TMember>::value)
	{
		r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}
	else
	{
		r = std::make_shared<FieldMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThan, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator <(const Expression<TEntity, TProperty> &left, const Expression<TEntity, TProperty> &right)
{
	Predicate<TEntity> result(BinaryOperators::LessThan, left, right);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator <=(const Expression<TEntity, TProperty> &left, const TProperty &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty, typename TMember>
static Predicate<TEntity> operator <=(const Expression<TEntity, TProperty> &left, TMember right)
{
	static_assert(std::is_member_pointer<TMember>::value, "right must be a member pointer.");
	static_assert(std::is_same<TProperty, typename std::result_of<member_types::decomposer (TMember)>::type::property_type>::value, "left and right must result in the same type.");

	std::shared_ptr<ISqlPredicateBuilder> r;

	if (std::is_member_function_pointer<TMember>::value)
	{
		r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}
	else
	{
		r = std::make_shared<FieldMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::LessThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator <=(const Expression<TEntity, TProperty> &left, const Expression<TEntity, TProperty> &right)
{
	Predicate<TEntity> result(BinaryOperators::LessThanOrEqualTo, left, right);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator >(const Expression<TEntity, TProperty> &left, const TProperty &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThan, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty, typename TMember>
static Predicate<TEntity> operator >(const Expression<TEntity, TProperty> &left, TMember right)
{
	static_assert(std::is_member_pointer<TMember>::value, "right must be a member pointer.");
	static_assert(std::is_same<TProperty, typename std::result_of<member_types::decomposer (TMember)>::type::property_type>::value, "left and right must result in the same type.");

	std::shared_ptr<ISqlPredicateBuilder> r;

	if (std::is_member_function_pointer<TMember>::value)
	{
		r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}
	else
	{
		r = std::make_shared<FieldMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThan, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator >(const Expression<TEntity, TProperty> &left, const Expression<TEntity, TProperty> &right)
{
	Predicate<TEntity> result(BinaryOperators::GreaterThan, left, right);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator >=(const Expression<TEntity, TProperty> &left, const TProperty &right)
{
	std::shared_ptr<ISqlPredicateBuilder> r = std::make_shared<ConstantExpressionSqlPredicateBuilder>(right);

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty, typename TMember>
static Predicate<TEntity> operator >=(const Expression<TEntity, TProperty> &left, TMember right)
{
	static_assert(std::is_member_pointer<TMember>::value, "right must be a member pointer.");
	static_assert(std::is_same<TProperty, typename std::result_of<member_types::decomposer (TMember)>::type::property_type>::value, "left and right must result in the same type.");

	std::shared_ptr<ISqlPredicateBuilder> r;

	if (std::is_member_function_pointer<TMember>::value)
	{
		r = std::make_shared<GetterMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}
	else
	{
		r = std::make_shared<FieldMemberExpressionSqlPredicateBuilder<TEntity, TMember>>(right);
	}

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::make_shared<BinaryExpressionSqlPredicateBuilder>(BinaryOperators::GreaterThanOrEqualTo, left.GetSqlPredicateBuilder(), r);

	Predicate<TEntity> result(predicateBuilder);

	return result;
}

template <typename TEntity, typename TProperty>
static Predicate<TEntity> operator >=(const Expression<TEntity, TProperty> &left, const Expression<TEntity, TProperty> &right)
{
	Predicate<TEntity> result(BinaryOperators::GreaterThanOrEqualTo, left, right);

	return result;
}
