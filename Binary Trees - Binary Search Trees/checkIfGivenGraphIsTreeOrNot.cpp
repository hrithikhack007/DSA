// declare an adjacency list of size n. traverse the edges and form the edge between nodes in adjacency list.
// declare a vector of bool visited of size n and set it to false.
// set count to 0, and call the rec function by passing par=-1,node=0,adj,count,visited as arguments.
// in each rec. call,mark the node as visited, increment the count by 1, noe traverse the children of the node,
// for each child, if it is not visited then simply rec where par is now node and node is child and if it returns false that
// means there exist a cycle then return false, else if  child is not visited and child is != par that means there is a cycle
// so return false, else after traversing all children of node we didn't encounter cycle so return true.
// after the rec. function is completely over then, check if it returned false it it does then return false or if count is not
// equal to n then the graph is not connected it didn't visit all nodes starting from a single node so return false in this case
// as well else return true it is a tree.



bool rec(int par, int node, vector<int> adj[], int &count, vector<bool> &visited) {

    visited[node] = true;
    count++;

    for (auto child : adj[node]) {

        if (!visited[child]) {
            if (!rec(node, child, adj, count, visited)) return false;
        } else if (child != par) {
            return false;
        }
    }

    return true;
}

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    // write your code here


    vector<int> adj[n];

    for (auto edge : edges) {

        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    int count = 0;
    bool ok = rec(-1, 0, adj, count, visited);

    if (count != n || !ok) return false;
    return true;



}


// t.c. = O(E) + O(N+E) = O(N)
// s.c. = O(N+E) + O(N)(stack space) = O(N+E) = O(N)