// brute force.
// first make a graph from given edges (bi-directed) then make a dfs call from 0th node(source vertex) and at each dfs call check if the
// cost to reach this node is >=k if it is then return true else mark this node as visited and traverse all its adjacent unvisited child
// nodes and make a dfs call on each of them by passing the updating the cost of path as current cost + edge weight. if the dfs call
// returns true then return true else before returning mark this node as unvisited as its dfs call is over and return false.

class Solution {
public:

	bool dfs(int node, vector<vector<int>> adj[], vector<bool> &visited, int k, int cost) {

		if (cost >= k) return true;
		visited[node] = true;

		for (auto child : adj[node]) {

			if (!visited[child[0]]) {

				if (dfs(child[0], adj, visited, k, cost + child[1])) return true;
			}
		}

		return visited[node] = false;


	}

	bool pathMoreThanK(int V, int E, int k, int *a)
	{
		//  Code Here


		vector<vector<int>> adj[V];


		for (int i = 0; i < 3 * E; i += 3) {

			adj[a[i]].push_back({a[i + 1], a[i + 2]});
			adj[a[i + 1]].push_back({a[i], a[i + 2]});

		}

		vector<bool> visited(V, false);

		return dfs(0, adj, visited, k, 0);


	}
};


// t.c. = O(N!)
// s.c. = O(N)