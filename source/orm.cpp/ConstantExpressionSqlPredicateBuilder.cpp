#include "stdafx.h"

#include "ConstantExpressionSqlPredicateBuilder.h"

#include <parameter.h>

#include "Guid.h"

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const int8_t &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<int8_t> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const uint8_t &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<uint8_t> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const int16_t &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<int16_t> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const uint16_t &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<uint16_t> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const int32_t &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<int32_t> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const uint32_t &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<uint32_t> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const int64_t &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<int64_t> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const uint64_t &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<uint64_t> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const float &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<float> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const double &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<double> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const bool &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<bool> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::string &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::string> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::wstring &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::wstring> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const Guid &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	parameter->set(value);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<Guid> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	std::shared_ptr<GUID> guid;

	if (value != nullptr)
	{
		guid = std::make_shared<GUID>(*value);
	}

	parameter->set(guid);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::tm &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	odbc::DateTime dateTime = {};

	dateTime.year = (uint16_t) value.tm_year;
	dateTime.month = (uint16_t) value.tm_mon;
	dateTime.day = (uint16_t) value.tm_mday;
	dateTime.hour = (uint16_t) value.tm_hour;
	dateTime.second = (uint16_t) value.tm_sec;

	parameter->set(dateTime);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const std::shared_ptr<std::tm> &value) :
	  _predicate("?")
{
	std::shared_ptr<odbc::parameter> parameter = std::make_shared<odbc::parameter>();

	std::shared_ptr<odbc::DateTime> dateTime;

	if (value != nullptr)
	{
		odbc::DateTime empty = {};

		dateTime = std::make_shared<odbc::DateTime>(empty);

		dateTime->year = (uint16_t) value->tm_year;
		dateTime->month = (uint16_t) value->tm_mon;
		dateTime->day = (uint16_t) value->tm_mday;
		dateTime->hour = (uint16_t) value->tm_hour;
		dateTime->second = (uint16_t) value->tm_sec;
	}

	parameter->set(dateTime);

	_predicate.AddParameter(parameter);
}

ConstantExpressionSqlPredicateBuilder::ConstantExpressionSqlPredicateBuilder(const ConstantExpressionSqlPredicateBuilder &other) :
	  ISqlPredicateBuilder(other)
	, _predicate(other._predicate)
{
}

ConstantExpressionSqlPredicateBuilder::~ConstantExpressionSqlPredicateBuilder()
{
}

ConstantExpressionSqlPredicateBuilder &ConstantExpressionSqlPredicateBuilder::operator = (const ConstantExpressionSqlPredicateBuilder &other)
{
	if (this != &other)
	{
		_predicate = other._predicate;
	}

	return *this;
}

SqlPredicate ConstantExpressionSqlPredicateBuilder::Build(const MappingRegistry &) const
{
	// TODO: do not create the SqlPredicate object until right here
	return _predicate;
}
