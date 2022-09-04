// if tree is empty then return -1.
// else, set a node pointer p to root and while p is not null update mini to p->data and move p to p->left.

int minValue(Node* root) {
    // Code here

    if (root == NULL) return -1;

    int mini = INT_MAX;

    Node *p = root;

    while (p) {

        mini = p->data;
        p = p->left;
    }

    return mini;



}

// t.c. = O(H)
// s.c. = O(1)