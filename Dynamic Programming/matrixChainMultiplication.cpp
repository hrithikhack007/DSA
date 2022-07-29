// pre - requisites: if we want to multiply two matrices m1 and m2 then no. of columns in the m1 should be equal to no. of rows in m2.
// the dimensions of the resultant matrix after multiplication of m1 and m2 say m will be r1 * c2. and to calculate each cell of resultant
// matrix we will have to perform c1 or r2 number of operations.
// Basically to calculate cell m11 we have to mutliply 1st row of m1 with 1st column of m2. e.g. let's say a is 3*4 and b is 4*5
// then resultant c11 = a[1][1]*b[1][1] + a[1][2]*b[2][1] + a[1][3]*b[3][1] + a[1][4]*b[4][1]
// then for c21 we have to multiply 2nd row of a and 1st column of b i.e.
// c21 = a[2][1]*b[1][1] + a[2][2]*b[2][1] + a[2][3]*b[3][1] + a[2][4]*b[4][1]
// ans so on....
// so resultant matrix will be of size 3*5 and to calculate each cell we have to perform 4 operations so total operations to multiply this two
// matrices are 3*5*4 = 60.

// now in the problem we have given matrices in the form of array i.e. of the size of the array is 6 then we have 5 matrices where matrix A is
// 0-1 , b is 1-2, c is 2-3 , d is 3-4 and e is 4-5.
// so if we are saying l = 0 to r = 3 then we are talking about matrices which is starting from index l and ending at index r in this case
// we are talking about matrices a,b and c because a is starting at 0 and c is ending at 3. so we will follow this indexing while storing our
// ans.

// dp[i][j] represents the minimum operations we have to perform to multiply matrices in the range l=i to r = j.

// now we will first store the ans to multiply 1 and 2 matrices. as 1 matrix take 2 index we will start our gap from 2 and if gap is 2 then
// we are talking about single matrix and to multiply single matrix we require 0 operations so simply store 0 else if gap is 3 then we are
// talking about two matrices a and b and to multiply them we will require ra * cb * rb so we will save it.
// else, we are talking about 3 or more matrices, so we will set k to l+1 and it will go till r-1.
// now we can multiply (l to k) matrices then its resultant with (k to r) matrices so the number of rows in the resultant matrix after multiplication
// of left side matrices will be arr[l] because the extremes remains in the resultant matrix after multiplication similarly the number of columns
// in the resultant matrix after multiplication of matrix right side matrices will be arr[r] and then the arr[k] will be the no. of columns in the
// left resultant and no. of rows in the right resultant so total number of operations to multiply left and right side matrices will be
// dp[l][k](to separately multiply left side matrices) + dp[k][r](to separately multiply right side matrices) and (arr[l]*arr[r]*arr[k])(to multiply
//  the resultant left and right matrix)
// and we will do this for all k from l+1 to r-1 for e.g. in the range l to r the matrices are c,d,e,f in the range l = 2 to r = 6
// then when k = l + 1 = 2 + 1 = 3, we will have left side ans from dp[l][k] => dp[2][3] min. operations to calculate matrix from 2 to 3 i.e. matrix
// c itself  and right side ans i.e. dp[3][6] min. operations required to multiply matrices (d,e,f) and arr[l]*arr[r]*arr[k] i.e. operations required
// to multiply resultant left and right. then we will minimize dp[l][r] with this i.e dp[l][k] + dp[k][r] + (arr[l]*arr[r]*arr[k]) then after this
// we will move k to 4 and now we will do dp[2][4] i.e. to multiply matrices c,d and dp[4][6] to multiply matrices from e,f and arr[l]*arr[r]*arr[k]
// operations required to multiply resultant of (c,d) and resultant of (e,f) and we will do this till k<r.
//for every k we will minimize our dp[l][r].


class Solution {
public:
    int matrixMultiplication(int N, int arr[])
    {

        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

        for (int g = 2; g <= N; g++) {

            for (int l = 0; l + g - 1 < N; l++) {

                int r = l + g - 1;

                dp[l][r] = INT_MAX;


                if (g == 2) {

                    dp[l][r] = 0;
                } else if (g == 3) {

                    dp[l][r] = arr[l] * arr[r] * arr[l + 1];

                } else {

                    for (int k = l + 1; k < r; k++) {

                        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + (arr[l] * arr[r] * arr[k]));

                    }
                }



            }

        }

        return dp[0][N - 1];


    }
};


// t.c. = O(N^3)
// s.c. = O(N^2)
