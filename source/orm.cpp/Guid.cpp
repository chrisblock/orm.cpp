#include "stdafx.h"

#include "Guid.h"

#include <atlbase.h>
#include <cstring>

const Guid Guid::Empty = Guid(GUID_NULL);
const char Guid::_guidPattern[] = "%08lx-%04hx-%04hx-%02hx%02hx-%02hx%02hx%02hx%02hx%02hx%02hx";

Guid Guid::NewGuid()
{
	GUID guid;
	if (::CoCreateGuid(&guid) != RPC_S_OK)
	{
		std::exception e("Couldn't create a new GUID.");

		throw e;
	}

	return Guid(guid);
}

Guid Guid::GuidComb()
{
	// in order to stay consistent to the .NET implementation of GuidComb, we need the
	// number of days between 1/1/1900 and 1/1/1970 to correct for CTime's badness
	//const ULONGLONG millsecondsBeforeEpoch = 2208988800000UL;
	const ULONG daysBeforeEpoch = 25567UL;

	SYSTEMTIME systemTimeCurrent;
	::GetLocalTime(&systemTimeCurrent);

	SYSTEMTIME systemTimeEpoch = { 1970, 1, 4, 1, 0, 0, 0, 0 };

	FILETIME fileTimeCurrent = {};
	FILETIME fileTimeEpoch = {};

	if ((::SystemTimeToFileTime(&systemTimeCurrent, &fileTimeCurrent) != TRUE) || (::SystemTimeToFileTime(&systemTimeEpoch, &fileTimeEpoch) != TRUE))
	{
		std::exception e("SystemTimeToFileTime call failed.");

		throw e;
	}

	ULARGE_INTEGER largeIntegerCurrent;

	largeIntegerCurrent.LowPart = fileTimeCurrent.dwLowDateTime;
	largeIntegerCurrent.HighPart = fileTimeCurrent.dwHighDateTime;

	ULARGE_INTEGER largeIntegerEpoch;

	largeIntegerEpoch.LowPart = fileTimeEpoch.dwLowDateTime;
	largeIntegerEpoch.HighPart = fileTimeEpoch.dwHighDateTime;

	ULONGLONG d = (largeIntegerCurrent.QuadPart - largeIntegerEpoch.QuadPart);
	d /= 24ULL;
	d /= 60ULL;
	d /= 60ULL;
	d /= 1000ULL;

	//CTime baseDate(1970, 1, 1, 0, 0, 0);
	//CTime now(time);

	//CTimeSpan days(now - baseDate);

	// fractional milliseconds aren't taken into account; they are lost to truncation when
	// converting to an integer type
	ULONGLONG msecs = (systemTimeCurrent.wHour * 3600000UL) + (systemTimeCurrent.wMinute * 60000UL) + (systemTimeCurrent.wSecond * 1000UL) + systemTimeCurrent.wMilliseconds;

	d += daysBeforeEpoch;
	ULONGLONG m = (ULONGLONG)(msecs / 3.333333);

	BYTE* daysArray = (BYTE *) &d;
	BYTE* msecsArray = (BYTE *) &m;

	Guid guid = Guid::NewGuid();

	GUID g = guid._guid;

	g.Data4[2] = daysArray[1];
	g.Data4[3] = daysArray[0];

	g.Data4[4] = msecsArray[3];
	g.Data4[5] = msecsArray[2];
	g.Data4[6] = msecsArray[1];
	g.Data4[7] = msecsArray[0];

	return Guid(g);
}

Guid Guid::Parse(const char *str)
{
	GUID guid = GUID_NULL;

	if (str != __nullptr)
	{
		// Microsoft's implementation of scanf does not support %hhx for reading unsigned chars
		// if it did, this would be super easy

		// as it is, if we just read into &guid.Data4[i], it technically works,
		// except that it corrupts the stack around the end of guid.Data4

		USHORT one, two, three, four, five, six, seven, eight;
		::scanf_s(str, _guidPattern
			, &guid.Data1
			, &guid.Data2
			, &guid.Data3
			, &one
			, &two
			, &three
			, &four
			, &five
			, &six
			, &seven
			, &eight);

		guid.Data4[0] = (BYTE)one;
		guid.Data4[1] = (BYTE)two;
		guid.Data4[2] = (BYTE)three;
		guid.Data4[3] = (BYTE)four;
		guid.Data4[4] = (BYTE)five;
		guid.Data4[5] = (BYTE)six;
		guid.Data4[6] = (BYTE)seven;
		guid.Data4[7] = (BYTE)eight;
	}

	Guid result(guid);

	return result;
}

