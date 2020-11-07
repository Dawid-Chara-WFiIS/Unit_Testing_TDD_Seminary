#define GTEST_LANG_CXX11 1
#include "gtest/gtest.h"
#include <vector>
#include <exception>

[[nodiscard]] double dotProduct(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != right.size())
		throw std::invalid_argument("Dot product can be calculated only for vectors with same size");

	auto ret = 0.0;

	for (unsigned idx = 0; idx < left.size(); idx++)
		ret += left[idx] * right[idx];
	return ret;
}

// Example 3
TEST(TestDotProduct, TestDotProductZerosVectors)
{
	const auto vectorV = std::vector<double>({ 0, 0, 0 });
	const auto vectorU = std::vector<double>({ 0, 0, 0 });
	const auto result = dotProduct(vectorV, vectorU);
	EXPECT_EQ(result, 0);
}

// Example 3
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

// Example 4
TEST(TestDotProduct, TestDotProductWrongVectorsSizes)
{
	const auto vectorV = std::vector<double>({ 1, 2, 3 });
	const auto vectorU = std::vector<double>({ 1, 2 });
	EXPECT_THROW(dotProduct(vectorV, vectorU), std::invalid_argument);
}

