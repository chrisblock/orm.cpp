#include "stdafx.h"

#include "TestSessionEntityMap.h"

TestSessionEntityMap::TestSessionEntityMap()
{
	Schema("dbo");

	Table("TestSessionTable");

	Id(&TestSessionEntity::_id, "Id")
		.GeneratedBy(GenerationStrategy::Assigned);

	Map(&TestSessionEntity::_column1, "Column1");
	Map(&TestSessionEntity::_column2, "Column2");
}

TestSessionEntityMap::~TestSessionEntityMap()
{
}
