#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/*
For details explaination:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week4_divide_and_conquer/Study_Material/merge_sort.md
*/

// Function to merge two array in sorted form
vector<int> merge(vector<int> arr_1, vector<int> arr_2) {

	vector<int> merged_arr;

	// Go through all the element till one of the array is empty.
	while (!arr_1.empty() && !arr_2.empty()) {

		int b = arr_1[0];
		int c = arr_2[0];

		if (b <= c) {
			merged_arr.push_back(b);
			arr_1.erase(arr_1.begin());

		}

		else {
			merged_arr.push_back(c);
			arr_2.erase(arr_2.begin());

		}

	}

	// If array is mot empty then add it to the end of resulted array
	if (!arr_1.empty()) {
		for (auto v : arr_1)
			merged_arr.push_back(v);
	}

	if (!arr_2.empty())
	{
		for (auto v : arr_2)
			merged_arr.push_back(v);
	}

	return merged_arr;

}

// Function to give subarray of the given array.
vector<int> slicing(vector <int> arr, int x, int y) {

	vector<int> result;

	for (int i = x; i <= y; i++) {
		result.push_back(arr[i]);
	}

	return result;

}

// Merged Sort Function
vector<int> merged_sort(vector<int>& arr) {

	// Return Condition
	if (arr.size() ==1)
		return arr;

	// Middle size of array.
	int mid = arr.size() / 2;

	// Slicing array into two equal parts
	auto first_half = slicing(arr, 0, mid - 1);
	auto second_half = slicing(arr, mid, arr.size() - 1);

	// Sorting the first half of array
	auto arr_1 = merged_sort(first_half);

	// Sorting the second half of array
	auto arr_2 = merged_sort(second_half);

	// Merging the two resulted array.
	auto sorted_array = merge(arr_1, arr_2);

	return sorted_array;

}

int main()
{

	vector<int> arr = {4, 435, 76, 2, 7, 2, 7, 2, 87, 3};

	cout << "Original Array: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;

	auto sorted_array = merged_sort(arr);

	cout << "Array after swapping: ";

	for (auto v : sorted_array)
		cout << v << " ";

	cout << endl;
}