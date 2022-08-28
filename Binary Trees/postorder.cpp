// declare the postorder vector to store the postorder travresal of tree.
// call rec function by passing root and postorder as an argument.
// in each rec call if root is null simply return,else
// call on its left subtree then call on its right subtree so when both left and right subtree of root node is considered then push the
// root->val in postorder.


class Solution {
public:

    void rec(TreeNode *root, vector<int> &postorder) {

        if (!root) {
            return;
        }

        rec(root->left, postorder);
        rec(root->right, postorder);
        postorder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> postorder;

        rec(root, postorder);

        return postorder;

    }
};

// t.c. = O(N)
// s.c. = O(H) excluding the space used for storing the postorder traversal.


// iterative using one stack.
// declare the stack of pointers , curr pointer set to root , postorder vector of int to store postorder traversal.
// while curr is not null || st is not empty, in each iteration, if curr is not null then push that curr into stack and move to curr->left.
// else, set curr to st.top() -> right , if curr is not null then continue else set temp to null and while st is not empty and st.top()->right
// == temp then set temp to st.top(), pop the top node and push the temp in postorder vector. after while loop is over then if st is not empty
// then set curr to st.top()->right.

// intuition: we are first moving left - left - left - left... then when we hit null then we check if top->right exist if it does then
// that means left of top is over move curr to top->right and continue else if right has also become null that means for top, left and right
// is complete so we set temp to null and start checking if top->right is equal to temp if it does then that means right subtree of top is
// done so we assign temp to that top node and pop that node out of stack and push it in postorder vector and continue also, when top->right
// is not equal to temp then that means temp is not on right side of top so top left is complete but not its right so we stop the loop
// and if stack is not empty we assign curr to top->right and continue.


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {


        stack<TreeNode*> st;
        TreeNode *curr = root;

        vector<int> postorder;

        while (curr != NULL || (!st.empty())) {


            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {

                curr = st.top()->right;

                if (curr == NULL) {

                    TreeNode *temp = NULL;

                    while (!st.empty() && st.top()->right == temp) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }

                    if (!st.empty()) {
                        curr = st.top()->right;
                    }

                }
            }

        }

        return postorder;


    }
};


// t.c. = O(2*N) = O(N)
// in worst case every node has child to its right
// e.g. 1
//       \
//        2
//         \
//          3
//           \
//            4
//             \
//              5
//
// so here we will start curr from root 1 and store it in stack then try to move left it will be null so we will move curr to top->right 2
// then again after storing curr in stack we move curr to left again it becomes null so we move to top->right i.e. 3 and so on we will
// fill the stack till 5. now from 5 we will start checking top->right is temp in while loop so it will again run 5 times till we reach
// root so to insert 5 nodes in stack we require O(N) time and to pop out 5 nodes with loop we again did 5 operations so O(N) time
// therefore O(2*N) time in worst case.

// s.c. = O(N) stack, excluding space used to store postorder traversal.
