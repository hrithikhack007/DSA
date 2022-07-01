// dfs and unordered map.

// take a unordered map of int,Node* . edge case: if give node is null return node else make a dfs call starting from the given node.
// at every func. call create a cloneNode of the current node. map current's node value to the clonedNode's address.
// now traverse all the child nodes of the current node and if the value of the child node is not mapped that means it is unvisited so make
// a dfs call on them. after returning of if the child was unvisited, the child's value will be mapped to its clonedNode address so push
// this cloneNode address in the current cloneNode's neigbors vector.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

	Node* dfs(Node* node, unordered_map<int, Node*> &mp) {

		Node *cloneNode =  new Node(node->val);
		mp[node->val] = cloneNode;

		for (auto child : node->neighbors) {

			if (mp.find(child->val) == mp.end()) {
				dfs(child, mp);
			}

			cloneNode->neighbors.push_back(mp[child->val]);
		}


		return cloneNode;


	}

	Node* cloneGraph(Node* node) {

		if (!node) return node;

		unordered_map<int, Node*> mp;

		return dfs(node, mp);


	}
};

// t.c. = O(N+E) where N is the no. of nodes in the graph
// s.c. = O(N)(map) + O(N+E)(space to store the cloned graph) + O(N)(stack space)

// using bfs and map. edge case: if node is null return node. take unordered map of int,Node*. take a queue of Node*. create a clone node
// of given node and map its value with the cloned node address. push the given node into queue. while q is not empty, get the front
// node as curr and pop it out of queue. traverse all of its child nodes and if its child node's value is not mapped with its cloned child
// node that means it is unvisited so kindly create a clone node of child and map its value to the address of child clone and push the child
// into queue,  also push the clone of this child into curr nodes's clone neigbors vector.

class Solution
{
public:

	Node* cloneGraph(Node *node)
	{

		if (!node) return node;

		unordered_map<int, Node*> mp;

		queue<Node*> q;
		q.push(node);
		mp[node->val] = new Node(node->val);

		while (!q.empty())
		{

			auto curr = q.front();
			q.pop();

			for (auto child : curr->neighbors)
			{

				if (mp.find(child->val) == mp.end())
				{
					mp[child->val] = new Node(child->val);
					q.push(child);
				}

				mp[curr->val]->neighbors.push_back(mp[child->val]);
			}
		}

		return mp[node->val];
	}
};


// t.c. = O(N+E)
// s.c. O(N)(map) + O(N+E)(space to store cloned graph)