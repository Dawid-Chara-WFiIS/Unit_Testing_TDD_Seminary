#include "SomeMath.h"

TEST(TestGreatestCommonDivisor, TestTwoEvenNumbers)
{
	const auto found = greatestCommonDivisor(4, 2);
	EXPECT_TRUE(found == 2);
}