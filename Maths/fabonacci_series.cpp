#include <iostream>

#define ll long long

using namespace std;

/*

 For better explaination:
 https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week2_algorithmic_warmup/Study_Material/1_intro_2_fibonaccinumbers3.pdf

*/
ll fibonacci_series(int n) {

	int previous = 1;
	int current = 1;
	int next;

	if (n < 2){
		return 1;
	}

	for (int i = 2; i < n; i++) {

		next = previous + current;

		previous = current;
		current = next;

	}

	return next;

}

int main() {

	int n;
	cin >> n;

	cout << endl << fibonacci_series(n) << endl;

}