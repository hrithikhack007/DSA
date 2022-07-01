// take a visited array initialized with false, call the rec func. with 0 , at each func. call mark the node as visited push it into dfs
// array. traverse the adjacencny list of the node if the adj. node is not visited then make a func. call on that adj node.
// this will work for a single component containing node 0.

class Solution {
public:

	void rec(int node, vector<bool> &visited, vector<int> adj[], vector<int> &dfs) {

		dfs.push_back(node);
		visited[node] = true;

		for (auto child : adj[node]) {
			if (!visited[child]) {
				rec(child, visited, adj, dfs);
			}
		}


	}

	// Function to return a list containing the DFS traversal of the graph.
	vector<int> dfsOfGraph(int V, vector<int> adj[]) {
		// Code here

		vector<bool> visited(V, false);

		vector<int> dfs;

		rec(0, visited, adj, dfs);

		return dfs;
	}
};

// t.c. = O(N+E)
// s.c. = O(N) + O(N)(stack space)

// this code will work with multiple disconnected components as well.

class Solution {
public:

	void rec(int node, vector<bool> &visited, vector<int> adj[], vector<int> &dfs) {

		dfs.push_back(node);
		visited[node] = true;

		for (auto child : adj[node]) {
			if (!visited[child]) {
				rec(child, visited, adj, dfs);
			}
		}


	}

	// Function to return a list containing the DFS traversal of the graph.
	vector<int> dfsOfGraph(int V, vector<int> adj[]) {
		// Code here

		vector<bool> visited(V, false);

		vector<int> dfs;

		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				rec(i, visited, adj, dfs);
			}
		}



		return dfs;
	}
};


