// recursion + memo.
// set ans to 0, now from first column we have n choices i.e. we can start from cell (0,0),(1,0),(2,0),...(n-3,0),(n-2,0),(n-1,0).
// so we will iterate from i=0 to n-1 and make a rec. call by passing r=i,c=0,M,n,m as arguments and we will maximize our ans by its returned value
// i.e. the maximum gold we can collect if we start from ith row/cell of the 0th column.
// in each rec. call if we went out of bound of matrix then return 0, else if dp[r][c]!=-1 that means it is already computed so return it.
// else, we will try 3 possible directions from the current cell , so run a loop from k = 0 to 2 where in each iteration take nr = r + row[k],
// nc = c + col[k] basically row[k],col[k] will give us the direction from the current cell.
// then add the golds of the current cell and call on the rec by passing rec(nr,nc) i.e. m[r][c] + rec(nr,nc) and maximize our ans by this.
// i.e. out of three possible choices take the choice which return the maximum amount of gold and update our ans.
// then store the ans in dp[r][c] and return it.


class Solution {
public:

    int row[3] = { -1, 0, 1};
    int col[3] = {1, 1, 1};

    int rec(int r, int c, vector<vector<int>> &M, int n, int m, vector<vector<int>> &dp) {

        if (r == -1 || r == n || c == -1 || c == m) {
            return 0;
        }

        if (dp[r][c] != -1) return dp[r][c];

        int ans = 0;

        for (int k = 0; k < 3; k++) {

            int nr = r + row[k], nc = c + col[k];

            ans = max(ans, rec(nr, nc, M, n, m, dp) + M[r][c]);


        }

        return dp[r][c] = ans;




    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {

        int ans = 0;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i < n; i++) {

            ans =  max(ans, rec(i, 0, M, n, m, dp));

        }

        return ans;


    }
};


// t.c. = O(N*M*3) + O(N) = O(N*M)
// s.c. = O(N*M) + O(M)(stack space)


// iterative.

// start from the last colum and in each iteration start row from 0 and for each cell set dp[r][c] to M[r][c] and then for that cell we have three
// choices so we will explore those choices and if the new cell is not out of bound then we will try to maximize dp[r][c] with dp[nr][nc] + M[r][c]
// where dp[nr][nc] is the maximum golds we can achieve if we start from cell nr,nc and M[r][c] is the current cell gold.
// and if we are at the 0th row then we will try to maximize the final ans with dp[r][c].


class Solution {
public:

    int row[3] = { -1, 0, 1};
    int col[3] = {1, 1, 1};

    int maxGold(int n, int m, vector<vector<int>> M)
    {

        int ans = 0;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));


        for (int c = m - 1; c >= 0; c--) {

            for (int r = 0; r < n; r++) {

                dp[r][c] = M[r][c];


                for (int k = 0; k < 3; k++) {

                    int nr = r + row[k], nc = c + col[k];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                        dp[r][c] = max(dp[r][c], dp[nr][nc] + M[r][c]);
                    }

                }

                if (c == 0) {
                    ans = max(ans, dp[r][c]);
                }


            }

        }


        return ans;


    }
};

// t.c. = O(N*M*3) = O(N*M)
// s.c. = O(N*M)


// space optimized.
// we can clearly see that for the calclation of the ith column we just require information of (i+1)th column so instead of storing all the columns
// we can keep only two columns i.e. curr and prev in which we will calculate the values of current column with the help of prev calculated column
// and after calculating current the curr will act as prev for next column.
// for e.g. if current column is 3 and row is 4th then it is dp[4][3] so we will represent it with curr[4] i.e. we know it is the current column
// and in this column we are talking about 4th row and we want let's say dp[5][4] i.e. we are talking about prev column so it will be represented
// as prev[5] i.e. 5th row in the prev column. and after computation of 3rd column is over all the values from row 0 to n - 1 will be stored in
// curr so we will assign it to prev so for the next column i.e. 2 it will act as prev.

// it is some what different from other dp problem because in this we are removing column dimension unlike other where we remove row dimension
// so we have to declare curr and prev with the size of rows i.e. n+1.


class Solution {
public:

    int row[3] = { -1, 0, 1};
    int col[3] = {1, 1, 1};

    int maxGold(int n, int m, vector<vector<int>> M)
    {

        int ans = 0;

        vector<int> curr(n + 1, 0);
        vector<int> prev(n + 1, 0);


        for (int c = m - 1; c >= 0; c--) {

            for (int r = 0; r < n; r++) {

                curr[r] = M[r][c];


                for (int k = 0; k < 3; k++) {

                    int nr = r + row[k], nc = c + col[k];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                        curr[r] = max(curr[r], prev[nr] + M[r][c]);
                    }

                }

                if (c == 0) {
                    ans = max(ans, curr[r]);
                }


            }

            prev = curr;

        }


        return ans;


    }
};

// t.c. = O(N*M)
// s.c. = O(N)


