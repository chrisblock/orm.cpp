#pragma once

#include "IMappingProvider.h"

#include <memory>
#include <string>
#include <vector>

#include "member_types.h"
#include "IdColumnBuilder.h"
#include "IdColumnSpecification.h"
#include "Record.h"
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

template <typename TEntity>
class ClassMap : public IMappingProvider
{
public:
	ClassMap() :
		  _schemaName("dbo")
	{
	};

	ClassMap(const ClassMap<TEntity> &other) :
		  _schemaName(other._schemaName)
		, _tableName(other._tableName)
		, _idColumnSpecification(other._idColumnSpecification)
		, _columnMappers(other._columnMappers)
		, _lobColumnMappers(other._lobColumnMappers)
	{
	};

	~ClassMap()
	{
		_columnMappers.clear();
	};

	ClassMap<TEntity> &operator =(const ClassMap<TEntity> &other)
	{
		if (this != &other)
		{
			_schemaName = other._schemaName;
			_tableName = other._tableName;
			_idColumnSpecification = other._idColumnSpecification;
			_columnMappers = other._columnMappers;
			_lobColumnMappers = other._lobColumnMappers;
		}

		return *this;
	};

	std::string GetMappedType() const
	{
		std::string result = typeid (TEntity).name();

		return result;
	};

	std::string GetSchemaName() const
	{
		return _schemaName;
	};

	std::string GetTableName() const
	{
		return _tableName;
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

		result.SetTable(_tableName);
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

		result.SetTable(_tableName);
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

		result.SetTable(_tableName);
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

		result.SetTable(_tableName);
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

		result.SetTable(_tableName);
		result.SetColumn(columnName);

		return result;
	};

