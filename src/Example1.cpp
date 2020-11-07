#include "SomeMath.h"

TEST(GreatestCommonDivisorTest, TwoEvenNumbersTest)
{
	const auto found = greatestCommonDivisor(4, 2);
	EXPECT_TRUE(found == 2);
}