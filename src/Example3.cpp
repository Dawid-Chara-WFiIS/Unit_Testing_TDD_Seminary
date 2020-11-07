#include "SomeMath.h"

TEST(TestDotProduct, TestDotProductZerosVectors)
{
	const auto vectorV = std::vector<double>({ 0, 0, 0 });
	const auto vectorU = std::vector<double>({ 0, 0, 0 });
	const auto result = dotProduct(vectorV, vectorU);
	EXPECT_EQ(result, 0);
}

TEST(TestDotProduct, TestDotProductComparison)
{
	const auto vectorV = std::vector<double>({ 1, 1, 1 });
	const auto vectorU = std::vector<double>({ 1, 1, 1 });

	const auto vectorA = std::vector<double>({ 3, 3, 3 });
	const auto vectorB = std::vector<double>({ 3, 3, 3 });

	const auto resultVU = dotProduct(vectorV, vectorU);
	const auto resultAB = dotProduct(vectorA, vectorB);

	EXPECT_LT(resultVU, resultAB);
}


