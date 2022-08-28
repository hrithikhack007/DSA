// if root is null then return empty vector, else
// declare a ans vector to store right view of binary tree, a queue of pointers and push root in it.
// while q is not empty, in each iteration, take the size of queue, i.e. the number of nodes present in the current level and traverse
// those nodes , while traversing take the front node in node and pop it out from queue, if i==0 that means this is the last node of the
// current level because we will be pushing the nodes from right side. now if node->right is present then push node->right in q and if
// node->left is present then push node->left in queue. this will make sure that next level's last node is present at the front of the
// queue.


class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here

        if (!root) return {};

        vector<int> ans;

        queue<Node*> q;

        q.push(root);

        while (!(q.empty())) {

            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                auto node = q.front();
                q.pop();

                if (i == 0) {
                    ans.push_back(node->data);
                }

                if (node->right) {
                    q.push(node->right);
                }
                if (node->left) {
                    q.push(node->left);
                }

            }
        }

        return ans;


    }
};

// t.c. = O(N)
// s.c. = O(N/2), excluding space used to store ans.

// recursive.
// declare ans vector, maxdepth = -1,currdepth = 0.
// call rec by passing root,ans,currdepth,maxdepth as arguments, in each rec call,if root is null then simply return,else
// if currDepth > maxDepth then we have reached a new depth and currently present at the last node of that depth so we will push the
// root->data in ans and update the maxdepth to currdepth. then we will call on the left subtree and right subtree by incrementing the
// currdepth by 1.



class Solution
{
public:


    void rec(Node *root, vector<int> &ans, int currDepth, int &maxDepth) {

        if (!root) {
            return;
        }

        if (currDepth > maxDepth) {
            ans.push_back(root->data);
            maxDepth = currDepth;
        }

        rec(root->right, ans, currDepth + 1, maxDepth);
        rec(root->left, ans, currDepth + 1, maxDepth);
    }

    vector<int> rightView(Node *root)
    {

        if (!root) return {};

        vector<int> ans;

        int maxDepth = -1, currDepth = 0;

        rec(root, ans, currDepth, maxDepth);
        return ans;


    }
};

// t.c. = O(N)
// s.c. = O(H)