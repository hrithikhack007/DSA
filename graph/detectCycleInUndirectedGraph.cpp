// using dfs.
//  take a visited array, run a loop from i=0 to n-1 , if ith node is not visited then make a rec call from that node by passing ith
// node as node and -1 as par. at each func. call mark node as visited, traverse the adj. list of that node and if child!=par and
// the child node is already visited so there is a cycle return true else if child is not visited then make a func. call by this
// child as node and node as par and if that returns true so return true. after traversing all the adj. nodes if no cycle is found return
// false. in for loop if ith node rec returns true then return true else after loop ends return false.


class Solution {
public:

	bool rec(int node, int par, vector<bool> &visited, vector<int> adj[]) {

		visited[node] = true;

		for (auto child : adj[node]) {
			if (child != par && visited[child]) {
				return true;
			} else if (!visited[child]) {
				if (rec(child, node, visited, adj)) return true;
			}
		}

		return false;
	}

	// Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int> adj[]) {
		// Code here

		vector<bool> visited(V, false);

		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				if (rec(i, -1, visited, adj)) {
					return true;
				}
			}
		}

		return false;

	}
};


// t.c. = O(N+E)
// s.c. = O(N)


// using bfs
// take a visited array. traverse from i=0 to n-1, if ith node not visited then take a queue of pair of int to store node and its parent
// push the ith node and -1 in the queue , mark the ith node as visited. run a while loop till q is not empty , in each iteration take
// the front element as curr and pop it. assign par and node from that curr. traverse the adj. nodes of node, if child not visited
// push it into queue with its parent as node and mark child as visited, else if child!=par then cycle exist return true.
// if external for loop ends then no cycle found return false.

class Solution {
public:
	// Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int> adj[]) {
		// Code here


		vector<bool> visited(V + 1, false);

		for (int i = 0; i < V; i++) {

			if (!visited[i]) {

				queue<pair<int, int>> q;
				q.push({i, -1});
				visited[i] = true;

				while (!q.empty()) {

					auto curr = q.front();
					q.pop();
					int par = curr.second;
					int node = curr.first;

					for (auto child : adj[node]) {
						if (!visited[child]) {
							visited[child] = true;
							q.push({child, node});
						} else if (child != par) {
							return true;
						}
					}

				}

			}

		}

		return false;


	}
};

// t.c. = O(N+E)
// s.c. = O(N)