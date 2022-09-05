
// set lca to root, now run a while loop and in each iteration check if n1 and n2 both are greater than lca->data if it is then move to
// right else if n1 and n2 both are less than lca->data if it is then move to left else either n1 is < root->data and n2 > root->data or
// n1 > root->data && n2 < root->data then the nodes n1 and n2 are going to be in different subtrees and this is the lowest level where both
// nodes have the same ancestor so we return the node as the lca.


Node* LCA(Node *root, int n1, int n2)
{
    Node *lca = root;

    while (lca) {

        if (n1 > lca->data && n2 > lca->data) lca = lca->right;
        else if (n1 < lca->data && n2 < lca->data) lca = lca->left;
        else return lca;

    }
}

// t.c. = O(H)
// s.c. = O(1)

