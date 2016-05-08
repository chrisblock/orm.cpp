#pragma once

class MappingRegistry;
class SqlPredicate;

class ISqlPredicateBuilder
{
public:
	virtual ~ISqlPredicateBuilder() = default;

	virtual SqlPredicate Build(const MappingRegistry &registry) const = 0;
};
