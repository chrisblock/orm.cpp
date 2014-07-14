#pragma once

#include "IColumnMapper.h"

#include <memory>
#include <string>

#include "IDataReader.h"
#include "member_types.h"
#include "IRecord.h"

template <typename TEntity, typename TProperty>
class FieldColumnMapper : public IColumnMapper<TEntity>
{
public:
	typedef typename member_types<TEntity, TProperty>::field field;

	FieldColumnMapper(field field, const std::string &columnName) :
		  _field(field)
		, _columnName(columnName)
	{
		_fieldLocation = member_types<TEntity, TProperty>::to_string(_field);
	};

	FieldColumnMapper(const FieldColumnMapper<TEntity, TProperty> &other) :
		  _field(other._field)
		, _columnName(other._columnName)
		, _fieldLocation(other._fieldLocation)
	{
	};

	virtual ~FieldColumnMapper()
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

		((entity).*(_field)) = value;
	};

	virtual void WritePropertyValueToRecord(TEntity &entity, IRecord &record) const
	{
		TProperty value = ((entity).*(_field));

		record.SetColumn(_columnName, value);
	};

protected:
	virtual bool IsForMember(_In_ const type_info &type, _In_ const std::string &memberLocation) const
	{
		bool result = ((type == typeid (field)) && (_fieldLocation == memberLocation));

		return result;
	};

private:
	std::string _fieldLocation;
	std::string _columnName;
	field _field;
};
