#pragma once

#include <string>

namespace orm
{
	namespace sql
	{
		class sql_table
		{
		public:
			sql_table();
			sql_table(const sql_table &other);
			sql_table(sql_table &&other);
			virtual ~sql_table();

			sql_table &operator =(sql_table other);
			bool operator ==(const sql_table &other) const;
			bool operator !=(const sql_table &other) const;

			friend void swap(sql_table &left, sql_table &right);

			void SetSchema(const std::string &schema);
			std::string GetSchema() const;

			void SetTable(const std::string &table);
			std::string GetTable() const;

		private:
			std::string _schema;
			std::string _table;
		};

		void swap(sql_table &left, sql_table &right);
	};
};
