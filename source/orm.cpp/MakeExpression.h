#pragma once

#include "Expression.h"

#include "BinaryExpressionSqlPredicateBuilder.h"
#include "ConstantExpressionSqlPredicateBuilder.h"
#include "FieldMemberExpressionSqlPredicateBuilder.h"
#include "GetterMemberExpressionSqlPredicateBuilder.h"

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

template <typename TMember>
auto MakeExpression(TMember member)
{
	static_assert(std::is_member_pointer<TMember>::value, "member must be a member pointer.");

	typedef TMember member_type;
	typedef typename std::result_of<member_types::decomposer (member_type)>::type decomposition_type;
	typedef typename decomposition_type::entity_type entity_type;
	typedef typename decomposition_type::property_type property_type;

	std::shared_ptr<ISqlPredicateBuilder> predicateBuilder = std::is_member_function_pointer<member_type>::value
		? std::static_pointer_cast<ISqlPredicateBuilder>(std::make_shared<GetterMemberExpressionSqlPredicateBuilder<entity_type, member_type>>(member))
		: std::static_pointer_cast<ISqlPredicateBuilder>(std::make_shared<FieldMemberExpressionSqlPredicateBuilder<entity_type, member_type>>(member));

	Expression<entity_type, property_type> result(predicateBuilder);

	return result;
}

#ifndef _E
#define _E(x) (::MakeExpression(x))
#endif
