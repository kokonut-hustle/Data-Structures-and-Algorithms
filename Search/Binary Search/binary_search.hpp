#ifndef __BINARY_SEARCH_HPP__
#define __BINARY_SEARCH_HPP__

#include <vector>
namespace dsa
{
// Comparing double values directly is bad practice.
// Using a small epsilon value is the preferred approach
static const double EPS = 1e-6;

class BinarySearch
{
public:
	static double binarySearch(double lo, double hi, double target, std::function< double(double) > func);
	static std::vector< int >::iterator lowerBound(std::vector< int > &arr, int target);
};
int BinarySearch_test();
} // namespace dsa

#endif /* __BINARY_SEARCH_HPP__ */
