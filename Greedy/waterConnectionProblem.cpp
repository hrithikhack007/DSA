// as each node will have no more than one incoming edge and outgoing edge, what we can do is store the indegrees of each node while forming
// adjacency list.
// Now, the 0 indegree node will be the starting point of a component and also there is an edge case that is even if the indegree of node is
// 0 but it should have 1 outgoing edge or else it will just be a component of 1 node so we cannot construct pair of tank and taps on one node.
// so if indegree of node is 0 and adj[node].size() > 0 then we will built tank on the ith node and we from the adjacency list we will try to
// find the last node of this component i.e. node with 0 outdegree.
// set minimum to the edge weight of the ith node and its adjacent node and set lastnode to adjacent node of ith node.
// now as long as adj[lastnode].size()>0 and lastnode is not i minimize the mini with the edge weight of current node and its adjacent node
// also set lastnode to its adjacent node.
// after the loop is over if the lastnode is not i that means we reached last node and there is no cycle in the component.
// so push the i,lastnode,mini in the ans.


class Solution
{
public:
  vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
  {
    vector<int> inDegree(n + 1, 0);

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < p; i++) {

      adj[a[i]].push_back({b[i], d[i]});
      inDegree[b[i]]++;
    }

    vector<vector<int>> ans;

    for (int i = 1; i <= n; i++) {

      if (inDegree[i] == 0 && adj[i].size() > 0) {

        int mini = adj[i][0].second;
        int lastNode = adj[i][0].first;

        while (adj[lastNode].size() > 0 && lastNode != i) {
          mini = min(mini, adj[lastNode][0].second);
          lastNode = adj[lastNode][0].first;
        }

        if (lastNode != i) ans.push_back({i, lastNode, mini});


      }
    }

    return ans;

  }
};

// t.c. = O(p) + O(n+p) = O(n+p)
// s.c. = O(n+p) + O(n) = O(n+p)