// recursive.
// if root is null then return false, if root->data == x return true, if root->data < x then search in left subtree else search in right subtree



bool search(Node* root, int x) {


   if (root == NULL) return false;

   if (root->data == x) return true;

   if (x < root->data) return search(root->left, x);
   return search(root->right, x);


}

// t.c. = O(H)
// s.c. = O(H)

// iterative.

bool search(Node* root, int x) {


   Node *curr = root;

   while (curr) {

      if (curr->data == x) {
         return true;
      } else if (x < curr->data) {
         curr = curr->left;
      } else curr = curr->right;

   }

   return false;


}

// t.c. = O(H)
// s.c. = O(1)
