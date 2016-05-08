#pragma once

#include "IColumnMapper.h"

#include <memory>
#include <string>

#include "decomposer.h"
#include "IDataReader.h"
#include "IRecord.h"
#include "memberizer.h"
#include "to_string.h"

template <typename TEntity, typename TField>
class FieldColumnMapper : public IColumnMapper<TEntity>
{
public:
	typedef TEntity entity_type;
	typedef typename std::result_of<member_types::decomposer (TField)>::type::property_type property_type;
	typedef typename std::result_of<member_types::memberizer (TField)>::type field_type;

	FieldColumnMapper(TField field, const std::string &columnName) :
		  _fieldLocation(member_types::to_string(field))
		, _columnName(columnName)
		, _field(std::mem_fn(field))
	{
	};

	FieldColumnMapper(const FieldColumnMapper &other) :
		  _fieldLocation(other._fieldLocation)
		, _columnName(other._columnName)
		, _field(other._field)
	{
	};

	virtual ~FieldColumnMapper()
	{
	};

	virtual std::string GetColumnName() const override
	{
		return _columnName;
	};

	virtual void ReadPropertyValueFromDataReader(entity_type &entity, const std::shared_ptr<IDataReader> &reader) const override
	{
		property_type &value = _field(entity);

		reader->Get(_columnName, value);
	};

	virtual void WritePropertyValueToRecord(entity_type &entity, IRecord &record) const override
	{
		property_type value = _field(entity);

		record.SetColumn(_columnName, value);
	};

protected:
	virtual bool IsForMember(_In_ const type_info &type, _In_ const std::string &memberLocation) const override
	{
		bool result = ((type == typeid (TField)) && (_fieldLocation == memberLocation));

		return result;
	};

private:
	std::string _fieldLocation;
	std::string _columnName;
	field_type _field;
};
