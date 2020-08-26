#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

/*
For better Understanding:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/3_Algorithms-on-Graphs/week4_paths_in_graphs2/Study_Material/bellman_ford_algorithm.md
*/
// Class Contanning the graph.
class Graph
{
	// No. of vertices
	int vertices;

	// Adjesant list contanning the pair of attached node and its weight.
	vector<vector<pair<int, int>>> adj;

public:

	// Graph Constructor
	Graph(int vertices)
	{
		this->vertices = vertices;

		adj.resize(vertices);
	}

	// Function to add the edge
	void addEdge(int u, int v, int w = 1)
	{

		// Checking for the right vertices.
		if (u > vertices || v > vertices)
			return;

		// Adding the edges and respective weight of the graphs in adj list.
		adj[u].push_back(make_pair(v, w));

		// For directed graph
		// adj[v].push_back(make_pair(u, w));

	}

	vector<int> bellman_ford(int src) {

		vector<int> dist(vertices, INT_MAX);
		vector<int> predecessor(vertices, INT_MIN);

		dist[src] = 0;

		int temp = vertices - 1;

		while (temp--) {

			for (int u = 0; u < vertices; u++) {
				for (auto edge : adj[u]) {

					int v = edge.first;
					int w = edge.second;

					if (dist[u] + w < dist[v]) {

						dist[v] = dist[u] + w;
						predecessor[v] = u;

					}

				}
			}
		}

		return dist;

	}

	void display()
	{

		cout << "\nDisplaying graph with " << vertices << " vertices." << endl;

		for (int i = 0; i < vertices; i++)
		{

			cout << "\nFor vertix: " << i << endl;

			cout << "Head";

			for (auto x : adj[i])
				cout << " -> " << x.first;

			cout << endl;
		}
	}

	void display_distance(int src)
	{

		auto dist = bellman_ford(src);

		cout << endl;

		cout << "Vertex"
			 << "\t"
			 << "Dist" << endl;

		for (int i = 0; i < vertices; i++)
			cout << i << "\t" << dist[i] << endl;
	}
};

int main()
{

	// int V;
	// cin >> V;

	Graph g(5);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 2, -2);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, -3);
	g.addEdge(2, 4, 1);
	g.addEdge(3, 4, 2);

	g.display();

	g.display_distance(0);

}