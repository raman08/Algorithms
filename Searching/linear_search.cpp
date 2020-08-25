#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/*
For proper expalaniation:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week4_divide_and_conquer/Study_Material/linear_search.md
*/

int linear_search(vector<int>& arr, int key) {

	for (int i = 0; i < arr.size(); i++) {

		if (arr[i] == key)
			return i;

	}

	return INT_MIN;

}

int main() {

	vector<int> arr = {1, 2, 3, 4, 5};

	cout << linear_search(arr, 4) << endl;

}