// first create 2-d prefix sum of given matrix.
// set maxi to -inf.
// now traverse all pairs of columns and for each pair of colum set sum to 0 and then traverse row from top to bottom then
// in each iteration, calculate the sum of that row and add it to sum and maximize the ans with this sum and if sum becomes negative
// then there is no meaning in taking this sum with us so we will set the sum to 0 and start the new submatrix from the next row.
// basically fixing two columns and applying kadane's on the submatrix between them by treating each row as the element of the array
// and entire submatrix as the array.

class Solution {
public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {


        vector<vector<int>> p(R + 1, vector<int>(C + 1, 0));

        for (int i = 1; i <= R; i++) {

            for (int j = 1; j <= C; j++) {

                p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + M[i - 1][j - 1];
            }
        }

        int maxi = INT_MIN;

        for (int c1 = 1; c1 <= C; c1++) {

            for (int c2 = c1; c2 <= C; c2++) {

                int sum = 0;

                for (int r = 1; r <= R; r++) {


                    sum += p[r][c2] - p[r][c1 - 1] - p[r - 1][c2] + p[r - 1][c1 - 1];

                    maxi = max(maxi, sum);

                    if (sum < 0) sum = 0;

                }

            }
        }

        return maxi;


    }
};

// t.c. = O(C*C*R) + O(R*C) = O((C^2)*R)
// s.c. = O(R*C)
