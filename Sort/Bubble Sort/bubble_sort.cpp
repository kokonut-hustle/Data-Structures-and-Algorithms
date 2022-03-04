#include "bubble_sort.hpp"
#include <iostream>

// using namespace for fast coding
// but not good for practical projects
using namespace std;

namespace dsa
{
void bubble_sort(vector< int > &arr)
{
	if (arr.empty()) return;
	bool sorted = true;
	while (sorted)
	{
		sorted = false;
		for (int i = 0; i < arr.size() - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				sorted = true;
				swap(arr[i], arr[i + 1]);
			}
		}
	}
	return;
}

int bubble_sort_test()
{
	cout << endl << ">> Bubble sort test" << endl;
	vector< int > arr{10, 23, 3, 5, -192, -20, 0, 50, 5, -20, 0};
	cout << "unsorted array:" << endl;
	for (auto t : arr)
		cout << t << " ";
	cout << endl;
	bubble_sort(arr);
	cout << "sorted array:" << endl;
	for (auto t : arr)
		cout << t << " ";
	cout << endl;

	return 0;
}

} // namespace dsa
