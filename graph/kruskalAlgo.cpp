// we will first push all the edges with thei weights in the min priority queue. we will initialized parent array such that each node is acting as
// its own parent and rank of all nodes to be 0. we will take a count initialize to 0.  while pq is not empty we will get the top element of the
// pq i.e. the minimum weight edge and will check can we add this edge in our mst , by adding this edge in mst there shouldn't be any cycle
// so we would check if the nodes sharing this edge is a part of the same component or not to do this we will find the par of this two nodes
// if par of both nodes are different then both nodes belong to different components so adding this edge in mst won't create cycle if it is the
// case we will add the weight of this edge in cost and unite this the parents of this two nodes and increment the count. if count becomes n-1
// that means mst is formed and we don't need to check remaining edges we can return cost.

class Solution
{
public:

	int findPar(int node, vector<int> &par) {

		if (node == par[node]) return node;

		return par[node] = findPar(par[node], par);
	}

	void unite(int u, int v, vector<int> &par, vector<int> &rank) {

		if (rank[u] > rank[v]) {

			par[v] = u;
		} else if (rank[v] > rank[u]) {
			par[u] = v;
		} else {
			par[u] = v;
			rank[v]++;

		}
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int n, vector<vector<int>> adj[])
	{
		// code here


		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;


		for (int node = 0; node < n; node++) {

			for (auto child : adj[node]) {
				pq.push({child[1], node, child[0]});
			}
		}



		int cost = 0;

		vector<int> par(n), rank(n, 0);

		for (int i = 0; i < n; i++) par[i] = i;

		int count = 0;

		while (!pq.empty()) {

			auto edge = pq.top();
			pq.pop();
			int u = edge[1];
			int v = edge[2];
			int w = edge[0];

			int paru = findPar(u, par);
			int parv = findPar(v, par);

			if (paru != parv) {
				cost += w;
				unite(paru, parv, par, rank);
				count++;
			}

			if (count == n - 1) break;
		}



		return cost;
	}
};

// t.c. = O(ELogE)  + O(N+E) + O(N)
// s.c. = O(E) + O(N)