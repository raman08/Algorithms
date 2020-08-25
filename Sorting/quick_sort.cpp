#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/*
For better explaination:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week4_divide_and_conquer/Study_Material/quick_short.md
*/

// Function for the partioning the array
int partition(vector<int>& arr, int l, int r) {

	int x = arr[l];
	int j = l;

	for (int i = l + 1; i < r; i++) {
		if (arr[i] <= x) {
			j++;
			swap(arr[j], arr[i]);
		}
	}

	swap(arr[l], arr[j]);

	return j;

}

// Quick sort the array
void quick_sort(vector<int>& arr, int l, int r) {

	if (l >= r)
		return;

	int m = partition(arr, l, r);

	quick_sort(arr, l, m - 1);
	quick_sort(arr, m + 1, r);

}

// Randomazied quick sort
void randomaized_quick_sort(vector<int>& arr, int l, int r) {

	if (l >= r)
		return;

	// Generating the random povit
	srand(time(NULL));
	int k = rand() % (r - l + 1) + l;

	swap(arr[l], arr[k]);

	int m = partition(arr, l, r);

	randomaized_quick_sort(arr, l, m);
	randomaized_quick_sort(arr, m + 1, r);

}


int main() {

	vector<int> arr = {4, 435, 76, 2, 7, 2, 7, 2, 87, 3};

	cout << "Original Array: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;

	// randomaized_quick_sort(arr, 0, arr.size());

	quick_sort(arr, 0, arr.size());

	cout << "Array after swapping: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;

}