#pragma once

#include "IMappingProvider.h"

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "member_types.h"
#include "IdColumnBuilder.h"
#include "IdColumnSpecification.h"
#include "IRecord.h"
#include "IColumnMapper.h"
#include "FieldColumnMapper.h"
#include "ConstReferenceSetterGetterColumnMapper.h"
#include "ConstReferenceSetterConstGetterColumnMapper.h"
#include "ConstReferenceSetterReferenceGetterColumnMapper.h"
#include "ConstReferenceSetterConstReferenceGetterColumnMapper.h"
#include "ConstSetterGetterColumnMapper.h"
#include "ConstSetterConstGetterColumnMapper.h"
#include "ConstSetterReferenceGetterColumnMapper.h"
#include "ConstSetterConstReferenceGetterColumnMapper.h"
#include "ReferenceSetterGetterColumnMapper.h"
#include "ReferenceSetterConstGetterColumnMapper.h"
#include "ReferenceSetterReferenceGetterColumnMapper.h"
#include "ReferenceSetterConstReferenceGetterColumnMapper.h"
#include "SqlColumn.h"
#include "SqlProjection.h"

// TODO: perhaps write a method that verifies some basic things about this mapping, and call it upon registration (could prevent some classes of error)

template <typename TEntity>
class ClassMap : public IMappingProvider
{
public:
	ClassMap() :
		  IMappingProvider()
	{
	};

	ClassMap(const ClassMap<TEntity> &other) :
		  IMappingProvider(other)
		, _idColumnSpecification(other._idColumnSpecification)
		, _columnMappers(other._columnMappers)
		, _lobColumnMappers(other._lobColumnMappers)
	{
	};

	~ClassMap()
	{
	};

	ClassMap<TEntity> &operator =(const ClassMap<TEntity> &other)
	{
		if (this != &other)
		{
			_idColumnSpecification = other._idColumnSpecification;
			_columnMappers = other._columnMappers;
			_lobColumnMappers = other._lobColumnMappers;
		}

		return *this;
	};

	virtual std::string GetMappedType() const
	{
		std::string result = typeid (TEntity).name();

		return result;
	};

	SqlProjection GetProjection() const
	{
		SqlProjection result;

		std::function<void (const std::shared_ptr<IColumnMapper<TEntity>> &)> addColumnToProjection = [this, &result] (const std::shared_ptr<IColumnMapper<TEntity>> &column)
		{
			SqlColumn col;

			col.SetTable(GetTable());
			col.SetColumn(column->GetColumnName());

			result.AddProjection(col);
		};

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			addColumnToProjection(columnMapper);
		}

		std::for_each(_columnMappers.cbegin(), _columnMappers.cend(), addColumnToProjection);

		std::for_each(_lobColumnMappers.cbegin(), _lobColumnMappers.cend(), addColumnToProjection);

