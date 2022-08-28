// call the rec. function by passing node as an argument. In each rec. call, if node is null then simply return 0.
// else, now call on the leftsubtree which will return left subtree sum , call on the right subtree it will return right subtree sum.
// now the current subtree sum is node->val + leftsum + rightsum. also replace the node->data with leftSum + rightSum and return the
// current sum of this subtree.


class Solution {
public:

  int rec(Node *node) {

    if (node == NULL) return 0;

    int leftSum = rec(node->left);
    int rightSum = rec(node->right);

    int curr = leftSum + rightSum + node->data;
    node->data = leftSum + rightSum;
    return curr;

  }

  void toSumTree(Node *node)
  {

    rec(node);

  }
};

// t.c. = O(N)
// s.c. = O(H)