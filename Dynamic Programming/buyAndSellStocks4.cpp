// dp[idx][total][active] represents maximum profit we can get from idxth day to n-1th day if total transactions performed till now
// is 'total' and the active status of the transaction is 'active'.
// if active is true means a transactions is active and we cannot buy and if it is not active then we can buy.
// base condition: if idx==n then we cannot do any transaction so return 0 also if total == k that means we have already performed
// k transactions so we cannot do more so return 0.
// if dp[idx][total][active]!=-1 return dp[idx][total][active] because it is already computed.
// else, if active is true that means we cannot buy so we have two options either to sell on this day and close the transaction or do not sell
// so if we choose to do not close then we call rec(idx+1,total,active) else if we choose to close the transaction then we call rec(idx+1,total+1,(
//  active^1)) and also add prices[idx] as we are selling at that price i.e. number of total closed transaction increases by 1 and active is now
// false so we can buy from next index.we will choose the maximum of this two choices.
// else if active is false then we have again two choices, either to buy or not buy so if we choose not to buy then call on rec(idx+1,total,active),
// else if we buy then rec(idx+1,total,(active^1)) make active true as after buying a transaction is active and also subtract prices[idx] from it
// as we are buying so we have to pay that much amount, we will choose maximum of two choices.


class Solution {
public:

    int rec(int idx, int total, int active, int k, vector<int> &prices, vector<vector<vector<int>>> &dp) {

        if (idx == prices.size() || total == k) return 0;

        if (dp[idx][total][active] != -1) return dp[idx][total][active];


        if (active) {

            return dp[idx][total][active] = max(rec(idx + 1, total, active, k, prices, dp),
                                                rec(idx + 1, total + 1, (active ^ 1), k, prices, dp) + prices[idx]);
        } else {

            return dp[idx][total][active] = max(rec(idx + 1, total, active, k, prices, dp),
                                                rec(idx + 1, total, (active ^ 1), k, prices, dp) - prices[idx]);

        }



    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));


        return rec(0, 0, 0, k, prices, dp);

    }
};


// t.c. = O(N*K*2) = O(N*K)
// s.c. = O(N*K*2) + O(N)(stack space) = O(N*K)

// iterative.
// just reverse the order of evaluation as compared to recursion and rest base contitions and transitions remains same.


class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        for (int idx = n; idx >= 0; idx--) {

            for (int total = k; total >= 0; total--) {

                for (int active = 1; active >= 0; active--) {

                    if (idx == n || total == k) {
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


// t.c. = O(N*K*2) = O(N*K)
// s.c. = O(N*K*2) = O(N*K)

// space optimized.


class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> curr(k + 1, vector<int>(2)), prev(k + 1, vector<int>(2));

        for (int idx = n; idx >= 0; idx--) {

            for (int total = k; total >= 0; total--) {

                for (int active = 1; active >= 0; active--) {

                    if (idx == n || total == k) {
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

// t.c. = O(N*K*2) = O(N*K)
// s.c. = O(K*2) = O(K)


