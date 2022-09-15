
// set newroot to null, previous to null.
// call rec. function by passing root,previous,newRoot as arguments.
// now if root is null then return, else call on left subtree , after returning from it check if previous is null then we will make the current
// root as the newroot else we will set previous->right to root and prev->left to NULL.
// after this we will set previous to root and call on its right subtree.
// we want sorted list therefore we are doing inorder traversal as inorder traversal of bst generates a sorted sequence.

void rec(TreeNode<int>* &root, TreeNode<int>* &previous, TreeNode<int>* &newRoot) {

    if (root == NULL) return;

    rec(root->left, previous, newRoot);
    if (previous == NULL) {
        newRoot = root;
    } else {
        previous->right = root;
        previous->left = NULL;
    }
    previous = root;
    rec(root->right, previous, newRoot);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int> *newRoot = NULL, *previous = NULL;

    rec(root, previous, newRoot);
    previous->left = NULL;
    return newRoot;
}

// t.c. = O(N)
// s.c. = O(N) or O(H)

// just use morris inorder traversal.
// edge case: after the while loop is over previous will be pointing at the last node in the inorder traversal so make sure to make it's left as
// NULL.

TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int> *newRoot = NULL, *previous = NULL, *curr = root;

    while (curr) {

        if (curr->left) {

            TreeNode<int> *pred = curr->left;

            while (pred->right != NULL && pred->right != curr) pred = pred->right;

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {

                previous->left = NULL;
                previous = curr;
                curr = curr->right;

            }

        } else {

            if (previous == NULL) {
                newRoot = curr;
            } else {
                previous->right = curr;
                previous->left = NULL;
            }

            previous = curr;
            curr = curr->right;

        }

    }


    previous->left = NULL;
    return newRoot;

}

// t.c. = O(N)
// s.c. = O(1)

