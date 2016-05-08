#pragma once

#include <string>
#include <vector>

namespace orm
{
	namespace sql
	{
		class sql_column;
	};
};

namespace orm
{
	namespace sql
	{
		class projection
		{
		public:
			projection();
			projection(const projection &other);
			projection(projection &&other);
			virtual ~projection();

			projection &operator =(projection other);

			friend void swap(projection &left, projection &right);

			void AddProjection(const orm::sql::sql_column &column);
			std::vector<orm::sql::sql_column> &GetProjections();
			const std::vector<orm::sql::sql_column> &GetProjections() const;

		private:
			std::vector<orm::sql::sql_column> _projections;
		};

		void swap(projection &left, projection &right);
	};
};
