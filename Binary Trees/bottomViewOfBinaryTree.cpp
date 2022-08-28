// so we will decalare a map of int,pair<int,int> where key will be the x - cordinate and value will be a pair of int,int where
// first value is y - cordinate of the corresponding node and second value is the node->data.
// we are taking two parameters here i.e. x and y cordinate because there in tree there might be some nodes whose x cordinate are same
// but their y cordinates might differ so in that case we have to take the bottom most node which we will get to know by their y
// cordinate. In recursion or dfs of the tree, there might be cases where the deeper level nodes with same x-cordinate are visited first
// then the shallow level nodes or the shallow level nodes are visited first then then the deeper level nodes that is why we are taking
// two parameters here to compare the depth of nodes with same x cordinates.
// declare the ans array which will store the bottom view of binary tree.
// call the rec. function by passing root,x=0,y=0,mp as arguments. in each rec. call, if root is null then simply return, else if
// at the current x cordinate there is no node find in our map then we will simply map the current x cordinate with the x and node->data
// else if a node is present at the current x cordinate and depth of the current node is > than the map node the the current node is
// deeper at this x cordinate compared to map node so it should be in the bottom view or if the depths are equal then also we have to
// select the current as this node will be to the right side of the map node as we are calling left first then right. so in these
// conditions we will map x to the current node.
// after this we will make call on the left subtree by decrementing the x by 1 and incrementing the depth by 1 also we will call on the
// right subtree by incrementing the x cordinate by 1 and incrementing the y cordinate by 1.
// after the rec. is over then our map will store the bottom most node at each x cordinate of the binary tree.
// as map stores the key in sorted order we can simply iterate map and push the node->data in our ans array and it will stored from
// left to right.



class Solution {
public:

  void rec(Node *root, int x, int y, map<int, pair<int, int>> &mp) {

    if (root == NULL) {
      return;
    }

    if (mp.find(x) == mp.end()) {
      mp[x] = {y, root->data};
    } else {

      if (y >= mp[x].first) {
        mp[x] = {y, root->data};
      }
    }

    rec(root->left, x - 1, y + 1, mp);
    rec(root->right, x + 1, y + 1, mp);


  }

  vector <int> bottomView(Node *root) {

    map<int, pair<int, int>> mp;

    vector<int> ans;

    rec(root, 0, 0, mp);

    for (auto a : mp) {

      ans.push_back(a.second.second);
    }

    return ans;


  }
};

// t.c. = O(NLogN)
// s.c. = O(H) + O(N), excluding the space used for storing the ans.

// using level order + unordered map.
// edge case: if root is null simply return empty vector.
// declare and vector, unordered map of int,int where key is x-cordinate of the node and value is the node->data.
// queue of pair of int,int where first value is node address and second value is x cordinate of the corresponding node.
// push the root,0 in queue.also take mini=0,maxi=0 which will store the minimum and maximum x - cordinate of the binary tree.
// while q is not empty, in each iteration, take the size of the queue i.e. the number of nodes present in the current level.
// then traverse the curr level nodes and for each node take it in curr and pop the front from queue, take the node and xcordinate
// from curr and map the x cordinate with the node->data.after this check if node->left is present then push it into queue by
// decrementing the x cordinate by 1 and also if the node->right is present then push it into queue by incrementing the x cordinate
// by 1.minimize the mini and maximize the maxi with current x cordinate.
// after while loop is over, then iterate from minimum x cordinate to maximum x cordinate and push the node->data mapped to that
// x-cordinate.

// basically we are finding the bottom most and rightmost node for each x cordinate in the binary tree from left to right.


class Solution {
public:
  vector <int> bottomView(Node *root) {
    // Your Code Here

    if (root == NULL) {
      return {};
    }

    vector<int> ans;

    unordered_map<int, int> mp;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int mini = 0, maxi = 0;

    while (!(q.empty())) {

      int sz = q.size();

      for (int i = 0; i < sz; i++) {

        auto curr = q.front();
        q.pop();
        auto node = curr.first;
        auto x = curr.second;

        mp[x] = node->data;

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