//TODO: TryParse
/*
#define IsDigit(c) (((c) >= _T('0')) && ((c) <= _T('9')))

#define IsHexDigit(c) (IsDigit(c) || (((c) >= _T('a')) && ((c) <= _T('f'))) || (((c) >= _T('A')) && ((c) <= _T('F'))))

#define IsDashPosition(i) (((i) == 8) || ((i) == 13) || ((i) == 18) || ((i) == 23))

BOOL Guid::TryParse(LPCTSTR str, Guid &result)
{
	BOOL success = FALSE;
	result = GUID_NULL;

	if (str != __nullptr)
	{
		CString g(str);

		g.Trim();

		// length of Guid including dashes; other styles not yet supported
		if (g.GetLength() == 36)
		{
			BOOL go = TRUE;
			for (int i = 0; i < 36; i++)
			{
				TCHAR c = g.GetAt(i);

				if ((IsDashPosition(i) && (c != _T('-'))) || !IsHexDigit(c))
				{
					go = FALSE;
					break;
				}
			}

			if (go == TRUE)
			{
				// pattern: /^[0-9a-f]{8}-[0-9a-f]{4}-[1-4][0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}$/i

				result = Parse(str);
				success = TRUE;
			}
		}
	}

	return success;
}
*/

Guid::Guid() :
	  _guid(GUID_NULL)
{
}

Guid::Guid(const GUID &guid) :
	  _guid(guid)
{
}

Guid::Guid(const Guid &other) :
	  _guid(other._guid)
{
}

Guid::~Guid()
{
}

Guid &Guid::operator=(const Guid &other)
{
	if (this != &other)
	{
		_guid = other._guid;
	}

	return *this;
}

Guid &Guid::operator=(const GUID &other)
{
	_guid = other;

	return *this;
}

bool Guid::operator ==(const Guid &other) const
{
	BOOL eq = (_guid == other._guid);

	bool result = (eq == TRUE);

	return result;
}

bool Guid::operator ==(const GUID &other) const
{
	BOOL eq = (_guid == other);

	bool result = (eq == TRUE);

	return result;
}

bool Guid::operator !=(const Guid &other) const
{
	return !(*this == other);
}

bool Guid::operator !=(const GUID &other) const
{
	return !(*this == other);
}

bool Guid::operator <(const Guid &other) const
{
	bool result = ToString() < other.ToString();

	return  result;
}

bool Guid::operator <=(const Guid &other) const
{
	bool result = ToString() <= other.ToString();

	return  result;
}

bool Guid::operator >(const Guid &other) const
{
	bool result = ToString() > other.ToString();

	return  result;
}

bool Guid::operator >=(const Guid &other) const
{
	bool result = ToString() >= other.ToString();

	return  result;
}

Guid::operator GUID() const
{
	return _guid;
}

UINT Guid::GetVersion() const
{
	UINT result = (_guid.Data3 >> 12) & 0x000F;

	return result;
}

std::string Guid::ToString() const
{
	char buffer[37] = {};

	::sprintf_s(buffer, _guidPattern
		, _guid.Data1
		, _guid.Data2
		, _guid.Data3
		, _guid.Data4[0]
		, _guid.Data4[1]
		, _guid.Data4[2]
		, _guid.Data4[3]
		, _guid.Data4[4]
		, _guid.Data4[5]
		, _guid.Data4[6]
		, _guid.Data4[7]);

	std::string result(buffer);

	return result;
}

std::unique_ptr<std::uint8_t[]> Guid::ToByteArray() const
{
	std::unique_ptr<std::uint8_t[]> result = std::make_unique<std::uint8_t[]>(16);

	::memcpy(result.get(), &_guid, sizeof (GUID));

	return result;
}
