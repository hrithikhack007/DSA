// recursive
//call the rec. function by passing root and preorder array as an argument. then at each recursion call, first push the node->data in
// preorder array then first call rec. on node->left subtree then on node->right subtree. if node is null then return.


class Solution {
public:

	void rec(TreeNode *root, vector<int> &preorder) {

		if (!root) return;

		preorder.push_back(root->val);
		rec(root->left, preorder);
		rec(root->right, preorder);

	}

	vector<int> preorderTraversal(TreeNode* root) {

		vector<int> preorder;

		rec(root, preorder);

		return preorder;


	}
};

// t.c. = O(N)
// s.c. = O(H)(stack space) , H is the height of the tree

// iterative.

// take a stack of treeNode. edge case: if root is null return preoder.
// push the root node in stack. while stack is not empty pop the top node of stack and push its val into preorder array , if node->right
// child is not null then push it into stack and if node->left child is not null then push it into stack.
// intuition: because we want to explore left subtree first and stack store elements in reverse order therefore we are pushing right
// child first then left child so on top of the stack left child is present and it will be explored before right.



class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {

		vector<int> preorder;

		if (!root) return preorder;

		stack<TreeNode*> st;

		st.push(root);

		while (!st.empty()) {

			auto node = st.top();

			st.pop();

			preorder.push_back(node->val);

			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);


		}

		return preorder;



	}
};

// t.c. = O(N)
// s.c. = O(N) or O(H)

//         1
//        / \
//       2   11
//      / \
//     4   3
//    / \
//   6   5
//  / \
//  7  8
// / \
// 9  10

// worst case space compleixity i.e. O(N) arises in this types of trees.