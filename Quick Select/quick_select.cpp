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
// O(n) time, O(log(n)) space on avarage
// can optimize space by remove recursive (if asked)

int kthLargest(vector< int > &arr, size_t lo, size_t hi, size_t k)
{
	if (lo > hi) return -1;
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
		return kthLargest(arr, l + 1, hi, k);
	else
		return kthLargest(arr, lo, l, k - (hi - l));
}

int kthLargest_test()
{
	vector< int > arr{3, 2, 9, 102, 32, 4, 102, 3, 3, 10, 95};
	for (size_t i = 1; i <= arr.size(); ++i)
	{
		vector< int > arr_temp = arr;
		cout << i << " largest element is " << kthLargest(arr_temp, 0, arr.size() - 1, i) << endl;
	}
	cout << "sorted array: ";
	sort(arr.begin(), arr.end());
	for (auto t : arr)
		cout << t << " ";
	cout << endl;

	return 0;
}

} // namespace dsa
