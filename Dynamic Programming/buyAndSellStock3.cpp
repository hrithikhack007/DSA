// dp[i][j][k] represents maximum profit we can get from ith day to n-1th day if the total j transactions has been completed and active status of
// transaction is k. if k is true that means one transaction is pending so we cannot buy else we can buy.
// if total == 2 that means we have performed 2 transactions and cannot peform more so return 0 also if idx reached the end of prices array then also
// we cannot do any transaction so return 0.
// else if dp[idx][total][active] is not -1 then it is already computed so return it.
// else, if active is true that means we cannot buy so we have two options either to sell on this day and close the transaction or do not sell
// so if we choose to do not close then we call rec(idx+1,total,active) else if we choose to close the transaction then we call rec(idx+1,total+1,(
//  active^1)) and also add prices[idx] as we are selling at that price i.e. number of total closed transaction increases by 1 and active is now
// false so we can buy from next index.we will choose the maximum of this two choices.
// else if active is false then we have again two choices, either to buy or not buy so if we choose not to buy then call on rec(idx+1,total,active),
// else if we buy then rec(idx+1,total,(active^1)) make active true as after buying a transaction is active and also subtract prices[idx] from it
// as we are buying so we have to pay that much amount, we will choose maximum of two choices.


class Solution {
public:

    int rec(int idx, int total, int active, vector<int> &prices, vector<vector<vector<int>>> &dp) {

        if (total == 2 || idx == prices.size()) return 0;

        if (dp[idx][total][active] != -1) return dp[idx][total][active];

        if (active) {

            return dp[idx][total][active] = max(rec(idx + 1, total, active, prices, dp), rec(idx + 1, total + 1, (active ^ 1), prices, dp) + prices[idx]);
        } else {

            return dp[idx][total][active] = max(rec(idx + 1, total, active, prices, dp), rec(idx + 1, total, (active ^ 1), prices, dp) - prices[idx]);

        }

    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));


        return rec(0, 0, 0, prices, dp);



    }
};

// t.c. = O(N*3*2) = O(N)
// s.c. = O(N*3*2) + O(N)(stack space) = O(N)

// iterative.
// just reverse the orde of evaluation as compared to recursion. rest base conditions and transitions remains exactly same.

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, -1)));

        for (int idx = n; idx >= 0; idx--) {

            for (int total = 2; total >= 0; total--) {

                for (int active = 1; active >= 0; active--) {

                    if (total == 2 || idx == n) {
                        dp[idx][total][active] = 0;
                    } else {

                        if (active) {

                            dp[idx][total][active] = max(dp[idx + 1][total][active], dp[idx + 1][total + 1][(active ^ 1)] + prices[idx]);
                        } else {
                            dp[idx][total][active] = max(dp[idx + 1][total][active], dp[idx + 1][total][(active ^ 1)] - prices[idx]);
                        }

                    }
                }
            }

        }


        return dp[0][0][0];

    }
};

// t.c. = O(N*3*2) = O(N)
// s.c. = O(N*3*2) = O(N)

// space optimizations.

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> curr(3, vector<int>(2));
        vector<vector<int>> prev(3, vector<int>(2));

        for (int idx = n; idx >= 0; idx--) {

            for (int total = 2; total >= 0; total--) {

                for (int active = 1; active >= 0; active--) {

                    if (total == 2 || idx == n) {
                        curr[total][active] = 0;
                    } else {

                        if (active) {

                            curr[total][active] = max(prev[total][active], prev[total + 1][(active ^ 1)] + prices[idx]);
                        } else {
                            curr[total][active] = max(prev[total][active], prev[total][(active ^ 1)] - prices[idx]);
                        }

                    }
                }
            }

            prev = curr;

        }


        return prev[0][0];
    }
};

// t.c. = O(N*3*2) = O(N)
// s.c. = O(3*2*2) = O(1)