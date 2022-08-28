// edge case: if root is null, then simply return empty vector.
// declare a queue of pointers, vector of int ans to store diagonal traversal of tree.
// push the root into queue.while the queue is not empty, take the size of the queue, i.e. the number of starting points for the current
// diagonal. so process all the starting points one by one and for each starting point take it into node from queue and pop the front of
// queue. now after taking the starting node run a loop again in which push the node->data in ans array and if its left child exist then
// push it into queue basically the starting node of next line, after this move node to node->right do this until we hit a null node.

// intuition: basically for every node, its line is defined by its right side because we want diagonals to be rightside down. so for
// every node we are traversing to its right till we reach null and also while traversing we want the starting points of the next line
// which will be present in node->left of the current line nodes, so we will push them into queue so after completion of the current diagonal
// we will have the starting nodes of the next diagonal ready in our queue and we will repeat the process till the queue becomes empty
// at that point we will know that we have traversed all the diagonals.
// and also for a given diagonal there can be multiple starting point nodes so we will process them one by one completely by taking the
// size of the queue initially and then iterating that many times so all the starting nodes are processed for that diagonal resulting in
// all the nodes of that diagonal to be visited.




vector<int> diagonal(Node *root)
{
	if (root == NULL) {
		return {};
	}

	queue<Node*> q;

	vector<int> ans;

	q.push(root);

	while (!q.empty()) {

		int sz = q.size();

		for (int i = 0; i < sz; i++) {

			auto node = q.front();
			q.pop();

			while (node) {
				ans.push_back(node->data);

				if (node->left) {
					q.push(node->left);
				}

				node = node->right;


			}

		}

	}

	return ans;

}

// t.c. = O(N)
// s.c. = O(N)
