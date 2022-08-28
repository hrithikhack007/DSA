// prefix sum trick.
// first declare an unordered_map of long,long where key is the prefix sum and value is the current occurence of that sum.
// to avoid overflow of sum use long. set ans to 0 i.e. call rec. by passing root,targetSum,mp,ans,sum=0 as arguments.
// in each rec. call, if root is null then return, else, add the root->val to the sum now sum contains the sum of nodes from
// root to the current root. so if sum is equal to k then increment ans we have found 1 path. after this we will count the
// number of paths ending at the current root of path sum = k, to do this simply check mp[sum-k] which is the occurences of
// path from whose sum was sum -k so if we remove those paths then the remaining part will be of path sum = k, sum = (sum-k)+k
// (sum-k) removed and k remaining. this will give us the number of paths ending at current root with sum k. now we will
// increment the occurenece of sum in the map by 1. then recursively call on left subtree and right subtree.
// before returning, decrement the occurence of sum from map by 1 as we are returning from the current root so it is no longer
// in consideration in our path sum and after this subtract the root->val from sum.

// Also to limit the space complexity to O(H) we will remove the sum from map if its occurence becomes 0.



class Solution {
public:

  void rec(TreeNode *root, int k, unordered_map<long, long> &mp, int &ans, long sum) {

    if (root == NULL) return;

    sum += root->val;

    if (sum == k) {
      ans++;
    }

    ans += mp[sum - k];

    mp[sum]++;

    rec(root->left, k, mp, ans, sum);
    rec(root->right, k, mp, ans, sum);

    mp[sum]--;
    if (mp[sum] == 0) mp.erase(sum);
    sum -= root->val;

  }
  int pathSum(TreeNode* root, int targetSum) {


    unordered_map<long, long> mp;

    int ans = 0;

    rec(root, targetSum, mp, ans, (long)0);
    return ans;

  }
};


// t.c. = O(N)
// s.c. = O(H)

// clean and concised code.
// declare an unordered map of long,long.
// for sum=0 assign its occurence to be 1 so we don't have to check if the sum becomes = k separately it will be dealt
// by mp[sum-k] only because it will sum-k will be 0 if sum = k and we already have mp[0]=1 so it will consider that path.
// now call rec. by passing root, targetsum, mp,sum=0 as arguments, in each rec. call if root is null then simply return 0,
// else, add root->val to sum and in ans add mp[sum-k] i.e. the number of paths ending at current root with path sum k as
// explained in above approach. after this, increment the occurence of sum in mp by 1 , then recursively call on left subtree
// and right subtree ass their returned ans and add it to current ans. before returning decrement the sum in mp by 1 as we
// are removing the root->val from the path sum so its one of the occurenece is decreasing and also decrement the sum by
// root->val then return ans.


class Solution {
public:

  int rec(TreeNode *root, int k, unordered_map<long, long> &mp, long sum) {

    if (root == NULL) return 0;

    sum += root->val;

    int ans = mp[sum - k];
    mp[sum]++;

    ans += rec(root->left, k, mp, sum) + rec(root->right, k, mp, sum);

    mp[sum]--;
    if (mp[sum] == 0) mp.erase(sum);
    sum -= root->val;

    return ans;

  }
  int pathSum(TreeNode* root, int targetSum) {


    unordered_map<long, long> mp;

    mp[0] = 1;

    return rec(root, targetSum, mp, (long)0);


  }
};

// t.c. = O(N)
// s.c. = O(H)
