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
	ConstantExpressionSqlPredicateBuilder(const int8_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<int8_t> &value);
	ConstantExpressionSqlPredicateBuilder(const uint8_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<uint8_t> &value);
	ConstantExpressionSqlPredicateBuilder(const int16_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<int16_t> &value);
	ConstantExpressionSqlPredicateBuilder(const uint16_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<uint16_t> &value);
	ConstantExpressionSqlPredicateBuilder(const int32_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<int32_t> &value);
	ConstantExpressionSqlPredicateBuilder(const uint32_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<uint32_t> &value);
	ConstantExpressionSqlPredicateBuilder(const int64_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<int64_t> &value);
	ConstantExpressionSqlPredicateBuilder(const uint64_t &value);
	ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<uint64_t> &value);
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

	virtual SqlPredicate Build(const MappingRegistry &) const;

private:
	SqlPredicate _predicate;
};
