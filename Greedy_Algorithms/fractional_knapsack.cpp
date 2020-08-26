#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/*
For better explaination:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week3_greedy_algorithms/Study_Material/fractional_knapsack.md
*/

// Structure Containning weight and values of the items
struct Bag_values{

	int weight;
	int value;

};

// Sort items by the value pre weight
bool compair_ratios(Bag_values a, Bag_values b) {
	return (a.value / a.weight) > (b.value / b.weight);
}

// Sorting the items
void sort_items(vector<Bag_values>& items) {
	sort(items.begin(), items.end(), compair_ratios);
}

// Knapsack function
int knapack(vector<Bag_values> items, int W) {

	// Sorting the items
	sort_items(items);

	// Total value we can get
	int v = 0;
	vector<int> ammounts(items.size(), 0);

	// For every item
	for (int i = 0; i < items.size(); i++) {

		// If weight become 0 return v
		if (W == 0)
			return v;

		// Find the ammount that can be filled in the bagpack
		int a = min(items[i].weight, W);

		// Adding the value of the that weight
		v += a * items[i].value / items[i].weight;

		// Reducing the weight of the items
		items[i].weight -= a;
		ammounts[i] += a;
		W -= a;

	}

	return v;

}


int main() {

	int W;
	cin >> W;

	int n;
	cin >> n;

	vector<Bag_values> items(n);

	for (int i = 0; i < n; i++) {
		cin >> items[i].weight >> items[i].value;
	}

	cout << knapack(items, W);

}