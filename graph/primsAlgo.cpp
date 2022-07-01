// take a min priority queue,visited array initialized to false, cost array initialized to max value. take any node as starting node say node 0
// set cost of node 0 to 0 and push 0,0 into queue, first value of pair is cost and second is node.
// while pq is not empty, get the top node of pq in curr and pop it out. if this node is already visited then continue else mark it as visited,add
// its cost in mst and traverse its child nodes, if the child node is not visited and  weight of the edge to add the child node in mst is less than
// the current cost of the child node then update the cost and push the new cost , child node in queue.

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		// code here

		vector<bool> visited(V, false);
		vector<int> cost(V, INT_MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		cost[0] = 0;
		pq.push({0, 0});
		int mst = 0;

		while (!pq.empty()) {

			auto curr = pq.top();
			pq.pop();


			int node = curr.second;
			if (visited[node]) continue;
			visited[node] = true;
			mst += curr.first;

			for (auto child : adj[node]) {

				int childNode = child[0];
				int weight = child[1];

				if (!visited[childNode] && weight < cost[childNode]) {
					cost[childNode] = weight;
					pq.push({weight, childNode});
				}
			}



		}

		return mst;





	}
};

// t.c. = O((N+E)LogN)
// s.c. = O(N)