#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

/*
For proper explaination:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week4_divide_and_conquer/Study_Material/binary_search.md
*/

int binary_search_recursive(vector<int> arr, int low, int high, int key) {

	int mid = low + floor( (high - low) / 2);

	if (high < low)
		return INT8_MIN;

	if (arr[mid] == key)
		return mid;

	else if (arr[mid] < key)
		return binary_search_recursive(arr, low, mid - 1, key);

	else if (arr[mid] > key)
		return binary_search_recursive(arr, mid + 1, high, key);

	else
		return INT16_MIN;

}

int binary_search_iterative(vector<int> arr, int key) {

	int low = 0;
	int high = arr.size();

	while (low <= high) {

		int mid  = low + floor((high - low) / 2);

		if (arr[mid] == key)
			return mid;

		else if (arr[mid] < key)
			low = mid + 1;

		else
			high = mid - 1;

	}

	return INT16_MIN;

}

int main() {

	vector<int> arr = {1, 2, 3, 4, 5};

	// cout << binary_search_iterative(arr, 3) << endl;

	cout << binary_search_recursive(arr, 0, arr.size(), 3) << endl;


}