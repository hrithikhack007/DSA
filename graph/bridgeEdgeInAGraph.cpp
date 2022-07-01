// take a time of insertion array and low time array , timer initialized to 0, visited array.

// we will make a dfs call from c with -1 as parent, at each call we will mark the node as visited and increment the timer
// assign it to ti and low of node.
// traverse all the child nodes of the node except its parent, if child is not visited then make a dfs call on that child
// with node as the parent  else if child is already visited then its inserted before the node so try to minimize the low
// of node with the ti of child. now, if the low of child is > ti of node that means the child couldn't reach the node
// or any any node having insertion time <= ti[node] because its low is > ti[node] that means the lowest insertion time node
// child can reach is > ti[node] so if we remove the edge between node and child then child won't be able to reach the node
// or nodes coming before current node that means it is a bridge and if node==c and child==d that means c-d is a bridge
// so we return true. else after traversing adjacent nodes we couldnt find c-d as bridge we return false.

// for e.g let's say low[child]=7 and ti[node]=6 so the lowest insertion time node child can reach is 6 but if we remove the
// edge then the child would be cut from nodes having insertion time lower than 7 therefore it is a bridge.

class Solution
{
public:

	bool rec(int node, int par, vector<int> adj[], vector<int> &ti, vector<int> &low, int &timer, int c, int d, vector<bool> &visited) {

		ti[node] = low[node] = ++timer;
		visited[node] = true;

		for (auto child : adj[node]) {
			if (child == par) continue;

			if (!visited[child]) {
				if (rec(child, node, adj, ti, low, timer, c, d, visited)) return true;
			} else low[node] = min(low[node], ti[child]);

			if (low[child] > ti[node] && node == c && child == d) {
				return true;
			}

			low[node] = min(low[node], low[child]);

		}

		return false;


	}

	//Function to find if the given edge is a bridge in graph.
	int isBridge(int V, vector<int> adj[], int c, int d)
	{
		// Code here

		vector<int> ti(V, 0), low(V, 0);
		int timer = 0;
		vector<bool> visited(V, false);

		return rec(c, -1, adj, ti, low, timer, c, d, visited);

	}
};


// t.c. = O(N+E)
// s.c. = O(N)