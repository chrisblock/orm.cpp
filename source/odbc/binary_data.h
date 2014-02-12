#pragma once

namespace odbc
{
	class binary_data
	{
	public:
		binary_data(_In_ unsigned char *data, _In_ unsigned int length);
		binary_data(_In_ const binary_data &other);
		virtual ~binary_data();

		binary_data &operator =(_In_ const binary_data &other);

	private:
		unsigned char *_data;
		unsigned int _length;
	};
};
