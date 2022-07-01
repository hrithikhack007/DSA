// brute force check all paths.

// we will make a rec. call from node 0 and keep variables res,mini where res initialized to 0 keeps track of path cost
// and mini will store the minimum cost path seen till now.
// if n==1 that means we have visited all nodes so the cost from node to 0 with give total cost path and we will minimize that
// using mini.
// else, we will mark the node as visited and  from node we have option to go from node 0 to n-1 if it is not visited we will
// make a rec. call to that node , decrement n by 1 and add the path cost from node to child in res.
// after checking all child nodes mark the node as false in visited before returning.



class Solution {
public:

	void rec(int node, vector<vector<int>> &cost, vector<bool> &visited, int n, int res, int &mini) {

		if (n == 1) {
			mini = min(mini, cost[node][0] + res);
			return;
		}

		visited[node] = true;

		for (int i = 0; i < cost.size(); i++) {
			if (!visited[i]) {
				rec(i, cost, visited, n - 1, res + cost[node][i], mini);
			}
		}

		visited[node] = false;
	}

	int total_cost(vector<vector<int>>cost) {
		// Code here

		int n = cost.size();

		vector<bool> visited(n, false);
		int res = 0;
		int mini = INT_MAX;

		rec(0, cost, visited, n, res, mini);
		return mini;



	}

// t.c. = O(N!)
// s.c. = O(N)(stack space)

// optimized using dp with bitmask.

// we can use bit mask dp here. we will make a mask of size n bits to represent the state of the visited cities so far.
// dp[bits][node] will state the minimum cost path we can achieve from node if the current state of visited cities are
// represented by mask.
// when bit contains only 1 set bit that means all cities are visited so return dist[node][0]
// else if dp[bits][node]!=-1 return dp[bits][node];
// else mark this city as visited by unsetting the node'th bit in bits.now, traverse all child of this node and if that city is
// unvisited then make rec. call on them also keep minimizing the distance from this node to last for all child nodes.
// in last mark this node as unvisited , save the minimum cost for this state and return it.


	class Solution {
	public:

		int rec(int node, int bit, vector<vector<int>> &cost, vector<vector<int>> &dp) {

			if (__builtin_popcount(bit) == 1) {

				return cost[node][0];
			}

			if (dp[bit][node] != -1) return dp[bit][node];

			int ans = INT_MAX;
			bit ^= ((1 << node));
			for (int i = 0; i < cost.size(); i++) {
				if (((1 << i) & (bit))) {

					ans = min(ans, rec(i, bit, cost, dp) + cost[node][i]);
				}
			}

			bit ^= (((1 << node)));


			return dp[bit][node] = ans;

		}

		int total_cost(vector<vector<int>>cost) {
			// Code here

			int n = cost.size();

			int bit = (1 << n) - 1;

			vector<bool> visited(n, false);
			int res = 0;
			int mini = INT_MAX;

			vector<vector<int>> dp((1 << n), vector<int>(n, -1));

			return rec(0, bit, cost, dp);


		}
	};

// t.c. = O((2^N)*(N)*(N))
// s.c. = O((2^N)*N) + O(N)(stack space)