// set a bool ok to true, call rec function by passing root and ok as arguments, in each rec. call if root is null return 0.
// else, we will calculate the maxHeight of the left subtree and maxHeight of the rightSubtree. after this we will check if
// abs difference of left subtree height and right subtree height is <= 1 and update the ok accordingly.
// then we will simply return the maximum height we can reach from the current node i.e. max(leftheight,rightheight)+1.

class Solution {
public:

	int rec(TreeNode *root, bool &ok) {

		if (!root) {
			return 0;
		}

		int leftHeight = rec(root->left, ok);
		int rightHeight = rec(root->right, ok);

		ok = (ok && (abs(leftHeight - rightHeight) <= 1));

		return max(leftHeight, rightHeight) + 1;
	}

	bool isBalanced(TreeNode* root) {

		bool ok = true;

		rec(root, ok);

		return ok;

	}
};

// t.c. = O(N)
// s.c. = O(H)