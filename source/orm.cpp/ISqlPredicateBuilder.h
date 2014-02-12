#pragma once

class MappingRegistry;
class SqlPredicate;

class ISqlPredicateBuilder
{
public:
	virtual ~ISqlPredicateBuilder();

	virtual SqlPredicate Build(const MappingRegistry &registry) const = 0;
};
