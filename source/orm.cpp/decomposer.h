#pragma once

#include "decompose.h"

namespace member_types
{
	class decomposer
	{
	public:
		template <typename TMember>
		auto operator ()(TMember member)
		{
			return member_types::decompose(member);
		};
	};
}
