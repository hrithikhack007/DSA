// set ok to true,call on rec. by passing root and ok as arguments,in each func. call , if root is null then return 0,
// else if it is a lead node then return its data, else call recursively on left subtree of root and store the left subtree
// sum , similarly call on the right subtree and store its sum.
// curr is root->data, if curr != leftsum + rightsum then update ok to false. after this return curr+leftSum + rightSum
// i.e. the sum of the subtree of root.


class Solution
{
public:

    int rec(Node *root, bool &ok) {

        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL && root->right == NULL) {
            return root->data;
        }

        int leftSum = rec(root->left, ok);
        int rightSum = rec(root->right, ok);
        int curr = root->data;

        if (curr != leftSum + rightSum) {
            ok = false;
        }

        return curr + leftSum + rightSum;

    }

    bool isSumTree(Node* root)
    {
        // Your code here
        bool  ok = true;
        rec(root, ok);
        return ok;

    }
};

// t.c. = O(N)
// /s.c. = O(H)