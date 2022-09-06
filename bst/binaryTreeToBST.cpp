// first store all the node values in the array values by doing a normal pre order traversal of the binary tree.
// sort the values array.
// set idx to 0.
// do the inorder traversal of the tree and in each rec. call first call the left subtree then set root->data to values[idx] and increment idx
// by 1 and then move to root->right subtree.
// as we want to create a bst out of the binary tree in the same structure and the inorder traversal of the bst produce sorted sequence so we
// can simply setting the root->val to values[idx] by doing in order traversal and values are sorted in increasing order so the resultant tree
// will be bst.


class Solution {
public:

  void rec(Node *root, vector<int> &values) {

    if (root == NULL) return;

    values.push_back(root->data);
    rec(root->left, values);
    rec(root->right, values);
  }

  void inorder(Node *root, vector<int> &values, int &idx) {

    if (root == NULL) return;

    inorder(root->left, values, idx);
    root->data = values[idx++];
    inorder(root->right, values, idx);
  }

  Node *binaryTreeToBST (Node *root)
  {
    vector<int> values;

    rec(root, values);

    sort(values.begin(), values.end());
    int idx = 0;
    inorder(root, values, idx);
    return root;

  }
};

// t.c. = O(N) + O(NLogN) + O(N) = O(NLogN)
// s.c. = O(N) + O(N) = O(2*N) = O(N)

