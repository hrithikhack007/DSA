// we will try to minimize the distance between every pair of nodes n times starting from k=0 to n.

// e.g. after minimizing the distance between pairs for k=3, the distance between any pair a,b will be storing the mimimum distance we can have
// by considering nodes only <=3 in between its path.

// so if by adding node k in the path between node a and b is going to minimize the path then k would be reachable by a and b would be reachable
// by k, also min. distance between pair a and k  and min. distance between k and a would have been calculated for k-1 nodes so that means
// by adding k we are maintaing our argument that all nodes in between a and b are <=k so if dist from a to k + dist from k to b is smaller
// than the current dist of a and b then we will update dist of a and b to dist[a][k] + dist[k][b] as adding k reduces cost else if it doesn't
// reduces then we won't update.

// similarly after k=n-1 iterations, minimum distance between any pairs such that the min. distance path between nodes can contain any subset
// of nodes <=n-1 which  will basically store the min. cost possible between a and b in a  graph.

// edge case: start from 0 if 0 indexed node else start from 1 if 1 indexed node.

class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix) {
		// Code here
		int n = matrix.size();

		for (int k = 0; k < n; k++) {

			for (int i = 0; i < n; i++) {

				for (int j = 0; j < n; j++) {


					if (matrix[i][k] != -1 && matrix[k][j] != -1) {
						if (matrix[i][j] == -1) matrix[i][j] = INT_MAX;
						matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
					}

				}
			}
		}

	}
};


// t.c. = O(N^3)
// s.c. = O(1)