// we will traverse all edges and try to minimize the distance of node v via node u and its weight if node u is reachable from node 0.
// i.e. it is not maximum. we will do this relaxation for all edges n-1 times because in worst case edges can be given in reverse order
// so the node which is n-1th distance from node 0 will be relaxed in n-1th iteration at max. after this relaxation we will again check
// if distance of any node can be reduced further if it is possible then there is a negative cycle present in the graph else no.



class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges) {
		// Code here

		vector<int> dist(n, INT_MAX);

		dist[0] = 0;

		for (int i = 0; i < n - 1; i++) {

			for (auto edge : edges) {

				int u = edge[0], v = edge[1], w = edge[2];

				if (dist[u] != INT_MAX) {
					dist[v] = min(dist[v], dist[u] + w);
				}
			}

		}

		for (auto edge : edges) {
			int u = edge[0], v = edge[1], w = edge[2];

			if (dist[u] != INT_MAX) {
				if (dist[u] + w < dist[v]) {
					return 1;
				}
			}
		}

		return 0;



	}
};

// t.c. = O(N*E)
// s.c. = O(N)
