
// create a dummyRoot of value inf and assign root to its left.
// set curr to root and par to dummyRoot.
// now while curr is not null then if curr->val is equal to key then simply break we have found the target node else set par to curr and if
// key < curr->val then move curr to left else move it to right.
// after the while loop is over, if curr is null that means we haven't found the key so return root as it is.
// now check on which direction the current is attached to its parent.
// if curr->left is null then assign curr->right to its parent in the correct direction else if curr->right is null then assign curr->left to
// its parent.
//else, find the inorder successor of the curr->val i.e. the node that comes just after the curr node in the inorder traversal, so we will replace
// the curr->val with the succ->val it will work because that succ->val will be the least in the right subtree of the curr node so all the nodes
// present in the right subtree of curr will be > than succ->val also as succ is present to the right of curr so all the values to the left of
// curr will be < than succ->val.
// so we will first set the succ to curr->right and succPar to curr, now we will move left till the succ->left != NULL and keep track of its
// parent now when we found the succ->val so we will assign its val to the curr->val and if the succPar is not curr then this succ will be attach
// to the left of its par so we will set succPar->left to succ->right else if succPar is curr itself so we will set curr->right to succ->right.
// in the end we will return dummyRoot->left.



class Solution
{
public:

    void assign(TreeNode *par, int dir, TreeNode *node) {

        if (dir) {
            par->right = node;
        } else par->left = node;

    }

    TreeNode* deleteNode(TreeNode *root, int key)
    {

        TreeNode *dummyRoot = new TreeNode(INT_MAX);
        dummyRoot->left = root;
        TreeNode *curr = root, *par = dummyRoot;

        while (curr)
        {

            if (curr->val == key)
            {
                break;
            }
            else if (key < curr->val)
            {
                par = curr;
                curr = curr->left;
            }
            else
            {
                par = curr;
                curr = curr->right;
            }
        }

        if (!curr) return root;

        int dir = curr->val < par->val ? 0 : 1;

        if (curr->left == NULL)
        {
            assign(par, dir, curr->right);
        }
        else if (curr->right == NULL)
        {
            assign(par, dir, curr->left);
        }
        else
        {

            TreeNode *succ = curr->right, *succPar = curr;

            while (succ->left != NULL)
            {
                succPar = succ;
                succ = succ->left;
            }

            curr->val = succ->val;
            if (succPar != curr)
                succPar->left = succ->right;
            else curr->right = succ->right;
        }

        return dummyRoot->left;
    }
};


// t.c. = O(H)
// s.c. = O(1)


// using recursion.

// if root is null return root,
// else if key < root->val then search in root->left and whatever it returns assign it to its root->left,else if key > root->val then search
// in root->right and whatever it returns assign it to its root->right,else if it is equal then:
// if any one of its child is NULL then return the non null child,else find the inorder successor of the root and set the root->val to
// succ->val then if succPar == root then set root->right to succ->right else set succPar->left to succ->right.
// return root in last.


class Solution
{
public:

    TreeNode* rec(TreeNode *root, int key)
    {

        if (root == NULL) return root;

        if (key < root->val)
        {
            root->left = rec(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = rec(root->right, key);
        }
        else
        {

            if (root->left == NULL || root->right == NULL)
            {

                TreeNode *child = root->left ? root->left : root->right;
                return child;
            }
            else
            {

                TreeNode *succ = root->right, *succPar = root;

                while (succ->left)
                {
                    succPar = succ;
                    succ = succ->left;
                }

                root->val = succ->val;

                if (succPar != root)
                {
                    succPar->left = succ->right;
                }
                else root->right = succ->right;
            }
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode *root, int key)
    {

        return rec(root, key);
    }
};

// t.c. = O(H)
// s.c. = O(H)