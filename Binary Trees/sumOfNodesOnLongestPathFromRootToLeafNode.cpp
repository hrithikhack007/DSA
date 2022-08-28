// recursive, top to down.
// set maxHeight to -1 and maxHeightSum to 0, call the rec. function by passing root,height=0,sum=0,maxHeight and maxHeightSum
// as arguments.In each rec. call if root is null then return, else if root is a leaf node then the sum will contain the
// path sum from node to its parent so  we will add root->sum to this sum so it become totalsum of the path from root to
// lead then we will check if the current height of the tree is > maxHeight or current height == maxHeight && totalSum > max
// heightSum then update maxHeight to height and maxHeightSum to totalsum then after this return(outside the if statement)
// edge case: whenever reach leaf node always add its value to the sum and assign it to totalsum before comparing totalsum
// with maxHeightSum.
// if it is not a leaf node then, recursively call on the left subtree and right subtree by incrementing height by 1 and sum
// by root->data.

// intuition: basicallt we are traversing from root to leaf while keeping the sum of nodes and height of the path and depending
// on the height of the path and sum value we are updating maxheight and maxheightsum.


class Solution
{
public:

    void rec(Node *root, int height, int sum, int &maxHeight, int &maxHeightSum) {

        if (root == NULL) {
            return;
        }

        if (root->left == NULL && root->right == NULL) {

            int totalSum = sum + root->data;

            if (height > maxHeight || (height == maxHeight && totalSum > maxHeightSum)) {
                maxHeight = height;
                maxHeightSum = totalSum;
            }
            return;
        }

        rec(root->left, height + 1, sum + root->data, maxHeight, maxHeightSum);
        rec(root->right, height + 1, sum + root->data, maxHeight, maxHeightSum);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {

        int maxHeight = -1, maxHeightSum = 0;

        rec(root, 0, 0, maxHeight, maxHeightSum);

        return maxHeightSum;
    }
};

// t.c. = O(N)
// s.c. = O(H)

// iterative, level order.

// declare maxHeight to -1, maxHeightSum = 0 and height to 0.
// declare a queue of pair of Node*,int where first is the address of a node and second value is the sum of nodes in the path
// from root to the corresponding node's parent.
// push root,0 in queue, while queue is not empty, in each iteration, take the size of the queue i.e. the number of nodes in
// the current level the iterate the nodes in the current level and for each node take it in curr and pop the front from queue
// then take curr.first as node and sum as curr.second + root->data, now sum contains sum of nodes from root to node.
// if node is leaf then if the  current height is > maxHeight or current height == maxHeight but sum > maxHeightSum then
// update the maxHeight to height and maxHeightSum to sum.
// after this, if node->left exist then push node->left,sum in queue and similarly if node->right exist then push node->right,sum
// in queue.
// after the completion of current level, increment the height by 1.
// when queue becomes empty return  maxHeightSum.

class Solution
{
public:

    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here

        int maxHeight = -1, maxHeightSum = 0;
        int height = 0;

        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                auto curr = q.front();
                q.pop();
                auto node = curr.first;
                auto sum = curr.second + node->data;

                if (node->left == NULL && node->right == NULL) {

                    if (height > maxHeight || (height == maxHeight && sum > maxHeightSum)) {
                        maxHeight = height;
                        maxHeightSum = sum;
                    }
                }

                if (node->left) {
                    q.push({node->left, sum});
                }
                if (node->right) {
                    q.push({node->right, sum});
                }
            }

            height++;
        }

        return maxHeightSum;



    }
};

// t.c. = O(N)
// s.c. = O(N)

