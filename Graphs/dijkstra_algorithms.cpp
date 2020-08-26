#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>


using namespace std;

/*
For better understanding:
https://github.com/raman08/Coursera-Data-Structure-And-Algorithms-by-University-of-California-San-Diego/blob/master/3_Algorithms-on-Graphs/week4_paths_in_graphs2/Study_Material/dijkstra.md
*/


// Class Contanning the graph.
class Graph {

	// No. of vertices
	int vertices;

	// Adjesant list contanning the pair of attached node and its weight.
	vector<vector<pair<int, int> > > adj;

public:

	// Graph Constructor
	Graph(int vertices) {
		this->vertices = vertices;

		adj.resize(vertices);

	}

	// Function to add the edge
	void addEdge(int u, int v, int w = 1) {

		// Checking for the right vertices.
		if (u > vertices || v > vertices)
			return;

		// Adding the edges and respective weight of the graphs in adj list.

		adj[u].push_back(make_pair(v, w));

		// For directed graph
		// adj[v].push_back(make_pair(u, w));


	}

	// Implementing the dijkstra algorithm
	vector<int> dijkstra(int src) {

		// Doing the BFS
		priority_queue<pair<int, int>, vector<pair<int , int> >, greater<pair<int, int> > > pq;

		// Store the distance of all node from the given node. Inital all the distance if infinite
		vector<int> dist(vertices, INT_MAX);

		// Start from the given node
		pq.push(make_pair(0, src));
		dist[src] = 0;

		while (!pq.empty()) {

			int u = pq.top().second;
			pq.pop();

			for (auto i = adj[u].begin(); i != adj[u].end(); i++) {

				int v = (*i).first;
				int weight = (*i).second;

				// If distance is smaller the change it.
				if (dist[v] > dist[u] + weight) {

					dist[v] = dist[u] + weight;
					pq.push(make_pair(dist[v], v));

				}

			}
		}

		return dist;
	}

	void display() {

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

	void display_distance(int src) {

		auto dist = dijkstra(src);

		cout << endl;

		cout << "Vertex" << "\t" << "Dist" << endl;

		for (int i = 0; i < vertices; i++)
			cout << i << "\t" << dist[i] << endl;


	}


};

int main() {

	// int V;
	// cin >> V;

	Graph g(6);

	g.addEdge(0, 1, 3);
	g.addEdge(0, 2, 10);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 3, 3);
	g.addEdge(1, 4, 5);
	g.addEdge(2, 4, 5);
	g.addEdge(2, 1, 2);
	g.addEdge(3, 2, 3);
	g.addEdge(3, 4, 1);
	g.addEdge(3, 5, 2);
	g.addEdge(4, 5, 0);

	g.display();

	g.display_distance(0);

}