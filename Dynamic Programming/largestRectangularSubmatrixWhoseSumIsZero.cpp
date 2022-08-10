// we will first create a 2d prefix sum.
// then take a indexes array to store largest submatrix indexes and set maxi to -1.
// now we will traverse over all possible pairs of columns and for each pair of column we will traverse the rows in between that columns from
// 1st to nth row as we have stored prefix sum in 1 based indexing.
// so before traversing rows take an unordere map to store prefix sum of rows.
// for each row take sumTillRow i.e. sum till current row or sum of current submaxtrix between two columns c1 and c2 and till rth row.
// that we can get by just subtrcating prefix sum of sub matrix pa[r][c1-1] from prefix sum of whole submatrix pa[r][c2].
// now if sum of this submatrix is 0 or this sum has appeared in one of the previous submatrix then there exist a submatrix with sum = 0
// so the index of the row where this current sum occured will be present in our map so the submatrix with 0 sum will start from just after that
// index and end at the current rth row or else if sum is only 0 then starting row of zero sum submatrix will be 1 as default.
// now we have indexes of this zero sum submatrix and if the area of it it > current maxi then assign maxi with this new maxi area and update
// the indexes of largest submatrix with 0 sum.
// else if sum!=0 || sum doesn't exist in map then there is not any zero sum subarray ending at rth row so just assign current row to mp[sum].
// and if it was already present then don't assign it as we want to keep the row as above as possible to have the largest area.
// in last if indexes if empty then return empty sub matrix or traverse that indices and push the elements in sub matrix and return the largest
// sub matrix with 0 sum.


class Solution {
public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a) {

    int n = a.size(), m = a[0].size();


    vector<vector<int>> pa(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {

      for (int j = 1; j <= m; j++) {

        pa[i][j] = pa[i - 1][j] + pa[i][j - 1] - pa[i - 1][j - 1] + a[i - 1][j - 1];
      }
    }

    vector<int> indexes;
    int maxi = -1;

    for (int c1 = 1; c1 <= m; c1++) {

      for (int c2 = c1; c2 <= m; c2++) {

        unordered_map<int, int> mp;


        for (int r = 1; r <= n; r++) {

          int sumTillRow = pa[r][c2] - pa[r][c1 - 1];

          if (sumTillRow == 0 || mp.find(sumTillRow) != mp.end()) {

            int R1 = sumTillRow == 0 ? 1 : mp[sumTillRow] + 1;
            int C1 = c1, C2 = c2;
            int R2 = r;

            if ((R2 - R1 + 1) * (C2 - C1 + 1) > maxi) {

              maxi = (R2 - R1 + 1) * (C2 - C1 + 1);
              indexes = {R1 - 1, R2 - 1, C1 - 1, C2 - 1};

            }



          } else {

            mp[sumTillRow] = r;

          }

        }


      }
    }


    vector<vector<int>> ans;

    if (indexes.size() == 0) return ans;


    for (int i = indexes[0]; i <= indexes[1]; i++) {

      vector<int> row;

      for (int j = indexes[2]; j <= indexes[3]; j++) {

        row.push_back(a[i][j]);

      }

      ans.push_back(row);
    }

    return ans;


  }
};

// t.c. = O(M*M*N) = O((M^2)*N) => where M is the number of columns and N is the no. of rows.
// s.c. = O(N*M) + O(N) = O(N*M)