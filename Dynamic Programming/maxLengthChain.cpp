// first sort the pairs based on their first value in increasing order.
// set maxi to 1, declare dp[n] with all 1.
// iterate from i = 1 to n-1 and in each iteration loop from j=i-1 to 0 and in each of that iteration check if p[j].second < p[i].first
// then we can chain the ith pair behing the jth pair so maximize the dp[i] with dp[j]+1 where dp[x] stores the maximum length chain we can form
// if chain ends at the xth pair.
// after the inner loop is complete, dp[i] would be computed so maximize maxi with dp[i]. As the longest chain will end at some ith pair so maxi
// will store the ans.

// we have to sort because of cases like : (8,10),(12,17),(3,7). if we put smallest pair based on first value before then we can increase the length
// of chain. in the above example ans will be 2 but if we sort it then it will be (3,7),(8,10),(12,17) so now longest chain will be 3.


class Solution {
public:

    static bool comp(val a, val b) {

        return a.first < b.first;
    }

    int maxChainLen(struct val p[], int n) {


        sort(p, p + n, comp);

        int maxi = 1;

        vector<int> dp(n + 1, 1);

        for (int i = 1; i < n; i++) {

            for (int j = i - 1; j >= 0; j--) {

                if (p[j].second < p[i].first) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;


    }
};

// t.c. = O(NlogN + N^2) = O(N^2)
// s.c. = O(N)
