// we want to check if tree rooted at root1 can become equal to tree rooted at root2 if we can swap any node's left and right subtree.
// base conditions: if root1 and root2 both are null then return true, else if only one is null then return false, else if root1->data
// is not equal to root2->data then return false.
// else, we can match left subtree of root1 to left subtree of root2 and right subtree of root1 match with right subtree of root2 that
// is if we don't decided to swap left and right subtree of root1 or we can match left subtree of root1 with right subtree of root2 and
// right subtree of root1 with left subtree of root2 that is we decided to swap left and right subtree of root1 and we will this choices
// for all the nodes down the left and right subtree of root1 and if either of the two choices returns true for all nodes then both trees
// are isomorphic and if for a node if both choices returns false then return false.


class Solution {
public:


  bool isIsomorphic(Node *root1, Node *root2)
  {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;



    if (root1->data != root2->data) return false;


    return (((isIsomorphic(root1->left, root2->left) &&  isIsomorphic(root1->right, root2->right))
             || (isIsomorphic(root1->left, root2->right) &&  isIsomorphic(root1->right, root2->left))));


  }
};

// t.c. = min(N1,N2)
// s.c. min(H1,H2)