// as it is a DAG, find the topsort of the graph using dfs. take a distance array initialized it to INT_MIN.
// set distance of src node to 0. now at each iteration, pop the last node from the toposort array, if the distance of that
// node from src is int-min then continue because it is not reachable from src, else traverse the child nodes of this node
// and update the distance of child if distance[node] + edge weight is > distance[child] because we want maximum distance.


// intuition: as we are doing topo sort and traversing nodes according to that ordering, so when we visit a node then that means
// all the nodes coming before the node in toposort is already considered and all the incoming edges towards the node is already
// compared that means all the possible paths to reach this node has been considered and from those paths maximum distance
// path cost to reach this node is stored in the distance array at node index. so we will traverse its childs and compare the
// path costs to reach that child node ans store the maximum so this is it. for any node, nodes which has incoming edges towards
// the node is considered before the current node so to reach the current node we can have the maximum path and maintain a
// consitent order of evaluation that's why toposort.



class Solution
{
public:

	void dfs(int node, vector<vector<int>> adj[], vector<bool> &visited, vector<int> &topoSort) {

		visited[node] = true;

		for (auto child : adj[node]) {

			if (!visited[child[0]]) {
				dfs(child[0], adj, visited, topoSort);
			}
		}

		topoSort.push_back(node);

	}

	vector <int> maximumDistance(vector<vector<int>> edges, int v, int e, int src)
	{
		// code here


		vector<int> topoSort;

		vector<bool> visited(v, false);

		vector<vector<int>> adj[v];

		for (auto edge : edges) {
			adj[edge[0]].push_back({edge[1], edge[2]});
		}

		for (int i = 0; i < v; i++) {
			if (!visited[i]) {
				dfs(i, adj, visited, topoSort);
			}
		}

		vector<int> distance(v, INT_MIN);
		distance[src] = 0;

		while (topoSort.size() != 0) {

			int node = topoSort.back();
			topoSort.pop_back();

			if (distance[node] == INT_MIN) continue;

			for (auto child : adj[node]) {

				if (distance[node] + child[1] > distance[child[0]]) {
					distance[child[0]] = distance[node] + child[1];
				}

			}


		}

		return distance;


	}
};


// t.c. = O(N+E)
// s.c. = O(N+E)