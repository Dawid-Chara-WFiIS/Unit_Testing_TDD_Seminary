#include "SomeMath.h"

double dotProduct(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != right.size())
		throw std::invalid_argument("Dot product can be calculated only for vectors with same size");

	auto ret = 0.0;

	for (unsigned idx = 0; idx < left.size(); idx++)
		ret += left[idx] * right[idx];
	return ret;
}

double calculatePiIterative(int iterations)
{
	double ret = 0;
	for (auto curIter = 1; curIter < iterations - 1; curIter++)
	{
		ret += std::pow(-1, curIter - 1) / (2 * curIter - 1);
	}
	ret *= 4;
	return ret;
}

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
		: testing::AssertionFailure() << first << " " << second << " are not mutually prime";
}