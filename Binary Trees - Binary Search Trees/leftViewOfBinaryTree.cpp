// if root is null simply return empty vector,
// else declare a ans vector which will store the left view of binary tree, then declare a queue of pointers, push root into queue
// while queue is not empty , in each iteration, take the size of the queue i.e. the number of nodes in the current level, traverse
// the current level nodes and in each iteration take the front of queue in node and pop the front node from queue, if i==0 that means
// it is the first node of this level so it will be present in our left view so push this node->val in ans array, then if node->left
// exist then push node->left in queue and if node->right exist then push node->right in queue.



vector<int> leftView(Node *root)
{

    if (root == NULL) {
        return {};
    }

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

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }

    }

    return ans;


}

// t.c. = O(N)
// s.c. = O(N/2)

// declare an ans array to store the left view of the binary tree, declare an unordered_set of int which will store the depth of
// tree.
// call the rec. function by passing root, depth, ans,currDepth =0 as arguments and in each rec call,if root is null simply return,
// else, if currDepth is not present in depth then this is the first node of this depth so this should be included in our ans
// so we will push the root->val in ans and also insert the currDepth in depth,then we will call on left subtree and right subtree and
// while calling we will increment the currDepth by 1.


void rec(Node *root, unordered_set<int> &depth, vector<int> &ans, int currDepth) {

    if (root == NULL) {
        return;
    }

    if (!depth.count(currDepth)) {
        depth.insert(currDepth);
        ans.push_back(root->data);
    }

    rec(root->left, depth, ans, currDepth + 1);
    rec(root->right, depth, ans, currDepth + 1);
}

vector<int> leftView(Node *root)
{

    if (root == NULL) {
        return {};
    }

    vector<int> ans;

    unordered_set<int> depth;

    rec(root, depth, ans, 0);

    return ans;



}

// t.c. = O(N)
// s.c. = O(H)(stack space) + O(H) set

// recursive solution without using set.
// we will keep two variables currDepth and maxDepth initialized to 0 and -1 respectively.
// so whenever currdepth is > than maxDepth that means we have found a new level and we are currently at the first node of that level
// so we will push that node->data into our ans and update the maxDepth to currDepth.
// then we will call on the left subtree and right subtree by incrementing the currDepth by 1.



void rec(Node *root, vector<int> &ans, int currDepth, int &maxDepth) {

    if (root == NULL) {
        return;
    }

    if (maxDepth < currDepth) {
        ans.push_back(root->data);
        maxDepth = currDepth;
    }

    rec(root->left, ans, currDepth + 1, maxDepth);
    rec(root->right, ans, currDepth + 1, maxDepth);
}

vector<int> leftView(Node *root)
{

    if (root == NULL) {
        return {};
    }

    vector<int> ans;

    int maxDepth = -1;

    rec(root, ans, 0, maxDepth);

    return ans;



}

// t.c. = O(N)
// s.c. = O(H)(stack space)

