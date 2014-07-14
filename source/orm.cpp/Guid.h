#pragma once

#include <string>
#include <memory>
#include <guiddef.h>

class Guid
{
public:
	static const Guid Empty;
	static Guid NewGuid();
	static Guid GuidComb();
	static Guid Parse(const char *str);

	Guid();
	Guid(const GUID &guid);
	Guid(const Guid &other);
	virtual ~Guid();

	Guid &operator =(const Guid &other);
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

	std::uint32_t GetVersion() const;
	std::string ToString() const;
	std::unique_ptr<std::uint8_t[]> ToByteArray() const;

private:
	static const char _guidPattern[];

	GUID _guid;
};
