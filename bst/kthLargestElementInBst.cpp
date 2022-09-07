// set ans to 0,call the rec. function by passing root,k,ans as arguments and in each call if root is null simply return,
//else move to root->right subtree and after returning from it check if k==0 that means we have already found the kth largest so return
// else decrement k  by 1 and if it becomes 0 then we are standing at the kth largest element so set ans to root->data and return.
// else move to root->left subtree.

// by doing normal inorder traversal we get the elements in increasing sorted order but doing revrese inorder traversal we get the sequence
// in decreasing order so we will decrement our k at each element and when we reach the kth largest that is kth element in reverse inorder
// traversal then our k would have become 0.

class Solution
{
public:

    void rec(Node *root, int &k, int &ans) {

        if (root == NULL) return;

        rec(root->right, k, ans);
        if (k == 0) return;
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        rec(root->left, k, ans);
    }

    int kthLargest(Node *root, int k)
    {
        int ans = 0;
        rec(root, k, ans);
        return ans;

    }
};

// t.c. = O(N)
// s.c. = O(H)

// iterative.
// take a stack of Node pointers.
// push root in the stack, set curr pointer to root.
// now, while stack is not empty, in each iteration check if curr is not null if true then push curr->right in the stack and move curr to
// curr->right, else pop from the stack , decrement k by 1 and if k is 0 then the top element is the kth largest element so return it
// else pop the node from top and assign it to node now node->right is completely traversed so push node->left in the stack and move curr
// to st.top() i.e. node->left.

class Solution
{
public:

    int kthLargest(Node *root, int k)
    {

        stack<Node*> st;
        st.push(root);
        Node *curr = root;

        while (!st.empty()) {

            if (curr) {
                st.push(curr->right);
                curr = curr->right;
            } else {
                st.pop();
                if (st.empty()) break;
                k--;
                if (k == 0) return st.top()->data;
                auto node = st.top();
                st.pop();
                st.push(node->left);
                curr = st.top();
            }
        }

    }
};

// t.c. = O(N)
// s.c. = O(N)