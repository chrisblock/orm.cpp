#pragma once

#include <cstdint>
#include <guiddef.h>
#include <memory>
#include <string>

class Guid
{
public:
	static const Guid Empty;
	static Guid NewGuid();
	static Guid GuidComb();
	static Guid Parse(const std::string &str);

	Guid();
	Guid(const GUID &guid);
	Guid(const Guid &other);
	Guid(Guid &&other);
	virtual ~Guid();

	Guid &operator =(Guid other);
	Guid &operator =(const GUID &other);
	bool operator ==(const Guid &other) const;
	bool operator ==(const GUID &other) const;
	bool operator !=(const Guid &other) const;
	bool operator !=(const GUID &other) const;
	bool operator <(const Guid &other) const;
	bool operator <=(const Guid &other) const;
	bool operator >(const Guid &other) const;
	bool operator >=(const Guid &other) const;

	operator GUID() const;

	friend void swap(Guid &left, Guid &right);

	std::uint32_t GetVersion() const;
	std::string ToString() const;
	std::unique_ptr<std::uint8_t[]> ToByteArray() const;

private:
	static const char _guidPattern[];

	GUID _guid;
};

void swap(Guid &left, Guid &right);
