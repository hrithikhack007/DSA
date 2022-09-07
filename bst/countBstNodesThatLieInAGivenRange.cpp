// set count to 0.
// call rec. function by passing root,l,h,count as arguments and in each rec. call if root is null then return , else if root->data is less than
// l then all nodes on left subtree of root is also going to be small than l so we will move towards right subtree of root and if root->data > h
// then all the nodes on right subtree of root will also be going to be > than h so we will move towards ths left subtree of the root,
// else if the root->data is within the range then the left nodes can also be within the range as well as the nodes on the right so first we
// will increment the count by 1 and call on the left and right subtree of root.


class Solution {
public:

    void rec(Node *root, int l, int h, int &count) {

        if (root == NULL) return;

        if (root->data < l) rec(root->right, l, h, count);
        else if (root->data > h) rec(root->left, l, h, count);
        else {
            count++;
            rec(root->left, l, h, count);
            rec(root->right, l, h, count);
        }
    }

    int getCount(Node *root, int l, int h)
    {
        int count = 0;

        rec(root, l, h, count);
        return count;


    }
};

// t.c. = O(N)
// s.c. = O(H)