#include <iostream>
#include <vector>

using namespace std;

/*
For better explaination:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week6_dynamic_programming2/Study_Material/knapsack_with_repetitions.md
*/

// Structure for the items.
struct Bag_Item {

	int value;
	int weight;

};

// Knapsack Function
int knapsack(int W, vector<Bag_Item> items) {

	// Vector contaning the max values of at each weight.
	vector<int> values(W + 1);

	values[0] = 0;

	// Go through all the weights
	for (int w = 1; w <= W; w++){

		// Initialzing the weight as 0
		values[w] = 0;

		// Go through each item
		for (int i = 0; i < items.size(); i++) {

			// If item weight is less the bag weight
			if (items[i].weight <= w) {

				// Computing the value of the bag after adding the item
				int val = values[w - items[i].weight] + items[i].value;

				// If value is greater then the value added before assigninng the value as new value.
				if (val > values[w])
					values[w] = val;

			}
		}
	}

	return values[W];

}

int main() {

	int n, W;
	cin >> W >> n;

	vector<Bag_Item> items(n);

	for (int i = 0; i < n; i++)
		cin >> items[i].value >> items[i].weight;

	cout << knapsack(W, items);

}