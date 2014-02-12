#pragma once

#include <memory>
#include <string>

#include "member_types.h"

class IDataReader;
class Record;

template <typename TEntity>
class IColumnMapper
{
public:
	virtual ~IColumnMapper()
	{
	};

	virtual std::string GetColumnName() const = 0;

	virtual void ReadPropertyValueFromDataReader(TEntity &entity, const std::shared_ptr<IDataReader> &reader) const = 0;

	virtual void WritePropertyValueToRecord(TEntity &entity, Record &record) const = 0;

	template <typename TProperty>
	bool IsForMember(typename member_types<TEntity, TProperty>::field field) const
	{
		const type_info &type = typeid (field);

		std::string memberLocation = member_types<TEntity, TProperty>::to_string(field);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

	template <typename TProperty>
	bool IsForMember(typename member_types<TEntity, TProperty>::getter getter) const
	{
		const type_info &type = typeid (getter);

		std::string memberLocation = member_types<TEntity, TProperty>::to_string(getter);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

	template <typename TProperty>
	bool IsForMember(typename member_types<TEntity, TProperty>::const_getter getter) const
	{
		const type_info &type = typeid (getter);

		std::string memberLocation = member_types<TEntity, TProperty>::to_string(getter);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

	template <typename TProperty>
	bool IsForMember(typename member_types<TEntity, TProperty>::reference_getter getter) const
	{
		const type_info &type = typeid (getter);

		std::string memberLocation = member_types<TEntity, TProperty>::to_string(getter);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

	template <typename TProperty>
	bool IsForMember(typename member_types<TEntity, TProperty>::const_reference_getter getter) const
	{
		const type_info &type = typeid (getter);

		std::string memberLocation = member_types<TEntity, TProperty>::to_string(getter);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

	template <typename TProperty>
	bool IsForMember(typename member_types<TEntity, TProperty>::const_setter setter) const
	{
		const type_info &type = typeid (setter);

		std::string memberLocation = member_types<TEntity, TProperty>::to_string(setter);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

	template <typename TProperty>
	bool IsForMember(typename member_types<TEntity, TProperty>::reference_setter setter) const
	{
		const type_info &type = typeid (setter);

		std::string memberLocation = member_types<TEntity, TProperty>::to_string(setter);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

	template <typename TProperty>
	bool IsForMember(typename member_types<TEntity, TProperty>::const_reference_setter setter) const
	{
		const type_info &type = typeid (setter);

		std::string memberLocation = member_types<TEntity, TProperty>::to_string(setter);

		bool result = IsForMember(type, memberLocation);

		return result;
	};

protected:
	virtual bool IsForMember(_In_ const type_info &type, _In_ const std::string &memberLocation) const = 0;
};
