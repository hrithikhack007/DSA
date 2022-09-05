// set prev to NULL, call rec. by passing root and prev.
// in each rec. call , if root is null then return, else traverse to right subtree and after returning from there the prev would be pointing
// to the last visited node in the right subtree that would be the inorder successor of the current node so assign root->next to prev and
// set prev to root, now traverse to the left subtree of the root.


class Solution
{
public:

    void rec(Node *root, Node *&prev) {

        if (root == NULL) return;

        rec(root->right, prev);
        root->next = prev;
        prev = root;
        rec(root->left, prev);
    }

    void populateNext(Node *root)
    {

        Node *prev = NULL;

        rec(root, prev);

    }
};

// t.c. = O(N)
// s.c. = O(H)