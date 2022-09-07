// just do a basic inorder traversal of the bst and we know that the inorder traversal of bst generates sequence in increasing order
// so we will keep decrementing the k by 1 at each node and when k becomes 0 we know that we have reached kth smallest in bst so we save it
// in our ans. also set ans to -1 initially so if we don't find it we will return -1.

class Solution {
public:

  void rec(Node *root, int &k, int &ans) {

    if (root == NULL) return;

    rec(root->left, k, ans);
    if (k == 0) return;
    k--;
    if (k == 0) {
      ans = root->data;
      return;
    }
    rec(root->right, k, ans);
  }


  int KthSmallestElement(Node *root, int k) {
    int ans = -1;
    rec(root, k, ans);
    return ans;

  }
};

// t.c. = O(N)
// s.c. = O(H)

// iterative.
//take a stack of Node pointers and push the root in it. set curr to root.
// while stack is not empty, in each iteration, if curr is not null then push curr->left in the stack and move curr to curr->left.
// else we are at the null node so pop it out from stack and check if the stack becomes empty if it becomes empty that means we have traversed
// all the elements of tree and haven't found the kth smallest element so break. else decrement k by 1 and if k becomes 0 then simply
// return st.top()->data else set node to st.top(), pop it out and push its right in the stack and set curr to node->right.
// if the while loop is over then simply return -1.

class Solution {
public:


  // Return the Kth smallest element in the given BST
  int KthSmallestElement(Node *root, int k) {
    // add code here.

    stack<Node*> st;
    st.push(root);

    Node *curr = root;

    while (!st.empty()) {

      if (curr) {
        st.push(curr->left);
        curr = curr->left;
      } else {

        st.pop();
        if (st.empty()) break; //edge case.
        k--;
        if (k == 0) return st.top()->data;
        auto node = st.top();
        st.pop();
        st.push(node->right);
        curr = node->right;
      }

    }

    return -1;



  }
};

// t.c. = O(N)
// s.c. = O(N)

// using morris traversal.
// set curr to root, ans to -1.
// now while curr is not null, in each iteration, if curr->left exists then find its inorder predecessor, and if pred->right is null then
// set its right to  curr as it will be the last node which is going to be visited in the curr->left subtree so after its visit we can again
// return to curr so after setting pred->right to curr move curr to curr->left , else if pred->right is curr then we have traversed the left
// subtree of curr and this curr is the next node in the inorder traversal so decrement k by 1 and if k becomes 0 so set ans to curr->data
// after this move curr to its right subtree also set pred->right to NULL again.
// else if curr->left is null then curr is itself the next node in the inorder traversal so decrement k by 1 and if k becomes 0 set ans to
// curr->data and after this move curr to curr->right.

class Solution {
public:

  int KthSmallestElement(Node *root, int k) {
    Node *curr = root;
    int ans = -1;

    while (curr) {

      if (curr->left) {

        Node *pred = curr->left;

        while (pred->right != NULL && pred->right != curr) pred = pred->right;

        if (pred->right == NULL) {
          pred->right = curr;
          curr = curr->left;
        } else {

          k--;
          if (k == 0) ans = curr->data;
          pred->right = NULL;
          curr = curr->right;
        }

      } else {

        k--;
        if (k == 0) ans = curr->data;
        curr = curr->right;
      }

    }

    return ans;



  }
};

// t.c. = O(N)
// s.c. = O(1)