	template <typename TProperty>
	SqlColumn GetMappedColumn(typename member_types<TEntity, TProperty>::const_setter setter) const
	{
		std::string columnName;

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			if (columnMapper->IsForMember<TProperty>(setter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _columnMappers.cbegin(); (iter != _columnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(setter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _lobColumnMappers.cbegin(); (iter != _lobColumnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(setter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		SqlColumn result;

		result.SetTable(_tableName);
		result.SetColumn(columnName);

		return result;
	};

	/*
	template <typename TProperty>
	std::string GetMappedColumn(typename member_types<TEntity, TProperty>::reference_setter setter) const
	{
		std::string result;

		for (auto iter = _columnMappers.cbegin(); iter != _columnMappers.cend(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(setter))
			{
				result = columnMapper->GetColumnName();
				break;
			}
		}

		if (result.empty())
		{
			for (auto iter = _lobColumnMappers.cbegin(); iter != _lobColumnMappers.cend(); iter++)
			{
				const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

				if (columnMapper->IsForMember<TProperty>(setter))
				{
					result = columnMapper->GetColumnName();
					break;
				}
			}
		}

		return result;
	};
	*/

	template <typename TProperty>
	SqlColumn GetMappedColumn(typename member_types<TEntity, TProperty>::const_reference_setter setter) const
	{
		std::string columnName;

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			if (columnMapper->IsForMember<TProperty>(setter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _columnMappers.cbegin(); (iter != _columnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(setter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		for (auto iter = _lobColumnMappers.cbegin(); (iter != _lobColumnMappers.cend()) && columnName.empty(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &columnMapper = *iter;

			if (columnMapper->IsForMember<TProperty>(setter))
			{
				columnName = columnMapper->GetColumnName();
			}
		}

		SqlColumn result;

		result.SetTable(_tableName);
		result.SetColumn(columnName);

		return result;
	};

	IdColumnSpecification<TEntity> GetIdColumnSpecification() const
	{
		return _idColumnSpecification;
	};

	/*
	void GetMappedIdColumns(std::vector<std::string> &idColumns) const
	{
		std::shared_ptr<IColumnMapper<TEntity>> idMapper = _idColumnSpecification.GetColumnMapper();

		auto columnName = idMapper->GetColumnName();

		idColumns.push_back(columnName);
	};

	void GetNonIdMappedColumns(std::vector<std::string> &columns) const
	{
		for (auto iter = _columnMappers.cbegin(); iter != _columnMappers.cend(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &mapper = *iter;

			std::string columnName = mapper->GetColumnName();

			columns.push_back(columnName);
		}

		for (auto iter = _lobColumnMappers.cbegin(); iter != _lobColumnMappers.cend(); iter++)
		{
			const std::shared_ptr<IColumnMapper<TEntity>> &mapper = *iter;

			std::string columnName = mapper->GetColumnName();

			columns.push_back(columnName);
		}
	};

	void GetAllMappedColumns(std::vector<std::string> &columns) const
	{
		GetMappedIdColumns(columns);
		GetNonIdMappedColumns(columns);
	};
	*/

	void ReadIdFromDataReader(TEntity &entity, const std::shared_ptr<IDataReader> &reader)
	{
		std::shared_ptr<IColumnMapper<TEntity>> idMapper = _idColumnSpecification.GetColumnMapper();

		idMapper->ReadPropertyValueFromDataReader(entity, reader);
	};

	void ReadEntityFromDataReader(TEntity &entity, const std::shared_ptr<IDataReader> &reader)
	{
		ReadIdFromDataReader(entity, reader);

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
	void WriteEntityToRecord(TEntity &entity, Record &record)
	{
		record.SetSchema(_schemaName.c_str());

		record.SetTable(_tableName.c_str());

		if (_idColumnSpecification.GetGenerationStrategy() == GenerationStrategy::Assigned)
		{
			std::shared_ptr<IColumnMapper<TEntity>> idMapper = _idColumnSpecification.GetColumnMapper();

			idMapper->WritePropertyValueToRecord(entity, record);
		}

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
	void Schema(const char *schemaName)
	{
		_schemaName = schemaName;
	};

	void Table(const char *tableName)
	{
		_tableName = tableName;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::field field, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<FieldColumnMapper<TEntity, TProperty>>(field, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::const_setter setter, typename member_types<TEntity, TProperty>::getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::const_setter setter, typename member_types<TEntity, TProperty>::const_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::const_setter setter, typename member_types<TEntity, TProperty>::reference_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::const_setter setter, typename member_types<TEntity, TProperty>::const_reference_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	/*
	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ReferenceSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::const_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ReferenceSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::reference_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ReferenceSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::const_reference_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ReferenceSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};
	*/

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::const_reference_setter setter, typename member_types<TEntity, TProperty>::getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::const_reference_setter setter, typename member_types<TEntity, TProperty>::const_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::const_reference_setter setter, typename member_types<TEntity, TProperty>::reference_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	IdColumnBuilder<TEntity> Id(typename member_types<TEntity, TProperty>::const_reference_setter setter, typename member_types<TEntity, TProperty>::const_reference_getter getter, const char *columnName)
	{
		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<ConstReferenceSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TProperty>
	void Map(typename member_types<TEntity, TProperty>::field field, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<FieldColumnMapper<TEntity, TProperty>>(field, columnName);

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
	void Map(typename member_types<TEntity, TProperty>::const_setter setter, typename member_types<TEntity, TProperty>::getter getter, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ConstSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

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
	void Map(typename member_types<TEntity, TProperty>::const_setter setter, typename member_types<TEntity, TProperty>::const_getter getter, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ConstSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

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
	void Map(typename member_types<TEntity, TProperty>::const_setter setter, typename member_types<TEntity, TProperty>::reference_getter getter, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ConstSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

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
	void Map(typename member_types<TEntity, TProperty>::const_setter setter, typename member_types<TEntity, TProperty>::const_reference_getter getter, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ConstSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		if (isLobField == false)
		{
			_columnMappers.push_back(columnMapper);
		}
		else
		{
			_lobColumnMappers.push_back(columnMapper);
		}
	};

	/*
	template <typename TProperty>
	void Map(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::getter getter, const char *columnName, bool isLobField = false)
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
	void Map(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::const_getter getter, const char *columnName, bool isLobField = false)
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
	void Map(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::reference_getter getter, const char *columnName, bool isLobField = false)
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
	void Map(typename member_types<TEntity, TProperty>::reference_setter setter, typename member_types<TEntity, TProperty>::const_reference_getter getter, const char *columnName, bool isLobField = false)
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
	void Map(typename member_types<TEntity, TProperty>::const_reference_setter setter, typename member_types<TEntity, TProperty>::getter getter, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ConstReferenceSetterGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

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
	void Map(typename member_types<TEntity, TProperty>::const_reference_setter setter, typename member_types<TEntity, TProperty>::const_getter getter, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ConstReferenceSetterConstGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

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
	void Map(typename member_types<TEntity, TProperty>::const_reference_setter setter, typename member_types<TEntity, TProperty>::reference_getter getter, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ConstReferenceSetterReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

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
	void Map(typename member_types<TEntity, TProperty>::const_reference_setter setter, typename member_types<TEntity, TProperty>::const_reference_getter getter, const char *columnName, bool isLobField = false)
	{
		auto columnMapper = std::make_shared<ConstReferenceSetterConstReferenceGetterColumnMapper<TEntity, TProperty>>(setter, getter, columnName);

		if (isLobField == false)
		{
			_columnMappers.push_back(columnMapper);
		}
		else
		{
			_lobColumnMappers.push_back(columnMapper);
		}
	};

	template <typename TChildEntity>
	void HasMany(const std::vector<TChildEntity> &(TEntity::*childEntityCollectionGetter)() const, void (TEntity::*childEntityAdder)(const TChildEntity &), const char *childForeignKeyColumnName)
	{
		ChildRelationship<TEntity, TChildEntity> relationship(childEntityCollectionGetter, childEntityAdder, childForeignKeyColumnName);
	}

	template <typename TChildEntity>
	void HasMany(const std::vector<TChildEntity> &(TEntity::*childEntityCollectionGetter)() const, void (TEntity::*childEntityAdder)(const TChildEntity &), const char *parentColumnName, const char *childForeignKeyColumnName)
	{
		UNREFERENCED_PARAMETER(childEntityCollectionGetter);
		UNREFERENCED_PARAMETER(childEntityAdder);
		UNREFERENCED_PARAMETER(parentColumnName);
		UNREFERENCED_PARAMETER(childForeignKeyColumnName);
	}

private:
	std::string _schemaName;
	std::string _tableName;
	IdColumnSpecification<TEntity> _idColumnSpecification;
	std::vector<std::shared_ptr<IColumnMapper<TEntity>>> _columnMappers;
	std::vector<std::shared_ptr<IColumnMapper<TEntity>>> _lobColumnMappers;
};
