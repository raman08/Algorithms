#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

/*

For Refrence:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/2_Data-Structures/week3_priority_queues_and_disjoint_sets/Study_Material/heap_sort.md

*/
void heapify(vector<int>& array, int size, int index) {

	int max_index = index;

	int left_child_index = (2 * index) + 1;

	int right_child_index = (2 * index) + 2;

	if (left_child_index < size && array[left_child_index] > array[max_index])
		max_index = left_child_index;


	if (right_child_index < size && array[right_child_index] > array[max_index])
		max_index = right_child_index;

	if (max_index != index) {
		swap(array[index], array[max_index]);

		heapify(array, size, max_index);

	}
}


void build_heap(vector<int>& array) {

	int array_size = array.size();

	for (int i = floor((array_size / 2) - 1); i >= 0; i--)
		heapify(array, array.size(), i);

}

void heap_sort(vector<int>& array) {


	build_heap(array);

	for (int i = array.size() - 1; i >= 0; i--) {

		swap(array[0], array[i]);

		heapify(array, i, 0);

	}
}

int main() {

	vector<int> arr = {4, 435, 76, 2, 7, 67, 545, 2, 87, 3};

	cout << "Original Array: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;

	heap_sort(arr);

	cout << "Array after swapping: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;

	assert(is_sorted(arr.begin(), arr.end()));

}