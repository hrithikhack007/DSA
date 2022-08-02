// declare dp[n][m] with all 0. dp[i][j] represents the maximum size square I can form that ends at cell i,j.
// now traverse the matrix and for each cell, check if it is 1 , if it is then check dp[i-1][j],dp[i][j-1],dp[i-1][j-1] i.e. maximum size square
// that can end to its up,left and diagonal left cell and take minimum and add 1 that will be the maximum size square I can form at cell (i,j)
// return maxi*maxi number of cells in the maximal square.

// intuition: let's say the minimum of three adjacent cell is 2 that means we can at most have 2 1's cells in the bottom row , right row and diagonal
// so by adding this cell i,j I will have three 1's in the bottom,right and diagonal so we will have square of size 3. also we are taking minimum
// because let's two cells have size 3 and one left cell is having size 2 so even if we 3 cells in diagonal and right we will only have 2 cells in
// left so adding the current cell will only result in 3 cells in row even though we had 3 cells in diagonal and right so the maximum size square
// we can form by adding cell i,j depends on the minima of left,up and diagonal cell.


class Solution
{
public:
    int maximalSquare(vector<vector < char>> &matrix)
    {

        int n = matrix.size(), m = matrix[0].size();

        vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));
        int maxi = 0;

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= m; j++)
            {

                if (matrix[i - 1][j - 1] - '0')
                {
                    dp[i][j] = min({ dp[i - 1][j],
                                     dp[i][j - 1],
                                     dp[i - 1][j - 1]
                                   }) + 1;
                }
                maxi = max(maxi, dp[i][j]);
            }
        }

        return maxi * maxi;
    }
};

// t.c. = O(N*M)
// s.c. = O(N*M)

// space optimized.
// edge case: if cell i,j is  0 then explicitly set curr[j] to 0 because in the prev state/row jth column might had value 1 but now it
// should be 0.

class Solution
{
public:
    int maximalSquare(vector<vector < char>> &matrix)
    {

        int n = matrix.size(), m = matrix[0].size();

        vector<int> curr(m + 1, 0), prev(m + 1, 0);
        int maxi = 0;

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= m; j++)
            {

                if (matrix[i - 1][j - 1] - '0')
                {
                    curr[j] = min({prev[j],
                                   curr[j - 1],
                                   prev[j - 1]
                                  }) + 1;
                } else {
                    curr[j] = 0;
                }
                maxi = max(maxi, curr[j]);
            }

            prev = curr;
        }

        return maxi * maxi;
    }
};

// t.c. = O(N*M)
// s.c. = O(M)