// declare a globalMax set to 0 , it will keep track of the longest path we have seen till now.
// make a rec call by passing root and globalmax as arguments,in each rec call if root is null then return 0, else take the maxdepth from
// root->left in leftmax , maxdepth from root->right in rightmax and if the longest path passing from this root i.e. leftmax + rightmax is
// is greater than globalmax then update the globalmax to current longest path.
// return max(leftmax,rightmax) + 1 i.e. the maximum depth reachable from this root node.

// intuition: at every root we are trying to find out the longest path passing from that root which we can calculate by maxdepth on its
// left and maxdepth on its right so if that path is > globalmaxi we update the globalmax, also while returning we are returning the max
// depth we can reach from the current root so its ancestor so it can calculate the longest path passing through it and similarly for
// all nodes , so the diameter will be one of the longest path passing through some node which we will keep in globalmax.


class Solution {
public:

	int rec(TreeNode *root, int &globalMax) {

		if (!root) return 0;

		int leftMax = rec(root->left, globalMax);
		int rightMax = rec(root->right, globalMax);

		globalMax = max(globalMax, leftMax + rightMax);

		return max(leftMax , rightMax) + 1;



	}

	int diameterOfBinaryTree(TreeNode* root) {

		int globalMax = 0;

		rec(root, globalMax);

		return globalMax;

	}
};

// t.c. = O(N)
// s.c. = O(H)