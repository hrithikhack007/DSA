// we will find the toposort of the given graph then we will make a transpose graph by revresing all edges and do a second dfs
// on topo sort nodes which  will be separate the connected components which we will count and return.

// intuition: if you notice carefully, each connected component can be considered as a node and graph form by this nodes
// is known as condensed graph, in this condesed graph there will always be a node with 0-indegree. so we can use this condensed
// graph to evaluate the ordering of connected components. basically when we start from the 0-indegree node we are bound
// to visit every other nodes which is coming after that node similarly if we do a dfs from 2nd node in condesed graph then
// all connnected components from 2 to n will be visited and so on so the best case is to start dfs from reverse order of
// components so when we do a dfs on that component then no other component is going to be visited and from there we will do
// dfs on second last component here also all connected components which is having incoming edge towards this component won't
// be visited and this second last compo. will be having edge to last compo. but as it was already visited it won't call again
// in this way we can visit all connected components one by one.

// so that's why we found the topo sort of the original array so the initial nodes will be of 1st connected compo with 0 indegree
// then 2nd connected compo. which is having indegree from 1st and so on. after this we transpose the graph so now the first
// connected compo. will become last in order and we can do dfs calls from the originally found topo sort of the graph.
// as the topo sort contains the ordering according to the original array so the first component nodes will be present in starting
// but now we are doing dfs on transpose graph so this first component nodes are of last component in transpose graph.
// basically the ordering of toposort in transpose graph is reversed which help us to traverse the components from last to first.




class Solution
{
public:

	void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &topoSort) {

		visited[node] = true;

		for (auto child : adj[node]) {
			if (!visited[child]) {
				dfs(child, adj, visited, topoSort);
			}
		}

		topoSort.push_back(node);
	}

	void dfs2(int node, vector<bool> &visited, vector<int> adj[]) {

		visited[node] = true;
		for (auto child : adj[node]) {
			if (!visited[child]) {
				dfs2(child, visited, adj);
			}
		}
	}

	//Function to find number of strongly connected components in the graph.
	int kosaraju(int V, vector<int> adj[])
	{
		//code here

		vector<int> topoSort;
		vector<bool> visited(V, false);

		for (int i = 0; i < V; i++) {

			if (!visited[i]) {
				dfs(i, adj, visited, topoSort);
			}
		}

		reverse(topoSort.begin(), topoSort.end());

		fill(visited.begin(), visited.end(), 0);

		int count = 0;

		vector<int> transpose[V];

		for (int node = 0; node < V; node++) {

			for (auto child : adj[node]) {

				transpose[child].push_back(node);
			}
		}

		for (auto node : topoSort) {

			if (!visited[node]) {
				count++;
				dfs2(node, visited, transpose);
			}

		}

		return count;


	}
};


// t.c. = O(N+E)
// s.c. = O(N+E)