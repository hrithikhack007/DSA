// declare a dp array of size n with all zeroes.
// dp[n] will represent number of ways/combinaton to form sum = n.
// set dp[0] to 1.
// start from 0th coin and iterate till m - 1 th coin and for each coin we will iterate from sum = S[coin] to n and for each sum we will
// calculate in how may ways we can form sum such that it ends with S[coin] i.e. x + S[coin] = sum therefore we are seeing dp[sum - S[coin]]
// i.e. x = sum - S[coin] , i.e. number of ways we can form x using first 'coin+1' coins let's say dp[x] is 3 so in those 3 ways if we add
// S[coin] then we can form the current sum so there are 3 ways we can have such that we can form the current sum by adding S[coin] in the end
// then we will add this ways in dp[sum] i.e. dp[sum] = dp[sum] + dp[sum-S[coin]] because we have found new ways to form sum.

// we don't want to count different permutations of same combination like if we can form sum like 2,2,3,5 then we just want to count it once and
// don't want to count 2,3,2,5 or 5,3,2,2, or 5,2,2,3 that's why we are choosing coin first and processing all the sum using that coin and calculating
// ways so that add that coin in the last to form sum so what will happen is after processing  first 2 coins , in our dp array we will have ways
// for every sum which we can form only using 0th and 1st coin and in that too 0th coin will come first and then 1st like 0th,0th,1th,1th
// or 0th,1th,1th and while we will process 2nd coin we will just add this 2nd coin in last to form sum so it will make ways like 0th,0th,1st,2nd
// 0th,0th,2nd or 0th,1th,2nd,1th,2nd,and so on so it will count a combination only once and not form any permutation.


class Solution {
public:

#define ll long long

    long long int count(int S[], int m, int n) {

        vector<ll> dp(n + 1, 0);

        dp[0] = 1;

        for (ll coin = 0; coin < m; coin++) {

            for (ll sum = S[coin]; sum <= n; sum++) {

                dp[sum] += dp[sum - S[coin]];
            }
        }

        return dp[n];



    }
};

// t.c. = O(N*M)
// s.c. = O(N)