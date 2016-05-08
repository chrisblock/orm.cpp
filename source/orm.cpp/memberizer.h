#pragma once

#include <functional>

namespace member_types
{
	class memberizer
	{
	public:
		template <typename TMember>
		auto operator ()(TMember member)
		{
			return std::mem_fn(member);
		};
	};
}
