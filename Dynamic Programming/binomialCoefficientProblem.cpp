// recursive + memo.

// we know that nCr = (n-1)C(r-1) + (n-1)C(r) by pascal's identity or pascal's triangle we can prove it.
// so we declare a 2D vector of size n,r initialized to -1.
// call the rec. function by passing n,r and dp as arguments and in each rec. call, if r>n then return 0, else if r==n or r==0 return 1.
// else if dp[n][r] is already computed so return dp[n][r], else call on rec(n-1,r-1) and rec(n-1,r) add their result take it under mod and save
// it in dp[n][r] and return it.

// as there are n*r different states possible and for each state we do O(1) operation so t.c. will be O(n*r)


class Solution {
public:

    int mod = (int)(1e9 + 7);

    int rec(int n, int r, vector<vector<int>> &dp) {

        if (r > n) {
            return 0;
        }

        if (r == n || r == 0) {
            return 1;
        }

        if (dp[n][r] != -1) return dp[n][r];

        return dp[n][r] = (rec(n - 1, r - 1, dp) % mod + rec(n - 1, r, dp) % mod) % mod;
    }

    int nCr(int n, int r) {


        vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

        return rec(n, r, dp);


    }
};

// t.c. = O(n*r)
// s.c. = O(n*r) + O(r)(stack space)

// iterative.
// just reverse the order of evaluation as compared to recursion.
// declare a 2d dp array of size (n+1,r+1) initialized to 0.
// then , start i from 0 to n and j from 0 to r as in rec. we were starting from n to 0 and r to 0 so it is just reverse.
// then base conditions are all same and recurrence is also same , ans will be stored in dp[n][r].

class Solution {
public:

    int mod = (int)(1e9 + 7);

    int nCr(int n, int r) {


        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

        for (int i = 0; i <= n; i++) {

            for (int j = 0; j <= r; j++) {

                if (j > i) {
                    dp[i][j] = 0;
                } else if (j == i || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
                }
            }
        }


        return dp[n][r];


    }
};

// t.c. = O(n*r)
// s.c. = O(n*r)

// space optimization.
// to calculate current state we are just looking one row behind so we don't need to store all the rows we can just store the prev row and use
// it to calculate the current states and then for the next state we can treat current as prev.
// so declare curr of size(r+1) and prev of size(r+1) both initialized to 0.
// dp[i] will be replaced with curr and dp[i-1] will be replaced with prev.
// after calculating current row make curr as a new prev.
// after calculating all the states, the final row/state will be stored in prev  i.e. dp[n] so the ans will be prev[r] i.e. dp[n][r].


class Solution {
public:

    int mod = (int)(1e9 + 7);

    int nCr(int n, int r) {


        vector<int> curr(r + 1, 0);
        vector<int> prev(r + 1, 0);

        for (int i = 0; i <= n; i++) {

            for (int j = 0; j <= r; j++) {

                if (j > i) {
                    curr[j] = 0;
                } else if (j == i || j == 0) {
                    curr[j] = 1;
                } else {
                    curr[j] = (prev[j - 1] % mod + prev[j] % mod) % mod;
                }
            }

            prev = curr;
        }


        return prev[r];


    }
};

// t.c. = O(n*r)
// s.c. = O(r)


