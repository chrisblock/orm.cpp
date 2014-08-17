#pragma once

#include <cstdint>

namespace odbc
{
	class binary_data
	{
	public:
		binary_data();
		binary_data(_In_ std::uint8_t *data, _In_ const std::uint32_t length);
		binary_data(_In_ const binary_data &other);
		binary_data(binary_data &&other);
		virtual ~binary_data();

		binary_data &operator =(_In_ binary_data other);

		friend void swap(binary_data &left, binary_data &right);

		std::uint8_t *data() const;
		std::uint32_t length() const;

	private:
		// TODO: use a smart pointer to store this, like std::unique_ptr<std::uint8_t[]>
		std::unique_ptr<std::uint8_t[]>_data;
		std::uint32_t _length;
	};

	void swap(binary_data &left, binary_data &right);
};
