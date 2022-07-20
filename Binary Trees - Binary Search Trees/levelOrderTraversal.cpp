// declare 2d vector to store all levels of the tree, queue of pointers.
// edge case: if root is null then return empty 2d vector else
// push root node in queue.
// while q is not empty , in each iteration, take the size of the queue that will tell us the number of nodes in the current level.
// so , run a loop from i=0 to sz-1 and in each time take the front node from queue as node and pop the front node , push the node in
// currlevel vector, check if node->left child exist if it does then push the node->left in queue also if node->right child exist then push
// node->right in queue.after the for loop push the currLevel in ans.



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (!root) {
            return {};
        }


        vector<vector<int>> ans;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            int sz = q.size();
            vector<int> currLevel;

            for (int i = 0; i < sz; i++) {

                auto node = q.front();
                q.pop();
                currLevel.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }

            }

            ans.push_back(currLevel);

        }

        return ans;




    }
};


// t.c.= O(N)
// s.c. = O(N/2) because see if the tree is complete binary tree and contains n levels so the last level will contain 2^x where x is
// n-1. and 2^x is also the maximum number of nodes we can have in the level or in the queue at a time. and the remaining nodes i.e.
// the nodes present from level 0 to x-1 will contain 2^x - 1 nodes so total nodes in tree is N = 2^x + (2^x-1) = 2^x + 2^x
// let's say 2^x is a then N = a + a = 2a. so our queue contains a nodes at max i.e. (N/2) nodes.