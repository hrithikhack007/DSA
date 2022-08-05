// iterative.
// dp[i][j] represents the longest common subtring between s1 and s2 such that it is ending at ith index in s1 and jth index in s2.
// declare dp[n][m], set maxi to 0.
// iterate from i=0 to n and for each i iterate from j=0 to n and in each iteration if i==0 || j==0 then there is no commom subtring so
// set dp[i][j]=0, else if s1[i-1]==s2[j-1] then set dp[i][j] = dp[i-1][j-1] + 1 else dp[i][j] = 0(because ith and jth character only
//  doesn't match then the there cannot be any common substring ending at ith index in s1 and jth index in s2) else if they are equal then
// we will ask dp[i-1][j-1] and add 1 in it.
// after this we will maximize maxi with dp[i][j] because longest common subtring can end at any i,j so we have to check every state.



class Solution {
public:

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        int maxi = 0;

        for (int i = 0; i <= n; i++) {

            for (int j = 0; j <= m; j++) {

                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {

                    dp[i][j] = (S1[i - 1] == S2[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
                }

                maxi = max(maxi, dp[i][j]);
            }
        }

        return maxi;

    }
};

// t.c. = O(N*M)
// s.c. = O(N*M)

// space optimized.


class Solution {
public:

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {

        vector<int> curr(m + 1), prev(m + 1);

        int maxi = 0;

        for (int i = 0; i <= n; i++) {

            for (int j = 0; j <= m; j++) {

                if (i == 0 || j == 0) {
                    curr[j] = 0;
                } else {

                    curr[j] = (S1[i - 1] == S2[j - 1]) ? prev[j - 1] + 1 : 0;
                }

                maxi = max(maxi, curr[j]);
            }

            prev = curr;
        }

        return maxi;

    }
};

// t.c. = O(N*M)
// s.c. = O(M)


// recursive solution.
// initially assign dp[i][j] to 0.
// if s[i]==s[j] then call on rec(i+1,j+1) and add 1 and assign it to dp[i][j].
// also call on rec(i+1,j) and rec(i,j+1) even if i and j matches.
// because there might be case like these : s1 = abcd , s2 = aabc . so if we see that s1[0] and s2[0] matches and didn't call on
// rec(i,j+1) then it will return 1 as ans but right ans is 3 so basically we have to exlpore every starting point where both string
// can start and dp[i][j] stores the longest common subtring between s1 and s2 where s1 starts from i and s2 starts from j.


class Solution {
public:

    int rec(int i, int j, string &s1, string &s2, int &maxi, vector<vector<int>> &dp) {

        if (i == s1.size() || j == s2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = 0;

        if (s1[i] == s2[j]) {

            dp[i][j] = 1 + rec(i + 1, j + 1, s1, s2, maxi, dp);
        }

        rec(i + 1, j, s1, s2, maxi, dp);
        rec(i, j + 1, s1, s2, maxi, dp);

        maxi = max(maxi, dp[i][j]);


        return dp[i][j];

    }


    int longestCommonSubstr (string S1, string S2, int n, int m)
    {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int maxi = 0;

        rec(0, 0, S1, S2, maxi, dp);

        return maxi;

    }
};

// t.c. = O(N*M)
// s.c. = O(N*M) + O(max(N,M))(stack space).

