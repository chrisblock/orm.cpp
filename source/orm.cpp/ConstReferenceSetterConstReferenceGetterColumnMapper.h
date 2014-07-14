#pragma once

#include "IColumnMapper.h"

#include <memory>
#include <string>

#include "IDataReader.h"
#include "IRecord.h"
#include "member_types.h"

template <typename TEntity, typename TProperty>
class ConstReferenceSetterConstReferenceGetterColumnMapper : public IColumnMapper<TEntity>
{
public:
	typedef typename member_types<TEntity, TProperty>::const_reference_setter const_reference_setter;
	typedef typename member_types<TEntity, TProperty>::const_reference_getter const_reference_getter;

	ConstReferenceSetterConstReferenceGetterColumnMapper(const_reference_setter setter, const_reference_getter getter, const std::string &columnName) :
		  _getter(getter)
		, _setter(setter)
		, _columnName(columnName)
	{
		_getterLocation = member_types<TEntity, TProperty>::to_string(_getter);
		_setterLocation = member_types<TEntity, TProperty>::to_string(_setter);
	};

	ConstReferenceSetterConstReferenceGetterColumnMapper(const ConstReferenceSetterConstReferenceGetterColumnMapper<TEntity, TProperty> &other) :
		  _getter(other._getter)
		, _setter(other._setter)
		, _columnName(other._columnName)
		, _getterLocation(other._getterLocation)
		, _setterLocation(other._setterLocation)
	{
	};

	virtual ~ConstReferenceSetterConstReferenceGetterColumnMapper()
	{
	};

	virtual std::string GetColumnName() const
	{
		return _columnName;
	};

	virtual void ReadPropertyValueFromDataReader(TEntity &entity, const std::shared_ptr<IDataReader> &reader) const
	{
		TProperty value;

		reader->Get(_columnName, value);

		((entity).*(_setter))(value);
	};

	virtual void WritePropertyValueToRecord(TEntity &entity, IRecord &record) const
	{
		TProperty value = ((entity).*(_getter))();

		record.SetColumn(_columnName, value);
	};

protected:
	virtual bool IsForMember(_In_ const type_info &type, _In_ const std::string &memberLocation) const
	{
		bool result = ((type == typeid (const_reference_getter)) && (_getterLocation == memberLocation))
			|| ((type == typeid (const_reference_setter)) && (_setterLocation == memberLocation));

		return result;
	};

private:
	std::string _getterLocation;
	std::string _setterLocation;
	std::string _columnName;
	const_reference_getter _getter;
	const_reference_setter _setter;
};
