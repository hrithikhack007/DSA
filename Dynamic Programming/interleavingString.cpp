// recursive + 3-d dp.
// dp[i][j][k] represents if string s3 from k to sz3 - 1 is interleaving string of string s1 from i to sz1 - 1 and string s2 from j to sz2-1.
// if k==sz3 and i == sz1 and j == sz2 that means we have successfully made string s3 using s1 and s2 so return true.
// if dp[i][j][k]!=-1 return dp[i][j][k] as it is already computed.
// set ok1 and ok2 to false.
// if i!=sz1 and if s1[i] == s3[k] then we can choose the kth character from s1's ith character so we will call on rec(i+1,j,k+1) and store it in
// ok1 and also if j1 != sz2 and s2[j] == s3[k] then we can make the kth character of s3 from s2's jth character so we will call on rec(i,j+1,k+1).
// now if either of the choices returns true so we return true i.e.return ok1 || ok2.
// edge cases: if sz1 + sz2 != sz3 return false in the start only.

class Solution {
public:

    bool rec(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp) {

        if (k == s3.size() && i == s1.size() && j == s2.size()) return true;

        if (dp[i][j][k] != -1) return dp[i][j][k];

        bool ok1 = false, ok2 = false;

        if (i != s1.size() && s1[i] == s3[k]) {

            ok1 = rec(i + 1, j, k + 1, s1, s2, s3, dp);
        }

        if (j != s2.size() && s2[j] == s3[k]) {
            ok2 = rec(i, j + 1, k + 1, s1, s2, s3, dp);
        }

        return dp[i][j][k] = (ok1 || ok2);

    }

    bool isInterleave(string s1, string s2, string s3) {


        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();

        if (sz1 + sz2 != sz3) return false;

        vector<vector<vector<int>>> dp(sz1 + 1, vector<vector<int>>(sz2 + 1, vector<int>(sz3 + 1, -1)));


        return rec(0, 0, 0, s1, s2, s3, dp);


    }
};

// t.c. = O(N*M*K)
// s.c. = O(N*M*K) + O(K)(stack space) = O(N*M*K)

// optimized to 2d space.
//  we can calculate the 3rd dimension k from i and j itself. i.e. k = i+j.

class Solution {
public:

    bool rec(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {

        int k = i + j;

        if (k == s3.size() && i == s1.size() && j == s2.size()) return true;

        if (dp[i][j] != -1) return dp[i][j];

        bool ok1 = false, ok2 = false;

        if (i != s1.size() && s1[i] == s3[k]) {

            ok1 = rec(i + 1, j, s1, s2, s3, dp);
        }

        if (j != s2.size() && s2[j] == s3[k]) {
            ok2 = rec(i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = (ok1 || ok2);

    }

    bool isInterleave(string s1, string s2, string s3) {


        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();

        if (sz1 + sz2 != sz3) return false;

        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, -1));


        return rec(0, 0, s1, s2, s3, dp);


    }
};

// t.c. = O(N*M)
// s.c. = O(N*M) + O(K)(stack space). = O(N*M)


// iterative.
// just reverse the order of evaluation as compared to recursion and keep all base conditions and transitions exactly same.

class Solution
{
public:


    bool isInterleave(string s1, string s2, string s3)
    {

        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();

        if (sz1 + sz2 != sz3) return false;

        vector<vector < int>> dp(sz1 + 1, vector<int> (sz2 + 1));

        for (int i = sz1; i >= 0; i--)
        {

            for (int j = sz2; j >= 0; j--)
            {

                int k = i + j;

                if (k == sz3 && i == sz1 && j == sz2)
                {
                    dp[i][j] = true;
                }
                else
                {

                    bool ok1 = false, ok2 = false;

                    if (i != s1.size() && s1[i] == s3[k])
                    {

                        ok1 = dp[i + 1][j];
                    }

                    if (j != s2.size() && s2[j] == s3[k])
                    {
                        ok2 = dp[i][j + 1];
                    }

                    dp[i][j] = (ok1 || ok2);
                }
            }
        }

        return dp[0][0];
    }
};

// t.c. = O(N*M)
// s.c. = O(N*M)

// space optimized.

class Solution
{
public:


    bool isInterleave(string s1, string s2, string s3)
    {

        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();

        if (sz1 + sz2 != sz3) return false;

        vector<int> curr(sz2 + 1), prev(sz2 + 1);

        for (int i = sz1; i >= 0; i--)
        {

            for (int j = sz2; j >= 0; j--)
            {

                int k = i + j;

                if (k == sz3 && i == sz1 && j == sz2)
                {
                    curr[j] = true;
                }
                else
                {

                    bool ok1 = false, ok2 = false;

                    if (i != s1.size() && s1[i] == s3[k])
                    {

                        ok1 = prev[j];
                    }

                    if (j != s2.size() && s2[j] == s3[k])
                    {
                        ok2 = curr[j + 1];
                    }

                    curr[j] = (ok1 || ok2);
                }
            }

            prev = curr;
        }

        return prev[0];
    }
};

// t.c. = O(N*M)
// s.c. = O(M)