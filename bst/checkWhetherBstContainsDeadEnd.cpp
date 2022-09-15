// the dead end will be at leaf node only. if we reached null then return false , but if we reached the leaf node then we will check if the
// root->data + 1 is equals to lastLeft and root->data - 1 equals to lastRight if it is true then we have found the dead end so return true
// else return false, if we are not at the leaf node then we will call on the left subtree and right subtree and take or of their result because
// if dead end exists in any one of the subtree then we return true.

// intuition: here lastLeft is the value of the node from which we took the last left turn while reaching this node and lastRight is the value
// of the node from which we took the last Right turn to reach the current node.so if we want to attach some node on the left of the current node
// then it's value must be > than the lastRight because we are in the right subtree of that node with lastRight value similarly if we want to
// attach some node on right then its value must be < than the lastLeft because we are in the left subtree of that node's with lastleft value.
// so the condition for the leaf node to be dead end is if the lastleft is > than 1 and lastRight is smaller than 1 by the current node's value.
// so you cannot attach anything on its right as well on its right.


bool rec(Node *root, int lastLeft, int lastRight) {

    if (root == NULL) return false;

    if (root->left == NULL && root->right == NULL) {

        if (root->data + 1 == lastLeft && root->data - 1 == lastRight) return true;
        return false;
    }

    return rec(root->left, root->data, lastRight) || rec(root->right, lastLeft, root->data);
}

bool isDeadEnd(Node *root)
{

    return rec(root, INT_MAX, 0);

}


// t.c. = O(N)
// s.c. = O(N) or O(H)