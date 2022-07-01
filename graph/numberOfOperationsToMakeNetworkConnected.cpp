// using union find

// edge case: minimum number of edges required to connect to have n nodes in a single component is n-1, so if connections < n-1 that means
// there is no enough edges to connect the network in a single component so simply return -1.variable compo will keep track of number of
// components formed based on connections we will traverse connections initialized to n and for each edge will find the parent of node u
// and v if there parent is not same then we will unite this two components and decrement the compo by 1.

class Solution
{
public:

	int findPar(int node, vector<int> &par)
	{

		if (node == par[node]) return node;

		return par[node] = findPar(par[node], par);
	}

	void Union(int u, int v, vector<int> &par, vector<int> &rank)
	{

		if (rank[u] > rank[v])
		{

			par[v] = u;
		}
		else if (rank[v] > rank[u])
		{
			par[u] = v;
		}
		else
		{
			par[u] = v;
			rank[v]++;
		}
	}

	int makeConnected(int n, vector<vector < int>> &connections)
	{

		if (connections.size() < n - 1) return -1;

		int compo = n;

		vector<int> rank(n, 0), par(n);

		for (int i = 0; i < n; i++) par[i] = i;

		for (auto edge : connections)
		{

			int u = edge[0], v = edge[1];

			int paru = findPar(u, par);
			int parv = findPar(v, par);

			if (paru != parv)
			{
				compo--;
				Union(paru, parv, par, rank);
			}
		}

		return compo - 1;
	}
};


// t.c. = O(E*(4*alpha)) +O(N) => O(E) + O(N)(for initializing parent array), where E is the number of edges
//s.c. = O(N)

// can also do regular dfs and bfs after forming adjacency list from connections array but it will take O(N+E) space to store that adj. list

