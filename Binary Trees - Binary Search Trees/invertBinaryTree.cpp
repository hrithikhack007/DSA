// recursion, dfs
// as we want mirror image, we will first create the mirror image of root's left and right subtree then before returning we will
// swap the left child with right and return root. because in mirror image , left part becomes right and right part becomes left.
// if root is null simply return null, else store the left subtree result in lef and store the right subtree result in rig then
// assign rig to root->left to and lef to root->right and return root.


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {


        if (!root) {
            return NULL;
        }


        TreeNode *lef = invertTree(root->left);
        TreeNode *rig = invertTree(root->right);

        root->left = rig , root->right = lef;
        return root;


    }
};

// t.c. = O(N)
// s.c. = O(H)


// iterative,bfs

// declare a queue of pointers.
// push root into queue.
// while q is not empty, take the size of the queue i.e. the number of nodes in the current level.
// traverse current level nodes and for each node, take it into node and pop it out from queue, then take node's left child and right
// child. and set node->left to rig and node->right to lef basically swapping left and right part. first check if right child exist
// then push it into queue then check if left child exist if it does then push it into queue. we are checking right first because it
// is now our new left and left is our new right.



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (!root) {
            return NULL;
        }


        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                auto node = q.front();
                q.pop();

                TreeNode *lef = node->left;
                TreeNode *rig = node->right;

                node->left = rig, node->right = lef;

                if (rig) {
                    q.push(rig);
                }
                if (lef) {
                    q.push(lef);
                }
            }
        }

        return root;

    }
};

// t.c. = O(N)
// s.c. = O(N/2)