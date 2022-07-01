// one pair defines two astronauts belong to same coutries so we will form a edge between this two nodes , in this way if a-b
// and b-c then a-b-c are in one component and belong to same country. we will store the number of nodes of each connected
// component. now nodes present in one component can pair only with nodes of other component so we have a variable s i.e.
// total no. of nodes and we will start from first component to last component.
// at each iteration we will subtract b from s where b is the no. of nodes in the current component (s-b) is the no. of nodes
// that can be paired up with the nodes of current component so we multiply them i.e. b*(s-b) and add it in our ans.
// also we will decrease s by b for future components because the current component already would have considered pairs with
// those components  so for any component  we only need to check for component ahead of them because component before them
//  would have been already considered.

// edge case: take long long as ans can be large.

void dfs(int node, vector<int> adj[], vector<bool> &visited, int &count) {

	visited[node] = true;
	count++;

	for (auto child : adj[node]) {
		if (!visited[child]) {
			dfs(child, adj, visited, count);
		}
	}

}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {

	if (n == 1) return 1;


	vector<int> adj[n];

	for (auto edge : astronaut) {
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}

	vector<bool> visited(n, false);
	vector<int> compoSize;
	long long s = 0;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int count = 0;
			dfs(i, adj, visited, count);
			compoSize.push_back(count);
			s += count;
		}
	}

	long long ans = 0;



	for (auto a : compoSize) {

		long long b = a;
		// cout<<b<<"\n";
		ans += ((s - b) * (1LL) * b);
		s -= b;
	}


	return ans;

}


// t.c. = O(N+E)
// s.c. = O(N+E)