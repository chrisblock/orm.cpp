#include "stdafx.h"

#include <cstdint>
#include <tchar.h>

#include "TestDatabase.h"

int _tmain(std::int32_t argc, TCHAR *argv[])
{
	TestDatabase db("OdbcCppTestDatabase");

	::testing::InitGoogleTest(&argc, argv);

	::testing::GTEST_FLAG(shuffle) = true;

	static const TCHAR PAUSE[] = _T("-pause");

	bool pause = false;

	for (std::int32_t i = 1; i < argc; i++)
	{
		if (::_tcsicmp(argv[i], PAUSE) == 0)
		{
			pause = true;
		}
	}

	RUN_ALL_TESTS();

	if ((::_isatty(::_fileno(stdin))) && (pause == true))
	{
		::_tprintf_s(_T("Please press any key to continue."));

		int result = ::_gettch();

		result;
	}

	return EXIT_SUCCESS;
}
