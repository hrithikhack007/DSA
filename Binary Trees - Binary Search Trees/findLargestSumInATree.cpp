// set maxi to int min, call rec. function by passing root and maxi as arguments, in each rec. call if root is null then
// return 0, else call on left subtree which will return the left subtree sum and call on right subtree which will return
// right subtree sum , now maximize the maxi with leftSum + rightSum + root->data i.e. the current subtree sum and return
// the current subtree sum (lsum + rsum + root->data);



#include<bits/stdc++.h>

int rec(TreeNode<int> *root, int &maxi) {

    if (root == NULL) return 0;

    int leftSum = rec(root->left, maxi);
    int rightSum = rec(root->right, maxi);

    maxi = max(maxi, leftSum + rightSum + root->data);
    return leftSum + rightSum + root->data;
}

int largestSubtreeSum(TreeNode<int> *root) {
    // Write your code here.

    int maxi = INT_MIN;

    rec(root, maxi);

    return maxi;

}

// t.c. = O(N)
// s.c. = O(H)