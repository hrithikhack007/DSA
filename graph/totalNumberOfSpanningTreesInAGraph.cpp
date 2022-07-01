// brute force

// we will first create graph from the given adjacency matrix using array of unordered set and also push all edges in connections array.
// variable remove = total edges - (n-1) will store the number of edges we have to remove from the graph so it contains n-1 edges.
// if edges < n-1 then remove will be < 0 that means we can't create any spanning tree so return 0.

// else, we will make a recursion call with count=0,idx=0,and remove.
// at each function call, we will have two options either to remove the idx'th edge from the graph or not remove it, if we remove it then
// we will make a call on idx+1,remove-1 else if number of remaining edges from idx is exactly equal to remove so we can't skip the idx'th
// edge else we can skip it and make a call on idx+1,remove.

// if remove becomes 0 that means you have removed the extra edges can graph contains n-1 edges now so check if the graph doesn't break in disco-
// nected components. we can do this by making a dfs call from any node and incrementing a counter on each dfs call to see if every node visitied
// from that single node dfs call if it does then graph is still a single connected component with n-1 edges that means a spanning tree is found
// so we increment count by 1 and return.





#include<bits/stdc++.h>

void dfs(int node, unordered_set<int> adj[], vector<bool> &visited, int &nodes) {

	visited[node] = true;
	nodes++;
	for (auto child : adj[node]) {
		if (!visited[child]) {
			dfs(child, adj, visited, nodes);
		}
	}
}

void rec(int idx, int remove, unordered_set<int> adj[], vector<vector<int>> &connections, int &count, int n) {

	if (remove == 0) {

		vector<bool> visited(n, false);
		int nodes = 0;

		dfs(0, adj, visited, nodes);

		if (nodes == n) count++;
		return;

	}

	int sz = connections.size();

	int u = connections[idx][0], v = connections[idx][1];
	adj[u].erase(v);
	adj[v].erase(u);

	rec(idx + 1, remove - 1, adj, connections, count, n);

	adj[u].insert(v);
	adj[v].insert(u);

	if (sz - idx != remove) {
		rec(idx + 1, remove, adj, connections, count, n);
	}


}

int spanningTrees(vector<vector<int>> &adjMatrix, int n, int m)
{

	unordered_set<int> adj[n];
	vector<vector<int>> connections;
	int edges = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (adjMatrix[i][j]) {
				edges++;
				adj[i].insert(j);
				adj[j].insert(i);
				connections.push_back({i, j});
			}
		}
	}


	int remove = edges - (n - 1);

	if (remove < 0) return 0;

	int count = 0;

	rec(0, remove, adj, connections, count, n);

	return count;



}


// t.c. = nCr = O(n!/(r!)*(n-r)!) , n is the total no. of edges and r is remove i.e. the extra edges we have to remove to have n-1 edges in graph.
// this is nothing but no. of ways we can remove r edges from a given set of n edges.

// s.c. = O(N+E)


// kirchoff's matrix tree theorem.

// we will traverse the adj. matrix and mark the diagonal with the degree of that node by counting the non zero cells in its row and also setting
// those non zeroes cell to -1.

// now the answer will be the determinant of matrix of size (n-1)*(n-1) by deleting the first row and first column.

// to calculate |D| of size n we will divide it into recursive subproblems,  i.e. |D| = summation of {(-1)^j}*(mat[i][j])*|D| of matrix of size
// (n-1)*(n-1) excluding the 0th row and jth column of the current matrix we will create this in a function createMat and recursively call
// the determinant function by passing this small mat. and n-1 for all j from j=0 to n.

// base case when n==1 then return single element else if n == 2 then return the diff of cross multiplication.



#include<bits/stdc++.h>

vector<vector<int>> createMat(int r, int c, vector<vector<int>> &mat, int n) {
	vector<vector<int>> newMat;

	for (int i = 0; i < n; i++) {

		if (i == r) continue;
		vector<int> row;
		for (int j = 0; j < n; j++) {
			if (j == c) continue;
			row.push_back(mat[i][j]);
		}

		newMat.push_back(row);
	}

	return newMat;
}

int determinant(vector<vector<int>> mat, int n) {

	if (n == 1) {
		return mat[0][0];
	} else if (n == 2) {
		return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
	} else {

		int d = 0;

		for (int j = 0; j < n; j++) {

			int s = (j % 2 == 0 ? 1 : -1);

			d += (s * mat[0][j]) * (determinant(createMat(0, j, mat, n), n - 1));

		}

		return d;

	}

}

int spanningTrees(vector<vector<int>> &adjMatrix, int n, int m)
{
	// Write your code here

	for (int i = 0; i < n; i++) {
		int degree = 0;
		for (int j = 0; j < n; j++) {

			if (adjMatrix[i][j]) {
				degree++;
				adjMatrix[i][j] = -1;
			}


		}

		adjMatrix[i][i] = degree;
	}


	return determinant(createMat(0, 0, adjMatrix, n), n - 1);

}

// t.c. = O(N^4)
// s.c. = O(N^3)