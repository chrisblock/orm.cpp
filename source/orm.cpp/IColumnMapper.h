#pragma once

#include <memory>
#include <string>

#include "to_string.h"

class IDataReader;
class IRecord;

template <typename TEntity>
class IColumnMapper
{
public:
	typedef TEntity entity_type;

	virtual ~IColumnMapper()
	{
	};

	virtual std::string GetColumnName() const = 0;

	virtual void ReadPropertyValueFromDataReader(entity_type &entity, const std::shared_ptr<IDataReader> &reader) const = 0;

	virtual void WritePropertyValueToRecord(entity_type &entity, IRecord &record) const = 0;

	template <typename TMember>
	bool IsForMember(TMember member) const
	{
		const type_info &type = typeid (TMember);

		std::string memberLocation = member_types::to_string(member);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

protected:
	virtual bool IsForMember(_In_ const type_info &type, _In_ const std::string &memberLocation) const = 0;
};
