#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
For refrence: (Hash Function)
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/2_Data-Structures/week4_hash_tables/Study_Material/hash_functions.md
*/
long long hash_function(string word, long long prime, long long cardinality) {

	int hash = 0;

	for (int i = word.size() -1; i >= 0; i--) {
		hash = (hash * cardinality + word[i]) % prime;
	}

	return hash;

}

/*
For refreance: (Rabin Karp ALgorithm)
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/2_Data-Structures/week4_hash_tables/Study_Material/robin_karps_algorithms.md
*/
vector<int> pre_compute_hash(string text,string t_substring, int pattren_size, long long prime, int cadinality) {

	vector<int> computed_hash(text.size() - pattren_size + 1);

	computed_hash[text.size() - pattren_size] = hash_function(t_substring, prime, cadinality);

	long long y = 1;

	for (int i = 1; i <= pattren_size; i++)
		y = (y * cadinality) % prime;

	for (int i = text.size() - pattren_size - 1; i >= 0; i--)
		computed_hash[i] = ((computed_hash[i + 1] * cadinality) + text[i] - (y * text[i + pattren_size])) % prime;

	return computed_hash;

}

vector<int> ribin_karp(string text, string pattern) {

	long long prime = 100000007;
	long long cadinality = 1;

	srand(time(0));

	while (cadinality > (prime - 1))
	{
		cadinality = 1 + rand() / ((RAND_MAX + 1u) + prime - 1);
	}

	int pattren_size = pattern.size();
	int text_size = text.size();

	vector<int> result;

	long long pattren_hash = hash_function(pattern, prime, cadinality);

	string t_substr = text.substr(text_size - pattren_size, pattren_size);

	auto computed_hash = pre_compute_hash(text, t_substr, pattren_size, prime, cadinality);

	for (int i = 0; i <= text_size - pattren_size; i++) {

		if ((computed_hash[i] == pattren_hash) &&  (text.substr(i, pattren_size).compare(pattern) == 0))

			result.push_back(i);

	}

	return result;

}

int main() {

	string text = "abababcab";
	string pattren = "ab";

	auto result = ribin_karp(text, pattren);

	for (auto x : result)
		cout << x << " ";

	cout << endl;

}