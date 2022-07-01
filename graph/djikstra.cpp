// using priority queue.
// take a distance array initialized to some max value. set distance of source to 0. take min heap of pair of int,int. push 0 and source
// node in pq. first value is distance and second is node. while q is not empty at each iteration get the top element of pq as curr and
// pop it out. take dist. to reach this node and node itself. traverse the child of this nodes, if dist. to this node + weight of edge
// between child and node is < than dist. of child then update the dist. of child to that and push new distance of child , child into
// pq.

class Solution
{
public:
	//Function to find the shortest distance of all the vertices
	//from the source vertex S.
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
	{
		// Code here

		vector<int> distance(V, (int)1e9);

		distance[S] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, S});

		while (!pq.empty()) {

			auto curr = pq.top();
			pq.pop();

			int dist = curr.first;
			int node = curr.second;

			for (auto child : adj[node]) {

				int childNode = child[0];
				int weight = child[1];

				if (dist + weight < distance[childNode]) {
					distance[childNode] = dist + weight;
					pq.push({distance[childNode], childNode});
				}

			}


		}

		return distance;


	}
};


// t.c. = O((N+E)logN)
// s.c. = O(N)

// using set. all similar just when we found distance of child > dist of node + weight then erase the old entry of child IF it exist.
// this saves time because the old distance is already > new distance so new distance will going to come first and after exploring the node
// with new distance and then again exploring it with old distance changes nothing and consumes times. so it is a little bit of time
// optimization.

#include<bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

	// Write your code here.

	vector<vector<long>> adj[vertices];

	for (auto a : vec) {
		adj[a[0]].push_back({a[1], a[2]});
		adj[a[1]].push_back({a[0], a[2]});
	}

	vector<int> distance(vertices, INT_MAX);

	distance[source] = 0;

	set<pair<int, int>> st;
	st.insert({0, source});
	while (!st.empty()) {

		auto curr = *(st.begin());
		st.erase(st.begin());

		int dist = curr.first;
		int node = curr.second;

		for (auto child : adj[node]) {

			int childNode = child[0];
			int weight = child[1];

			if (dist + weight < distance[childNode]) {
				if (st.find({distance[childNode], childNode}) != st.end())
					st.erase(st.find({distance[childNode], childNode}));
				distance[childNode] = dist + weight;
				st.insert({distance[childNode], childNode});
			}

		}


	}

	return distance;



}


// t.c. = O((N+E)logN)
// s.c. = O(N+E)