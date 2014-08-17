#include "stdafx.h"

#include "binary_data.h"

#include <algorithm>
#include <cstdlib>

void odbc::swap(odbc::binary_data &left, odbc::binary_data &right)
{
	using std::swap;

	swap(left._data, right._data);
	swap(left._length, right._length);
}

odbc::binary_data::binary_data() :
	  _length(0)
{
}

odbc::binary_data::binary_data(_In_ std::uint8_t *data, _In_ const std::uint32_t length) :
	  _data(nullptr)
	, _length(length)
{
	_data = std::make_unique<std::uint8_t[]>(_length);

	::memcpy_s(_data.get(), _length, data, _length);
}

odbc::binary_data::binary_data(_In_ const odbc::binary_data &other) :
	  _data(nullptr)
	, _length(other._length)
{
	_data = std::make_unique<std::uint8_t[]>(_length);

	::memcpy_s(_data.get(), _length, other._data.get(), _length);
}

odbc::binary_data::binary_data(_In_ odbc::binary_data &&other) :
	  odbc::binary_data()
{
	swap(*this, other);
}

odbc::binary_data::~binary_data()
{
}

odbc::binary_data &odbc::binary_data::operator =(_In_ odbc::binary_data other)
{
	swap(*this, other);

	return *this;
}

std::uint8_t *odbc::binary_data::data() const
{
	return _data.get();
}

std::uint32_t odbc::binary_data::length() const
{
	return _length;
}
