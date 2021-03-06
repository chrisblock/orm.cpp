#pragma once

#include "ISqlPredicateBuilder.h"

#include <cstdint>
#include <memory>
#include <string>

#include "SqlPredicate.h"

class Guid;

class ConstantExpressionSqlPredicateBuilder : public ISqlPredicateBuilder
{
public:
	ConstantExpressionSqlPredicateBuilder(const std::int8_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::int8_t> &value);
	ConstantExpressionSqlPredicateBuilder(const std::uint8_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::uint8_t> &value);
	ConstantExpressionSqlPredicateBuilder(const std::int16_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::int16_t> &value);
	ConstantExpressionSqlPredicateBuilder(const std::uint16_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::uint16_t> &value);
	ConstantExpressionSqlPredicateBuilder(const std::int32_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::int32_t> &value);
	ConstantExpressionSqlPredicateBuilder(const std::uint32_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::uint32_t> &value);
	ConstantExpressionSqlPredicateBuilder(const std::int64_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::int64_t> &value);
	ConstantExpressionSqlPredicateBuilder(const std::uint64_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::uint64_t> &value);
	ConstantExpressionSqlPredicateBuilder(const float &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<float> &value);
	ConstantExpressionSqlPredicateBuilder(const double &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<double> &value);
	ConstantExpressionSqlPredicateBuilder(const bool &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<bool> &value);
	ConstantExpressionSqlPredicateBuilder(const std::string &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::string> &value);
	ConstantExpressionSqlPredicateBuilder(const std::wstring &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::wstring> &value);
	ConstantExpressionSqlPredicateBuilder(const Guid &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<Guid> &value);
	ConstantExpressionSqlPredicateBuilder(const std::tm &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::tm> &value);
	ConstantExpressionSqlPredicateBuilder(const ConstantExpressionSqlPredicateBuilder &other);
	virtual ~ConstantExpressionSqlPredicateBuilder();

	ConstantExpressionSqlPredicateBuilder &operator =(const ConstantExpressionSqlPredicateBuilder &other);

	virtual SqlPredicate Build(const MappingRegistry &) const override;

private:
	SqlPredicate _predicate;
};
