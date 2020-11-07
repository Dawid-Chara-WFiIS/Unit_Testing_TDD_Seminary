#pragma once
#include <vector>
#include "gtest/gtest.h"


[[nodiscard]] double dotProduct(const std::vector<double>& left, const std::vector<double>& right);
[[nodiscard]] double calculatePiIterative(int iterations);
[[nodiscard]] int greatestCommonDivisor(int first, int second);
[[nodiscard]] bool mutuallyPrime(int first, int second);