#include "SomeMath.h"

TEST(TestMutuallyPrime, TestMutuallyPrimeTrueMutuallyPrime)
{
	EXPECT_PRED2(mutuallyPrime, 6, 4);
	EXPECT_FALSE(mutuallyPrime(6, 5));
}