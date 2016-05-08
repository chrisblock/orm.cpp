#pragma once

#include <string>
#include <vector>

#include "sql_table.h"

namespace orm
{
	namespace sql
	{
		class join_clause;
	};
};

namespace orm
{
	namespace sql
	{
		class from_clause
		{
		public:
			from_clause();
			from_clause(const from_clause &other);
			from_clause(from_clause &&other);
			virtual ~from_clause();

			from_clause &operator =(from_clause other);

			friend void swap(from_clause &left, from_clause &right);

			void SetMainTable(const orm::sql::sql_table &mainTable);
			orm::sql::sql_table &GetMainTable();
			const orm::sql::sql_table &GetMainTable() const;

			// TODO: add overloads for this
			void AddJoin(const orm::sql::join_clause &join);
			std::vector<orm::sql::join_clause> &GetJoins();
			const std::vector<orm::sql::join_clause> &GetJoins() const;

			std::string BuildSqlClause() const;

		private:
			orm::sql::sql_table _mainTable;
			std::vector<orm::sql::join_clause> _joins;
		};

		void swap(from_clause &left, from_clause &right);
	}
}
