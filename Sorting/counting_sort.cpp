#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/*
For better explaination:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week4_divide_and_conquer/Study_Material/Counting_Sort.md
*/

// Function performing counting sort
void counting_sort(vector<int>& arr) {

	// Finding the range of the array
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());

	int range = max - min + 1;

	// Couning the elements
	vector<int> count;
	count.resize(range);

	// Arranging the element
	for (auto v : arr)
		count[v - min] += 1;

	vector<int> pos(range, 0);
	// pos[0] = 1;

	for (int j = 1; j < count.size(); j ++)
		count[j] += count[j - 1];

	for (int i = arr.size() - 1; i >= 0; i--) {
		pos[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;

	}

	for (int i = 0; i < arr.size(); i++)
		arr[i] = pos[i];

}

int main()
{

	vector<int> arr = {4, 9, 6, 2, 7, 2, 7, 2, 8, 3};

	cout << "Original Array: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;

	counting_sort(arr);

	cout << "Array after swapping: ";

	for (auto v : arr)
		cout << v << " ";

	cout << endl;
}
