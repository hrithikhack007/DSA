// distance[node][j] will represent minimum cost path from src to node such that there are exactly j nodes behind the node.

// we will have a min priority queue of vector<int> where a[0] -> cost to reach node, a[1] -> no. of nodes behind in that path,
// a[2] -> node label. we will have a distance array of size n*k+2 initialzed src distance to 0. push {0,0,src} in pq.

// while priority queue is not empty, pop the top element get the node,dist to node,no. of nodes behind that node.
// if the current node is the dst node then return the dist.
// if no. of nodes behind is == k+1 that means now by adding any node adjacent to this node will result into more than k nodes
// in the path so we will continue , else traverse the adjacent child
// of current node and check if the distance to this node having beh. nodes behind + weight < distance to child such that
// beh. + 1 nodes will be behind if it is then update the distace of child and push the {update child distance,beh.+1,childNode}
// in pq.

// if we couldn't reach the dst node in <=k nodes in between the path then return -1 .



class Solution {
public:

	class comp
	{
	public:
		bool operator() (vector<int> a, vector<int> b)
		{
			return a[0] > b[0];
		}
	};


	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


		vector<vector<int>> distance(n, vector<int>(k + 2, INT_MAX));

		vector<vector<int>> adj[n];

		for (auto flight : flights) {
			adj[flight[0]].push_back({flight[1], flight[2]});

		}

		priority_queue<vector<int>, vector<vector<int>>, comp> pq;

		pq.push({0, 0, src});

		fill(distance[src].begin(), distance[src].end(), 0);



		while (!(pq.empty())) {


			auto curr = pq.top();
			pq.pop();

			int node = curr[2];
			int dist = curr[0];
			int behind = curr[1];

			if (node == dst) return dist;

			if (behind == k + 1) continue;


			for (auto child : adj[node]) {

				int childNode = child[0];
				int weight = child[1];

				if (distance[node][behind] + weight < distance[childNode][behind + 1]) {

					distance[childNode][behind + 1] = distance[node][behind] + weight;
					pq.push({distance[childNode][behind + 1], behind + 1, childNode});

				}
			}


		}

		return -1;




	}
};

// t.c. = O(N*K(LOGN))
// s.c. = O(N*K)


// clean and concised but tle
// the idea is to start from the source node and while the q is not empty , at each iteration get the current node,dist,behind.
// if the current node is the dst node then return the dist.
// if the no. of nodes behind the curr node is == k+1 then adding any adjacent node to it will result in more than k nodes in path
// /so we will continue else we will traverse the child nodes of curr node and we will push the dist to reach that child i.e.
// dist to reach node + weight , behind + 1 , childNode into pq.

// intuition: there might be case where the shorter distance path have many edges to the destination node but large distance path
// might have smaller no. of edges till destinatio node so we want to check every path because it might be the candidate as well.



class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

		vector<vector<int>> adj[n];

		for (auto flight : flights) {

			adj[flight[0]].push_back({flight[1], flight[2]});

		}

		pq.push({0, 0, src});

		while (!pq.empty()) {


			auto curr = pq.top();

			int dist = curr[0];
			int behind = curr[1];
			int node = curr[2];

			pq.pop();
			if (node == dst) return dist;

			if (behind == k + 1) continue;

			for (auto child : adj[node]) {

				auto childNode = child[0];
				auto weight = child[1];

				pq.push({dist + weight, behind + 1, childNode});

			}

		}

		return -1;

	}
};


// time and space compleixty couldn't find as of now.


// dp
// dp[i][j] represents minimum cost path to reach node i from src such that there are exactly j edges in the path.
// so we will run a loop from i=1 to i=k+1.
// in each iteration we will traverse all the edges of graph and do the transition like if node u is reachable from src i.e.
// dist[u][i-1] is not INT_MAX so dist[v][i] = min(dist[v][i],w + dist[u][i-1]) basically to find the min. distance to reach
// node v such that there are exactly i edges in between the path we are first making sure that u is reachable from src with
// a path having exactly i-1 edges if it does then the minimum distance to reach node u from src having i-1 edges + edge between
// u and v with cost w will result in exactly i edges between src and node v so we will minimize the cost to reach node v with i
// edges with this newly found path.
// also if the node v is the dst node then minimize the overall ans i.e. minimum cost to reach node dst with atmost k+1 edges in
// between.
// because for k nodes to be in between a path we can have k+1 edges.


class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


		vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

		dist[src][0] = 0;

		int mini = INT_MAX;

		for (int i = 1; i <= k + 1; i++) {

			for (auto flight : flights) {

				int u = flight[0], v = flight[1], w = flight[2];

				if (dist[u][i - 1] != INT_MAX)
					dist[v][i] = min(dist[v][i], w + dist[u][i - 1]);

				if (v == dst) mini = min(mini, dist[v][i]);
			}

		}

		if (mini == INT_MAX) return -1;
		return mini;





	}
};

// t.c. = O(E*K)
// s.c. = O(N*K)