		return result;
	};

	template <typename TProperty>
	SqlColumn GetMappedColumn(typename member_types<TEntity, TProperty>::field field) const
	{
		std::string columnName;

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			if (columnMapper->IsForMember<TProperty>(field))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _columnMappers.cbegin(); (iter != _columnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(field))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _lobColumnMappers.cbegin(); (iter != _lobColumnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(field))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		SqlColumn result;

		result.SetTable(GetTable());
		result.SetColumn(columnName);

		return result;
	};

	template <typename TProperty>
	SqlColumn GetMappedColumn(typename member_types<TEntity, TProperty>::getter getter) const
	{
		std::string columnName;

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _columnMappers.cbegin(); (iter != _columnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _lobColumnMappers.cbegin(); (iter != _lobColumnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		SqlColumn result;

		result.SetTable(GetTable());
		result.SetColumn(columnName);

		return result;
	};

	template <typename TProperty>
	SqlColumn GetMappedColumn(typename member_types<TEntity, TProperty>::const_getter getter) const
	{
		std::string columnName;

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _columnMappers.cbegin(); (iter != _columnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _lobColumnMappers.cbegin(); (iter != _lobColumnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		SqlColumn result;

		result.SetTable(GetTable());
		result.SetColumn(columnName);

		return result;
	};

	template <typename TProperty>
	SqlColumn GetMappedColumn(typename member_types<TEntity, TProperty>::reference_getter getter) const
	{
		std::string columnName;

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _columnMappers.cbegin(); (iter != _columnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _lobColumnMappers.cbegin(); (iter != _lobColumnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		SqlColumn result;

		result.SetTable(GetTable());
		result.SetColumn(columnName);

		return result;
	};

	template <typename TProperty>
	SqlColumn GetMappedColumn(typename member_types<TEntity, TProperty>::const_reference_getter getter) const
	{
		std::string columnName;

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _columnMappers.cbegin(); (iter != _columnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _lobColumnMappers.cbegin(); (iter != _lobColumnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(getter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		SqlColumn result;

		result.SetTable(GetTable());
		result.SetColumn(columnName);

		return result;
	};

	IdColumnSpecification<TEntity> GetIdColumnSpecification() const
	{
		return _idColumnSpecification;
	};

	void ReadEntityFromDataReader(TEntity &entity, const std::shared_ptr<IDataReader> &reader)
	{
		std::shared_ptr<IColumnMapper<TEntity>> idMapper = _idColumnSpecification.GetColumnMapper();

		if (idMapper != nullptr)
		{
			idMapper->ReadPropertyValueFromDataReader(entity, reader);
		}

		for (auto iter = _columnMappers.cbegin(); iter != _columnMappers.cend(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &mapper = *iter;

			mapper->ReadPropertyValueFromDataReader(entity, reader);
		}

		for (auto iter = _lobColumnMappers.cbegin(); iter != _lobColumnMappers.cend(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &mapper = *iter;

			mapper->ReadPropertyValueFromDataReader(entity, reader);
		}
	};

	// TODO: revisit the decision of whether or not the entity parameter here should be const qualified
	void WriteEntityToRecord(TEntity &entity, IRecord &record)
	{
		record.SetSchema(GetSchema());

		record.SetTable(GetTable());

		record.SetIsIdAssigned(_idColumnSpecification.GetGenerationStrategy() == GenerationStrategy::Assigned);

		std::shared_ptr<IColumnMapper<TEntity>> idMapper = _idColumnSpecification.GetColumnMapper();

		idMapper->WritePropertyValueToRecord(entity, record);

		std::string idColumnName = idMapper->GetColumnName();

		record.AddIdColumn(idColumnName);

		for (auto iter = _columnMappers.cbegin(); iter != _columnMappers.cend(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &mapper = *iter;

			mapper->WritePropertyValueToRecord(entity, record);
		}

		for (auto iter = _lobColumnMappers.cbegin(); iter != _lobColumnMappers.cend(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &mapper = *iter;

			mapper->WritePropertyValueToRecord(entity, record);
		}
	};

protected:
	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(TProperty (TEntity::*field), const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<FieldColumnMapper<TEntity, TProperty>>(field, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(void (TEntity::*setter)(const TProperty), TProperty (TEntity::*getter)(), const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(void (TEntity::*setter)(const TProperty), TProperty (TEntity::*getter)() const, const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(void (TEntity::*setter)(const TProperty), TProperty &(TEntity::*getter)(), const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(void (TEntity::*setter)(const TProperty), const TProperty &(TEntity::*getter)() const, const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	/*
	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::getter getter, const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ReferenceSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::const_getter getter, const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ReferenceSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::reference_getter getter, const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ReferenceSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::const_reference_getter getter, const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ReferenceSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};
	*/

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(void (TEntity::*setter)(const TProperty &), TProperty (TEntity::*getter)(), const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(void (TEntity::*setter)(const TProperty &), TProperty (TEntity::*getter)() const, const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(void (TEntity::*setter)(const TProperty &), TProperty &(TEntity::*getter)(), const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(void (TEntity::*setter)(const TProperty &), const TProperty &(TEntity::*getter)() const, const std::string &columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	void Map(TProperty (TEntity::*field), const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<FieldColumnMapper<TEntity, TProperty>>(field, columnName);

		Map(columnMapper, isLobField);
	};

	template <typename TProperty>
	void Map(void (TEntity::*setter)(const TProperty), TProperty (TEntity::*getter)(), const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		Map(columnMapper, isLobField);
	};

	template <typename TProperty>
	void Map(void (TEntity::*setter)(const TProperty), TProperty (TEntity::*getter)() const, const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		Map(columnMapper, isLobField);
	};

	template <typename TProperty>
	void Map(void (TEntity::*setter)(const TProperty), TProperty &(TEntity::*getter)(), const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		Map(columnMapper, isLobField);
	};

	template <typename TProperty>
	void Map(void (TEntity::*setter)(const TProperty), const TProperty &(TEntity::*getter)() const, const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		Map(columnMapper, isLobField);
	};

	/*
	template <typename TProperty>
	void Map(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::getter getter, const std::string &columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ReferenceSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		if (isLobField == false)
		{
			_columnMappers.push_back(columnMapper);
		}
		else
		{
			_lobColumnMappers.push_back(columnMapper);
		}
	};

	template <typename TProperty>
	void Map(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::const_getter getter, const std::string &columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ReferenceSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		if (isLobField == false)
		{
			_columnMappers.push_back(columnMapper);
		}
		else
		{
			_lobColumnMappers.push_back(columnMapper);
		}
	};

	template <typename TProperty>
	void Map(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::reference_getter getter, const std::string &columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ReferenceSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		if (isLobField == false)
		{
			_columnMappers.push_back(columnMapper);
		}
		else
		{
			_lobColumnMappers.push_back(columnMapper);
		}
	};

	template <typename TProperty>
	void Map(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::const_reference_getter getter, const std::string &columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ReferenceSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		if (isLobField == false)
		{
			_columnMappers.push_back(columnMapper);
		}
		else
		{
			_lobColumnMappers.push_back(columnMapper);
		}
	};
	*/

	template <typename TProperty>
	void Map(void (TEntity::*setter)(const TProperty &), TProperty (TEntity::*getter)(), const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		Map(columnMapper, isLobField);
	};

	template <typename TProperty>
	void Map(void (TEntity::*setter)(const TProperty &), TProperty (TEntity::*getter)() const, const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		Map(columnMapper, isLobField);
	};

	template <typename TProperty>
	void Map(void (TEntity::*setter)(const TProperty &), TProperty &(TEntity::*getter)(), const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		Map(columnMapper, isLobField);
	};

	template <typename TProperty>
	void Map(void (TEntity::*setter)(const TProperty &), const TProperty &(TEntity::*getter)() const, const std::string &columnName, bool isLobField = false)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		Map(columnMapper, isLobField);
	};

	// TODO: implement somd kind of HasMany for childrens, and References for parents

private:
	void Map(const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper, const bool isLobField)
	{
		if (isLobField == false)
		{
			_columnMappers.push_back(columnMapper);
		}
		else
		{
			_lobColumnMappers.push_back(columnMapper);
		}
	};

	IdColumnSpecification<TEntity> _idColumnSpecification;
	std::vector<std::shared_ptr<IColumnMapper<TEntity>>> _columnMappers;
	std::vector<std::shared_ptr<IColumnMapper<TEntity>>> _lobColumnMappers;

	// TODO: is this a good idea? it makes some things easier and lets us ensure a single member isn't assigned to multiple columns...
	//       .....should probably make this a thing
	//std::map<std::string, std::shared_ptr<IColumnMapper<TEntity>>> _mappersByMemberLocation;
};
