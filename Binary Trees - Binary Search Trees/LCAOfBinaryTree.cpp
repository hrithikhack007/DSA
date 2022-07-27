// we will lca function by passing root , p and q as arguments then in each func. call if root is null then simply return null
// if root==p || root==q then return root, else call on left subtree and right subtree and saved their returned node.
// if left and right are not null that means root is the lca so return root else if left is not null then return left else return right

// intuition: if root itself is one of the two given nodes then it can be lca if other node is within its subtree .the other node can
// present in different subtree so we don't need to explore it's subtree we simply return it.else if root is not p or q,
// then after calling left and right subtree recursively if both of them returns not null node then root will be lca because we have
// found p and q under its subtree or else if we found just one of the node either in left or right we will return it i.e. the non
//null node else if we don't find any of two node within its subtree we will return NULL


class Solution {
public:

    TreeNode* lca(TreeNode *root, TreeNode *p, TreeNode *q) {


        if (root == NULL) return NULL;

        if (root == p || root == q) return root;

        TreeNode *Left = lca(root->left, p, q);
        TreeNode *Right = lca(root->right, p, q);

        if (Left && Right) return root;
        else if (Left) return Left;
        else return Right;


    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return lca(root, p, q);


    }
};

// t.c. = O(N)
// s.c. = O(H)