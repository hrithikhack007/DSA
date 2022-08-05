// variation of coin change.
// dp[j] represents maximum profit we can get by taking exactly j kg of items.
// declare dp[W+1] with all -inf, set dp[0] to 0,maxi to 0.
// start iterating from i = 0 to N-1, for each i iterate from j = wt[i] to W , basically we want to calculate maximum profit we can get
// by taking exactly j items if we can choose only from first i items.
// so in each iteration, if we take the ith item then weight j will decrease by wt[i] so remaining weight will be j - wt[i] so what is
// the maximum profit we can get for that weight i.e. dp[j-wt[i]] + val[i] because we took ith item so add value of ith item and
// maximize it with dp[j] i.e. if we don't take this ith item and choose maximum from both.
// also j should be >= wt[i] then only we can take item of weight wt[i] in the bag of size j.
// maximize maxi with dp[j] because we can get optimal value at any weight j so maxi will store the final ans.


class Solution {
public:
    int knapSack(int N, int W, int val[], int wt[])
    {

        vector<int> dp(W + 1, INT_MIN);
        dp[0] = 0;

        int maxi = 0;

        for (int i = 0; i < N; i++) {

            for (int j = wt[i]; j <= W; j++) {

                if (dp[j - wt[i]] != INT_MIN) {

                    dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
                }

                maxi = max(maxi, dp[j]);

            }
        }

        return maxi;

    }
};

// t.c. = O(N*W)
// s.c. = O(W)
