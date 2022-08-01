// create a dp[n1][n1][n3] with all -1.
// call the rec. function by passing i=0,j=0,k=0 and dp as arguments.in each rec. call if i==sz1 or j==sz2 or k==sz3 return 0,
// else if dp[i][j][k]!=-1 return dp[i][j][k] as it is already calculated.
// if a[i]=b[j]=c[k] then we have found a matching character so call on rec(i+1,j+1,k+1,dp) and add 1 for the matching character and stored it then
// return it.
// else, we for each pointer we have two choices i.e. increment it or keep it as it is and out of those 2 possibilities i.e. increment all pointer and
// not increment any pointer won't be a valid choice so except them we will explore other 6 choices of pointers and whichever choice return maximum
// we will store it and return it.


string a, b, c;
int sz1, sz2, sz3;

int rec(int i, int j, int k, vector<vector<vector<int>>> &dp) {

    if (i == sz1 || j == sz2 || k == sz3) return 0;

    if (dp[i][j][k] != -1) return dp[i][j][k];

    if (a[i] == b[j] && b[j] == c[k]) {

        return dp[i][j][k] = 1 + rec(i + 1, j + 1, k + 1, dp);
    } else {

        return dp[i][j][k] = max({rec(i + 1, j, k, dp), rec(i + 1, j + 1, k, dp), rec(i + 1, j, k + 1, dp), rec(i, j, k + 1, dp),
                                  rec(i, j + 1, k + 1, dp), rec(i, j + 1, k, dp)
                                 });
    }

}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here

    a = A, b = B, c = C;
    sz1 = n1, sz2 = n2 , sz3 = n3;

    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));

    return rec(0, 0, 0, dp);


}

// t.c. = O(N1*N2*N3)
// s.c. = O(N1*N2*N3) + O(max(N1,N2,N3))(stack space).

// iterative.
// just reverse the order of evaluation as compare to recursion of parameters and rest all base conditions, transitions remains exactly the same.


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{


    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));

    for (int i = n1; i >= 0; i--) {

        for (int j = n2; j >= 0; j--) {

            for (int k = n3; k >= 0; k--) {

                if (i == n1 || j == n2 || k == n3) dp[i][j][k] = 0;
                else {

                    if (A[i] == B[j] && B[j] == C[k]) {
                        dp[i][j][k] = 1 + dp[i + 1][j + 1][k + 1];
                    } else {

                        dp[i][j][k] = max({dp[i + 1][j][k], dp[i + 1][j + 1][k], dp[i + 1][j][k + 1], dp[i][j][k + 1], dp[i][j + 1][k + 1], dp[i][j + 1][k]});
                    }
                }
            }
        }
    }

    return dp[0][0][0];


}

// t.c.  = O(N1*N2*N3)
// s.c. = O(N1*N2*N3)

// space optimized.

//to calculate the current state we were just requiring previous state so we will just store prev state and use it to calculate curr state and
// after calculation of curr state we will make it prev to calculate the next state.


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{


    vector<vector<int>> curr(n2 + 1, vector<int>(n3 + 1)), prev(n2 + 1, vector<int>(n3 + 1));

    for (int i = n1; i >= 0; i--) {

        for (int j = n2; j >= 0; j--) {

            for (int k = n3; k >= 0; k--) {

                if (i == n1 || j == n2 || k == n3) curr[j][k] = 0;
                else {

                    if (A[i] == B[j] && B[j] == C[k]) {
                        curr[j][k] = 1 + prev[j + 1][k + 1];
                    } else {

                        curr[j][k] = max({prev[j][k], prev[j + 1][k], prev[j][k + 1], curr[j][k + 1], curr[j + 1][k + 1], curr[j + 1][k]});
                    }
                }
            }
        }

        prev = curr;
    }

    return prev[0][0];


}


// t.c. = O(N1*N2*N3)
// s.c. = O(N2*N3)


// clean code.

// the following three transitions will cover all the 6 choices : rec(i+1,j,k),rec(i,j+1,k),rec(i,j,k+1).


string a, b, c;
int sz1, sz2, sz3;

int rec(int i, int j, int k, vector<vector<vector<int>>> &dp) {

    if (i == sz1 || j == sz2 || k == sz3) return 0;

    if (dp[i][j][k] != -1) return dp[i][j][k];

    if (a[i] == b[j] && b[j] == c[k]) {

        return dp[i][j][k] = 1 + rec(i + 1, j + 1, k + 1, dp);
    } else {

        return dp[i][j][k] = max({rec(i + 1, j, k, dp), rec(i, j + 1, k, dp), rec(i, j, k + 1, dp)});
    }

}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here

    a = A, b = B, c = C;
    sz1 = n1, sz2 = n2 , sz3 = n3;

    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));

    return rec(0, 0, 0, dp);


}

// we can easily convert it into space optimized like previous codes.


