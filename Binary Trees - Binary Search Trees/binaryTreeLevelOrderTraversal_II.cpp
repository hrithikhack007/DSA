// first we will calculate the maxDepth of the given binary tree using dfs. so declare a variable maxdepth set to 0.
// call rec function with root,depth=0,and maxdepth, in each rec call , call on root->left subtree and incrementing depth by 1 also
// call on root->right subtree and incrementing depth by 1 then after returning from those calls maximizet the maxDepth with current
// depth. if root is null then return.

// declare a 2d vector of size maxdepth +1.
// call rec2 function by passing root , ans ,depth=0,maxdepth and in each rec2 call if root is null then return, else push the current root
// in ans[maxDepth - depth] vector basically upside down level. e.g.  if maxdepth is 3 and depth is 0 then node will be pushed into 3-0
// 3rd vector that is the top level nodes pushed in bottom level similalry if depth was 1 then it will be pushed into 3 - 1 = 2nd level
// so second level node is pushed into second last level so in this way we will get our reverse level order traversal.



class Solution {
public:

	void rec2(TreeNode *root, vector<vector<int>> &ans, int depth, int &maxDepth) {

		if (!root) {
			return;
		}

		ans[maxDepth - depth].push_back(root->val);
		rec2(root->left, ans, depth + 1, maxDepth);
		rec2(root->right, ans, depth + 1, maxDepth);

	}

	void rec(TreeNode *root, int depth, int &maxDepth) {

		if (!root) return;

		rec(root->left, depth + 1, maxDepth);
		rec(root->right, depth + 1, maxDepth);
		maxDepth = max(maxDepth, depth);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {

		if (!root) {
			return {};
		}

		int maxDepth = 0;

		rec(root, 0, maxDepth);

		vector<vector<int>> ans(maxDepth + 1);

		rec2(root, ans, 0, maxDepth);

		return ans;


	}
};


// s.c. = O(H), excluding space used for storing ans.
// t.c. = O(2*N) = O(N)

// It is almost similar to level order traversal , after storing all levels from top to bottom just reverse the ans array before
// returning.

class Solution {
public:



	vector<vector<int>> levelOrderBottom(TreeNode* root) {

		if (!root) {
			return {};
		}


		vector<vector<int>> ans;

		queue<TreeNode*> q;

		q.push(root);

		while (!q.empty()) {

			int sz = q.size();
			vector<int> currLevel;

			for (int i = 0; i < sz; i++) {

				auto node = q.front();
				q.pop();
				currLevel.push_back(node->val);

				if (node->left) {
					q.push(node->left);
				}

				if (node->right) {
					q.push(node->right);
				}
			}

			ans.push_back(currLevel);

		}

		reverse(ans.begin(), ans.end());

		return ans;




	}
};


// t.c. = O(N) + O(H)
// one O(N) for storing levels and another O(H) for reversing the levels which depends on height of tree.
//s.c. = O(N/2), excluding space used to store ans array.


// it is similar to first approach where we calculate the maxDepth of tree first then push the nodes in reverse level using 2nd dfs
// but here we will use queue and perform bfs.
// so maxDepth part will remain same then after that we will declare ans of size maxdepth+1, set depth to 0,then declare a queue ans push
// root in it. while q is not empty , in each iteration, take its size and run a for loop from 0 to sz-1 basicallt traverse all nodes
// at current depth, while traversing take the front node of queue and pop it out of queue, push the current node in its reverse level
// i.e. maxdepth - depth vector and check if it has left child then push that in queue also if it has right child then push it in queue.
// increment depth by 1 after finishing the for loop or finishing the current depth.


class Solution {
public:

	void rec(TreeNode *root, int depth, int &maxDepth) {

		if (!root) return;

		rec(root->left, depth + 1, maxDepth);
		rec(root->right, depth + 1, maxDepth);
		maxDepth = max(maxDepth, depth);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {

		if (!root) {
			return {};
		}

		int maxDepth = 0;

		rec(root, 0, maxDepth);

		vector<vector<int>> ans(maxDepth + 1);

		queue<TreeNode*> q;

		q.push(root);

		int depth = 0;

		while (!(q.empty())) {

			int sz = q.size();

			for (int i = 0; i < sz; i++) {

				auto node = q.front();
				q.pop();

				ans[maxDepth - depth].push_back(node->val);

				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}

			}

			depth++;

		}

		return ans;


	}
};


// t.c. = O(N) + O(N) = O(N)
// s.c. = O(H) + O(N/2) , exclusing space used to store ans array.
