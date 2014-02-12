#include "stdafx.h"

#include <SessionFactoryBuilder.h>

#include <Query.h>
#include <Session.h>
#include <SessionFactory.h>
#include <SessionFactoryConfiguration.h>

#include "TestSessionEntity.h"
#include "TestSessionMappingRegistrar.h"

class SessionFactoryBuilderTests : public testing::Test
{
};

TEST_F(SessionFactoryBuilderTests, Test)
{
	SessionFactoryBuilder builder;

	TestSessionMappingRegistrar registrar;

	SessionFactoryConfiguration configuration;

	configuration.ConfigureMappingRegistry(registrar);

	SessionFactory factory = builder.Build(configuration);

	Session session = factory.Open();

	Query<TestSessionEntity> query = session.QueryOver<TestSessionEntity>();
}
