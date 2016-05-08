#pragma once

#include <string>

namespace orm
{
	namespace sql
	{
		class sql_column
		{
		public:
			sql_column();
			sql_column(const sql_column &other);
			sql_column(sql_column &&other);
			virtual ~sql_column();

			sql_column &operator =(sql_column other);
			bool operator ==(const sql_column &other) const;
			bool operator !=(const sql_column &other) const;

			friend void swap(sql_column &left, sql_column &right);

			void SetTable(const std::string &table);
			std::string GetTable() const;

			void SetColumn(const std::string &column);
			std::string GetColumn() const;

			std::string GetColumnString() const;

		private:
			std::string _table;
			std::string _column;
		};

		void swap(sql_column &left, sql_column &right);
	};
};
