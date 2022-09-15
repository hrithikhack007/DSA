// set maxi to 0. call rec. function by passing root and maxi as arguments. in each rec. call if root is null then return mini=inf,maxi=-inf,size=0.
// else, call on the left subtree and store its result in Left and call on right subtree and store its result in Right.
// now, check if left subtree is invalid or right subtree is invalid or the greatest value in the left subtree is > than root->data or smallest
// value in the right subtree is < root->data because on the left subtree every value should be < root->data and every value on right subtree
// should be > than root->val.so if either of the above conditions are true then we return mini=-1,maxi=-1,size=0 indicating that subtree is not bst.
// else if the subtree is valid then we will maximize our ans with the size of the current subtree and return the mini,maxi and size of the current
// subtree.
// so the mini value we will check in left subtree because in right every value is > than root->val so mini is min(root->data,Left[0]).
// and for maxi compare it with largest value in right subtree i.e. max(root->data,Right[1]).

class Solution {
public:

    vector<int> rec(Node *root, int &maxi) {

        if (root == NULL) {
            return {INT_MAX, INT_MIN, 0};
        }

        auto Left = rec(root->left, maxi);
        auto Right = rec(root->right, maxi);

        if (Left[0] == -1 || Right[0] == -1 || Left[1] >= root->data || Right[0] <= root->data) {
            return { -1, -1, 0};
        } else {

            maxi = max(maxi, Left[2] + Right[2] + 1);
            return {min(Left[0], root->data), max(Right[1], root->data), Left[2] + Right[2] + 1};

        }

    }

    int largestBst(Node *root)
    {

        int maxi = 0;

        rec(root, maxi);

        return maxi;

    }
};

// t.c. = O(N)
// s.c. = O(N) or O(H)

