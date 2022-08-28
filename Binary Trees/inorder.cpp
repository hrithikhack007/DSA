// recursive.
// take a inorder array , call the rec. function by passing root and inorder array as an argument.
// at each rec. call if the root is null return.
// else, first explore the left subtree then after returning from left subtree push the root's val in inorder array then explore the
// right subtree.


class Solution {
public:

	void rec(TreeNode *root, vector<int> &inorder) {

		if (!root) return;

		rec(root->left, inorder);
		inorder.push_back(root->val);
		rec(root->right, inorder);
	}

	vector<int> inorderTraversal(TreeNode* root) {

		vector<int> inorder;

		rec(root, inorder);

		return inorder;

	}
};

//t.c. = O(N)
//s.c. = O(H)

// iterative.
// if root is null then return inorder;
// take a stack of TreeNode.
// take a pointer of type TreeNode node initialized to root.
// now, run a while loop till  till stack is not empty or node is not null, at each iteration check, if node is not null then push the node
// into stack and move the node to left child of node else if node becomes null then pop the top of the stack and push it into inorder
// array and move node to top's right child.

// intuition: we keep moving left while pushing the node encoutered to keep track of path and whenever the node hits null we know that
// left subtree of some node is completely explored and that node is on top of the stack so we pushed that node in inorder array after
// exploring its left subtree then pop it out of stack and then explored its right subtree.



class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {

		vector<int> inorder;

		stack<TreeNode*> st;

		TreeNode *node = root;

		while (!st.empty() || node) {

			if (node) {
				st.push(node);
				node = node->left;
			} else {

				node = st.top();
				st.pop();
				inorder.push_back(node->val);
				node = node->right;

			}

		}

		return inorder;


	}
};

// t.c. = O(N)
// s.c. = O(H) or O(N)


// worst case space occurs if the tree is a bamboo or linear tree.