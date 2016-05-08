#pragma once

#include <cstdint>
#include <string>

namespace member_types
{
	template <typename TMember>
	std::string to_string(TMember member)
	{
		static_assert(std::is_member_pointer<TMember>::value, "member must be a member pointer.");

		const std::int32_t length = sizeof (member);

		const std::uint8_t *data = reinterpret_cast<const std::uint8_t *>(&member);

		std::string result;

		for (std::int32_t i = 0; i < length; i++)
		{
			std::int32_t c = data[i];
			char hex[3] = {};

			::sprintf_s(hex, "%02X", c);

			result.append(hex);
		}

		return result;
	};
}
