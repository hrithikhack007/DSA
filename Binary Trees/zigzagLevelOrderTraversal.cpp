// edge case: if root is null simply return empty 2-d vector.
// declare a 2-d vector of vector of int zigzag to store level order traversal.
// declare a queue and stack of pointers.
// push root in queue.
// set level to 0.
// while q is not empty , in each iteration, take the size of the queue i.e. the number of nodes in the current Level, also declare a
// currlevel vector to store the currlevel nodes.
// while travresing the current level nodes, take the front of queue in node and pop it out from queue,push the node->val in currlevel.
// take the left and right child of node in respective pointers. if level is odd then we want to first push right child then left child
// so swap left with right and push left and right in the stack if they are not null.
// after the level is complete, put the elements from the stack one by one in the queue and pop the top of stack.
// push the current level in zigzag array.
// increment level by 1.


// intuition: we want to traverse the even level from left to right and odd level from right to left.
// so at the even level we will push the left child of node first then right child into stack so after the traversal of that even level
// node , the rightmost child will be present at the top of the stack and in this way we will get the right to left nodes of the next
// level by popping the nodes from the stack and we will push them in queue so that the next level is traversed from right to left.
// similarly, when we are at the odd level node, we will push the right child first and left child in stack so after the level
// completion, we will have the leftmost node of the next level on top of stack, so we will pop the node from stack and push them into
// queue so now queue will contain nodes from left to right for the even level.


class Solution {
public:

    void insertIntoStack(TreeNode *First, TreeNode *Second, stack<TreeNode*> &st) {

        if (First) st.push(First);
        if (Second) st.push(Second);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


        if (root == NULL) {
            return {};
        }

        vector<vector<int>> zigzag;

        queue<TreeNode*> q;
        stack<TreeNode*> st;

        q.push(root);

        int level = 0;

        while (!q.empty()) {

            int sz = q.size();
            vector<int> currLevel;

            for (int i = 0; i < sz; i++) {

                auto node = q.front();
                q.pop();
                currLevel.push_back(node->val);

                TreeNode *leftChild = node->left;
                TreeNode *rightChild = node->right;

                if ((level & 1)) {
                    swap(leftChild, rightChild);
                }

                insertIntoStack(leftChild, rightChild, st);

            }

            while (!st.empty()) {
                q.push(st.top());
                st.pop();
            }

            zigzag.push_back(currLevel);

            level++;


        }

        return zigzag;

    }
};


// t.c. = O(2*N) = O(N)
// s.c. = O(N/2) = O(N)

// optimized space using indexing.

// if root is null simply return empty 2-d vector.
// declare a 2-d vector to store zigzag level order traversal.
// declare a queue of pointers.
// push root in queue.
// set level to 0.
// while queue is not empty, in each iteration, take the size of the queue i.e. the number of nodes in that level and also declare the
// vector currlevel of size sz to store nodes of that level.
// for each node in the current level, take it in the node pointer and pop it out from queue, if level is odd then take idx as sz - i - 1
// else i only.
// assign the node->val in currlevel[idx],if node->left is present then push it into queue and if node->right is present then push it into
// queue. after completion of the level , push the currlevel vector in zigzag vector and increment the level by 1.

// intuition: at odd level nodes we want to travrese from right to left so in the queue we have nodes stored from left to right fashion
// for each level, so to obtain right to left order ,we know that first node from the left will come last in right to left traversal
// and second node will come second last and so on till last node of from left to right will come first in right to left traversal.
// so we will beforehand declare the currlevel vector to the size of number of nodes in the currlevel. so if the level is odd we will place
// the ith node on sz-i-1 position in currlevel so it will store the nodes of the current level in reverse order resulting in right to
// left traversal of nodes at odd level.



class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


        if (root == NULL) {
            return {};
        }

        vector<vector<int>> zigzag;

        queue<TreeNode*> q;

        q.push(root);

        int level = 0;

        while (!q.empty()) {

            int sz = q.size();
            vector<int> currLevel(sz);

            for (int i = 0; i < sz; i++) {

                auto node = q.front();
                q.pop();

                int idx = (level & 1) ? (sz - i - 1) : i;

                currLevel[idx] = node->val;

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }

            }

            zigzag.push_back(currLevel);

            level++;


        }

        return zigzag;



    }
};

// t.c. = O(N)
// s.c. = O(N/2) = O(N)