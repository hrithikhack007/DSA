// declare a dp[n][2].
// dp[i][0] stores the number of ways we can paint i fences such that it is valid and last 2 fence have same color,
// dp[i][1] stores the number of ways we can paint i fences such that it is valid and last 2 fence have different color.
// now set dp[1][0] = 0, dp[1][1] = k.
// run a loop from i=2 to n, in each iteration, set dp[i][0] to dp[i-1][1] and dp[i][1] to (dp[i-1][0] + dp[i-1][1])*(k-1).
// in all calculations take it under mod.
// return dp[n][0] + dp[n][1].

// intuition: now let's first see how to calculate dp[i][0], here if we use dp[i-1][0] then whatever color we choose to paint ith fence it won't result
// in exactly two consecutives color in last for e.g. if one of the combination in dp[i-1][0] is xxx11 then if I try to paint the ith fence with
// color 1 then it will result in three consecutives fences of same color so it will be invalid and for any other color it won't form two consecutive
// same colors in the last like xxx1y where y!=1 so we cannot choose any combination of dp[i-1][0] for calculating dp[i][0].
// so let's check dp[i-1][1], now for each combination in this we will have only one choice such that it results in same color for last 2 fences,
// e.g. if one of the combination is xxx1 then we can can color the ith fence with color 1 so last 2 will be of same color so we have only 1 choice
// for this combination and if it would've end with 2 then we will again have one option i.e. to paint it with 2 so dp[i][0] = dp[i-1][1]*1
// => dp[i-1][1].

// now let's see how to calculate dp[i][1], here we want last two to be different so for each combination in dp[i-1][0] and dp[i-1][1] we have k-1
// choices to paint the ith color. for e.g. if one of the combination in dp[i-1][1] is xxx1 then except 1 I can color ith fence with any color and
// it will result in two different colors in the last so if we have k colors then we have k-1 option for this combo.
// let's say one of the combo of dp[i-1][0] is xxxx11 then also we have k-1 choices for this combo as we cannot color the ith guy with 1 as it would
// cause three consecutive fences to have same color so except that we have remaining k-1 choices to paint the ith fence such that last 2 guy will
// have different color so dp[i][1] = (dp[i-1][0] + dp[i-1][1])*(k-1)

// final ans will be dp[n][0] + dp[n][1]



class Solution {
public:

#define ll long long
    ll mod = (ll)(1e9 + 7);

    long long countWays(int n, int k) {


        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

        dp[1][0] = 0, dp[1][1] = k;

        for (ll i = 2; i <= n; i++) {

            dp[i][0] = dp[i - 1][1];
            dp[i][1] = ((dp[i - 1][0] + dp[i - 1][1]) % mod * (k - 1) % mod) % mod;
        }

        return (dp[n][0] + dp[n][1]) % mod;



    }
};

// t.c. = O(N)
// s.c. = O(2*N) = O(N)

// we are just using prev state to calculate the new state so instead of storing all states we can store only last state and calculate currentstate
// with it and then asssign this curr to last state for the calculation of next state.
// take two variable prevSame and prevDiff which will act as dp[i][0] and dp[i][1].
// then in each iteration calculate the current state with the help of same and diff and after calculating make the curr states as prev states.

class Solution {
public:

#define ll long long
    ll mod = (ll)(1e9 + 7);

    long long countWays(int n, int k) {

        if (n == 1) {
            return k;
        }

        ll prevSame = 0, prevDiff = k;

        for (ll i = 2; i <= n; i++) {

            ll currSame = prevDiff;
            ll currDiff  = ((prevSame + prevDiff) % mod * (k - 1) % mod) % mod;

            prevSame = currSame;
            prevDiff = currDiff;
        }

        return (prevSame + prevDiff) % mod;



    }
};

// t.c. = O(N)
// s.c. = O(1)