#pragma once

#include <cstdint>
#include <memory>

namespace odbc
{
	class binary_data
	{
	public:
		binary_data();
		binary_data(_In_reads_(length) std::uint8_t *data, _In_ const std::uint32_t length);
		binary_data(_In_ const binary_data &other);
		binary_data(_In_ binary_data &&other);
		virtual ~binary_data();

		binary_data &operator =(_In_ binary_data other);

		friend void swap(binary_data &left, binary_data &right);

		_Ret_bytecount_(_length)
		std::uint8_t *data() const;
		std::uint32_t length() const;

	private:
		std::unique_ptr<std::uint8_t[]> _data;
		std::uint32_t _length;
	};

	void swap(_Inout_ binary_data &left, _Inout_ binary_data &right);
};
