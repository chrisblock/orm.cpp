#pragma once

#include "IColumnMapper.h"

#include <memory>
#include <string>

#include "decomposer.h"
#include "IDataReader.h"
#include "IRecord.h"
#include "memberizer.h"
#include "to_string.h"

template <typename TEntity, typename TGetter, typename TSetter>
class GetterSetterColumnMapper : public IColumnMapper<TEntity>
{
public:
	typedef TEntity entity_type;
	typedef typename std::result_of<member_types::decomposer (TGetter)>::type::property_type property_type;
	typedef typename std::result_of<member_types::memberizer (TGetter)>::type getter_type;
	typedef typename std::result_of<member_types::memberizer (TSetter)>::type setter_type;

	GetterSetterColumnMapper(TGetter getter, TSetter setter, const std::string &columnName) :
		  _getterLocation(member_types::to_string(getter))
		, _setterLocation(member_types::to_string(setter))
		, _column(columnName)
		, _getter(getter)
		, _setter(setter)
	{
	};

	GetterSetterColumnMapper(const GetterSetterColumnMapper &other) :
		  _getterLocation(other._getterLocation)
		, _setterLocation(other._setterLocation)
		, _column(other._column)
		, _getter(other._getter)
		, _setter(other._setter)
	{
	};

	virtual ~GetterSetterColumnMapper()
	{
	};

	virtual std::string GetColumnName() const override
	{
		return _column;
	};

	virtual void ReadPropertyValueFromDataReader(TEntity &entity, const std::shared_ptr<IDataReader> &reader) const override
	{
		property_type value;

		reader->Get(_column, value);

		_setter(entity, value);
	};

	virtual void WritePropertyValueToRecord(TEntity &entity, IRecord &record) const override
	{
		property_type value = _getter(entity);

		record.SetColumn(_column, value);
	};

protected:
	virtual bool IsForMember(_In_ const type_info &type, _In_ const std::string &memberLocation) const override
	{
		bool result = ((type == typeid (TGetter)) && (_getterLocation == memberLocation))
			|| ((type == typeid (TSetter)) && (_setterLocation == memberLocation));

		return result;
	};

private:
	std::string _getterLocation;
	std::string _setterLocation;
	std::string _column;
	getter_type _getter;
	setter_type _setter;
};
