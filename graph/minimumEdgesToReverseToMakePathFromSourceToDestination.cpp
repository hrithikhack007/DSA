// 0-1 bfs.
// first while creating graph , if there is an edge from u to v then we will add that edge with cost 0 and add an extra edge from v to
// u with cost 1 i.e. to reach u from v we have to reverse edge u --> v so 1 cost for that.
// as we have only two edge weights here i.e. 0 and 1 so instead of using djikstra here we can use 0-1 bfs to reduce the complexity
// from O((N+E)log(N+E)) to O(N+E).
// we will take a distance array initialzed to inf , a deque. push the source node in deque and set distance[source] = 0.
// now, while the deque is not empty get the front node of deque and pop it out.
// now if the current node is end node then simply return distance[node] else traverse the child nodes of the current node, if the
// distance of current node + edge weight < distance of child node then update the distance of child and if the edge weight between
// child and node is 0 then push the node in front of deque and if it is 1 then push the node in back of deque this will make sure that
// shortest distance nodes are visited first.

#include<bits/stdc++.h>

int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
	// Write your code here

	vector<vector<int>> adj[n];

	for (auto edge : edgeList) {

		adj[edge[0]].push_back({edge[1], 0});
		adj[edge[1]].push_back({edge[0], 1});

	}


	deque<int> dq;

	dq.push_front(start);
	vector<int> distance(n, INT_MAX);
	distance[start] = 0;

	while (!dq.empty()) {

		auto node = dq.front();
		dq.pop_front();

		if (node == end) return distance[node];

		for (auto child : adj[node]) {

			if (distance[node] + child[1] < distance[child[0]]) {
				distance[child[0]] =   min(distance[child[0]], distance[node] + child[1]);

				if (child[1] == 0) dq.push_front(child[0]);
				else dq.push_back(child[0]);
			}
		}

	}


}


// t.c. = O(N+E)
// s.c. = O(N+E)