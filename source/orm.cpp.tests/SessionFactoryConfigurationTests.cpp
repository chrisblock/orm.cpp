#include "stdafx.h"

#include <SessionFactoryConfiguration.h>

#include "TestDatabaseConfiguration.h"

TEST(SessionFactoryConfigurationTests, DefaultConstructor_SetsDriverToEmptyString)
{
	SessionFactoryConfiguration configuration;

	EXPECT_EQ("", configuration.GetDriver());
}

TEST(SessionFactoryConfigurationTests, DefaultConstructor_SetsServerToEmptyString)
{
	SessionFactoryConfiguration configuration;

	EXPECT_EQ("", configuration.GetServer());
}

TEST(SessionFactoryConfigurationTests, DefaultConstructor_SetsDatabaseToEmptyString)
{
	SessionFactoryConfiguration configuration;

	EXPECT_EQ("", configuration.GetDatabase());
}

TEST(SessionFactoryConfigurationTests, DefaultConstructor_SetsUserNameToEmptyString)
{
	SessionFactoryConfiguration configuration;

	EXPECT_EQ("", configuration.GetUserName());
}

TEST(SessionFactoryConfigurationTests, DefaultConstructor_SetsPasswordToEmptyString)
{
	SessionFactoryConfiguration configuration;

	EXPECT_EQ("", configuration.GetPassword());
}

TEST(SessionFactoryConfigurationTests, DefaultConstructor_SetsIsTrustedConnectionToTrue)
{
	SessionFactoryConfiguration configuration;

	EXPECT_TRUE(configuration.IsTrusted());
}

TEST(SessionFactoryConfigurationTests, CopyConstructor_CopiesDriver)
{
	SessionFactoryConfiguration expected;

	expected.SetDriver("Driver");

	SessionFactoryConfiguration actual(expected);

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, CopyConstructor_CopiesServer)
{
	SessionFactoryConfiguration expected;

	expected.SetServer("Server");

	SessionFactoryConfiguration actual(expected);

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, CopyConstructor_CopiesDatabase)
{
	SessionFactoryConfiguration expected;

	expected.SetDatabase("Database");

	SessionFactoryConfiguration actual(expected);

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, CopyConstructor_CopiesUserName)
{
	SessionFactoryConfiguration expected;

	expected.SetUserName("UserName");

	SessionFactoryConfiguration actual(expected);

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, CopyConstructor_CopiesPassword)
{
	SessionFactoryConfiguration expected;

	expected.SetPassword("Password");

	SessionFactoryConfiguration actual(expected);

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, CopyConstructor_CopiesIsTrusted)
{
	SessionFactoryConfiguration expected;

	expected.SetTrusted(false);

	SessionFactoryConfiguration actual(expected);

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, AssignmentOperator_AssignsDriver)
{
	SessionFactoryConfiguration expected;

	expected.SetDriver("Driver");

	SessionFactoryConfiguration actual;

	actual = expected;

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, AssignmentOperator_AssignsServer)
{
	SessionFactoryConfiguration expected;

	expected.SetServer("Server");

	SessionFactoryConfiguration actual;

	actual = expected;

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, AssignmentOperator_AssignsDatabase)
{
	SessionFactoryConfiguration expected;

	expected.SetDatabase("Database");

	SessionFactoryConfiguration actual;

	actual = expected;

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, AssignmentOperator_AssignsUserName)
{
	SessionFactoryConfiguration expected;

	expected.SetUserName("UserName");

	SessionFactoryConfiguration actual;

	actual = expected;

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, AssignmentOperator_AssignsPassword)
{
	SessionFactoryConfiguration expected;

	expected.SetPassword("Password");

	SessionFactoryConfiguration actual;

	actual = expected;

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, AssignmentOperator_AssignsIsTrusted)
{
	SessionFactoryConfiguration expected;

	expected.SetTrusted(false);

	SessionFactoryConfiguration actual;

	actual = expected;

	EXPECT_EQ(expected.GetDriver(), actual.GetDriver());
}

