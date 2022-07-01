// we want to color nodes of the graph such that no two adjacent nodes have same color.

// we will take a colors array of size n initialzed to -1.
// run a loop from i=0 to n-1 as graph can be disconnected.
// if ith node is not color i.e. it is -1 then make a dfs call on that node with color 0.
// on each dfs call assign the color to the node, traverse its adjacent nodes and if the child is not colored then make a dfs
// call on that child by passing opposite color of the node and if the dfs of child returns false return false, if the child
// is colored then check if the color of child is same as color of node then return false.
// after traversing all childs of the nodes if no false is encountered then return true.

// in for loop , if any component returns false then return false else after checking all components and no one returns false
// so graph is bipartitie return true.


class Solution {
public:

	bool dfs(int node, vector<vector<int>> &graph, vector<int> &colors, int color) {

		colors[node] = color;

		for (auto child : graph[node]) {

			if (colors[child] == -1) {
				if (!dfs(child, graph, colors, (color ^ 1))) return false;
			} else if (colors[node] == colors[child]) {
				return false;
			}
		}

		return true;
	}

	bool isBipartite(vector<vector<int>>& graph) {


		int n = graph.size();

		vector<int> colors(n, -1);

		for (int i = 0; i < n; i++) {

			if (colors[i] == -1) {

				if (!dfs(i, graph, colors, 0)) return false;
			}
		}

		return true;


	}
};


// t.c. = O(N+E)
// s.c. = O(N)