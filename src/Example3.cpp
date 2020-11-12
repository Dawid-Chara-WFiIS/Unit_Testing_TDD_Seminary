#include "SomeMath.h"

TEST(DotProductTest, DotProductWrongVectorsSizesTest)
{
	const auto vectorV = std::vector<double>({ 1, 2, 3 });
	const auto vectorU = std::vector<double>({ 1, 2 });
	EXPECT_THROW(dotProduct(vectorV, vectorU), std::invalid_argument);
}

