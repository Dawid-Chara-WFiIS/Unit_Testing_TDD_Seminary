//#include "SomeMath.h"
//
//testing::AssertionResult AssertMutuallyPrime(int first, int second)
//{
//	const auto isMutuallyPrime = greatestCommonDivisor(first, second) == 1;
//	return isMutuallyPrime ? testing::AssertionSuccess() << first << " " << second << " are mutually prime"
//		: testing::AssertionFailure() << first << " " << second << " are not mutually prime";
//}
//
//TEST(GreatestCommonDivisorTest, MutuallyPrimeTest)
//{
//	/*EXPECT_PRED2(mutuallyPrime, 6, 4);
//	EXPECT_FALSE(mutuallyPrime(6, 5));*/
//	EXPECT_FALSE(AssertMutuallyPrime(6, 4));
//	EXPECT_FALSE(AssertMutuallyPrime(6, 5));
//}
//
