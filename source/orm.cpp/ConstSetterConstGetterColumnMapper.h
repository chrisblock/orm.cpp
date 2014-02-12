#pragma once

#include "IColumnMapper.h"

#include <memory>
#include <string>

#include "IDataReader.h"
#include "member_types.h"
#include "Record.h"

template <typename TEntity, typename TProperty>
class ConstSetterConstGetterColumnMapper : public IColumnMapper<TEntity>
{
public:
	typedef typename member_types<TEntity, TProperty>::const_setter const_setter;
	typedef typename member_types<TEntity, TProperty>::const_getter const_getter;

	ConstSetterConstGetterColumnMapper(const_setter setter, const_getter getter, const char *columnName) :
		  _getter(getter)
		, _setter(setter)
		, _columnName(columnName)
	{
		_getterLocation = member_types<TEntity, TProperty>::to_string(_getter);
		_setterLocation = member_types<TEntity, TProperty>::to_string(_setter);
	};

	ConstSetterConstGetterColumnMapper(const ConstSetterConstGetterColumnMapper<TEntity, TProperty> &other) :
		  _getter(other._getter)
		, _setter(other._setter)
		, _columnName(other._columnName)
		, _getterLocation(other._getterLocation)
		, _setterLocation(other._setterLocation)
	{
	};

	virtual ~ConstSetterConstGetterColumnMapper()
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

	virtual void WritePropertyValueToRecord(TEntity &entity, Record &record) const
	{
		TProperty value = ((entity).*(_getter))();

		record.SetColumn(_columnName.c_str(), value);
	};

protected:
	virtual bool IsForMember(_In_ const type_info &type, _In_ const std::string &memberLocation) const
	{
		bool result = ((type == typeid (const_getter)) && (_getterLocation == memberLocation))
			|| ((type == typeid (const_setter)) && (_setterLocation == memberLocation));

		return result;
	};

private:
	std::string _getterLocation;
	std::string _setterLocation;
	std::string _columnName;
	const_getter _getter;
	const_setter _setter;
};
