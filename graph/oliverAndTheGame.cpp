// using lca.


// by observation we can see that oliver can find bob only when they both are in the same path i.e. their lca is same.
// so we will first find the levelorder traversal of the tree and then calculate 2^k parent of each node where k is from 0 to
// log2(N).
// we know that 2^n = 2^(n-1) + 2^(n-1) so similarly 2^n th parent of node is the 2^(n-1) th parent of 2^(n-1) parent of the node.
// if 2^(n-1) th parent of the node does not exist so 2^n th parent can also not exist so we break there.

// we precalculate the level of each node using dfs.
// for each query we will find the lca and if lca is not bob && oliver then no else we check if lca is o and t is 0 that means
// oliver is above bob and also heading towards root so he can't reach bob or lca is b and t is 1 that means oliver is below bob in
// path and also heading away from root node so can't reach bob hence in this cases return no else return no. also if o==b return
// yes.

// in find lca we just need to make the level of o and b equal so we calculate the difference between their level and move the higher
// level node up by the power of 2 so that it reaches the same level as lower level node.
// k is the initial power of 2 we are starting with and d is 2^k. at every iteration, we check if d is <= diff so move the node a up
// by d distance and also decrease the diff by d. and decrease k and divide d by 2 to reach k-1th power of 2. stop when d becomes 0.

// if after making levels of both node same and still a is not equal b then return -1 else return a.


#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define inf 1E18
#define ninf -1*1E18
#define mod 1000000007
#define fi first
#define si second
#define pb push_back
#define vi vector<long long int>
#define pi pair<long long int,long long int>
#define vpi vector<pair<long long int,long long int>>
#define vvi vector<vector<long long int>>
#define umii unordered_map<ll,ll>
#define sinf INT_MAX
#include<limits>
using namespace std;

int findLca(int a, int b, vvi &dp, vi &level) {

	if (level[b] > level[a]) swap(a, b);


	ll diff = level[a] - level[b];

	ll k = 30;
	ll d = pow(2, k);

	while (d > 0) {


		if (d <= diff) {

			a = dp[a][k];
			diff -= d;

		}
		d /= 2;
		k--;

	}

	if (a == b) return a;
	return -1;



}


string f(int t, int b, int o, vvi &dp, vi &level) {

	if (o == b) return "YES";


	ll lca  = findLca(b, o, dp, level);

	// cout << t << " " << b << " " << o << " " << lca << "\n";

	if ((lca != o && lca != b) || (t == 0 && lca == o) || (t == 1 && lca == b)) {
		return "NO";
	}

	return "YES";



}


void dfs(int node, int par, vi adj[], vi &level, int l) {

	level[node] = l;

	for (auto child : adj[node]) {
		if (child != par) {
			dfs(child, node, adj, level, l + 1);
		}
	}

}


void answerNikalBc() {

	ll n;
	cin >> n;

	vi adj[n + 1];
	vi level(n + 1, 0);
	vi par(n + 1, -1);

	for (ll i = 0; i < n - 1; i++) {

		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1, adj, level, 0);

	queue<int> q;

	q.push(1);

	int k = log2(n);


	vvi dp(n + 1, vi(k + 1, -1));


	while (!q.empty()) {

		int sz = q.size();

		for (int i = 0; i < sz; i++) {

			auto node = q.front();
			q.pop();
			level.push_back(node);

			for (auto child : adj[node]) {

				if (child != par[node]) {
					par[child] = node;
					q.push(child);
					dp[child][0] = node;
				}

			}

		}

	}

	for (auto node : level) {

		for (int power = 1; power <= k; power++) {

			if (dp[node][power - 1] == -1) break;

			dp[node][power] = dp[dp[node][power - 1]][power - 1];

		}

	}



	ll qu;
	cin >> qu;

	for (ll i = 0; i < qu; i++) {

		ll t, b, o;

		cin >> t >> b >> o;

		cout << f(t, b, o, dp, level) << "\n";

	}



}




int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	answerNikalBc();


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

	return 0;
}


// t.c. = O(N) + O(N*logN) + O(Q*log(N))
// s.c. = O(N) + O(N*logN)


// using intime and outtime(maxtime)

// we will take an time of insertion array ti and max time of insertion array maxti , a timer initialized to 0.
// we will make a dfs call from node 1.
// at each dfs call we will first set the maxti and ti of node as ++timer.
// we will traverse the adjacent childs of node and if child is not parent then we will try store the maxiti of the node by
// maxti of its child.

// for each query we will first check does both oliver and bob belongs to the same subtree to check if node b is under the subtree
// of node a time of insertion of b must be > than the time of insertion of node a and also time of insertion of node b must be <=
// max timer of insertion of node a.
//if the above condition is false then return no, else if node o is under subtree of node b and t is 1 then return no else yes
// or if node b is under subtree of node o and t is 0 then return no else yes. if o==b then return yes.

#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define inf 1E18
#define ninf -1*1E18
#define mod 1000000007
#define fi first
#define si second
#define pb push_back
#define vi vector<long long int>
#define pi pair<long long int,long long int>
#define vpi vector<pair<long long int,long long int>>
#define vvi vector<vector<long long int>>
#define umii unordered_map<ll,ll>
#define sinf INT_MAX
#include<limits>
using namespace std;




string f(int t, int b, int o, vi &maxti, vi &ti) {

	if (o == b) return "YES";


	if ((ti[o] >= ti[b] && ti[o] <= maxti[b])) {

		return t == 1 ? "NO" : "YES";

	} else if ((ti[b] >= ti[o] && ti[b] <= maxti[o])) {

		return t == 0 ? "NO" : "YES";

	} else {
		return "NO";
	}




}


void dfs(int node, int par, vi adj[], vi &maxti, vi &ti, int &timer) {

	maxti[node] = ti[node] = ++timer;

	for (auto child : adj[node]) {
		if (child != par) {
			dfs(child, node, adj, maxti, ti, timer);
			maxti[node] = max(maxti[child], maxti[node]);
		}
	}

}


void answerNikalBc() {

	ll n;
	cin >> n;

	vi adj[n + 1];
	vi maxti(n + 1, 0), ti(n + 1, 0);
	int timer = 0;

	for (ll i = 0; i < n - 1; i++) {

		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1, adj, maxti, ti, timer);





	ll qu;
	cin >> qu;

	for (ll i = 0; i < qu; i++) {

		ll t, b, o;

		cin >> t >> b >> o;

		cout << f(t, b, o, maxti, ti) << "\n";

	}



}




int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	answerNikalBc();


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

	return 0;
}


// t.c. = O(N) + O(Q)
// s.c. = O(N)