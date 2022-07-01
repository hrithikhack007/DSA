// using bfs (kahn's algo)

// create graph from given dependencies.

// take an indegree array initialized to 0. traverse all the nodes from 0 to n and for each node traverse its adjacent nodes and increment
// the indegree of their child by 1.
// take a counter=0, queue.
// traverse node from 0 to n, for each node if indegree of node is 0 then push it into queue.
// while queue is not empty, get the front node as node and pop it out, increment count by 1, traverse the child nodes of the node
// decremet the indegree of child by 1 and if the indegree of child becomes 0 push it into queue.

// intuition: we are exploring nodes with 0 dependecy first then by removing those nodes we also remove the dependency this node has on
// their child nodes so in this process whenever a node with 0 dependency is found we pushed it into queue because now all the dependency
// it has is now removed that means all nodes coming before it are now considered so we can explore this node and the proces continues
// till the queue is not empty

// in this way, courses that needs to be studied before for a particular course will be covered first then when some node's indegree becomes
// 0 then that means all the courses required to learn before this course has been covered so we can learn this course.

// if all the courses are completed then counter would have become n so else if there was some cycle then some course cannot be completed
// so count would be <n .

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


		vector<int> adj[numCourses];

		int count = 0;

		for (auto prerequisite : prerequisites) {

			adj[prerequisite[1]].push_back(prerequisite[0]);

		}

		vector<int> inDegree(numCourses, 0);

		for (int node = 0; node < numCourses; node++) {

			for (auto child : adj[node]) {

				inDegree[child]++;
			}

		}


		queue<int> q;

		for (int node = 0; node < numCourses; node++) {
			if (inDegree[node] == 0) q.push(node);
		}

		while (!q.empty()) {

			auto node = q.front();
			q.pop();

			count++;

			for (auto child : adj[node]) {

				inDegree[child]--;
				if (inDegree[child] == 0) q.push(child);
			}

		}

		return (count == numCourses);


	}
};

// t.c. = O(N+E)
// s.c. = O(N+E)



// using dfs.

// basically we have to find out if there is cycle present or not in a directed graph, because if there is a cycle then dependencies can
// never be satisfied so we return false else true.

// take a visited array, dfs visited array initialized to false. run a loop from i = 0 to n. if the ith node is not visited then make a
// dfs call from that ith node. at each func. call mark the node as true in both visited and dfsvisited array. traverse the child nodes
// of the current node and if it is not visited then make a dfs call on that child node and if that dfs return false return false
// else if it visited and also dfs visited is true that means this child is currently present in dfs call and from there we could reach here
// and we got another path to reach this child from the current node so there is a cycle and we return false. after traversing child nodes
// dfs call for current node is over so make node as false in dfs visited array and return true.

// in for loop if any ith node dfs call returns false return false . when loop is over that means we didn't detect cycle so return true.

class Solution {
public:

	bool dfs(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[]) {

		visited[node] = dfsVisited[node] = true;

		for (auto child : adj[node]) {
			if (!visited[child]) {
				if (!dfs(child, visited, dfsVisited, adj)) return false;
			} else if (dfsVisited[child]) return false;
		}

		dfsVisited[node] = false;

		return true;

	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		vector<int> adj[numCourses];

		for (auto prerequisite : prerequisites) {
			adj[prerequisite[0]].push_back(prerequisite[1]);
		}


		vector<bool> visited(numCourses, false), dfsVisited(numCourses, false);

		for (int i = 0; i < numCourses; i++) {

			if (!visited[i]) {
				if (!dfs(i, visited, dfsVisited, adj)) return false;
			}
		}

		return true;

	}
};


// t.c. = O(N+E)
// s.c. = O(N+E)
