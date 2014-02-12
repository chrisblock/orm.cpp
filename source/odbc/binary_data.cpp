#include "stdafx.h"

#include "binary_data.h"

#include <cstdlib>

odbc::binary_data::binary_data(_In_ unsigned char *data, _In_ unsigned int length) :
	  _data(nullptr)
	, _length(length)
{
	_data = (unsigned char *) ::calloc(_length, sizeof (unsigned char));

	::memcpy_s(_data, _length, data, _length);
}

odbc::binary_data::binary_data(_In_ const odbc::binary_data &other)
{
	_length = other._length;

	_data = (unsigned char *) ::calloc(_length, sizeof (unsigned char));

	::memcpy_s(_data, _length, other._data, _length);
}

odbc::binary_data::~binary_data()
{
	::free(_data);
}

odbc::binary_data &odbc::binary_data::operator =(_In_ const odbc::binary_data &other)
{
	if (this != &other)
	{
		::free(_data);

		_length = other._length;

		_data = (unsigned char *) ::calloc(_length, sizeof (unsigned char));

		::memcpy_s(_data, _length, other._data, _length);
	}

	return *this;
}
