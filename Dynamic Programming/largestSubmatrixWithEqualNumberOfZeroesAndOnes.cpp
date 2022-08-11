// first create 2-d prefix sum of given matrix by considering 0's as -1 and 1's as 1.
// set maxi to 0.
// traverse all pairs of columns and for each pair declare an unordered map and traverse rows from r = 1 to n, and in each iteration calculate
// the sum of the current sub matrix using 2-d prefix in constant time.
// if the sum is 0 or sum is already encountered by previous row then there exist a sub matrix such that its sum is zero that means it contains
// equal number of 0's and 1's and ending at rth row.
// so if the sum is only 0 that means starting row is 1 else starting row is the row where we encountered this sum previously + 1 so and columns
// are c1 and c2 and ending row is r so using this indexes of sub matrix calculate the area and maximize the ans with that area.

#include<bits/stdc++.h>

int maximumArea(vector<vector<int>>& mat, int n, int m)
{

    vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            int val = mat[i - 1][j - 1] == 0 ? -1 : 1;

            p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + val;
        }
    }

    int maxi = 0;

    for (int c1 = 1; c1 <= m; c1++) {

        for (int c2 = c1; c2 <= m; c2++) {

            unordered_map<int, int> mp;

            for (int r = 1; r <= n; r++) {

                int sumTillRow = p[r][c2] - p[r][c1 - 1];

                if (sumTillRow == 0 || mp.find(sumTillRow) != mp.end()) {

                    int r1 = sumTillRow == 0 ? 1 : mp[sumTillRow] + 1;
                    int r2 = r;

                    maxi = max(maxi, (r2 - r1 + 1) * (c2 - c1 + 1));

                } else {
                    mp[sumTillRow] = r;
                }
            }
        }

    }

    return maxi;

}

// t.c. = O(M*M*N) + O(N*M) = O((M^2)*N)
// s.c. = O(N*M) + O(N)(map) = O(N*M)

// we can optimize the space complexity to O(N) by using the given matrix to store the 2-d prefix.
