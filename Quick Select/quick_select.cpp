#include "quick_select.hpp"
#include <iostream>

// using namespace for fast coding
// but not good for practical projects
using namespace std;

namespace dsa
{
// k-th largest (smallest) element in an array (unsorted)
// Very often question in coding interview
// Consider nth_element in stl
// { 1   2   3   4   5   6 }
//   6th 5th 4th 3th 2nd 1st
// O(n) time on avarage, O(1) space

int kth_largest(vector< int > &arr, size_t k)
{
	if (k <= 0 || k > arr.size()) return -1;
	size_t lo = 0, hi = arr.size()-1;
	while (lo <= hi)
	{
		size_t mid = lo + (hi - lo) / 2;

		swap(arr[mid], arr[hi]);
		size_t l = lo, r = hi;
		while (l < r)
		{
			while (l < r && arr[l] < arr[hi])
				l++;
			while (l < r && arr[r] >= arr[hi])
				r--;
			swap(arr[l], arr[r]);
		}
		swap(arr[l], arr[hi]);
		if (hi - l + 1 == k)
			return arr[l];
		else if (hi - l + 1 > k)
			lo = l + 1;
		else
			k -= (hi - l), hi = l;
	}
	return -1;
}

int kth_largest_test()
{
	cout << endl << ">> Quick select test" << endl;
	vector< int > arr{3, 2, 9, 102, 32, 4, 102, 3, 3, 10, 95};
	for (size_t i = 1; i <= arr.size(); ++i)
	{
		vector< int > arr_temp = arr;
		cout << i << " largest element is " << kth_largest(arr_temp, i) << endl;
	}
	cout << "sorted array: ";
	sort(arr.begin(), arr.end());
	for (auto t : arr)
		cout << t << " ";
	cout << endl;

	return 0;
}

} // namespace dsa
