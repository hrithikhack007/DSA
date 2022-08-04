// recursion + memo.
// we can start from 0 to n-1 columns from the 0th row. so iterate loop from c=0 to n - 1 and in each iteration call rec(c=c,r=0) as arguments
// then in each rec. call if r,c is out of bound of matrix then return 0, else if dp[r][c] != -1 that means it is already computed so return it.
// else we have three options from current cell i.e. left down, right down or just down so we will explore this choices and whichever returns maximum
// we will return that.



int col[3] = { -1, 1, 0};

int rec(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

    if (c < 0 || c == matrix.size() || r == matrix.size()) return 0;

    if (dp[r][c] != -1) return dp[r][c];

    int ans = -1;

    for (int k = 0; k < 3; k++) {

        int nr = r + 1, nc = c + col[k];

        ans = max(ans, rec(nr, nc, matrix, dp) + matrix[r][c]);
    }

    return dp[r][c] = ans;


}

class Solution {
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {


        int ans = -1;

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

        for (int c = 0; c < N; c++) {


            ans = max(ans, rec(0, c, Matrix, dp));

        }


        return ans;



    }
};


// t.c. = O(3*N*N) = O(N^2)
//s.c. = O(N*N) + O(N)(stack space). = O(N^2)

// iterative.
// just start from last row and for each row traverse column c from N-1 to 0 and for each r,c we have three options explore it and if the new
// cell is out of bound then take 0 else take dp[nr][nc] as val and maximixe the temp with val + matrix[r][c] so after the three choices whichever
// gives maximum will be our dp[r][c] i.e. the the maximum coins I can get starting from cell r,c. when we reach 0th row i.e. r = 0 then after
// calculation of dp[r][c] maximize the ans with dp[r][c].

int col[3] = { -1, 1, 0};

class Solution {
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {


        int ans = -1;

        vector<vector<int>> dp(N + 1, vector<int>(N + 1));

        for (int r = N - 1; r >= 0; r--) {

            for (int c = N - 1; c >= 0; c--) {

                int temp = -1;

                for (int k = 0; k < 3; k++) {

                    int nr = r + 1, nc = c + col[k];

                    int val = (nr == N || nc < 0 || nc == N) ? 0 : dp[nr][nc];

                    temp = max(temp, val + Matrix[r][c]);

                }

                dp[r][c] = temp;

                if (r == 0) ans = max(ans, dp[r][c]);

            }

        }

        return ans;

    }
};

// t.c. = O(3*N*N) = O(N^2)
// s.c. = O(N^2)

// space optimized.

int col[3] = { -1, 1, 0};

class Solution {
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {


        int ans = -1;

        vector<int> curr(N + 1), prev(N + 1);

        for (int r = N - 1; r >= 0; r--) {

            for (int c = N - 1; c >= 0; c--) {

                int temp = -1;

                for (int k = 0; k < 3; k++) {

                    int nr = r + 1, nc = c + col[k];

                    int val = (nr == N || nc < 0 || nc == N) ? 0 : prev[nc];

                    temp = max(temp, val + Matrix[r][c]);

                }

                curr[c] = temp;

                if (r == 0) ans = max(ans, curr[c]);

            }

            prev = curr;

        }

        return ans;

    }
};

// t.c. = O(N^2)
// s.c. = O(N)
