// brute force
// check every triplets of vertices in the given graph and see if i is connected with j and j is connected with k and k is connected with
// i. if it is then increment the counter. do this for both directed and undirected graph.

// now, there might be multiple triangles of same 3 vertices. like in undirected graph, one triangle will be counted 6 times and in
// directed graph one triangle will be counted 3 times so in the final ans we have to divide no. of triangles in undirected graph
// by 6 and in directed graph with 3 to get unique no. of triangles in undirected and directed graph respectively.

#include<bits/stdc++.h>
vector<int> countTriangles(int v1, vector<vector<int>>& edgeListOfDirectedGraph, int v2,
                           vector<vector<int>>& edgeListOfUnDirectedGraph) {

	unordered_set<int> adj1[v1], adj2[v2];

	for (auto edge : edgeListOfDirectedGraph) {

		adj1[edge[0]].insert(edge[1]);
	}

	for (auto edge : edgeListOfUnDirectedGraph) {
		adj2[edge[0]].insert(edge[1]);
		adj2[edge[1]].insert(edge[0]);
	}

	int t1 = 0, t2 = 0;

	for (int i = 0; i < v1; i++) {

		for (int j = 0; j < v1; j++) {
			for (int k = 0; k < v1; k++) {

				if (adj1[i].count(j) && adj1[j].count(k) && adj1[k].count(i))
					t1++;
			}
		}
	}

	t1 /= 3;

	for (int i = 0; i < v2; i++) {

		for (int j = 0; j < v2; j++) {
			for (int k = 0; k < v2; k++) {

				if (adj2[i].count(j) && adj2[j].count(k) && adj2[k].count(i)) t2++;
			}
		}
	}

	t2 /= 6;

	return {t1, t2};


}


// t.c. = O(N1^3) + O(N2^3)
// s.c. = O(N1+E1) + O(N2 + E2)

