#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue>

using namespace std;

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
		adj[v].push_back(make_pair(u, w));
	}

	vector<int> prim_algorithm() {

		vector<int> keys(vertices, INT_MAX);
		vector<int> parent(vertices, INT_MIN);

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		vector<bool> inMST(vertices, false);

		int src = 5;

		pq.push(make_pair(0, src));
		keys[src] = 0;

		while (!pq.empty()) {

			int u = pq.top().second;
			pq.pop();

			inMST[u] = true;

			for (auto x : adj[u]) {

				int node = x.first;
				int weight = x.second;

				if (!inMST[node] && keys[node] > weight) {
					keys[node] = weight;

					pq.push(make_pair(weight, node));

					parent[node] = u;

				}
			}
		}

		return parent;

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

	void display_MST() {

		auto MST = prim_algorithm();

		for (int i = 0; i < vertices; i++)
			cout << MST[i] << "->" << i << endl;

	}

};

int main()
{


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

	g.display();

	g.display_MST();

}
