// first store the inorder travresal of tree1 and tree2 in a and b by doing their inorder traversal.
// now both a and b have node addresses such that their values are sorted in increasing order.
// so merge this two sorted arrays into ans using two pointers.
// now build the balances bst using the merged sorted ans vector using divide and conquer technique.


void rec(TreeNode<int> *root, vector<TreeNode<int>*> &arr) {

    if (root == NULL) return;

    rec(root->left, arr);
    arr.push_back(root);
    rec(root->right, arr);
}

TreeNode<int> *buildTree(int l, int r, vector<TreeNode<int>*> &ans) {

    if (l > r) return NULL;

    int mid = (l + r) / 2;

    TreeNode<int> *node = ans[mid];
    node->left = buildTree(l, mid - 1, ans);
    node->right = buildTree(mid + 1, r, ans);
    return node;


}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
    vector<TreeNode<int>*> a, b;

    rec(root1, a);
    rec(root2, b);

    vector<TreeNode<int>*> ans;

    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {

        if (a[i]->data < b[j]->data) {
            ans.push_back(a[i++]);
        } else ans.push_back(b[j++]);
    }

    while (i < a.size()) {
        ans.push_back(a[i++]);
    }

    while (j < b.size()) {
        ans.push_back(b[j++]);
    }


    return buildTree(0, ans.size() - 1, ans);
}

// t.c. = O(N) + O(M) + O(N) + O(M) + O(N+M) = O(N+M)
// s.c. = O(H1) + O(H2) +  O(N) + O(M) + O(Log(N+M)) = O(N+M)
