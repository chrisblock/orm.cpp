#pragma once

#include <memory>

#include "GenerationStrategy.h"
#include "IColumnMapper.h"

template <typename TEntity>
class IdColumnSpecification
{
public:
	IdColumnSpecification() :
		  _generationStrategy(GenerationStrategy::Assigned)
	{
	};

	~IdColumnSpecification()
	{
	};

	bool IsSpecified() const
	{
		return (_columnMapper != nullptr);
	};

	void SetColumnMapper(const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper)
	{
		_columnMapper = columnMapper;
	};

	std::shared_ptr<IColumnMapper<TEntity>> GetColumnMapper() const
	{
		return _columnMapper;
	};

	void SetGenerationStrategy(GenerationStrategy strategy)
	{
		_generationStrategy = strategy;
	};

	GenerationStrategy GetGenerationStrategy() const
	{
		return _generationStrategy;
	};

private:
	GenerationStrategy _generationStrategy;
	std::shared_ptr<IColumnMapper<TEntity>> _columnMapper;
};
