// call the rec. function by passing root,lb = -inf,ub = inf.
// now in each call, if root is null then return true.
// else if root->val >= upper bound or root->val <= lower bound return false.
// else call on left subtree by updating upper bound as root->val and call on right subtree by passing lower bound as root->val.
// return false if either of the call returns false so return and of left and right result.

// intuition: if we are at some node we want its value to be > lower bound because that lower bound is the last node->val from which we took
// right and reached the current node so for a tree to be in bst the current node->val must be greater than the lower bound as values on right
// are greater.
// similarly node->val should be < upper bound because that upper bound is the last node->val from which we took the left and reach the current
// node.

class Solution {
public:

    bool rec(TreeNode *root, long lb, long ub) {

        if (root == NULL) return true;

        if (root->val >= ub || root->val <= lb) return false;

        return rec(root->left, lb, root->val) && rec(root->right, root->val, ub);

    }

    bool isValidBST(TreeNode* root) {

        return rec(root, LONG_MIN, LONG_MAX);

    }
};

// t.c. = O(N)
// s.c. = O(H) (stack space).

// inorder traversal of the bst is always sorted in increasing order.
// so we will use this observation and perform the inorder travresal of the bst and whenever we find that the increasing sequence is breaking
// we mark ok as false that it is not a binary tree else if we don't encounter any dereasing sequence then return true.

// morris traversal.

// set prev to -inf, node to root,ok to true.
// now while node is not null, in each iteration, if node->left is not null then assign pred to node->left and run a while loop as long as
// pred->right is not null and pred->right is not equal to node then move pred to right.
// if pred->right is null then assign pred->right to node and move node to node->left.
// else if pred->right was node then that means we have already completed the inorder traversal of the left subtree of the node so now
// check if the node->val is > than the prev value of the node if not then set ok to false. set prev->right again to null , set prev to node->val
// and move node to node->right.

// else if node->left is null then check if node->val > prev if not then set ok to false.set prev to node->val and move node to right.


class Solution {
public:



    bool isValidBST(TreeNode* root) {

        long prev = LONG_MIN;

        TreeNode *node = root;
        bool ok = true;

        while (node) {

            if (node->left) {

                TreeNode *pred = node->left;

                while (pred->right != NULL && pred->right != node) pred = pred->right;

                if (pred->right == NULL) {

                    pred->right = node;
                    node = node->left;
                } else {

                    if (node->val <= prev) ok = false;
                    pred->right = NULL;
                    prev = node->val;
                    node = node->right;
                }

            } else {

                if (node->val <= prev) ok = false;
                prev = node->val;
                node = node->right;

            }

        }

        return ok;

    }
};

// t.c. = O(N)
// s.c. = O(1)