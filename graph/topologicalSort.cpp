// using dfs
// take a visited array of size n initialized with false. take a toposort array acting as a stack. run a loop from i=0 to n. if ith node is
// not visited then make a dfs call starting from this node. at every func. call mark the node as visited traverse its child nodes and if
// the child is not visited then make a dfs call on that child. after all its child are traversed push this node in toposort array.

// intuition: basically, we are moving in depth of every node and whenever we can't find any adjacent node we push it so we are pushing
// the last node in depth first so it make sures that node which comes before is placed on top of it and similarly after all traversal of
// that top node that node is also pushed making the node before it to be placed on top of it and so on. to be precise, the node which is
// having high in time is placed first than the nodes having lesser in time so nodes with lesser comes before.

// before returning reverse the array

class Solution
{
public:

	void dfs(int node, vector<bool> &visited, vector<int> adj[], vector<int> &topoSort) {

		visited[node] = true;
		for (auto child : adj[node]) {
			if (!visited[child]) {
				dfs(child, visited, adj, topoSort);
			}
		}

		topoSort.push_back(node);
	}

	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		// code here

		vector<int> topoSort;
		vector<bool> visited(V, false);

		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				dfs(i, visited, adj, topoSort);
			}
		}

		reverse(topoSort.begin(), topoSort.end());

		return topoSort;


	}
};

// t.c. = O(N+E)
// s.c. = O(N)

// using bfs (kahn's algo)

// take an indegree array initialized to 0. traverse all the nodes from 0 to n and for each node traverse its adjacent nodes and increment
// the indegree of their child by 1.
// take a toposort array, queue.
// traverse node from 0 to n, for each node if indegree of node is 0 then push it into queue.
// while queue is not empty, get the front node as node and pop it out. push the node into toposort, traverse the child nodes of the node
// decremet the indegree of child by 1 and if the indegree of child becomes 0 push it into queue.

// intuition: we are exploring nodes with 0 dependecy first then by removing those nodes we also remove the dependency this node has on
// their child nodes so in this process whenever a node with 0 dependency is found we pushed it into queue because now all the dependency
// it has is now removed that means all nodes coming before it are now considered so we can explore this node and the proces continues
// till the queue is not empty

class Solution
{
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		// code here

		vector<int> inDegree(V, 0);

		for (int node = 0; node < V; node++) {

			for (auto child : adj[node]) {

				inDegree[child]++;
			}

		}


		vector<int> topoSort;

		queue<int> q;

		for (int node = 0; node < V; node++) {
			if (inDegree[node] == 0) q.push(node);
		}

		while (!q.empty()) {

			auto node = q.front();
			q.pop();

			topoSort.push_back(node);

			for (auto child : adj[node]) {

				inDegree[child]--;
				if (inDegree[child] == 0) q.push(child);
			}

		}

		return topoSort;

	}
};


// t.c. = O(N+E) + O(N) + O(N+E)
// s.c. = O(N) + O(N) + O(N)
