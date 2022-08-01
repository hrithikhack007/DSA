// declare dp[n] all with 1. dp[i] represents the maximum length subsequence i can get such that it ends at index i.
// set maxi = 1. for each i from 1 to n - 1, loop from j = i-1 to 0, and in each iteration if a[j] < a[i] then maximize dp[i] with dp[j] + 1.
// after the inner loop the lis ending at index i will be saved in dp[i] so maximize the maxi with dp[i]. Because lis of array will end at some i so
// we will get it in maxi.

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {

        vector<int> dp(n + 1, 1);

        int maxi = 1;

        for (int i = 1; i < n; i++) {

            for (int j = i - 1; j >= 0; j--) {

                if (a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;


    }
};

// t.c. = O(N*N)
// s.c. = O(N)