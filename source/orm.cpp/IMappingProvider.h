#pragma once

#include <string>

class IMappingProvider
{
public:
	virtual ~IMappingProvider();

	virtual std::string GetMappedType() const = 0;
};
