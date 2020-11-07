#define GTEST_LANG_CXX11 1
#include "gtest/gtest.h"

int greatestCommonDivisor(int first, int second)
{
	while (first != second)
		first > second ? first -= second : second -= first;

	return first; 
}

bool mutuallyPrime(int first, int second)
{
	const auto isMutuallyPrime = greatestCommonDivisor(first, second) == 1;
	return isMutuallyPrime ? testing::AssertionSuccess() << first << " " << second << " are mutually prime"
		: testing::AssertionSuccess() << first << " " << second << " are not mutually prime";
}

// Example1
TEST(TestGreatestCommonDivisor, TestTwoEvenNumbers)
{
	const auto found = greatestCommonDivisor(4, 2);
	EXPECT_TRUE(found == 2);
}

// Example 7
TEST(TestMutuallyPrime, TestMutuallyPrimeTrueMutuallyPrime)
{
	EXPECT_PRED2(mutuallyPrime, 6, 5);
}