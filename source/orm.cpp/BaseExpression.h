#pragma once

#include <memory>

class ISqlPredicateBuilder;
class MappingRegistry;
class SqlPredicate;

class BaseExpression
{
public:
	BaseExpression();
	BaseExpression(const std::shared_ptr<ISqlPredicateBuilder> &predicateBuilder);
	BaseExpression(const BaseExpression &other);
	virtual ~BaseExpression();

	BaseExpression &operator =(const BaseExpression &other);

	virtual SqlPredicate GetSqlPredicate(const MappingRegistry &registry) const;

	virtual std::shared_ptr<ISqlPredicateBuilder> GetSqlPredicateBuilder() const;

private:
	std::shared_ptr<ISqlPredicateBuilder> _predicateBuilder;
};
