// set ans to -1, declare vector of int ancestors to store nodes from root to target node.
// call rec. function by passing root,k,node,ans,ancestors as arguments, then in each rec. call if root is NULL then return false, else
// if root->data == node then we have found the target node so if k > ancestors.size() then assign -1 to ans else assign (n - k)th ancestor
// from ancestors array to ans and return true.
// else, push the root->data in ancestors array and call on left subtree and right subtree if either of them return true then pop the
// ancestors array and return true i.e. we had found the target node within current root's subtree else pop the current value out of ancestor
// and return false.

// intuition: basically our ancestor array will store nodes from root to target node so the 1st ancestor will be entered last and second
// ancestor will be entered second last and so on till n-1th ancestor will be at 1st index and nth ancestor will be at 0th index so if we
// have to found 1st ancestor that means we have to take nth (n-1)th index value and if second ancestor then (n-2)th index and so on till
// if we have to found (n-1)th ancestor then we have to take 1st index and for nth ancestor we have to take 0th index so for kth ancestor we
// have to take (n-k)th ancestor as ancestors are stored in reverse order.


bool rec(Node *root, int k, int node, int &ans, vector<int> &ancestors) {

    if (root == NULL) return false;

    if (root->data == node) {

        ans =  k > ancestors.size() ? -1  : ancestors[ancestors.size() - k];
        return true;
    }

    ancestors.push_back(root->data);

    if (rec(root->left, k, node, ans, ancestors) || rec(root->right, k, node, ans, ancestors)) {
        ancestors.pop_back();
        return true;
    }

    ancestors.pop_back();
    return false;
}

int kthAncestor(Node *root, int k, int node)
{

    int ans = -1;
    vector<int> ancestors;

    rec(root, k, node, ans, ancestors);

    return ans;

}

// t.c. = O(N)
// s.c. = O(H)(stack space) + O(H)(ancestor array space) = O(2*H) = O(H)

// space optimized without using ancestor array.

// set ans to -1. call rec. function by passing root,k,node,ans as arguments and in each rec. call if root is NULL then return false,
// else if root->data is equal to node then we have found the target node so return true,
// else call on left subtree and right subtree, after this check if either left or right is true if yes that means target node is found
// undere current root's subtree so the current root might be the kth ancestor of target node so decrement k by 1 and if k becomes 0
// then current root is kth ancestor of target node so we store it in our ans and return false because we don't need to check above nodes
// now, else if k is not 0 then we return true that is the search is still active and if we haven't found the target node within current
// root's subtree so return false.

// intuition: after finding the target node we return true and for each of its ancestor we decrement k by 1 and if it is not zero
// we return true that means we still have to check above ancestors but at the moment it becomes 0 we would have reach the kth ancestor
// because to make k to 0 we have to decrement k by k times so the last decrement will always be at kth ancestor.


bool rec(Node *root, int &k, int node, int &ans) {

    if (root == NULL) return false;

    if (root->data == node) {
        return true;
    }

    auto Left = rec(root->left, k, node, ans);
    auto Right = rec(root->right, k, node, ans);

    if (Left || Right) {
        k--;
        if (k == 0) {
            ans = root->data;
            return false;
        } else return true;
    }

    return false;

}

int kthAncestor(Node *root, int k, int node)
{

    int ans = -1;


    rec(root, k, node, ans);

    return ans;

}

// t.c. = O(N)
// s.c. = O(H)(stack space)
