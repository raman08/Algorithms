#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

/*
For better explaination:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/3_Algorithms-on-Graphs/week5_spanning_trees/Study_Material/kruskals_algorithm.md
*/
class Disjoint_set {

	vector<int> parent;
	vector<int> rank;

	int MAX_SIZE;

public:

	Disjoint_set(int size) {

		MAX_SIZE = size;

		parent.resize(MAX_SIZE);
		rank.resize(MAX_SIZE);

	}

	void make_set(int u) {

		parent[u] = u;
		rank[u] = 0;

	}

	int find(int u) {

		if (u != parent[u])
			parent[u] =find(parent[u]);

		return parent[u];

	}

	void union_by_rank(int u, int v) {

		int u_id = find(u);
		int v_id = find(v);

		if (u_id >= 0 && v_id >= 0) {

			if (u_id == v_id)
				return;

			if (rank[u_id] > rank[v_id])
				parent[v_id] = u_id;

			else {

				parent[u_id] = v_id;

				if (rank[u_id] == rank[v_id])
					rank[v_id] += 1;

			}
		}
	}

	vector<int> return_parent() {
		return parent;
	}


};


// Class Contanning the graph.
class Graph
{
	// No. of vertices
	int vertices;

	// Adjesant list contanning the pair of attached node and its weight.
	vector<pair<int, pair<int, int> > > edges;

public:

	// Graph Constructor
	Graph(int vertices)
	{
		this->vertices = vertices;
	}

	// Function to add the edge
	void addEdge(int u, int v, int w = 1)
	{

		// Checking for the right vertices.
		if (u > vertices || v > vertices)
			return;

		// Adding the edges and respective weight of the graphs in adj list.

		edges.push_back(make_pair(w, make_pair(u, v)));

	}


	vector<int> kruskal() {

		Disjoint_set set(vertices);

		for (int i = 0; i < vertices; i++)
			set.make_set(i);

		auto temp_graph = edges;

		sort(temp_graph.begin(), temp_graph.end());

		for (auto e : temp_graph) {

			int u = e.second.first;
			int v = e.second.second;

			if (set.find(u) != set.find(v)) {
				set.union_by_rank(u, v);
			}

		}

		return set.return_parent();

	}

	void display_MST() {

		auto set = kruskal();

		for (int i = 0; i < set.size(); i++) {
			cout << i << " -> " << set[i] << endl;
		}

	}

};

int main() {

	// int V;
	// cin >> V;

	Graph g(6);

	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 4);
	g.addEdge(0, 3, 1);
	g.addEdge(1, 3, 3);
	g.addEdge(2, 3, 5);
	g.addEdge(2, 4, 8);
	g.addEdge(3, 5, 9);
	g.addEdge(2, 5, 6);
	g.addEdge(4, 5, 1);

	g.display_MST();

}