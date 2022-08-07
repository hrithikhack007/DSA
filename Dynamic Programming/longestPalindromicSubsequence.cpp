// first of all longest palindromic subsequence is the longest common subsequence between the original string and its reversed .
// so dp[i][j] represents the longest common subsequencce I can get if i start from i in original string and from j in reversed string.
// basically when the character of string A matches with character of string B at i and j respectively that means i and n - i - 1 characters
// in the original substring matches so if this is the first match then it is the extremes of the palindromic subsequence and similarly
// if some i1 and j1 matches second time so i1 will be the second character and j1 will be the second last character in the palindromic
// subsequence and so on so it just boils down to find the lcs of original and reversed .

class Solution {
public:

  int rec(int i, int j, string &A, string &RA, vector<vector<int>> &dp) {

    if (i == A.size() || j == A.size()) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (A[i] == RA[j]) {
      return dp[i][j] = rec(i + 1, j + 1, A, RA, dp) + 1;
    } else {
      return dp[i][j] = max(rec(i, j + 1, A, RA, dp), rec(i + 1, j, A, RA, dp));
    }

  }

  int longestPalinSubseq(string A) {

    string RA = A;
    reverse(RA.begin(), RA.end());

    int n = A.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return rec(0, 0, A, RA, dp);


  }
};


// t.c. = O(N*N)
// s.c. = O(N*N) + O(N)(reversed string) + O(N)(stack space).


// we can optimize space by not using the reversed string so while accessing the characters from the reversed string we will access it directly
// from original string because jth character in the reversed string is (n - j - 1)th character in the original string.

class Solution {
public:

  int rec(int i, int j, string &A, vector<vector<int>> &dp) {

    if (i == A.size() || j == A.size()) return 0;


    if (dp[i][j] != -1) return dp[i][j];

    if (A[i] == A[A.size() - j - 1]) {
      return dp[i][j] = rec(i + 1, j + 1, A, dp) + 1;
    } else {
      return dp[i][j] = max(rec(i, j + 1, A, dp), rec(i + 1, j, A, dp));
    }

  }

  int longestPalinSubseq(string A) {

    int n = A.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return rec(0, 0, A, dp);


  }
};

// t.c. = O(N*N)
// s.c. = O(N*N) + O(N)(stack space).

// iterative.
// just reverse the order of evaluation as compared to recursion like in recursion we were calling i and j from 0 so in iterative we will
// start i and j from n to 0.
//rest all the base conditions + transitions will remain same.

class Solution {
public:


  int longestPalinSubseq(string A) {

    int n = A.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = n; i >= 0; i--) {

      for (int j = n; j >= 0; j--) {

        if (i == n || j == n) {
          dp[i][j] = 0;
        } else {
          if (A[i] == A[n - j - 1]) {
            dp[i][j] = 1 + dp[i + 1][j + 1];
          } else {
            dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
          }
        }

      }
    }

    return dp[0][0];


  }
};

// t.c. = O(N*N)
// s.c. = O(N*N)

// space optimization.


class Solution {
public:


  int longestPalinSubseq(string A) {

    int n = A.size();

    vector<int> prev(n + 1), curr(n + 1);

    for (int i = n; i >= 0; i--) {

      for (int j = n; j >= 0; j--) {

        if (i == n || j == n) {
          curr[j] = 0;
        } else {
          if (A[i] == A[n - j - 1]) {
            curr[j] = 1 + prev[j + 1];
          } else {
            curr[j] = max(curr[j + 1], prev[j]);
          }
        }

      }

      prev = curr;
    }

    return prev[0];


  }
};

// t.c. = O(N*N)
// s.c. = O(N)