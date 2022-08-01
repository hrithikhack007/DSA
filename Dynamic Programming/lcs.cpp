// recursion + memo.
// call the rec. function by passing i=0,j=0,s1,s2,dp as arguments and in rec. call if i==n or j==m return 0 because we cannot have any common
// subsequence if one of the string doesn't have any characters.
// else, if dp[i][j]!=-1 return dp[i][j] as this state is already calculated.
// if s1[i]==s2[j] then we have found a common character  call on rec(i+1,j+1) i.e. lcs of s1 and s2 from i+1,n and j+1,m and add 1 as the ith and jth
// character are equal so 1 + rec(i+1,j+1), we store it and return.
// else if they are not equal then we can keep i as it is and move j by 1 i.e. rec(i,j+1) i.e. the lcs of s1 and s2 from i,n and j+1,m or
// we can keep j as it is and move i by 1 i.e. rec(i+1,j) i.e. the lcs of s1 and s2 from i+1,n and j,m whichever returns maximum we will store it in
// and return


class Solution
{
public:

    int rec(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {

        if (i == s1.size() || j == s2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + rec(i + 1, j + 1, s1, s2, dp);
        } else {

            return dp[i][j] = max(rec(i, j + 1, s1, s2, dp), rec(i + 1, j, s1, s2, dp));
        }
    }

    int lcs(int x, int y, string s1, string s2)
    {
        int n = s1.size(), m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return rec(0, 0, s1, s2, dp);

    }
};

// t.c. = O(N*M)
// s.c. = O(N*M) + O(min(N,M))(stack space)

// iterative.
// dp[i][j] stores the lcs of string s1 and s2 from 0 to i-1 and 0 to j-1 respectively.
// now iterate from i from 1 to n and j from 1 to m, and in each iteration check if the i-1 th and j-1th character are equal if they are then we found
// a match so set dp[i][j] =  dp[i-1][j-1] + 1 i.e. the lcs of string s1 and s2 just before this two characters and added 1 because of the newly found
// match. else, if they are not equal then skip ith character of string s1 and check dp[i-1][j] or skip jth character of s2 and check dp[i][j-1]
// whichever is maximum assign it to dp[i][j].

class Solution
{
public:



    int lcs(int x, int y, string s1, string s2)
    {
        int n = s1.size(), m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];


    }
};

// t.c. = O(N*M)
// s.c. = O(N*M)

// space optimized.
// for calculating current state we are just checking prev row so instead of storing all rows we can just keep 1 prev row and 1 curr row where
// we can calculate curr row/state with the help of prev and then after calculating curr we can make curr as new prev for the next state/row.
// final ans will be in prev as after calculation of final state we will assign it to prev and ans will be dp[n][m] i.e. prev[m].


class Solution
{
public:

    int lcs(int x, int y, string s1, string s2)
    {
        int n = s1.size(), m = s2.size();

        vector<int> curr(m + 1, 0), prev(m + 1, 0);

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            prev = curr;
        }

        return prev[m];


    }
};

// t.c. = O(N*M)
// s.c. = O(2*M) = O(M)