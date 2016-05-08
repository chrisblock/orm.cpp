#pragma once

#include "sql_column.h"
#include "sql_table.h"

namespace orm
{
	namespace sql
	{
		class join_clause
		{
		public:
			join_clause();
			join_clause(const join_clause &other);
			join_clause(join_clause &&other);
			virtual ~join_clause();

			join_clause &operator =(join_clause other);
			bool operator ==(const join_clause &other) const;
			bool operator !=(const join_clause &other) const;

			friend void swap(join_clause &left, join_clause &right);

			void SetIsOuterJoin(const bool isOuterJoin);
			bool IsOuterJoin() const;

			void SetSourceTable(const orm::sql::sql_table &sourceTable);
			orm::sql::sql_table &GetSourceTable();
			const orm::sql::sql_table &GetSourceTable() const;

			void SetSourceColumn(const orm::sql::sql_column &sourceColumn);
			orm::sql::sql_column &GetSourceColumn();
			const orm::sql::sql_column &GetSourceColumn() const;

			void SetDestinationTable(const orm::sql::sql_table &destinationTable);
			orm::sql::sql_table &GetDestinationTable();
			const orm::sql::sql_table &GetDestinationTable() const;

			void SetDestinationColumn(const orm::sql::sql_column &destinationColumn);
			orm::sql::sql_column &GetDestinationColumn();
			const orm::sql::sql_column &GetDestinationColumn() const;

		private:
			bool _isOuterJoin;
			orm::sql::sql_table _sourceTable;
			orm::sql::sql_table _destinationTable;
			orm::sql::sql_column _sourceColumn;
			orm::sql::sql_column _destinationColumn;
		};

		void swap(join_clause &left, join_clause &right);
	};
};
