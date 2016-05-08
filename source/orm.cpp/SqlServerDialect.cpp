#include "stdafx.h"

#include "SqlServerDialect.h"

#include <algorithm>
#include <functional>

#include <parameter.h>

#include "from_clause.h"
#include "IRecord.h"
#include "sql_column.h"
#include "SqlPredicate.h"
#include "projection.h"
#include "statement.h"

SqlServerDialect::SqlServerDialect()
{
}

SqlServerDialect::SqlServerDialect(const SqlServerDialect &other)
{
	other;
}

SqlServerDialect::~SqlServerDialect()
{
}

SqlServerDialect &SqlServerDialect::operator =(const SqlServerDialect &other)
{
	if (this != &other)
	{
	}

	return *this;
}

// TODO: all of the implementation specific stuff (e.g. things not related to how the SQL itself is structured) need to be abstracted out;
//       probably need to implement the template method pattern for great success, and place these method into an abstract base class of destiny)

orm::sql::statement SqlServerDialect::BuildSelectStatement(const orm::sql::projection &projection, const orm::sql::from_clause &fromClause, const SqlPredicate &predicate) const
{
	orm::sql::statement result;

	std::string sql("SELECT ");

	const std::vector<orm::sql::sql_column> &columns = projection.GetProjections();

	std::function<void (const orm::sql::sql_column &str)> appendToSql = [&sql] (const orm::sql::sql_column &column) { sql.append(", "); sql.append(column.GetColumnString()); };

	std::vector<orm::sql::sql_column>::const_iterator start = columns.cbegin();

	if (start != columns.cend())
	{
		const orm::sql::sql_column &column = *start;

		sql.append(column.GetColumnString());

		++start;
	}

	std::for_each(start, columns.cend(), appendToSql);

	sql.append(" ");

	sql.append(fromClause.BuildSqlClause());

	if (predicate.IsEmpty() == false)
	{
		sql.append(" WHERE ");

		sql.append(predicate.GetPredicate());

		for (auto item : predicate)
		{
			result.AddParameter(item);
		}
	}

	result.SetSql(sql);

	return result;
}

orm::sql::statement SqlServerDialect::BuildInsertStatement(const IRecord &record) const
{
	orm::sql::statement result;

	std::string sql("INSERT INTO ");
	sql.append(record.GetSchema());
	sql.append(".");
	sql.append(record.GetTable());
	sql.append(" (");

	std::string values("VALUES (");

	const std::vector<std::shared_ptr<odbc::parameter>> &parameters = record.GetParameters();

	std::function<bool (const std::shared_ptr<odbc::parameter> &)> predicate;
	
	if (record.IsIdAssigned())
	{
		predicate = [] (const std::shared_ptr<odbc::parameter> &) { return true; };
	}
	else
	{
		predicate = [&record] (const std::shared_ptr<odbc::parameter> &p) { return (record.IsIdColumn(p->get_name()) == false); };
	}

	std::vector<std::shared_ptr<odbc::parameter>>::const_iterator iter = std::find_if(parameters.cbegin(), parameters.cend(), predicate);

	if (iter != parameters.cend())
	{
		const std::shared_ptr<odbc::parameter> &parameter = *iter;

		sql.append(parameter->get_name());

		values.append("?");

		result.AddParameter(parameter);
	}

	for (iter = std::find_if(++iter, parameters.cend(), predicate); iter != parameters.cend(); iter = std::find_if(++iter, parameters.cend(), predicate))
	{
		const std::shared_ptr<odbc::parameter> &parameter = *iter;

		sql.append(", ");
		sql.append(parameter->get_name());

		values.append(", ?");

		result.AddParameter(parameter);
	}

	sql.append(") ");
	sql.append(values);
	sql.append(")");

	result.SetSql(sql);

	return result;
}

orm::sql::statement SqlServerDialect::BuildUpdateStatement(const IRecord &record) const
{
	orm::sql::statement result;

	std::string sql("UPDATE ");
	sql.append(record.GetSchema());
	sql.append(".");
	sql.append(record.GetTable());
	sql.append(" SET ");

	std::string predicate(" WHERE ");
	std::vector<std::shared_ptr<odbc::parameter>> idParameters;

	const std::vector<std::shared_ptr<odbc::parameter>> &parameters = record.GetParameters();

	for (auto iter = parameters.cbegin(); iter != parameters.cend(); iter++)
	{
		const std::shared_ptr<odbc::parameter> &parameter = *iter;

		if (record.IsIdColumn(parameter->get_name()))
		{
			if (idParameters.empty() == false)
			{
				predicate.append(" AND ");
			}

			predicate.append(parameter->get_name());
			predicate.append(" = ?");

			idParameters.push_back(parameter);
		}
		else
		{
			if (result.GetNumberOfParameters() > 0)
			{
				sql.append(", ");
			}

			sql.append(parameter->get_name());
			sql.append(" = ?");

			result.AddParameter(parameter);
		}
	}

	sql.append(predicate);

	for (auto iter = idParameters.cbegin(); iter != idParameters.cend(); iter++)
	{
		const std::shared_ptr<odbc::parameter> &parameter = *iter;

		result.AddParameter(parameter);
	}

	result.SetSql(sql);

	return result;
}

orm::sql::statement SqlServerDialect::BuildDeleteStatement(const IRecord &record) const
{
	orm::sql::statement result;

	std::string sql("DELETE FROM ");
	sql.append(record.GetSchema());
	sql.append(".");
	sql.append(record.GetTable());
	sql.append(" WHERE ");

	const std::vector<std::shared_ptr<odbc::parameter>> &parameters = record.GetParameters();

	std::function<bool (const std::shared_ptr<odbc::parameter> &)> predicate = [&record] (const std::shared_ptr<odbc::parameter> &p) { return record.IsIdColumn(p->get_name()); };

	std::vector<std::shared_ptr<odbc::parameter>>::const_iterator iter = std::find_if(parameters.cbegin(), parameters.cend(), predicate);

	if (iter != parameters.cend())
	{
		const std::shared_ptr<odbc::parameter> &parameter = *iter;

		sql.append(parameter->get_name());

		sql.append(" = ?");

		result.AddParameter(parameter);
	}

	for (iter = std::find_if(++iter, parameters.cend(), predicate); iter != parameters.cend(); iter = std::find_if(++iter, parameters.cend(), predicate))
	{
		const std::shared_ptr<odbc::parameter> &parameter = *iter;

		sql.append(" AND ");
		sql.append(parameter->get_name());

		sql.append(" = ?");

		result.AddParameter(parameter);
	}

	result.SetSql(sql);

	return result;
}
