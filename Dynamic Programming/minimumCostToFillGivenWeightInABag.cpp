// it is a variation of coin combination.
// declare dp[W] with all intmax, set dp[0] = 0.
// dp[i] represents minimum cost to buy i kg of oranges using available packets.
// now iterate from i = 1 to i=N, and in each iteration if cost[i-1] != -1 i.e. if the ith kg packet is available then iterate from j=i to W,
// basically we want to minimize the cost to buy j kg from j = i to W where the last packet we buy will be ith kg packet and its cost will be cost[i-1].
// so in each iteration , check if dp[j-i] != intmax i.e. we can buy the j-i kg oranges using packets from 1 to i-1 kg. if it is true then
// minimize dp[j] with dp[j-i] + cost[i-1]. i.e. we are going to buy the ith kg packet and the tell me the minimum cost to buy the remaining j-i kg
// oranges.
// in last if dp[W] == intmax then we cannot buy W kg of oranges from available packets so return -1 else return dp[W].


class Solution {
public:

    int minimumCost(int cost[], int N, int W)
    {

        vector<int> dp(W + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= N; i++) {

            if (cost[i - 1] != -1) {

                for (int j = i; j <= W; j++) {

                    if (dp[j - i] != INT_MAX) {

                        dp[j] = min(dp[j], dp[j - i] + cost[i - 1]);
                    }
                }
            }
        }


        return (dp[W] == INT_MAX) ? -1 : dp[W];

    }
};

// t.c. = O(N*W)
// s.c. = O(W)