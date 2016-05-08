#pragma once

#include "IMappingProvider.h"

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "IdColumnBuilder.h"
#include "IdColumnSpecification.h"
#include "IRecord.h"
#include "IColumnMapper.h"
#include "FieldColumnMapper.h"
#include "GetterSetterColumnMapper.h"
#include "sql_column.h"
#include "projection.h"

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

	virtual ~ClassMap()
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

	virtual std::string GetMappedType() const override
	{
		std::string result = typeid (TEntity).name();

		return result;
	};

	orm::sql::projection GetProjection() const
	{
		orm::sql::projection result;

		std::function<void (const std::shared_ptr<IColumnMapper<TEntity>> &)> addColumnToProjection = [this, &result] (const std::shared_ptr<IColumnMapper<TEntity>> &column)
		{
			orm::sql::sql_column col;

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

	template <typename TMember>
	orm::sql::sql_column GetMappedColumn(TMember member) const
	{
		std::string column;

		if (_idColumnSpecification.IsSpecified())
		{
			std::shared_ptr<IColumnMapper<TEntity>> columnMapper = _idColumnSpecification.GetColumnMapper();

			if (columnMapper->IsForMember(member))
			{
				column = columnMapper->GetColumnName();
			}
		}

		for (const auto &mapper : _columnMappers)
		{
			if (mapper->IsForMember(member))
			{
				column = mapper->GetColumnName();
			}
		}

		for (const auto &mapper : _lobColumnMappers)
		{
			if (mapper->IsForMember(member))
			{
				column = mapper->GetColumnName();
			}
		}

		orm::sql::sql_column result;

		result.SetTable(GetTable());
		result.SetColumn(column);

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

		for (const std::shared_ptr<IColumnMapper<TEntity>> &mapper : _columnMappers)
		{
			mapper->ReadPropertyValueFromDataReader(entity, reader);
		}

		for (const std::shared_ptr<IColumnMapper<TEntity>> &mapper : _lobColumnMappers)
		{
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

		for (const std::shared_ptr<IColumnMapper<TEntity>> &mapper : _columnMappers)
		{
			mapper->WritePropertyValueToRecord(entity, record);
		}

		for (const std::shared_ptr<IColumnMapper<TEntity>> &mapper : _lobColumnMappers)
		{
			mapper->WritePropertyValueToRecord(entity, record);
		}
	};

protected:
	template <typename TField>
	IdColumnBuilder<TEntity> Id(TField field, const std::string &column)
	{
		static_assert(std::is_member_pointer<TField>::value, "field must be a member pointer.");
		static_assert(std::is_member_function_pointer<TField>::value == false, "field must not be a member function pointer.");
		static_assert(std::is_same<TEntity, typename std::result_of<member_types::decomposer (TField)>::type::entity_type>::value, "field must be a member of the TEntity type.");

		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<FieldColumnMapper<TEntity, TField>>(field, column);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TGetter, typename TSetter>
	IdColumnBuilder<TEntity> Id(TGetter getter, TSetter setter, const std::string &column)
	{
		static_assert(std::is_member_function_pointer<TGetter>::value, "getter must be a member function pointer.");
		static_assert(std::is_member_function_pointer<TSetter>::value, "setter must be a member function pointer.");

		static_assert(std::is_same<TEntity, typename std::result_of<member_types::decomposer (TGetter)>::type::entity_type>::value, "getter must be a member of the TEntity type.");
		static_assert(std::is_same<TEntity, typename std::result_of<member_types::decomposer (TSetter)>::type::entity_type>::value, "setter must be a member of the TEntity type.");

		static_assert(std::is_same<
				  typename std::result_of<member_types::decomposer (TGetter)>::type::property_type
				, typename std::result_of<member_types::decomposer (TSetter)>::type::property_type
			>::value
			, "getter and setter must operate on the same property type.");

		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<GetterSetterColumnMapper<TEntity, TGetter, TSetter>>(getter, setter, column);

		_idColumnSpecification.SetColumnMapper(columnMapper);

		IdColumnBuilder<TEntity> idColumnBuilder(_idColumnSpecification);

		return idColumnBuilder;
	};

	template <typename TField>
	void Map(TField field, const std::string &column, bool isLobField = false)
	{
		static_assert(std::is_member_pointer<TField>::value, "field must be a member pointer.");
		static_assert(std::is_member_function_pointer<TField>::value == false, "field must not be a member function pointer.");
		static_assert(std::is_same<TEntity, typename std::result_of<member_types::decomposer (TField)>::type::entity_type>::value, "field must be a member of the TEntity type.");

		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<FieldColumnMapper<TEntity, TField>>(field, column);

		Map(columnMapper, isLobField);
	};

	template <typename TGetter, typename TSetter>
	void Map(TGetter getter, TSetter setter, const std::string &column, bool isLobField = false)
	{
		static_assert(std::is_member_function_pointer<TGetter>::value, "getter must be a member function pointer.");
		static_assert(std::is_member_function_pointer<TSetter>::value, "setter must be a member function pointer.");

		static_assert(std::is_same<TEntity, typename std::result_of<member_types::decomposer (TGetter)>::type::entity_type>::value, "getter must be a member of the TEntity type.");
		static_assert(std::is_same<TEntity, typename std::result_of<member_types::decomposer (TSetter)>::type::entity_type>::value, "setter must be a member of the TEntity type.");

		static_assert(std::is_same<
				  typename std::result_of<member_types::decomposer (TGetter)>::type::property_type
				, typename std::result_of<member_types::decomposer (TSetter)>::type::property_type
			>::value
			, "getter and setter must operate on the same property type.");

		std::shared_ptr<IColumnMapper<TEntity>> columnMapper = std::make_shared<GetterSetterColumnMapper<TEntity, TGetter, TSetter>>(getter, setter, column);

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
