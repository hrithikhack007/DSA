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

// optimized using binary search.
// dp[i] represents maximum length of chain we can form using subset of pairs from 0 to i.
// first we will sort the pairs according to second value in increasing order.
// now set dp[0] to 1.
// iterate from i=1 to n - 1 and in each iteration, set dp[i] to 1.
// find the lower bound of the first value of the ith pair in the prefix
// i.e. the index of first pair whose second value is >= first value of ith pair. so that means all the pairs from the 0 to lb-1
// will have second value < first value of ith pair so do lb-- but if lb becomes -1 then we can't pair it with anyone but if it
// is not -1 then set dp[i] to dp[lb] + 1.
// also if we don't chain this pair then the remaining will be i-1 pairs so maximize dp[i] with dp[i-1].
// basically max of choices if we choose to chain this ith pair or do not choose to chain up the ith pair.



class Solution {
public:

    static bool comp(vector<int> a, vector<int> b) {

        return a[1] < b[1];
    }

    int lowerBound(int val, int l, int r, vector<vector<int>> &pairs) {

        int ans = 0;

        while (l <= r) {

            int mid = (l + r) / 2;

            if (pairs[mid][1] >= val) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return ans;

    }

    int findLongestChain(vector<vector<int>>& pairs) {

        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), comp);

        int maxi = 0;
        vector<int> dp(n);

        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            int lb  = lowerBound(pairs[i][0], 0, i, pairs);
            lb--;
            if (lb != -1) {
                dp[i] = dp[lb] + 1;
            }


            dp[i] = max(dp[i], dp[i - 1]);

        }

        return dp[n - 1];


    }
};

// t.c. = O(NLogN) + O(NLogN) = O(NLogN)
// s.c. = O(N)
