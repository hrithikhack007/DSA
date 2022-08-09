// dp[l][r] represents minimum cost binary search tree constructed from the nodes in the range l to r.
// declare dp[n][n], prefix[n];
// create a prefix sum array of frequency.
// now using gap strategy, we will first calculate the minimum cost bst constructed of range 0-0,1-1,....then 0-1,1-2,and so on till 0-n.
// now, if gap is 1 i.e. there is only one node then cost will be freq[l] , else we will try to make each node in the range l to r as the root of
// bst and whichever gives minimum cost we will store that in dp[l][r].
// so start k from l and interate till r, in each iteration if k!=l then set ltree to dp[l][k-1] + prefix of (l,k-1) , if k!=r then set rtree to
// dp[k+1][r] + prefix of (k+1,r) and set root as freq[k] and then minimize the dp[l][r] with root + ltree + rtree.
// ans will be dp[0][n-1] => minimum cost bst constructed from nodes in the range 0 to n-1.

// intuition: basically in the loop from k=l to r, we are trying each node as the root , so the cost of the root will be freq[k] as it is on the
// first level, now all the nodes in the left of k will belong to left subtree so we want to add nodes from l to k-1 in the left subtree of kth
// node and we already calculated the minimum cost of bst constructed from nodes in the range l to k-1 but now all the nodes in that tree will
// go one level deeper as it is going to attached to the left of the kth node so we have to increment freq of all the nodes in that range by
// by one more time. for e.g. if let's say the kth node is 2 and left node is 1 and the freq of 1 is 10 so if we attached the node 1 in the left
// of 2 so the cost for 1 will be 2*10 i.e. we have to add freq of 1 again so similarly we have to add the sum of freq. of nodes in the range l to
//  k-1. that's why dp[l][k-1](already calculated cost) + prefix sum of (l,k-1)(additional cost to move all nodes one level deeper).
// similarly for the right subtree.



class Solution {
public:

    int pre(int l, int r, vector<int> &prefix) {

        if (l == 0) return prefix[r];
        return prefix[r] - prefix[l - 1];
    }

    int optimalSearchTree(int keys[], int freq[], int n)
    {


        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> prefix(n, 0);

        prefix[0] = freq[0];

        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + freq[i];


        for (int g = 1; g <= n; g++) {

            for (int l = 0; l + g - 1 < n; l++) {

                int r = l + g - 1;

                dp[l][r] = INT_MAX;

                if (g == 1) {
                    dp[l][r] = freq[l];
                } else {

                    for (int k = l; k <= r; k++) {

                        int ltree = 0, rtree = 0, root = freq[k];

                        if (k != l) {
                            ltree = dp[l][k - 1] + pre(l, k - 1, prefix);
                        }
                        if (k != r) {
                            rtree = dp[k + 1][r] + pre(k + 1, r, prefix);
                        }
                        dp[l][r] = min(dp[l][r], root + ltree + rtree);

                    }

                }


            }
        }

        return dp[0][n - 1];



    }
};

// t.c. = O(N^3)
// s.c. = O(N^2) + O(N) = O(N^2)
