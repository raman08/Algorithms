#include <iostream>

#define ll long long

using namespace std;

// For proper explaination : https : //github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/1_Algorithmic-Toolbox/week2_algorithmic_warmup/Study_Material/1-intro-3-GCD2.pdf


 ll gcd(int a, int b) {

	if (b == 0)
		return a;

	int r = a % b;

	return gcd(b, r);
}

int main() {

	int a, b;
	cin >> a >> b;

	cout << gcd(a, b);

}