// using bfs (kahn's algo)

// take an indegree array initialized to 0. traverse all the nodes from 0 to n and for each node traverse its adjacent nodes and increment
// the indegree of their child by 1.
// take a queue, timer array.
// traverse node from 0 to n, for each node if indegree of node is 0 then push it into queue and set timer[node] = 1.
// while queue is not empty, get the front node as node and pop it out. traverse the child nodes of the node,
// decremet the indegree of child by 1 and if the indegree of child becomes 0 push it into queue and set timer[child] = timer[node]+1.

// intuition: we are exploring nodes with 0 dependecy first then by removing those nodes we also remove the dependency this node has on
// their child nodes so in this process whenever a node with 0 dependency is found we pushed it into queue because now all the dependency
// it has is now removed that means all nodes coming before it are now considered so we can explore this node and the proces continues
// till the queue is not empty.

// in this way all the job for a particular node which has to be completed before will be processed first then only we will reach to the
// node after completing all the before work if its indegree becomes 0 so it can now do it process in 1 unit time + the time required to
// complete the last work before its indegree becomes 0.

class Solution {
public:
	vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
	{
		// code here

		vector<int> adj[n + 1];

		for (auto edge : edges) {

			int u = edge[0];
			int v = edge[1];

			adj[u].push_back(v);


		}


		vector<int> inDegree(n + 1, 0);

		for (int node = 1; node <= n; node++) {

			for (auto child : adj[node]) {

				inDegree[child]++;
			}

		}



		queue<int> q;
		vector<int> timer(n);

		for (int node = 1; node <= n; node++) {
			if (inDegree[node] == 0) {
				timer[node - 1] = 1;
				q.push(node);

			}
		}





		while (!q.empty()) {

			auto node = q.front();
			q.pop();



			for (auto child : adj[node]) {

				inDegree[child]--;
				if (inDegree[child] == 0) {
					q.push(child);
					timer[child - 1] = timer[node - 1] + 1;
				}
			}



		}

		return timer;


	}
};

// t.c. = O(N+E)
// s.c. = O(N+E)
