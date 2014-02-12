#pragma once

#include "GenerationStrategy.h"
#include "IdColumnSpecification.h"

template <typename TEntity>
class IdColumnBuilder
{
public:
	IdColumnBuilder(IdColumnSpecification<TEntity> &specification) :
		  _specification(specification)
	{
	};

	IdColumnBuilder(const IdColumnBuilder &other) :
		  _specification(other._specification)
	{
	};

	virtual ~IdColumnBuilder()
	{
	};

	IdColumnBuilder &operator =(const IdColumnBuilder &other)
	{
		if (this != &other)
		{
			_specification = other._specification;
		}

		return *this;
	};

	void GeneratedBy(const GenerationStrategy generationStrategy)
	{
		_specification.SetGenerationStrategy(generationStrategy);
	};

private:
	IdColumnSpecification<TEntity> &_specification;
};
