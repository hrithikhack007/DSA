// recursive solution or dfs.
//at every root, calculate the maxdepth on its left subtree and maxdepth on its right subtree and take maximum from both and add 1.
// that it will be the maximum depth we can reach from the current root node so return it. basically each root node will return the maximum
// depth reachable from that node giving us the maximum depth of tree.


class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (!root) {
            return 0;
        }

        int leftMax = maxDepth(root->left);
        int rigMax = maxDepth(root->right);

        return max(leftMax, rigMax) + 1;

    }
};


// t.c. = O(N)
// s.c. = O(H)

// iterative or bfs.
// we can do level order traversal here, startring with depth=0 and after each level we will increment the depth by 1 so in the end depth
// will be the maximum depth of tree.
// declare queue of pointers, push root in queue, while queue is not empty take size of queue i.e. the nodes at current depth, iterate those
// nodes and take them in node from front of queue and pop the front , check if node->left exist if it does then push it in queue, similarly
// check for node->right if it exist then push it into queue, after traversing the curr depth and when the for loop ends increment the depth
// by 1.


class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (!root) {
            return 0;
        }

        queue<TreeNode*> q;

        q.push(root);

        int depth = 0;

        while (!q.empty()) {

            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                auto node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            depth++;
        }

        return depth;

    }
};

// t.c. = O(N)
// s.c. = O(N/2)