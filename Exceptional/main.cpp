// Exceptional.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sstream>
#include "RangeInt.h"
#include <iostream>

int main()
{
	auto errors{ 0 };
	auto testCase{ 0 };

	try
	{
		try
		{
			++testCase;
			RangeInt test(10, 15);
			test.setValue(5);// test value is out of bounds
		}
		catch (std::out_of_range &e)
		{
			++errors;
		}

		try
		{
			++testCase;
			RangeInt test(20, 25);
			test.setValue(22);// test value is within bounds
		}
		catch (std::out_of_range &e)
		{
			++errors;
		}

		try
		{
			++testCase;
			RangeInt test(4.5, 10);
			test.setValue(9.0);// test value is within bounds
		}
		catch (std::out_of_range &e)
		{
			++errors;
			std::cout << e.what() << std::endl;
		}

	}
	catch (...) // Catch-all block may be used to ensure that no uncaught exceptions can possibly escape from a function that offers nothrow exception guarantee.
	{
		++errors;
		throw;
	}
	return 0;
}

