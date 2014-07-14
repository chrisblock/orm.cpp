#pragma once

#define DECLARE_TEST_COLUMN_ENTITY(ColumnType) \
	class ColumnType ## _ColumnTestsEntity \
	{ \
	public: \
		ColumnType ## _ColumnTestsEntity(); \
		ColumnType ## _ColumnTestsEntity(const ColumnType ## _ColumnTestsEntity &other); \
		~ColumnType ## _ColumnTestsEntity(); \
	\
		ColumnType ## _ColumnTestsEntity &operator =(const ColumnType ## _ColumnTestsEntity &other); \
	\
		void SetId(const std::int32_t id); \
		std::int32_t GetId() const; \
	\
		void SetColumn(const ColumnType integer); \
		ColumnType GetColumn() const; \
	\
	private: \
		std::int32_t _id; \
		ColumnType _column; \
	};

#define IMPLEMENT_TEST_COLUMN_ENTITY(ColumnType, TypeDefault) \
	ColumnType ## _ColumnTestsEntity::ColumnType ## _ColumnTestsEntity() : \
		  _id(0) \
		, _column(TypeDefault) \
	{ \
	} \
	\
	ColumnType ## _ColumnTestsEntity::ColumnType ## _ColumnTestsEntity(const ColumnType ## _ColumnTestsEntity &other) : \
		  _id(other._id) \
		, _column(other._column) \
	{ \
	} \
	\
	ColumnType ## _ColumnTestsEntity::~ColumnType ## _ColumnTestsEntity() \
	{ \
	} \
	\
	ColumnType ## _ColumnTestsEntity &ColumnType ## _ColumnTestsEntity::operator =(const ColumnType ## _ColumnTestsEntity &other) \
	{ \
		if (this != &other) \
		{ \
			_id = other._id; \
			_column = other._column; \
		} \
	\
		return *this; \
	} \
	\
	void ColumnType ## _ColumnTestsEntity::SetId(const std::int32_t id) \
	{ \
		_id = id; \
	} \
	\
	std::int32_t ColumnType ## _ColumnTestsEntity::GetId() const \
	{ \
		return _id; \
	} \
	\
	void ColumnType ## _ColumnTestsEntity::SetColumn(const ColumnType column) \
	{ \
		_column = column; \
	} \
	\
	ColumnType ColumnType ## _ColumnTestsEntity::GetColumn() const \
	{ \
		return _column; \
	}
