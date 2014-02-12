#pragma once

#include <string>

#define MEMBER_FIELD(T, TProperty, variable)			TProperty (T ## ::* ## variable)

template <typename T, typename TProperty>
class member_types
{
public:
	member_types() = delete;
	member_types(const member_types &other) = delete;
	~member_types() = delete;

	typedef TProperty (T::*field);

	//typedef MEMBER_FIELD(T, TProperty, field);

	// it appears that setter and const_setter are interchangeable
	//    that is, the const qualifier on the parmaeter is ignored as far as defining the member function pointer type goes
	//    so we will only allow one type to be used
	// typedef void (T::*setter)(TProperty);
	typedef void (T::*const_setter)(const TProperty);
	//typedef void (T::*reference_setter)(TProperty &);
	typedef void (T::*const_reference_setter)(const TProperty &);

	typedef TProperty (T::*getter)();
	typedef TProperty &(T::*reference_getter)();
	typedef TProperty (T::*const_getter)() const;
	typedef const TProperty &(T::*const_reference_getter)() const;

	static std::string to_string(field v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};

	/*
	static std::string to_string(setter v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};
	*/

	static std::string to_string(const_setter v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};

	/*
	static std::string to_string(reference_setter v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};
	*/

	static std::string to_string(const_reference_setter v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};

	static std::string to_string(getter v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};

	static std::string to_string(reference_getter v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};

	static std::string to_string(const_getter v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};

	static std::string to_string(const_reference_getter v)
	{
		const unsigned char *c = reinterpret_cast<const unsigned char *>(&v);

		return to_string(c, sizeof (v));
	};

private:
	static std::string to_string(const unsigned char *data, const int32_t length)
	{
		std::string result;

		for (int32_t i = 0; i < length; i++)
		{
			int32_t c = data[i];
			char hex[3] = {};

			::sprintf_s(hex, "%02X", c);

			result.append(hex);
		}

		return result;
	}
};
