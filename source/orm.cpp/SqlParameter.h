#pragma once

#include <memory>

namespace odbc
{
	class parameter;
};

class SqlParameter
{
public:
	SqlParameter();
	SqlParameter(const SqlParameter &other);
	~SqlParameter();

	SqlParameter &operator =(const SqlParameter &other);

	void SetSqlParameter(const std::shared_ptr<odbc::parameter> &parameter);
	std::shared_ptr<odbc::parameter> GetSqlParameter() const;

private:
	std::shared_ptr<odbc::parameter> _parameter;
};
