#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace odbc
{
	class parameter;
};

namespace orm
{
	namespace sql
	{
		class statement
		{
		public:
			statement();
			statement(const statement &other);
			statement(statement &&other);
			virtual ~statement();

			statement &operator =(statement other);

			friend void swap(statement &left, statement &right);

			void SetSql(const std::string &sql);
			std::string GetSql() const;

			std::uint32_t GetNumberOfParameters() const;
			void AddParameter(const std::shared_ptr<odbc::parameter> &parameter);
			std::vector<std::shared_ptr<odbc::parameter>> &GetParameters();
			const std::vector<std::shared_ptr<odbc::parameter>> &GetParameters() const;

		private:
			std::string _sql;
			std::vector<std::shared_ptr<odbc::parameter>> _parameters;
		};

		void swap(statement &left, statement &right);
	}
}
