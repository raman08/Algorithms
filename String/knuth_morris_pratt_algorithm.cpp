#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
For better understanding (Prefix Function):
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/4_Algorithms-on-Strings/week_3_knuth_morris_pratt_algorithm/Study_Material/prefix_function.md
*/
vector<int> compute_prefix(string text) {

	vector<int> prefix_array(text.size());

	prefix_array[0] = 0;
	int border = 0;

	for (int i = 1; i < text.size(); i++) {

		while (border > 0 && text[i] != text[border])
			border = prefix_array[border - 1];

		if (text[i] == text[border])
			border++;

		else
			border = 0;

		prefix_array[i] = border;
	}

	return prefix_array;

}

/*
For reference:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/4_Algorithms-on-Strings/week_3_knuth_morris_pratt_algorithm/Study_Material/knuth_morris_pratt_algorithm.md
*/
vector<int> knuth_moris_pratt(string text, string pattren) {

	string special_text = pattren + "$" + text;

	auto prefix_array = compute_prefix(special_text);

	vector<int> result;

	for (int i = pattren.size() + 1; i < special_text.size(); i++) {

		if (prefix_array[i] == pattren.size())
			result.push_back(i - (2 * pattren.size()));

	}

	return result;

}

int main() {

	string text = "abababcaab";
	string pattern = "ab";

	auto result = knuth_moris_pratt(text, pattern);

	for (auto r : result)
		cout << r << " ";

}