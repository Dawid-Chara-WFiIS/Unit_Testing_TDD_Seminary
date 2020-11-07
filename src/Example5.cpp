#define _USE_MATH_DEFINES
#include <math.h>
#include "SomeMath.h"

TEST(calculatePiIterativeTest, MillionIterationsTest)
{
	const auto iterations = static_cast<int>(std::pow(10, 6));
	const auto PI = calculatePiIterative(iterations);
	const auto abs_tolerance = std::pow(10, -4);
	EXPECT_NEAR(PI, M_PI, abs_tolerance);
	// EXPECT_DOUBLE_EQ(PI, M_PI); makes test failed
}

TEST(calculatePiIterativeTest, OneIterationCompareToAccurateTest)
{
	const auto iterations = 1;
	const auto PI = calculatePiIterative(iterations);

	EXPECT_PRED_FORMAT2(testing::DoubleLE, M_PI, PI);
}

