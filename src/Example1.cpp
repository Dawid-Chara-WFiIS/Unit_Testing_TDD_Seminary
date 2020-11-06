#include "pch.h"

int greatestCommonDivisor(int first, int second)
{
	while (first != second)
		first > second ? first -= second : second -= first;

	return first; 
}


TEST(TestGreatestCommonDivisor, TestTwoPrimes)
{
	const auto found = greatestCommonDivisor(3, 7);
	EXPECT_TRUE(found == 1);
}