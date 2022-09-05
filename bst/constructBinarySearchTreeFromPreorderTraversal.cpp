// iterative.
// create a dummyRoot of val inf.
// create a root from the first element of the preorder.
// take a stack and push the dummyRoot in it i.e. the last node from which we took left and reach the root.
// now take a curr pointer and set it to root.
// set i=1 and while i<n , in each iteration, if preorder[i] < curr->val then we are going to create a new node on the curr->left to this
// curr will be the last node from which we took left so push curr in stack , after this create a new node of value preorder[i] and assign its
// address to curr->left and move curr to curr->left
// else if preorder[i] > curr->val then while preorder[i] > st.top()->val that means we cannot put preorder[i] in the left of st.top() as it
// is greater so set curr to st.top() and do st.pop(), after this loop is over preorder[i] would be < st.top()->val so we can create a new
// node of value preorder[i] and assign its address to curr->right and move curr to curr->right.
// after if , else increment i by 1.



class Solution
{
public:
    TreeNode* bstFromPreorder(vector<int> &preorder)
    {

        TreeNode *dummyRoot = new TreeNode(INT_MAX);
        TreeNode *root = new TreeNode(preorder[0]);

        stack<TreeNode*> st;
        st.push(dummyRoot);
        TreeNode *curr = root;

        int i = 1, n = preorder.size();

        while (i < n)
        {

            if (preorder[i] < curr->val)
            {
                st.push(curr);
                curr->left = new TreeNode(preorder[i]);
                curr = curr->left;
            }
            else
            {

                while (preorder[i] > st.top()->val)
                {
                    curr = st.top();
                    st.pop();
                }

                curr->right = new TreeNode(preorder[i]);
                curr = curr->right;
            }

            i++;
        }

        return root;
    }
};

// t.c. = O(2*N) = O(N)
// s.c. = O(N)


// Recursive.
// set idx to 0, call buildtree by passing prev = inf,idx=0,preorder as arguments.
// in each rec. call, if idx reached out of bounds or preorder[idx] > prev i.e. it is > than the last node->val from which we took left
// then we cannot create the node of value preorder[idx] here as it will create a node having value > than the node from which we took left
// resulting in a node in the left subtree having > value than it so we will return NULL in this cases.
// else, we will create a new node of value preorder[idx] and increment idx by 1. then we will call on its left by passing root->val as prev
// because we are taking left and assign it to root->left then we will call on root->right by passing prev as it is and assign it to root->right
// then we will finally return this root.

class Solution
{
public:

    TreeNode* buildTree(int prev, int &idx, vector<int> &preorder) {

        if (idx == preorder.size() || preorder[idx] > prev) return NULL;

        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = buildTree(root->val, idx, preorder);
        root->right = buildTree(prev, idx, preorder);
        return root;


    }

    TreeNode* bstFromPreorder(vector<int> &preorder)
    {
        int idx = 0;
        return buildTree(INT_MAX, idx, preorder);


    }
};

// t.c. = O(N)
// s.c. = O(H)