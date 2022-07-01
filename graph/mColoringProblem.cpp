// brute force.

// take a visited array initialized to false and a colors array initialized to -1.
// run a loop from i=0 to n-1 , if color of node i is -1 then make a dfs call on that ith node.

// at each dfs call, mark the node as visited. run a loop of color from 0 to m-1. check if the current color can be assigned
// to this node such that all of its adjacent nodes have different color, so for each color traverse its child nodes.
// if color of child nodes is -1 then make a dfs call to that child also if color of child and color of node are same but child
// is not visited that means this child was assigned a color already but we made some changes in current node color so it becomes
// equal now so we will make a dfs call to this unvisited child node. else if the color of child is same as color of node
// but it is already visited that means this child was not visited through the dfs call of current node that means this child
// is actully an ancestor so we won't make a dfs call there we will try to color the current node with some different color.
// also if any dfs call from current node to its child node returns false for a particular color then we will try choose a
// different color.

// if all the adjacent child nodes of the current node's color are differnt from curren node's color then we have successfully
// assigned a color to this node so dfs call for this node is over so we mark this node as false in visited array and returns
// true else if even after checking all m colors on node we can't satisfy the condition then we return false after marking current
// node as false in visited array.

// important case:
// also condition for child node which is not visited but having different color than current node color and that color is not
// -1 that means the color we have alreay assigned to that node is still valid so we don't need to do a dfs call on that node
// even if it is unvisited.


// in the for loop in main func. if any of the component returns false we return false.
// in last if we can assign m colors to all components then return true.

//also here instead of having visited[i] as a condition we are using color[i] because before returning from the func. we are
// marking node as false in visited array so we might end up making a dfs call for the same component more than once.


bool dfs(int node, bool graph[101][101], int n, int m, vector<int> &colors, vector<bool> &visited) {

	visited[node] = true;

	for (int color = 0; color < m; color++) {
		colors[node] = color;
		bool ok = true;
		for (int child = 0; child < n; child++) {
			if (graph[node][child]) {
				if (colors[child] == -1 || (colors[child] == colors[node] && !visited[child])) {
					if (!dfs(child, graph, n, m, colors, visited)) {
						ok = false;
						break;
					}
				} else if (colors[node] == colors[child]) {
					ok = false;
					break;
				}
			}


		}

		if (ok) {
			visited[node] = false;
			return true;
		}
	}

	visited[node] = false;

	colors[node] = -1;

	return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {


	vector<int> adj[n];


	vector<int> color(n, -1);
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			if (!dfs(i, graph, n, m, color, visited)) return false;
		}
	}

	return true;


}


// t.c. = O(M^N)
// s.c. = O(N)



// concise and clean code:

// we will start from node 0 and at each func. call we will try to color the node from 0 to m-1 color and before assigning any
// color to the node we will first check if the color we are going to assign is not same to all ajdacent child nodes of the
// current node if it is then we will simply skip to next color else we will assign this color to the node and make a call
// on node+1 to color that node,if that call returns false that means there was some node which we couldn't color with any
// 0 to m-1 color so that their adjacent node's color are different in that case we will try to color the current node with
// some different color and first of all uncolor the node by asigining it with -1 else if that call returns true that means
// we were successfully able to color nodes from node+1 to n-1 so we return true.
// in case after checking with all m colors we couldn't color the current node with any color by maintaining the condition
// we will return false.

// base case: if node == n that means all nodes from 0 to n-1 nodes have been assigned color without any adjacent nodes having
// same color so we return true.



bool canColor(int color, int node, bool graph[101][101], vector<int> &colors, int n) {

	for (int child = 0; child < n; child++) {

		if (child != node && graph[node][child] && colors[child] == color) return false;
	}

	return true;
}

bool rec(int node, bool graph[101][101], vector<int> &colors, int m, int n) {

	if (node == n) return true;

	for (int color = 0; color < m; color++) {

		if (canColor(color, node, graph, colors, n)) {
			colors[node] = color;


			if (!rec(node + 1, graph, colors, m, n)) {
				colors[node] = -1;
				continue;
			}

			return true;
		}
	}

	return false;


}


bool graphColoring(bool graph[101][101], int m, int n) {
	// your code here


	vector<int> colors(n, -1);

	return rec(0, graph, colors, m, n);



}


// t.c. = O(M^N)
// s.c. = O(N)
