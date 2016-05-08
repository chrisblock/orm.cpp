#pragma once

#include <vector>

namespace orm
{
	namespace sql
	{
		class constraint;
	}
}

namespace orm
{
	namespace sql
	{
		class where_clause
		{
		public:
			where_clause();
			where_clause(const where_clause &other);
			where_clause(where_clause &&other);
			~where_clause();

			where_clause &operator =(where_clause other);

			friend void swap(where_clause &left, where_clause &right);

			void add(const constraint &);
			const std::vector<constraint> get_constraints() const;

		private:
			std::vector<constraint> _constraints;
		};

		void swap(where_clause &left, where_clause &right);
	}
}
