// recursive.
// first we will declare an ans vector of int to store the boundary traversal of tree.
// we will push the root->data in ans array and if the root itself is a leaf node then we will simply return ans.
//else, we will make call on the left subtree of the root i.e. to store leftBoundary by passing root->left and ans as arguments, then
// in each func. call if root is null or root is lead node then return, else we first push the root->data in ans array then we will call
// on the left subtree again recursively else if root->left is null then we will recursively call on the right subtree.
// This will make sure to trace the path from root to leftmost leaf node.
// after this is over, we will store all the leaf nodes in the tree, for this we will pass root and ans as arguments in lead function,
// in each func. call, if root is null then return , else if root is leaf then push its data in ans and return, else recursively call on
// the left and right subtree.
// this will make sure to store all the leaf nodes in ans.
// after this is over, we will trace the path from root to rightmost leaf node, so we will call rightboundary by passing root->right and
// ans as arguments, in each func. call we will check if root is null or leaf then return else we will first make call on right subtree of
// root if it is not present then only call on the left subtree as we want rightmost node,so we will give preference to right subtree.
// now after returning from call we will push the root->data in ans because we want right boundary in reverse order.

// edge cases: when root->left is Null, that is why we are before hand storing root->data then calling on left part of root because if
// we directly make a call on root then it will see that left is null so it will try to find leaf on right side resulting in storing
// right subtree nodes in left boundary.so we will push root first then separately call on root->left subtree so it can't access right
// subtree nodes.
// root right subtree is NULL, therfore we are calling on root-right because root would already considered.
// root is a leaf node in this case after pushing root->data in ans return ans. because if we went to leaf function it will see root as
// a leaf and again push it into the ans so to avoid that we will directly return after considering root->data if it is leaf.


class Solution {
public:


	bool isLeaf(Node *root) {
		return (!root->left && !root->right);
	}

	void leftBoundary(Node *root, vector<int> &ans) {

		if (!root || isLeaf(root)) {
			return;
		}

		ans.push_back(root->data);

		leftBoundary(root->left, ans);
		if (root->left == NULL) leftBoundary(root->right, ans);
	}

	void leaf(Node *root, vector<int> &ans) {

		if (!root) {
			return;
		}

		if (isLeaf(root)) {
			ans.push_back(root->data);
			return;
		}

		leaf(root->left, ans);
		leaf(root->right, ans);


	}

	void rightBoundary(Node *root, vector<int> &ans) {

		if (!root || isLeaf(root)) return;


		rightBoundary(root->right, ans);
		if (root->right == NULL) rightBoundary(root->left, ans);

		ans.push_back(root->data);

	}

	vector <int> boundary(Node *root)
	{

		vector<int> ans;

		ans.push_back(root->data);

		if (isLeaf(root)) {
			return ans;
		}

		leftBoundary(root->left, ans);
		leaf(root, ans);
		rightBoundary(root->right, ans);


		return ans;




	}
};

// t.c. = O(N) + O(N) + O(N) = O(3*N) = O(N)
// s.c. = O(H) , excluding the space used for storing the ans
