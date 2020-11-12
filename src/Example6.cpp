#include "SomeMath.h"


testing::AssertionResult AssertMutuallyPrimeFormattern(const char* first_expr, const char* second_expr, int first, int second)
{
	const auto gcd = greatestCommonDivisor(first, second);
	if (gcd == 1) return testing::AssertionSuccess();

	return testing::AssertionFailure() << first_expr << " and " << second_expr
		<< " (" << first << " and " << second << ") are not mutually prime, "
		<< "as they have a common divisor " << gcd;
}

TEST(GreatestCommonDivisorTest, MutuallyPrimeFormatternTest)
{
	const auto first = 4;
	//const auto first = 5;
	const auto second = 6;
	EXPECT_PRED_FORMAT2(AssertMutuallyPrimeFormattern, first, second);
}

