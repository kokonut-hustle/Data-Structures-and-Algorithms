#include "binary_search.hpp"
#include <iostream>

// using namespace for fast coding
// but not good for practical projects
using namespace std;

// This is a practical exercise for binary search
// With basic ds like vector can use stl function:
// binary_search(), upper_bound(), lower_bound()
// also consider lambda functions for comparator

namespace dsa
{
// binary search with function
// function must be non-decrease
// maybe non-increase, but need to config
double BinarySearch::binary_search(double lo, double hi, double target, function< double(double) > func)
{
	if (hi <= lo) std::invalid_argument("hi should be greater than lo");
	double mid;
	do
	{
		mid = lo + (hi - lo) / 2.0; // decrease of overflow chances
		double value = func(mid);

		if (value > target)
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	} while (hi - lo > EPS);

	return mid;
}

// binary search on sorted array
// should not implement by recursive (space optimize)
// return first element which equal to target
// if not found -> return upper bound
vector< int >::iterator BinarySearch::lower_bound(vector< int > &arr, int target)
{
	if (arr.back() < target) return arr.end();
	size_t n = arr.size();
	size_t l = 0, r = n - 1;
	while (l < r)
	{
		size_t mid = l + (r - l) / 2;
		if (arr[mid] == target)
			r = mid;
		else if (arr[mid] > target)
			r = mid;
		else
			l = mid + 1;
	}
	return arr.begin() + l;
}

int binary_search_test()
{
	cout << endl << ">> Binary search test" << endl;
	{
		// Ex 1: find sqrt(875)
		cout << "Test for binary search to find sqrt(875)" << endl;
		double lo = 0.0;
		double hi = 875.0;
		double target = 875.0;

		auto function = [](double x) -> double { return x * x; };
		double sqrtVal = BinarySearch::binary_search(lo, hi, target, function);
		std::cout << "sqrt(" << target << ") = " << sqrtVal << ", x^2 = " << (sqrtVal * sqrtVal) << std::endl;
	}

	{
		// Ex 2: binary search on a sorted array
		cout << "Test for binary search on a sorted array" << endl;
		vector< int > arr{1, 3, 4, 10, 10, 10, 10, 15, 35};
		int target = 12;

		for (auto t : arr)
			cout << t << " ";
		cout << endl << "target value: " << target << endl;

		auto result = BinarySearch::lower_bound(arr, target);
		(result == arr.end()) ? cout << "All of elements are less than target" << endl
				      : cout << "Lower bound is found at index: " << result - arr.begin() << endl;
	}

	return 0;
}
} // namespace dsa
