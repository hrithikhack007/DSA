// using dfs.
// take a visited array , dfsVisited array initialized to false. run a loop from i=0 to n-1, if ith node is not visited then make a dfs
// call from that node. at each func. call mark curr node as visited and also mark this node true in dfsVisited array. traverse all its
// adjacent nodes if not visited make a dfs call from that child and if it returns true then return true, else if it is visited
// and dfsvisited child is also visited then there is a cycle return true.after traversing adj. nodes of node mark node as false
// in dfsVisited as it dfs traversal is complete and it is no more active and return false. in the for loop if any component returns
// true then return true and after traversing all nodes return false.

class Solution {
public:

	bool dfs(int node, int par, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsVisited) {

		visited[node] = dfsVisited[node] = true;

		for (auto child : adj[node]) {

			if (!visited[child]) {
				if (dfs(child, node, adj, visited, dfsVisited)) return true;
			} else if (dfsVisited[child]) return true;
		}

		dfsVisited[node] = false;

		return false;

	}

	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		// code here


		vector<bool> visited(V, false) , dfsVisited(V, false);


		for (int i = 0; i < V; i++) {

			if (!visited[i]) {

				if (dfs(i, -1, adj, visited, dfsVisited)) return true;
			}
		}

		return false;



	}
};

// t.c. = O(N+E)
// s.c. = O(N)

// using bfs (kahn's algo)
// take an indegree array initialized to 0. now traverse from node = 0 to n-1 , traverse all the child of node and increment the indegree
// of child by 1. take a queue . traverse node from 0 to n-1 and nodes whose indegree and zero push it into the queue. run a while loop,
// till queue is not empty. in each iteration take out the front node in node pop it out and increment cnt by 1. traverse all adj. nodes
// of node and decrease the indegree of child by 1, if indegree child becomes 0 push it into the queue.
// if cnt not equal n means cycle is present.

// we are basically trying to generate topo sort of the given graph using kahnn's algo, as we know only dag have valid topo sort so
// if we can't generate any topo sort of the given graph that means it contains cycle. in topo sort nodes which have 0 dependency
// starts first and we remove that node so all of its adj. nodes dependencies decreased by one and the next node with 0 dependencies
// are explored. but in cycle every node has dependency on each other so there will be no node with 0 dependency that's why graph with
// cycles won't be able to generate top sort which contains all n nodes as nodes in cycle is going to be missed.

class Solution {
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		// code here

		vector<int> inDegree(V, 0);

		for (int node = 0; node < V; node++) {

			for (auto child : adj[node]) {

				inDegree[child]++;

			}
		}

		queue<int> q;

		for (int i = 0; i < V; i++) {

			if (inDegree[i] == 0) q.push(i);
		}

		int cnt = 0;

		while (!q.empty()) {

			auto node = q.front();
			q.pop();

			cnt++;

			for (auto child : adj[node]) {

				inDegree[child]--;
				if (inDegree[child] == 0) {
					q.push(child);
				}
			}


		}

		return (cnt != V);


	}
};

// t.c. = O(N+E)
// s.c. = O(N)
