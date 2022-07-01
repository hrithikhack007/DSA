// graph theory.
// there are only two conditions if one of those two are satisfied then only we can traverse all the nodes of graph visiting each edge
// exactly once.

// condition 1: if there are exactly two nodes having odd degree then we can have an euler path. because we will start from one of those
// odd degree node and as the degree is odd the node from where we are starting the last edge of that node will be used to leave that
// node and we will complete the path on the other odd degree node so the last used edge of that node will be used to end the path.

// condition 2: if there is no odd degree nodes, in this case we will have a euler circuit because all nodes have even degree so
// we can start from any node and for a even degree node if the first edge of that node is used to enter the node then the last edge
// will be used to leave that node and if the first edge is used to leave the node then the last edge will be used to reach that node
// and end the path that's why euler circuit ends the path from where it starts.

// other case is odd degree nodes > 2 where we won't be able to visit every edge because we will end up at a odd degree node from where
// we cannot use the same edge again to leave that node as the no. of odd degree nodes are > 2 so even if we start from one of the odd
// degree node there are more than 1 odd degree node so our path will end at one of the remaining odd degree nodes and rest of the
// edges of odd degree nodes will remain unvisited.


class Solution {
public:
	int isEularCircuit(int V, vector<int>adj[]) {
		// Code here

		vector<int> degree(V, 0);

		for (int node = 0; node < V; node++) {

			for (auto child : adj[node]) {

				degree[child]++;
			}

		}

		int oddDegree = 0;

		for (auto d : degree) {
			if ((d & 1)) oddDegree++;
		}

		if (oddDegree == 0) return 2;
		else if (oddDegree == 2) return 1;
		else return 0;


	}
};

// t.c. = O(N+E)
// s.c. = O(N)