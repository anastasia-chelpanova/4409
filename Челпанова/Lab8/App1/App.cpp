#include "App.hpp"

#include "IO.hpp"
#include "Ways.hpp"
#include "Tests.hpp"

int Run()
{
	try {
		PrintMessage("The program determines the number of ways in which you can climb the stairs.");
		int n = ReadSteps();
		int result = CountWays(n);
		PrintResult(n, result);
		PrintResultToFile(n, result, "result_recursion.txt");
		RunTests();
	}
	catch (const std::exception& ex) {
		PrintError(ex.what());
		return 1;
	}
	return 0;
}