TEST(SessionFactoryConfigurationTests, BuildConnectionString_EmptyDriver_ThrowsException)
{
	SessionFactoryConfiguration configuration;

	configuration.SetServer(TestDatabaseConfiguration::Server);
	configuration.SetDatabase(TestDatabaseConfiguration::Database);
	configuration.SetUserName(TestDatabaseConfiguration::Username);
	configuration.SetPassword(TestDatabaseConfiguration::Password);
	configuration.SetTrusted(TestDatabaseConfiguration::IsTrusted);

	EXPECT_THROW(configuration.BuildConnectionString(), std::exception);
}

TEST(SessionFactoryConfigurationTests, BuildConnectionString_EmptyServer_ThrowsException)
{
	SessionFactoryConfiguration configuration;

	configuration.SetDriver(TestDatabaseConfiguration::Driver);
	configuration.SetDatabase(TestDatabaseConfiguration::Database);
	configuration.SetUserName(TestDatabaseConfiguration::Username);
	configuration.SetPassword(TestDatabaseConfiguration::Password);
	configuration.SetTrusted(TestDatabaseConfiguration::IsTrusted);

	EXPECT_THROW(configuration.BuildConnectionString(), std::exception);
}

TEST(SessionFactoryConfigurationTests, BuildConnectionString_EmptyDatabase_ThrowsException)
{
	SessionFactoryConfiguration configuration;

	configuration.SetDriver(TestDatabaseConfiguration::Driver);
	configuration.SetServer(TestDatabaseConfiguration::Server);
	configuration.SetUserName(TestDatabaseConfiguration::Username);
	configuration.SetPassword(TestDatabaseConfiguration::Password);
	configuration.SetTrusted(TestDatabaseConfiguration::IsTrusted);

	EXPECT_THROW(configuration.BuildConnectionString(), std::exception);
}

TEST(SessionFactoryConfigurationTests, BuildConnectionString_IsTrustedIsFalseAndUserNameIsEmpty_ThrowsException)
{
	SessionFactoryConfiguration configuration;

	configuration.SetDriver(TestDatabaseConfiguration::Driver);
	configuration.SetServer(TestDatabaseConfiguration::Server);
	configuration.SetDatabase(TestDatabaseConfiguration::Database);
	configuration.SetPassword(TestDatabaseConfiguration::Password);
	configuration.SetTrusted(false);

	EXPECT_THROW(configuration.BuildConnectionString(), std::exception);
}

TEST(SessionFactoryConfigurationTests, BuildConnectionString_IsTrustedIsFalseAndPasswordIsEmpty_ThrowsException)
{
	SessionFactoryConfiguration configuration;

	configuration.SetDriver(TestDatabaseConfiguration::Driver);
	configuration.SetServer(TestDatabaseConfiguration::Server);
	configuration.SetDatabase(TestDatabaseConfiguration::Database);
	configuration.SetUserName(TestDatabaseConfiguration::Username);
	configuration.SetTrusted(false);

	EXPECT_THROW(configuration.BuildConnectionString(), std::exception);
}

TEST(SessionFactoryConfigurationTests, BuildConnectionString_IsTrustedIsTrueAndUserNameIsEmpty_DoesNotThrowException)
{
	SessionFactoryConfiguration configuration;

	configuration.SetDriver(TestDatabaseConfiguration::Driver);
	configuration.SetServer(TestDatabaseConfiguration::Server);
	configuration.SetDatabase(TestDatabaseConfiguration::Database);
	configuration.SetPassword(TestDatabaseConfiguration::Password);
	configuration.SetTrusted(true);

	EXPECT_NO_THROW(configuration.BuildConnectionString());
}

TEST(SessionFactoryConfigurationTests, BuildConnectionString_IsTrustedIsTureAndPasswordIsEmpty_DoesNotThrowException)
{
	SessionFactoryConfiguration configuration;

	configuration.SetDriver(TestDatabaseConfiguration::Driver);
	configuration.SetServer(TestDatabaseConfiguration::Server);
	configuration.SetDatabase(TestDatabaseConfiguration::Database);
	configuration.SetUserName(TestDatabaseConfiguration::Username);
	configuration.SetTrusted(true);

	EXPECT_NO_THROW(configuration.BuildConnectionString());
}
