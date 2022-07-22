// using map and recursion.

// we will declare a map of int,pair<int,int> where key will be the x-cordinate and value will be the pair where first value is
// y-cordinate and second value is the node->data at that x,y cordinate.
// we are taking x and y cordinates because there might be some nodes which are present at the same x-cordinate and different y-cordinate
// so in that case we have to use y-cordinate to pick up the top most node else we won't be able to tell the differnce of depth between
// /those nodes.
// declare a ans vector which will store the top view of binary tree.
// call rec function by passing root,x=0,y=0 and mp as arguments.
// in each rec call, if root is null then return else, if at the current x-cordinate we haven't found any node then simply map the
// current x cordinate with the current y cordinate and node->data, else if some node is already present at this x-cordinate but the
// y-cordinate or depth of that node is > than the current y-cordinate so it means current node is above that node so we will map
//  x cordinate with current y cordinate and root->data.
// after this we will explore left subtree by decrementing x by 1 and then right subtree by incrementing x by 1.
// after the recursive function call is over, we would have all the nodes from left extreme to right extreme x-cordinates of the binary
// tree. so we will iterate the map as the keys are stored in sorted order node with least x-cordinate that is the left most node
// will be present first so we will get the top view of binary from left to right nodes.

// intuition: we want the top level nodes at each x - cordinate of the binary tree.



class Solution
{
public:

    void rec(Node *root, int x, int y, map<int, pair<int, int>> &mp) {

        if (!root) {
            return;
        }

        if (mp.find(x) == mp.end()) {
            mp[x] = {y, root->data};
        } else {
            if (mp[x].first > y) {
                mp[x] = {y, root->data};
            }
        }

        rec(root->left, x - 1, y + 1, mp);
        rec(root->right, x + 1, y + 1, mp);
    }

    vector<int> topView(Node *root)
    {

        map<int, pair<int, int>> mp;

        vector<int> ans;

        rec(root, 0, 0, mp);

        for (auto a : mp) {
            ans.push_back(a.second.second);
        }

        return ans;

    }

};

// t.c. = O(N*Log(N))
// s.c. = O(H) + O(N)

// iterative,level order.

// declare an unordered map of int,int where key will be x-cordinate and value will be node->data.
// declare a queue of pair<Node*,int> where int is the x-cordinate of the corresponding node.
// push the root,0 in the q.
// also set mini = 0, maxi=0 i.e. the minimum and maximum x-cordinate of the binary tree.
// now, while q is not empty, in each iteration take the size of the queue, i.e. the number of nodes in the current level.
// now travrese the current level nodes, for each node, take out the front of the queue in curr and pop the front , take node as
// curr.first, x cordinate of node as curr.second.
// if no node is present at this x-cordinate then map this x cordinate with the node->data else if a node is already present in the
// map that means that node is present at top level of the current node so we won't consider the current node as it is present in the
// bottom of because we want the top - view of binary tree so we already considered the top level node for this x-cordinate.
// after this we will check if node->left is present then push it into queue with x-cordinate decremented by 1 and also if node->right
// is present then we will push it into queue with the xcordinate incrementing by 1.
// we will minimize the mini and maximize the maxi with the current x cordinate.
// after the while loop is over, we will start traversing from minimum x cordinate to maximum x cordinate of the binary tree and push
// the respective top level nodes in ans array at that x - cordinate i.e. from left to right.



class Solution
{
public:

    vector<int> topView(Node *root)
    {

        if (!root) {
            return {};
        }

        unordered_map<int, int> mp;

        vector<int> ans;

        queue<pair<Node*, int>> q;

        q.push({root, 0});

        int mini = 0, maxi = 0;

        while (!(q.empty())) {

            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                auto curr = q.front();
                auto node = curr.first;
                auto x = curr.second;
                q.pop();

                if (!mp[x]) {
                    mp[x] = node->data;
                }

                if (node->left) {
                    q.push({node->left, x - 1});
                }

                if (node->right) {
                    q.push({node->right, x + 1});
                }

                mini = min(mini, x);
                maxi = max(maxi, x);

            }

        }

        for (int i = mini; i <= maxi; i++) {

            ans.push_back(mp[i]);
        }

        return ans;

    }

};

// t.c. = O(N)
// s.c. = O(N)