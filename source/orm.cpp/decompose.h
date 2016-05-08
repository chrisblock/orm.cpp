#pragma once

#include "decomposition.h"

namespace member_types
{
	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(TProperty(TEntity::*))
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(TProperty(TEntity::*)())
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(TProperty(TEntity::*)() const)
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(TProperty(TEntity::*)() volatile)
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(TProperty(TEntity::*)() const volatile)
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(TProperty &(TEntity::*)())
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(const TProperty &(TEntity::*)() const)
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(volatile TProperty &(TEntity::*)() volatile)
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(const volatile TProperty &(TEntity::*)() const volatile)
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(void (TEntity::*)(TProperty))
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(void (TEntity::*)(TProperty &))
	{
		return decomposition<TEntity, TProperty>();
	}

	template <typename TEntity, typename TProperty>
	decomposition<TEntity, TProperty> decompose(void (TEntity::*)(const TProperty &))
	{
		return decomposition<TEntity, TProperty>();
	}
}
