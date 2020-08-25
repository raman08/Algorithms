#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/*
For explaniation :
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week4_divide_and_conquer/Study_Material/selection_sorting.md
*/

// Function to sort the array
void selection_sort(vector<int>& arr) {

	// For every element in arr
	for (int i = 0; i < arr.size(); i++) {

		int min_index = i; // Find the index of minimun element

		// Fing the minimun element in arr[i + 1:]
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}

		// swapping the element
		swap(arr[i], arr[min_index]);

	}

}

int main() {

	vector<int> arr = {4, 435, 76, 2, 7, 2, 7, 2, 87, 3};

	cout << "Original Array: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;

	selection_sort(arr);

	cout << "Array after swapping: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;

}