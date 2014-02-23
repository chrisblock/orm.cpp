#include "stdafx.h"

#include <string>

#include "TestDatabaseConfiguration.h"

#include <SessionFactoryConfiguration.h>

const char TestDatabaseConfiguration::Driver[] = "{SQL Server Native Client 11.0}";
const char TestDatabaseConfiguration::Server[] = "(local)";
const char TestDatabaseConfiguration::Database[] = "OdbcCppTestDatabase";
const char TestDatabaseConfiguration::Username[] = "Username";
const char TestDatabaseConfiguration::Password[] = "Password";
const bool TestDatabaseConfiguration::IsTrusted = true;
