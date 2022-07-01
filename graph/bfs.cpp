// take a visited array , queue. push 0th node in queue, mark 0th node as visited. while q is not empty pop out the front node
// from the queue and push that node in bfs array .
// traverse all its adjacent nodes if not visited mark them visited and push them into queue.
// this code runs only for single component in which node 0 is present.


class Solution {
public:
	// Function to return Breadth First Traversal of given graph.
	vector<int> bfsOfGraph(int V, vector<int> adj[]) {
		// Code here


		vector<bool> visited(V, false);

		queue<int> q;

		visited[0] = true;
		q.push(0);

		vector<int> bfs;

		while (!q.empty()) {

			auto node = q.front();
			q.pop();
			bfs.push_back(node);

			for (auto child : adj[node]) {
				if (!visited[child]) {
					visited[child] = true;
					q.push(child);
				}
			}


		}


		return bfs;

	}
};

// t.c. = O(N+E)
// s.c. = O(N)

// this code handles other disconnected components as well.

class Solution {
public:
	// Function to return Breadth First Traversal of given graph.
	vector<int> bfsOfGraph(int V, vector<int> adj[]) {
		// Code here

		vector<bool> visited(V, false);

		vector<int> bfs;

		for (int i = 0; i < V; i++) {

			if (!visited[i]) {
				queue<int> q;
				visited[i] = true;
				q.push(i);

				while (!q.empty()) {

					auto node = q.front();
					q.pop();
					bfs.push_back(node);

					for (auto child : adj[node]) {
						if (!visited[child]) {
							visited[child] = true;
							q.push(child);
						}
					}


				}


			}


		}

		return bfs;

	}
};