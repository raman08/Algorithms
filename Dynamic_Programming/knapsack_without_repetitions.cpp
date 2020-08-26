#include <iostream>
#include <vector>

using namespace std;

/*
For better explaination:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week6_dynamic_programming2/Study_Material/knapsack_without_repetitions.md
*/


struct Bag_Item {

	int value;
	int weight;

};

// Function for contanning the knapsack
int knapsack(int W, vector<Bag_Item> items) {

	// Vector contanning the max value of the items at each weight
	vector<vector<int> > values(W + 1, vector<int>(items.size() + 1));

	// Initialzing the row and coloums of the values as zero.
	for (int i = 0; i < items.size(); i++)
		values[0][i] = 0;

	for (int i = 0; i < W + 1; i++)
		values[i][0] = 0;

	// For each items
	for (int i = 1; i <= items.size(); i++) {

		// For each weight
		for (int w = 1; w <= W; w++) {

			values[w][i] = values[w][i - 1];

			// If weight of the item if less then iterating weight
			if (items[i - 1].weight <= w) {

				// Conputing the value of the new added items
				int val = values[w - items[i - 1].weight][i - 1] + items[i - 1].value;

				// If computed value is greater then stored value change it.
				if (values[w][i] < val)
					values[w][i] = val;

			}
		}
	}

	return values[W][items.size()];

}

int main() {

	int n, W;
	cin >> W >> n;

	vector<Bag_Item> items(n);

	for (int i = 0; i < n; i++)
		cin >> items[i].value >> items[i].weight;

	cout << knapsack(W, items);

}