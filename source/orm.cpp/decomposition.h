#pragma once

namespace member_types
{
	template <typename TEntity, typename TProperty>
	class decomposition
	{
	public:
		typedef TEntity entity_type;
		typedef TProperty property_type;
	};
}
