// first, do the inorder traversal of the tree and store the root->val in the values array.
// now using this sorted values array build a new balanced bst.
// so call the function buildTree by passing l=0,r = values.size()-1,values as arguments and in each func. call, if l>r return NULL,
// else , mid = (l+r)/2, and create a new node of values[mid] then call on the func. by passing l=l,r=mid-1 as argumenets and whatever it returns
// assign it to node->left,  similarly call on func. by passing l = mid+1,r=r and assign its returned value to node->right after this return
// the node.


Node* buildTree(int l, int r, vector<int> &values) {

    if (l > r) return NULL;

    int mid = (l + r) / 2;

    Node *node = new Node(values[mid]);

    node->left = buildTree(l, mid - 1, values);
    node->right = buildTree(mid + 1, r, values);
    return node;
}

void inorder(Node *root, vector<int> &values) {

    if (root == NULL) {
        return;
    }

    inorder(root->left, values);
    values.push_back(root->data);
    inorder(root->right, values);

}


Node* buildBalancedTree(Node* root)
{

    vector<int> values;

    inorder(root, values);

    return buildTree(0, values.size() - 1, values);

}

// t.c. = O(N) + O(N) = O(N)
// s.c. = O(N) + O(N) + O(N) = O(N)

// here instead of creating the new tree entirely we will be storing the node addresses in the vector of node* and simply use those nodes
// in the balances bst.

Node* buildTree(int l, int r, vector<Node*> &values) {

    if (l > r) return NULL;

    int mid = (l + r) / 2;

    Node *node =  values[mid];

    node->left = buildTree(l, mid - 1, values);
    node->right = buildTree(mid + 1, r, values);
    return node;
}

void inorder(Node *root, vector<Node*> &values) {

    if (root == NULL) {
        return;
    }

    inorder(root->left, values);
    values.push_back(root);
    inorder(root->right, values);

}


Node* buildBalancedTree(Node* root)
{

    vector<Node*> values;

    inorder(root, values);

    return buildTree(0, values.size() - 1, values);

}