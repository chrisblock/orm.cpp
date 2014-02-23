#include "stdafx.h"

#include "IRecord.h"

IRecord::IRecord()
{
}

IRecord::IRecord(const IRecord &other)
{
	other;
}

IRecord::~IRecord()
{
}

IRecord &IRecord::operator =(const IRecord &other)
{
	if (this != &other)
	{
	}

	return *this;
}
